#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define board(x) int x[16][32]

/* Bot 1 */
#define bot query_player1_move
#define bot_name player1_name

// Example bot 1.
char * bot_name = "Random bot 1";
int bot(board(b), int player) {
    return "UDLR"[rand() % 4];
}

#undef bot
#undef bot_name
/* Bot 2 */
#define bot query_player2_move
#define bot_name player2_name

// Example bot 2.
char * bot_name = "Random bot 2";
int bot(board(b), int player) {
    return "UDLR"[rand() % 4];
}

#undef bot
#undef bot_name

volatile int turn = 0;

/* Naive flood fill; returns the amount of space filled and whether
   the operation was lethal to the other player. The board is relatively
   small (32x16), so I can get away with this implementation. */
int fill(board(b), char player, int row, int col, int * lethal) {
    if (row < 0 || row >= 16 || col < 0 || col >= 32 || (player == 'X' ? (b[row][col] == 'X' || b[row][col] == '*') : (b[row][col] == 'O' || b[row][col] == '@')))
        return 0;
    int filled = 0;
    if(player == 'X')
        if(b[row][col] != 'X' && b[row][col] != '*')
            { if(b[row][col] == '@') *lethal = 1; b[row][col] = 'X'; filled = 1; }
    if(player == 'O')
        if(b[row][col] != 'O' && b[row][col] != '@')
            { if(b[row][col] == '*') *lethal = 1; b[row][col] = 'O'; filled = 1; }
    return fill(b, player, row + 1, col, lethal)
         + fill(b, player, row - 1, col, lethal)
         + fill(b, player, row, col + 1, lethal)
         + fill(b, player, row, col - 1, lethal)
         + filled;
}

void displayBoard(const board(b), int ticks, int p1X, int p1Y, int p2X, int p2Y) {
    printf("== Tick %d. ==\n", ticks);
    printf("Player \x1b[31mX\x1b[0m: %d, %d\n", p1X, p1Y);
    printf("Player \x1b[32mO\x1b[0m: %d, %d\n", p2X, p2Y);
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 32; j++) {
            if(b[i][j] == '@' || b[i][j] == 'O')
                printf("\x1b[32m%c\x1b[0m", b[i][j]);
            else if(b[i][j] == '*' || b[i][j] == 'X')
                printf("\x1b[31m%c\x1b[0m", b[i][j]);
            else
                printf("%c", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Conducts the game.
 * Returns -1 if 'X' won, 1 if 'O' won and 0 if it was a draw.
 */
int play() {
    board(b);
    int p1X = 0, p1Y = 0;
    int p2X = 31, p2Y = 15;
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 32; j++)
            b[i][j] = '.';
    b[0][0] = '*';
    b[15][31] = '@';
    int ticks = 0;
    printf("%s VS %s\n\n", player1_name, player2_name);
    for(; ticks < 1024; ticks++) {
        // Print the game status info.
        displayBoard(b, ticks, p1X, p1Y, p2X, p2Y);
        // Process player X move first.
        turn = 'X';
        char player1_move = query_player1_move(b, 'X');
        turn = 0;
        b[p1Y][p1X] = 'X';
        switch(player1_move) {
            case 'U':
                if(p1Y > 0) p1Y--;
                break;
            case 'D':
                if(p1Y < 15) p1Y++;
                break;
            case 'L':
                if(p1X > 0) p1X--;
                break;
            case 'R':
                if(p1X < 31) p1X++;
                break; 
        }
        // Player X kills player O?
        if(b[p1Y][p1X] == '@')
            { displayBoard(b, ticks, p1X, p1Y, p2X, p2Y); return -1; }
        b[p1Y][p1X] = '*';
        // Check if the curve marked by player X needs to be filled.
        // Everything that isn't 'X' or '*' is counted as empty space. 
        // Find the first empty space.
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 32; j++)
                if(b[i][j] != 'X' && b[i][j] != '*') {
                    board(copy); memcpy(copy, b, sizeof(int) * 16 * 32);
                    // Fill the curve.
                    int lethal = 0;
                    int score1 = fill(copy, 'X', i, j, &lethal);
                    // Check if there is empty space left...
                    for(int i2 = 0; i2 < 16; i2++)
                        for(int j2 = 0; j2 < 32; j2++)
                            if(copy[i2][j2] != 'X' && copy[i2][j2] != '*') {
                                // ...and if so, the entire board is not filled yet!
                                // Fill the new curve.
                                int lethal2 = 0;
                                memcpy(copy, b, sizeof(int) * 16 * 32);
                                int score2 = fill(copy, 'X', i2, j2, &lethal2);
                                lethal = 0;
                                if(score1 < score2) {
                                    // The old curve is preferred.
                                    fill(b, 'X', i, j, &lethal);
                                } else {
                                    // The new curve is preferred.
                                    fill(b, 'X', i2, j2, &lethal);
                                }
                                if(lethal)
                                    { displayBoard(b, ticks, p1X, p1Y, p2X, p2Y); return -1; }
                                goto p1_end;
                            }
                }
        p1_end:;
        // Process player O move.
        turn = 'O';
        char player2_move = query_player2_move(b, 'O');
        turn = '0';
        b[p2Y][p2X] = 'O';
        switch(player2_move) {
            case 'U':
                if(p2Y > 0) p2Y--;
                break;
            case 'D':
                if(p2Y < 15) p2Y++;
                break;
            case 'L':
                if(p2X > 0) p2X--;
                break;
            case 'R':
                if(p2X < 31) p2X++;
                break; 
        }
        // Player O kills player X?
        if(b[p2Y][p2X] == '*')
            { displayBoard(b, ticks, p1X, p1Y, p2X, p2Y); return 1; }
        b[p2Y][p2X] = '@';
        // Check if the curve marked by player O needs to be filled.
        // Everything that isn't 'O' or '@' is counted as empty space. 
        // Find the first empty space.
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 32; j++)
                if(b[i][j] != 'O' && b[i][j] != '@') {
                    board(copy); memcpy(copy, b, sizeof(int) * 16 * 32);
                    // Fill the curve.
                    int lethal = 1;
                    int score1 = fill(copy, 'O', i, j, &lethal);
                    // Check if there is empty space left...
                    for(int i2 = 0; i2 < 16; i2++)
                        for(int j2 = 0; j2 < 32; j2++)
                            if(copy[i2][j2] != 'O' && copy[i2][j2] != '@') {
                                // ...and if so, the entire board is not filled yet!
                                // Fill the new curve.
                                int lethal2 = 1;
                                memcpy(copy, b, sizeof(int) * 16 * 32);
                                int score2 = fill(copy, 'O', i2, j2, &lethal2);
                                lethal = 0;
                                if(score1 < score2) {
                                    // The old curve is preferred.
                                    fill(b, 'O', i, j, &lethal);
                                } else {
                                    // The new curve is preferred.
                                    fill(b, 'O', i2, j2, &lethal);
                                }
                                if(lethal)
                                    { displayBoard(b, ticks, p1X, p1Y, p2X, p2Y); return 1; }
                                goto p2_end;
                            }
                }
        p2_end:;
    }
    // If the game has not finished yet, it's time to count the scores.
    // Players ('*', '@') don't count, since there is exactly one per bot.
    int score1 = 0, score2 = 0;
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 32; j++)
            if(b[i][j] == 'X')
                score1++;
            else if(b[i][j] == 'O')
                score2++;
    displayBoard(b, ticks, p1X, p1Y, p2X, p2Y);
    if(score1 > score2)
        return -1;
    else if(score1 < score2)
        return 1;
    else
        return 0;
}

void sig_handler(int signo) {
    if(turn == 0) {
        printf("Internal error in host code.\n");
        exit(2);
    } else if(turn == 'X') {
        printf("Signal %d caught while bot X was processing its turn. X loses.", signo);
        exit(1);
    } else if(turn == 'O') {
        printf("Signal %d caught while bot O was processing its turn. O loses.", signo);
        exit(-1);
    }
}

int main(void) {
    signal(SIGFPE, sig_handler); signal(SIGBUS, sig_handler);
    signal(SIGILL, sig_handler); signal(SIGSEGV, sig_handler);

    int n = play();
    printf("Final score: %d\n", n);
    return n;
}

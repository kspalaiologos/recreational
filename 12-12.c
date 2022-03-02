#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,
    YYerror = 256,
    YYUNDEF = 257,
    T_INT = 258,
    T_PLUS = 259,
    T_MINUS = 260,
    T_MULTIPLY = 261,
    T_DIVIDE = 262,
    T_EOL = 263
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

union YYSTYPE
{int32_t ival;};
typedef union YYSTYPE YYSTYPE;


extern YYSTYPE yylval;


int yyparse (void);





typedef int8_t flex_int8_t;typedef uint8_t flex_uint8_t;typedef int16_t flex_int16_t;typedef uint16_t flex_uint16_t;typedef int32_t flex_int32_t;typedef uint32_t flex_uint32_t;

typedef struct yy_buffer_state*YY_BUFFER_STATE;typedef size_t yy_size_t;extern int yyleng;extern FILE*yyin,*yyout;

struct yy_buffer_state{FILE*yy_input_file;char*yy_ch_buf;char*yy_buf_pos;int yy_buf_size;int yy_n_chars;int yy_is_our_buffer;int yy_is_interactive;int yy_at_bol;int yy_bs_lineno;int yy_bs_column;int yy_fill_buffer;int yy_buffer_status;

};static size_t yy_buffer_stack_top=0;static size_t yy_buffer_stack_max=0;static YY_BUFFER_STATE*yy_buffer_stack=NULL;

static char yy_hold_char;static int yy_n_chars;int yyleng;static char*yy_c_buf_p=NULL;static int yy_init=0;static int yy_start=0;static int yy_did_buffer_switch_on_eof;void yyrestart(FILE*input_file);void yy_switch_to_buffer(YY_BUFFER_STATE new_buffer);YY_BUFFER_STATE yy_create_buffer(FILE*file,int size);void yy_flush_buffer(YY_BUFFER_STATE b);static void yyensure_buffer_stack(void);static void yy_load_buffer_state(void);static void yy_init_buffer(YY_BUFFER_STATE b,FILE*file);void*yyalloc(yy_size_t);void*yyrealloc(void*,yy_size_t);void yyfree(void*);

typedef flex_uint8_t YY_CHAR;FILE*yyin=NULL,*yyout=NULL;typedef const struct yy_trans_info*yy_state_type;extern int yylineno;int yylineno=1;extern char*yytext;static yy_state_type yy_get_previous_state(void);static int yy_get_next_buffer(void);static void __attribute__((__noreturn__))yy_fatal_error(const char*msg);

struct yy_trans_info{flex_int16_t yy_verify;flex_int16_t yy_nxt;};static const struct yy_trans_info yy_transition[532]={{0,0},{0,404},{0,0},{0,402},{1,260},{2,260},{3,260},{4,260},{5,260},{6,260},{7,260},{8,260},{9,260},{10,262},{11,260},{12,260},{13,260},{14,260},{15,260},{16,260},{17,260},{18,260},{19,260},{20,260},{21,260},{22,260},{23,260},{24,260},{25,260},{26,260},{27,260},{28,260},{29,260},{30,260},{31,260},{32,260},{33,260},{34,260},{35,260},{36,260},{37,260},{38,260},{39,260},{40,260},{41,260},{42,264},{43,266},{44,260},{45,268},{46,260},{47,270},{48,272},{49,272},{50,272},{51,272},{52,272},{53,272},{54,272},{55,272},{56,272},{57,272},{58,260},{59,260},{60,260},{61,260},{62,260},{63,260},{64,260},{65,260},{66,260},{67,260},{68,260},{69,260},{70,260},{71,260},{72,260},{73,260},{74,260},{75,260},{76,260},{77,260},{78,260},{79,260},{80,260},{81,260},{82,260},{83,260},{84,260},{85,260},{86,260},{87,260},{88,260},{89,260},{90,260},{91,260},{92,260},{93,260},{94,260},{95,260},{96,260},{97,260},{98,260},{99,260},{100,260},{101,260},{102,260},{103,260},{104,260},{105,260},{106,260},{107,260},{108,260},{109,260},{110,260},{111,260},{112,260},{113,260},{114,260},{115,260},{116,260},{117,260},{118,260},{119,260},{120,260},{121,260},{122,260},{123,260},{124,260},{125,260},{126,260},{127,260},{128,260},{0,0},{0,272},{1,130},{2,130},{3,130},{4,130},{5,130},{6,130},{7,130},{8,130},{9,130},{10,132},{11,130},{12,130},{13,130},{14,130},{15,130},{16,130},{17,130},{18,130},{19,130},{20,130},{21,130},{22,130},{23,130},{24,130},{25,130},{26,130},{27,130},{28,130},{29,130},{30,130},{31,130},{32,130},{33,130},{34,130},{35,130},{36,130},{37,130},{38,130},{39,130},{40,130},{41,130},{42,134},{43,136},{44,130},{45,138},{46,130},{47,140},{48,142},{49,142},{50,142},{51,142},{52,142},{53,142},{54,142},{55,142},{56,142},{57,142},{58,130},{59,130},{60,130},{61,130},{62,130},{63,130},{64,130},{65,130},{66,130},{67,130},{68,130},{69,130},{70,130},{71,130},{72,130},{73,130},{74,130},{75,130},{76,130},{77,130},{78,130},{79,130},{80,130},{81,130},{82,130},{83,130},{84,130},{85,130},{86,130},{87,130},{88,130},{89,130},{90,130},{91,130},{92,130},{93,130},{94,130},{95,130},{96,130},{97,130},{98,130},{99,130},{100,130},{101,130},{102,130},{103,130},{104,130},{105,130},{106,130},{107,130},{108,130},{109,130},{110,130},{111,130},{112,130},{113,130},{114,130},{115,130},{116,130},{117,130},{118,130},{119,130},{120,130},{121,130},{122,130},{123,130},{124,130},{125,130},{126,130},{127,130},{128,130},{0,7},{0,142},{0,6},{0,140},{0,4},{0,138},{0,2},{0,136},{0,3},{0,134},{0,5},{0,132},{0,1},{0,130},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{129,8},{1,0},};static const struct yy_trans_info*yy_start_state_list[3]={&yy_transition[1],&yy_transition[3],&yy_transition[133],};extern int yy_flex_debug;int yy_flex_debug=0;

char*yytext;





static int yy_init_globals(void);int yylex_destroy(void);int yyget_debug(void);void yyset_debug(int debug_flag);void*yyget_extra(void);void yyset_extra(void*user_defined);FILE*yyget_in(void);void yyset_in(FILE*_in_str);FILE*yyget_out(void);void yyset_out(FILE*_out_str);int yyget_leng(void);char*yyget_text(void);int yyget_lineno(void);void yyset_lineno(int _line_number);

static int input(void);

int yylex(){yy_state_type yy_current_state;char*yy_cp,*yy_bp;int yy_act;if(!(yy_init)){(yy_init)=1;if(!(yy_start))(yy_start)=1;if(!yyin)yyin=stdin;if(!yyout)yyout=stdout;if(!((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){yyensure_buffer_stack();(yy_buffer_stack)[(yy_buffer_stack_top)]=yy_create_buffer(yyin,16384);}yy_load_buffer_state();}{


while(1){yy_cp=(yy_c_buf_p);*yy_cp=(yy_hold_char);yy_bp=yy_cp;yy_current_state=yy_start_state_list[(yy_start)];yy_match:{const struct yy_trans_info*yy_trans_info;YY_CHAR yy_c;for(yy_c=((YY_CHAR)(*yy_cp));(yy_trans_info=&yy_current_state[yy_c])->yy_verify==yy_c;yy_c=((YY_CHAR)(*++yy_cp)))yy_current_state+=yy_trans_info->yy_nxt;}yy_find_action:yy_act=yy_current_state[-1].yy_nxt;(yytext)=yy_bp;yyleng=(int)(yy_cp-yy_bp);(yy_hold_char)=*yy_cp;*yy_cp='\0';(yy_c_buf_p)=yy_cp;;do_action:switch(yy_act){case 1:

{yylval.ival=atoi(yytext);return T_INT;}break;case 2:

{return T_PLUS;}break;case 3:

{return T_MINUS;}break;case 4:

{return T_MULTIPLY;}break;case 5:

{return T_DIVIDE;}break;case 6:

{return T_EOL;}break;case 7:

yy_fatal_error("flex scanner jammed");break;

case(8+0+1):return 0;case 8:{int yy_amount_of_matched_text=(int)(yy_cp-(yytext))-1;*yy_cp=(yy_hold_char);if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status==0){

(yy_n_chars)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars;(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_input_file=yyin;(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status=1;}

if((yy_c_buf_p)<=&(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)]){__builtin_unreachable();}else switch(yy_get_next_buffer()){case 1:{(yy_did_buffer_switch_on_eof)=0;if((1)){

(yy_c_buf_p)=(yytext)+0;yy_act=(8+(((yy_start)-1)/2)+1);goto do_action;}else{if(!(yy_did_buffer_switch_on_eof))yyrestart(yyin);}break;}case 0:(yy_c_buf_p)=(yytext)+yy_amount_of_matched_text;yy_current_state=yy_get_previous_state();yy_cp=(yy_c_buf_p);yy_bp=(yytext)+0;goto yy_match;case 2:(yy_c_buf_p)=&(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)];yy_current_state=yy_get_previous_state();yy_cp=(yy_c_buf_p);yy_bp=(yytext)+0;goto yy_find_action;}break;}}}}}

static int yy_get_next_buffer(void){char*dest=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf;char*source=(yytext);int number_to_move,i;int ret_val;if((yy_c_buf_p)>&(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)+1])yy_fatal_error("fatal flex scanner internal error--end of buffer missed");if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_fill_buffer==0){if((yy_c_buf_p)-(yytext)-0==1){return 1;}else{return 2;}}number_to_move=(int)((yy_c_buf_p)-(yytext)-1);for(i=0;i<number_to_move;++i)*(dest++)=*(source++);if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status==2)(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=(yy_n_chars)=0;else{int num_to_read=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size-number_to_move-1;while(num_to_read<=0){YY_BUFFER_STATE b=(yy_buffer_stack)[(yy_buffer_stack_top)];int yy_c_buf_p_offset=(int)((yy_c_buf_p)-b->yy_ch_buf);if(b->yy_is_our_buffer){int new_size=b->yy_buf_size*2;if(new_size<=0)b->yy_buf_size+=b->yy_buf_size/8;else b->yy_buf_size*=2;b->yy_ch_buf=(char*)yyrealloc((void*)b->yy_ch_buf,(yy_size_t)(b->yy_buf_size+2));}else b->yy_ch_buf=NULL;if(!b->yy_ch_buf)yy_fatal_error("fatal error-scanner input buffer overflow");(yy_c_buf_p)=&b->yy_ch_buf[yy_c_buf_p_offset];num_to_read=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size-number_to_move-1;}if(num_to_read>8192)num_to_read=8192;errno=0;while(((yy_n_chars)=(int)read(fileno(yyin),(&(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[number_to_move]),(yy_size_t)num_to_read))<0){if(errno!=EINTR){yy_fatal_error("input in flex scanner failed");break;}errno=0;clearerr(yyin);};(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=(yy_n_chars);}if((yy_n_chars)==0){if(number_to_move==0){ret_val=1;yyrestart(yyin);}else{ret_val=2;(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status=2;}}else ret_val=0;if(((yy_n_chars)+number_to_move)>(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size){int new_size=(yy_n_chars)+number_to_move+((yy_n_chars)>>1);(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf=(char*)yyrealloc((void*)(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf,(yy_size_t)new_size);if(!(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf)yy_fatal_error("out of dynamic memory in yy_get_next_buffer()");(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size=(int)(new_size-2);}(yy_n_chars)+=number_to_move;(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)]=0;(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)+1]=0;(yytext)=&(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[0];return ret_val;}static yy_state_type yy_get_previous_state(void){yy_state_type yy_current_state;char*yy_cp;yy_current_state=yy_start_state_list[(yy_start)];for(yy_cp=(yytext)+0;yy_cp<(yy_c_buf_p);++yy_cp){yy_current_state+=yy_current_state[(*yy_cp?((YY_CHAR)(*yy_cp)):128)].yy_nxt;}return yy_current_state;}

static int input(void){int c;*(yy_c_buf_p)=(yy_hold_char);if(*(yy_c_buf_p)==0){if((yy_c_buf_p)<&(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)])*(yy_c_buf_p)='\0';else{int offset=(int)((yy_c_buf_p)-(yytext));++(yy_c_buf_p);switch(yy_get_next_buffer()){case 2:

yyrestart(yyin);case 1:{if((1))return 0;if(!(yy_did_buffer_switch_on_eof))yyrestart(yyin);return input();}case 0:(yy_c_buf_p)=(yytext)+offset;break;}}}c=*(unsigned char*)(yy_c_buf_p);*(yy_c_buf_p)='\0';(yy_hold_char)=*++(yy_c_buf_p);return c;}void yyrestart(FILE*input_file){if(!((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){yyensure_buffer_stack();(yy_buffer_stack)[(yy_buffer_stack_top)]=yy_create_buffer(yyin,16384);}yy_init_buffer(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL),input_file);yy_load_buffer_state();}static void yy_load_buffer_state(void){(yy_n_chars)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars;(yytext)=(yy_c_buf_p)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_pos;yyin=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_input_file;(yy_hold_char)=*(yy_c_buf_p);}YY_BUFFER_STATE yy_create_buffer(FILE*file,int size){YY_BUFFER_STATE b;b=(YY_BUFFER_STATE)yyalloc(sizeof(struct yy_buffer_state));if(!b)yy_fatal_error("out of dynamic memory in yy_create_buffer()");b->yy_buf_size=size;b->yy_ch_buf=(char*)yyalloc((yy_size_t)(b->yy_buf_size+2));if(!b->yy_ch_buf)yy_fatal_error("out of dynamic memory in yy_create_buffer()");b->yy_is_our_buffer=1;yy_init_buffer(b,file);return b;}static void yy_init_buffer(YY_BUFFER_STATE b,FILE*file){int oerrno=errno;yy_flush_buffer(b);b->yy_input_file=file;b->yy_fill_buffer=1;if(b!=((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){b->yy_bs_lineno=1;b->yy_bs_column=0;}b->yy_is_interactive=file?(isatty(fileno(file))>0):0;errno=oerrno;}void yy_flush_buffer(YY_BUFFER_STATE b){if(!b)return;b->yy_n_chars=0;b->yy_ch_buf[0]=0;b->yy_ch_buf[1]=0;b->yy_buf_pos=&b->yy_ch_buf[0];b->yy_at_bol=1;b->yy_buffer_status=0;if(b==((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))yy_load_buffer_state();}static void yyensure_buffer_stack(void){yy_size_t num_to_alloc;if(!(yy_buffer_stack)){num_to_alloc=1;(yy_buffer_stack)=(struct yy_buffer_state**)yyalloc(num_to_alloc*sizeof(struct yy_buffer_state*));if(!(yy_buffer_stack))yy_fatal_error("out of dynamic memory in yyensure_buffer_stack()");memset((yy_buffer_stack),0,num_to_alloc*sizeof(struct yy_buffer_state*));(yy_buffer_stack_max)=num_to_alloc;(yy_buffer_stack_top)=0;return;}if((yy_buffer_stack_top)>=((yy_buffer_stack_max))-1){yy_size_t grow_size=8;num_to_alloc=(yy_buffer_stack_max)+grow_size;(yy_buffer_stack)=(struct yy_buffer_state**)yyrealloc((yy_buffer_stack),num_to_alloc*sizeof(struct yy_buffer_state*));if(!(yy_buffer_stack))yy_fatal_error("out of dynamic memory in yyensure_buffer_stack()");memset((yy_buffer_stack)+(yy_buffer_stack_max),0,grow_size*sizeof(struct yy_buffer_state*));(yy_buffer_stack_max)=num_to_alloc;}}static void __attribute__((__noreturn__))yy_fatal_error(const char*msg){fprintf(stderr,"%s\n",msg);exit(2);}

int yyget_lineno(void){return yylineno;}FILE*yyget_in(void){return yyin;}FILE*yyget_out(void){return yyout;}int yyget_leng(void){return yyleng;}char*yyget_text(void){return yytext;}void yyset_lineno(int _line_number){yylineno=_line_number;}void yyset_in(FILE*_in_str){yyin=_in_str;}void yyset_out(FILE*_out_str){yyout=_out_str;}int yyget_debug(void){return yy_flex_debug;}void yyset_debug(int _bdebug){yy_flex_debug=_bdebug;}static int yy_init_globals(void){(yy_buffer_stack)=NULL;(yy_buffer_stack_top)=0;(yy_buffer_stack_max)=0;(yy_c_buf_p)=NULL;(yy_init)=0;(yy_start)=0;yyin=NULL;yyout=NULL;return 0;}

void*yyalloc(yy_size_t size){return malloc(size);}void*yyrealloc(void*ptr,yy_size_t size){

return realloc(ptr,size);}void yyfree(void*ptr){free((char*)ptr);}


extern int yylex();extern int yyparse();extern FILE*yyin;void yyerror(const char*s);


enum yysymbol_kind_t{YYSYMBOL_YYEMPTY=-2,YYSYMBOL_YYEOF=0,YYSYMBOL_YYerror=1,YYSYMBOL_YYUNDEF=2,YYSYMBOL_T_INT=3,YYSYMBOL_T_PLUS=4,YYSYMBOL_T_MINUS=5,YYSYMBOL_T_MULTIPLY=6,YYSYMBOL_T_DIVIDE=7,YYSYMBOL_T_EOL=8,YYSYMBOL_YYACCEPT=9,YYSYMBOL_line=10,YYSYMBOL_top=11,YYSYMBOL_expression=12};typedef enum yysymbol_kind_t yysymbol_kind_t;

typedef signed char yytype_int8;typedef short int yytype_int16;

typedef unsigned char yytype_uint8;

typedef short unsigned int yytype_uint16;

typedef yytype_int8 yy_state_t;typedef int yy_state_fast_t;

void*malloc(long unsigned int);void free(void*);

union yyalloc{yy_state_t yyss_alloc;YYSTYPE yyvs_alloc;};

static const yytype_int8 yytranslate[]={0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,3,4,5,6,7,8};

static const yytype_int8 yypact[]={8,-5,12,8,-4,-5,-5,8,8,8,8,-5,3,3,-5,-5};static const yytype_int8 yydefact[]={3,6,0,3,5,1,2,0,0,0,0,4,7,8,9,10};static const yytype_int8 yypgoto[]={-5,10,-5,-2};static const yytype_int8 yydefgoto[]={0,2,3,4};static const yytype_int8 yytable[]={7,8,9,10,11,12,13,14,15,9,10,1,5,6};static const yytype_int8 yycheck[]={4,5,6,7,8,7,8,9,10,6,7,3,0,3};static const yytype_int8 yystos[]={0,3,10,11,12,0,10,4,5,6,7,8,12,12,12,12};static const yytype_int8 yyr1[]={0,9,10,10,11,11,12,12,12,12,12};static const yytype_int8 yyr2[]={0,2,2,0,2,1,1,3,3,3,3};enum{YYENOMEM=-2};

static void yydestruct(const char*yymsg,yysymbol_kind_t yykind,YYSTYPE*yyvaluep){((void)(yyvaluep));if(!yymsg)yymsg="Deleting";;









((void)(yykind));



}int yychar;YYSTYPE yylval;int yynerrs;

int yyparse(void){yy_state_fast_t yystate=0;int yyerrstatus=0;long int yystacksize=200;yy_state_t yyssa[200];yy_state_t*yyss=yyssa;yy_state_t*yyssp=yyss;YYSTYPE yyvsa[200];YYSTYPE*yyvs=yyvsa;YYSTYPE*yyvsp=yyvs;int yyn;int yyresult;yysymbol_kind_t yytoken=YYSYMBOL_YYEMPTY;YYSTYPE yyval;int yylen=0;((void)0);yychar=YYEMPTY;goto yysetstate;yynewstate:yyssp++;yysetstate:((void)0);((void)(0&&(0<=yystate&&yystate<16)));*yyssp=((yy_state_t)(yystate));;if(yyss+yystacksize-1<=yyssp){long int yysize=yyssp-yyss+1;

if(10000<=yystacksize);yystacksize*=2;if(10000<yystacksize)yystacksize=10000;{yy_state_t*yyss1=yyss;union yyalloc*yyptr=((union yyalloc*)(malloc(((long unsigned int)(((yystacksize)*(((long int)(sizeof(yy_state_t)))+((long int)(sizeof(YYSTYPE))))+(((long int)(sizeof(union yyalloc)))-1)))))));if(!yyptr);do{long int yynewbytes;__builtin_memcpy(&yyptr->yyss_alloc,yyss,((long unsigned int)((yysize)))*sizeof(*(yyss)));yyss=&yyptr->yyss_alloc;yynewbytes=yystacksize*((long int)(sizeof(*yyss)))+(((long int)(sizeof(union yyalloc)))-1);yyptr+=yynewbytes/((long int)(sizeof(*yyptr)));}while(0);do{long int yynewbytes;__builtin_memcpy(&yyptr->yyvs_alloc,yyvs,((long unsigned int)((yysize)))*sizeof(*(yyvs)));yyvs=&yyptr->yyvs_alloc;yynewbytes=yystacksize*((long int)(sizeof(*yyvs)))+(((long int)(sizeof(union yyalloc)))-1);yyptr+=yynewbytes/((long int)(sizeof(*yyptr)));}while(0);if(yyss1!=yyssa)free(yyss1);}yyssp=yyss+yysize-1;yyvsp=yyvs+yysize-1;((void)0);if(yyss+yystacksize-1<=yyssp)goto yyabortlab;}if(yystate==5)goto yyacceptlab;goto yybackup;yybackup:yyn=yypact[yystate];if(((yyn)==(-5)))goto yydefault;if(yychar==YYEMPTY){((void)0);yychar=yylex();}if(yychar<=YYEOF){yychar=YYEOF;yytoken=YYSYMBOL_YYEOF;((void)0);}else if(yychar==YYerror){yychar=YYUNDEF;yytoken=YYSYMBOL_YYerror;}else{yytoken=(0<=(yychar)&&(yychar)<=263?((yysymbol_kind_t)(yytranslate[yychar])):YYSYMBOL_YYUNDEF);;}yyn+=yytoken;if(yyn<0||13<yyn||yycheck[yyn]!=yytoken)goto yydefault;yyn=yytable[yyn];if(yyn<=0){if(0);yyn=-yyn;goto yyreduce;}if(yyerrstatus)yyerrstatus--;;yystate=yyn;









*++yyvsp=yylval;



yychar=YYEMPTY;goto yynewstate;yydefault:yyn=yydefact[yystate];goto yyreduce;yyreduce:yylen=yyr2[yyn];

yyval=yyvsp[1-yylen];;switch(yyn){case 4:

{printf("%i\n",(yyvsp[-1].ival));}

break;case 5:

{printf("%i\n",(yyvsp[0].ival));}

break;case 6:

{(yyval.ival)=(yyvsp[0].ival);}

break;case 7:

{(yyval.ival)=(yyvsp[-2].ival)+(yyvsp[0].ival);}

break;case 8:

{(yyval.ival)=(yyvsp[-2].ival)-(yyvsp[0].ival);}

break;case 9:

{(yyval.ival)=(yyvsp[-2].ival)*(yyvsp[0].ival);}

break;case 10:

{(yyval.ival)=(yyvsp[-2].ival)/(yyvsp[0].ival);}

break;

default:break;}

;(yyvsp-=(yylen),yyssp-=(yylen));yylen=0;*++yyvsp=yyval;{const int yylhs=yyr1[yyn]-9;const int yyi=yypgoto[yylhs]+*yyssp;yystate=(0<=yyi&&yyi<=13&&yycheck[yyi]==*yyssp?yytable[yyi]:yydefgoto[yylhs]);}goto yynewstate;yyacceptlab:yyresult=0;goto yyreturnlab;yyabortlab:yyresult=1;goto yyreturnlab;yyreturnlab:if(yychar!=YYEMPTY){yytoken=(0<=(yychar)&&(yychar)<=263?((yysymbol_kind_t)(yytranslate[yychar])):YYSYMBOL_YYUNDEF);yydestruct("Cleanup:discarding lookahead",yytoken,&yylval);}(yyvsp-=(yylen),yyssp-=(yylen));;while(yyssp!=yyss){yydestruct("Cleanup:popping",((yysymbol_kind_t)(yystos[+*yyssp])),yyvsp);(yyvsp-=(1),yyssp-=(1));}if(yyss!=yyssa)free(yyss);return yyresult;}

int main(){yyin=stdin;yyparse();return 0;}void yyerror(const char*s){exit(1);}

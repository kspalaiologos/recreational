float round(float x) {
    float v = (int)(x * 1000 + .5); 
    return (float)v / 1000; 
} 

char * find_constants(float f) {
	float x = round(f);
	static char buf[16];
	if(x == 3.142) return "pi";
	if(x == 2.718) return "e";
	sprintf(buf, "%.3g", f);
	return buf;
}

int main(void) {
	float x, y, z;
	long total_len = 0, amount = 0;
	while(scanf("%f %f %f", &x, &y, &z) == 3) {
		#ifdef LESS_CHEATY
			total_len += strlen(find_constants(x))+strlen(find_constants(y))+strlen(find_constants(z))+4;
			// printf("%s*%s*0+%s\n", find_constants(x), find_constants(y), find_constants(z));
		#else
			total_len += strlen(find_constants(z));
			// printf("%s\n", find_constants(z));
		#endif
		amount++;
	}
	printf("Average length: %d / %d: %f\n", total_len, amount, (float)total_len / (float)amount);
}

# include <stdio.h>
# include <string.h>

int main(void) {
	char str[7];
	int room, cond;
	scanf("%d%d%s", &room, &cond, str);
	if(!strcmp(str, "freeze"))
		printf("%d", room>cond?cond:room);
	else if(!strcmp(str, "heat"))
		printf("%d", room<cond?cond:room);
	else if(!strcmp(str, "auto"))
		printf("%d", cond);
	else if(!strcmp(str, "fan"))
		printf("%d", room);
	return 0;
}
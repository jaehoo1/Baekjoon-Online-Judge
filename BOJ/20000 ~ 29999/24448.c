# include <stdio.h>
# include <string.h>

char stack[200000][11];
int size;

void push(char *str) { strcpy(stack[size++], str); }
char* pop(void) { return stack[--size]; }

int main(void) {
	int Q;
	char S[11];
	scanf("%d", &Q);
	while(Q--) {
		scanf("%s", S);
		if(!strcmp(S, "READ"))
			printf("%s\n", pop());
		else
			push(S);
	}
	return 0;
}
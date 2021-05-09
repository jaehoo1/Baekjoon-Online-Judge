# include <stdio.h>

typedef struct {
	char arr[100000];
	int ptr;
}stack;

void init(stack *s) { s->ptr=0; }
void push(stack *s, const char c) { s->arr[s->ptr++]=c; }
void pop(stack *s) { s->ptr--; }
char peek(const stack *s) { return s->arr[s->ptr-1]; }
int isempty(const stack *s) { return !s->ptr; }

int main(void) {
	int N, i, cou=0;
	stack s;
	char str[100001];
	scanf("%d", &N);
	while(N--) {
		init(&s);
		scanf("%s", str);
		for(i=0 ; str[i] ; i++)
			if(isempty(&s))
				push(&s, str[i]);
			else if(peek(&s)==str[i])
				pop(&s);
			else
				push(&s, str[i]);
		if(isempty(&s))
			cou++;
	}
	printf("%d", cou);
	return 0;
}

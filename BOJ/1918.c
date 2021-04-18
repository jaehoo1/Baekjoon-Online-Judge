# include <stdio.h>

typedef struct {
	char arr[100];
	int ptr;
}stack;

void init(stack *s) {
	s->ptr=0;
}
void push(stack *s, const char data) {
	s->arr[s->ptr++]=data;
}
char pop(stack *s) {
	return s->arr[--s->ptr];
}
int isempty(const stack *s) {
	return !s->ptr;
}
char peek(const stack *s) {
	return s->arr[s->ptr-1];
}
int pre(const char op) {
	if(op=='('||op==')')return 0;
	else if(op=='+'||op=='-')return 1;
	else if(op=='*'||op=='/')return 2;
}

int main(void) {
	stack s;
	int i;
	char str[101];
	init(&s);
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]>='A'&&str[i]<='Z')
			printf("%c", str[i]);
		else if(str[i]=='(')
			push(&s, str[i]);
		else if(str[i]==')') {
			while(peek(&s)!='(')
				printf("%c", pop(&s));
			pop(&s);
		}
		else {
			while(!isempty(&s)) {
				if(pre(str[i])<=pre(peek(&s)))
					printf("%c", pop(&s));
				else	break;
			}
			push(&s, str[i]);
		}
	while(!isempty(&s))
		printf("%c", pop(&s));
	return 0;
}

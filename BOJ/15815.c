# include <stdio.h>

typedef struct {
	int arr[100];
	int ptr;
}stack;

void init(stack *s) {
	s->ptr=0;
}
void push(stack *s, const int data) {
	s->arr[s->ptr++]=data;
}
int pop(stack *s) {
	return s->arr[--s->ptr];
}

int main(void) {
	stack s;
	char str[101];
	int i, first, second;
	init(&s);
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]>='0'&&str[i]<='9')
			push(&s, str[i]-'0');
		else {
			second=pop(&s);
			first=pop(&s);
			if(str[i]=='+')
				push(&s, first+second);
			else if(str[i]=='-')
				push(&s, first-second);
			else if(str[i]=='*')
				push(&s, first*second);
			else if(str[i]=='/')
				push(&s, first/second);
		}
	printf("%d", pop(&s));
	return 0;
}

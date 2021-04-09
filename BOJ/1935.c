# include <stdio.h>

typedef struct {
	double arr[100];
	int ptr;
}stack;

void init(stack *s) {
	s->ptr=0;
}
void push(stack *s, const double data) {
	s->arr[s->ptr++]=data;
}
double pop(stack *s) {
	return s->arr[--s->ptr];
}

int main(void) {
	int N, arr[26], i;
	double first, second;
	stack s;
	char str[101];
	init(&s);
	scanf("%d%s", &N, str);
	for(i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(i=0 ; str[i] ; i++)
		if(str[i]>='A'&&str[i]<='Z')
			push(&s, arr[str[i]-'A']);
		else {
			second=pop(&s);
			first=pop(&s);
			if(str[i]=='+')push(&s, first+second);
			else if(str[i]=='-')push(&s, first-second);
			else if(str[i]=='*')push(&s, first*second);
			else if(str[i]=='/')push(&s, first/second);
		}
	printf("%.2lf", pop(&s));
	return 0;
}

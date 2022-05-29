# include <stdio.h>

typedef struct {
	char arr[1000001];
	int ptr;
}stack;

void init(stack *s) {
	s->ptr=0;
}
void push(stack *s, const char data) {
	s->arr[s->ptr++]=data;
}
void pop(stack *s) {
	--s->ptr;
}
int isppap(stack *s) {
	int i;
	if(s->ptr<3)
		return 0;
	if(s->arr[s->ptr-3]=='P'&&s->arr[s->ptr-2]=='P'&&s->arr[s->ptr-1]=='A')
		return 1;
	return 0;
}

int main(void) {
	char str[1000001];
	stack s;
	int i;
	init(&s);
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]=='A')
			push(&s, 'A');
		else if(str[i]=='P')
			if(isppap(&s)) {
				pop(&s);
				pop(&s);
			}
			else
				push(&s, 'P');
	if(s.ptr==1&&s.arr[0]=='P')
		puts("PPAP");
	else
		puts("NP");
	return 0;
}

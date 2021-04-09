# include <stdio.h>
# include <string.h>

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
int isbomb(stack *s, const char *bomb, const int bomblen) {
	int i;
	if(s->ptr<bomblen)
		return 0;
	for(i=0 ; i<bomblen ; i++)
		if(bomb[i]!=s->arr[s->ptr-bomblen+i])
			return 0;
	return 1;
}

int main(void) {
	char str[1000001], bomb[37], trigger;
	stack s;
	int i, j, len, bomblen;
	init(&s);
	scanf("%s%s", str, bomb);
	len=strlen(str);
	bomblen=strlen(bomb);
	trigger=bomb[bomblen-1];
	for(i=0 ; i<len ; i++) {
		push(&s, str[i]);
		if(trigger==str[i])
			if(isbomb(&s, bomb, bomblen))
				for(j=0 ; j<bomblen ; j++)
					pop(&s);
	}
	if(!s.ptr)
		puts("FRULA");
	else {
		s.arr[s.ptr]=0;
		puts(s.arr);
	}
	return 0;
}

# include <stdio.h>

typedef struct { int arr[100000], ptr; }stack;

void init(stack *s) { s->ptr=0; }
void push(stack *s, const int x) { s->arr[s->ptr++]=x; }
int pop(stack *s) { return s->arr[--s->ptr]; }

int main(void) {
	stack s;
	int n, i=1, num, ptr=0, temp;
	char arr[200000];
	init(&s);
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &num);
		while(i<=num) {
			push(&s, i++);
			arr[ptr++]='+';
		}
		temp=pop(&s);
		arr[ptr++]='-';
		if(temp!=num) {
			puts("NO");
			return 0;
		}
	}
	for(i=0 ; i<ptr ; i++)
		printf("%c\n", arr[i]);
	return 0;
}

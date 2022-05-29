# include <stdio.h>

int flag(const char *stack, int K, int ptr) {
	char temp=stack[--ptr];
	K--;
	while(K--)
		if(temp!=stack[--ptr])
			return 0;
	return 1;
}

int main(void) {
	int N, K, i, ptr=0;
	char str[200001], stack[200001];
	scanf("%d%d%s", &N, &K, str);
	for(i=0 ; i<N ; i++) {
		stack[ptr++]=str[i];
		if(ptr>=K)
			if(flag(stack, K, ptr))
				ptr-=K;
	}
	stack[ptr]=0;
	printf("%s", stack);
	return 0;
}

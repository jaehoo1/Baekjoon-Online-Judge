# include <stdio.h>

int main(void) {
	int K, E, A, k, cou;
	scanf("%d", &K);
	for(k=1 ; k<=K ; k++) {
		scanf("%d%d", &E, &A);
		printf("Data Set %d:\n", k);
		cou=0;
		while(A<E) {
			A*=5;
			cou++;
		}
		if(!cou)
			puts("no drought");
		else {
			cou--;
			while(cou--)
				printf("mega ");
			puts("drought");
		}
		puts("");
	}
	return 0;
}

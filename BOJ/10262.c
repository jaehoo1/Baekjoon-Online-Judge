# include <stdio.h>

int main(void) {
	int a1, b1, a2, b2, i, j;
	double G=0, E=0;
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
	for(i=a1 ; i<=b1 ; i++)
		for(j=a2 ; j<=b2 ; j++)
			G+=i+j;
	G/=(b1-a1+1)*(b2-a2+1);
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
	for(i=a1 ; i<=b1 ; i++)
		for(j=a2 ; j<=b2 ; j++)
			E+=i+j;
	E/=(b1-a1+1)*(b2-a2+1);
	if(G>E)
		puts("Gunnar");
	else if(G<E)
		puts("Emma");
	else
		puts("Tie");
	return 0;
}

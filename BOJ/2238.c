# include <stdio.h>

typedef struct {
	char S[11];
	int P;
}data;

int main(void) {
	int U, N, cou[10001]={0, }, vit[10001]={0, }, i, min_cou=100000, min;
	data arr[100000];
	scanf("%d%d", &U, &N);
	for(i=0 ; i<N ; i++) {
		scanf("%s%d", &arr[i].S, &arr[i].P);
		cou[arr[i].P]++;
		vit[arr[i].P]=1;
	}
	for(i=1 ; i<=U ; i++)
		if(vit[i]&&cou[i]<min_cou)
			min_cou=cou[i];
	for(i=1 ; i<=U ; i++)
		if(cou[i]==min_cou) {
			min=i;
			break;
		}
	for(i=0 ; i<N ; i++)
		if(arr[i].P==min) {
			printf("%s %d", arr[i].S, arr[i].P);
			return 0;
		}
	return 0;
}

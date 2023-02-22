# include <stdio.h>

int level[12], sum[4], cou[4], diff_min=4000000;

int max(void) {
	int res=0, i;
	for(i=0 ; i<4 ; i++)
		if(sum[i]>res)
			res=sum[i];
	return res;
}
int min(void) {
	int res=4000000, i;
	for(i=0 ; i<4 ; i++)
		if(sum[i]<res)
			res=sum[i];
	return res;
}
int diff(void) { return max()-min(); }
void recur(int depth) {
	int i;
	if(depth==12) {
		if(diff()<diff_min)
			diff_min=diff();
		return;
	}
	for(i=0 ; i<4 ; i++)
		if(cou[i]<3) {
			cou[i]++;
			sum[i]+=level[depth];
			recur(depth+1);
			cou[i]--;
			sum[i]-=level[depth];
		}
}

int main(void) {
	int i;
	for(i=0 ; i<12 ; i++)
		scanf("%d", &level[i]);
	recur(0);
	printf("%d", diff_min);
	return 0;
}
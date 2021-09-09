# include <stdio.h>

int arr[10000];

void recur(int left, int right) {
	int root=left, start=left, end=right;
	if(left>right)return;
	while(arr[start]>=arr[root])start++;
	while(arr[end]>arr[root])end--;
	recur(start, end);
	recur(end+1, right);
	printf("%d\n", arr[root]);
}

int main(void) {
	int i, ptr=0, left=0, right=0, num;
	while(~scanf("%d", &num))
		arr[ptr++]=num;
	recur(0, ptr-1);
	return 0;
}

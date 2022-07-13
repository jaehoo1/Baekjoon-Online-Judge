# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int main(void) {
	int N, ptr, index[1000000], A[1000000];
	vector<int> v, answer;
	scanf("%d%d", &N, &A[0]);
	v.push_back(A[0]);
	index[0]=0;
	for(int i=1 ; i<N ; i++) {
		scanf("%d", &A[i]);
		if(v.back()<A[i]) {
			index[i]=v.size();
			v.push_back(A[i]);
		}
		else {
			vector<int>::iterator iter=lower_bound(v.begin(), v.end(), A[i]);
			*iter=A[i];
			index[i]=iter-v.begin();
		}
	}
	printf("%d\n", v.size());
	ptr=v.size()-1;
	for(int i=N-1 ; i>=0 ; i--)
		if(ptr==index[i]) {
			answer.push_back(A[i]);
			ptr--;
		}
	reverse(answer.begin(), answer.end());
	for(int i=0 ; i<answer.size() ; i++)
		printf("%d ", answer[i]);
	return 0;
}
# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b) { return a>b; }

int main(void) {
	int N, arr[1000], left, right, max=0;
	vector<int> v;
	scanf("%d", &N);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &arr[i]);
	for(int i=0 ; i<N ; i++) {
		v.clear();
		left=0;
		right=0;
		if(i&&arr[0]>arr[i])
			v.push_back(arr[0]);
		for(int j=1 ; j<i ; j++)
			if(arr[j]<v.back()&&arr[j]>arr[i])
				v.push_back(arr[j]);
			else {
				vector<int>::iterator iter=lower_bound(v.begin(), v.end(), arr[j], cmp);
				*iter=arr[j];
			}
		left=v.size();
		v.clear();
		v.push_back(arr[i]);
		for(int j=i+1 ; j<N ; j++)
			if(arr[j]>v.back())
				v.push_back(arr[j]);
			else {
				vector<int>::iterator iter=lower_bound(v.begin(), v.end(), arr[j]);
				*iter=arr[j];
			}
		right=v.size();
		if(left+right>max)
			max=left+right;
	}
	printf("%d", max);
	return 0;
}
# include <cstdio>
# include <string>

using namespace std;

int arr[1000000];

bool check(string s) {
	bool cnt[10]={false, };
	for(auto i : s) {
		if(cnt[i-'0'])
			return false;
		cnt[i-'0']=true;
	}
	return true;
}

int main(void) {
	int n, num=0;
	for(int i=0 ; i<1000000 ; )
		if(check(to_string(++num)))
			arr[i++]=num;
	while(scanf("%d", &n))
		if(!n)
			break;
		else
			printf("%d\n", arr[n-1]);
	return 0;
}

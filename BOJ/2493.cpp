# include <cstdio>
# include <stack>

using namespace std;

int main(void) {
	int N, num, arr[500001]={0, };
	stack<pair<int, int>> s;
	scanf("%d%d", &N, &num);
	s.push({num, 1});
	for(int i=2 ; i<=N ; i++) {
		scanf("%d", &num);
		while(s.size()&&num>s.top().first)
			s.pop();
		if(s.size())
			arr[i]=s.top().second;
		else
			arr[i]=0;
		s.push({num, i});
	}
	for(int i=1 ; i<=N ; i++)
		printf("%d ", arr[i]);
	return 0;
}

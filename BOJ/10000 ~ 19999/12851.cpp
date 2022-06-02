# include <cstdio>
# include <vector>
# include <queue>

using namespace std;

int main(void) {
	int N, K, sec=-1, cou=0;
	bool visited[200001]={false, };
	queue<int> q;
	scanf("%d%d", &N, &K);
	q.push(N);
	while(!visited[K]) {
		int size=q.size();
		vector<int> v;
		while(size--) {
			int cur=q.front();
			q.pop();
			v.push_back(cur);
			if(cur==K)
				cou++;
			int next=cur-1;
			if(next>=0&&next<=200000&&!visited[next])
				q.push(next);
			next=cur+1;
			if(next>=0&&next<=200000&&!visited[next])
				q.push(next);
			next=cur*2;
			if(next>=0&&next<=200000&&!visited[next])
				q.push(next);
		}
		sec++;
		for(int i=0 ; i<v.size() ; i++)
			visited[v[i]]=true;
	}
	printf("%d\n%d", sec, cou);
	return 0;
}
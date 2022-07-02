# include <cstdio>
# include <unordered_set>

using namespace std;

int main(void) {
	int bed;
	char str[1001];
	while(scanf("%d", &bed)) {
		if(!bed)
			return 0;
		int cou=0;
		unordered_set<char> us;
		bool visited[26]={false, };
		scanf("%s", str);
		for(int i=0 ; str[i] ; i++)
			if(visited[str[i]-'A']) {
				if(us.find(str[i])!=us.end())
					us.erase(str[i]);
				else
					cou++;
			} else {
				if(us.size()<bed)
					us.insert(str[i]);
				visited[str[i]-'A']=true;
			}
		if(cou)
			printf("%d customer(s) walked away.\n", cou);
		else
			puts("All customers tanned successfully.");
	}
	return 0;
}
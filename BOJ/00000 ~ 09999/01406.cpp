# include <cstdio>
# include <cstring>
# include <list>

using namespace std;

int main(void) {
	list<char> l;
	char str[100001], cmd, x;
	int M;
	list<char>::iterator cur=l.begin();
	scanf("%s", str);
	for(int i=0 ; str[i] ; i++)
		l.push_back(str[i]);
	scanf("%d", &M);
	getchar();
	while(M--) {
		scanf("%c", &cmd);
		getchar();
		if(cmd=='L'&&cur!=l.begin())
			cur--;
		else if(cmd=='D'&&cur!=l.end())
			cur++;
		else if(cmd=='B'&&cur!=l.begin()) {
			cur--;
			cur=l.erase(cur);
		}
		else if(cmd=='P') {
			scanf("%c", &x);
			getchar();
			l.insert(cur, x);
		}
	}
	for(char c : l)
		printf("%c", c);
	return 0;
}

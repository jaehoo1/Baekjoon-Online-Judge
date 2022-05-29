# include <cstdio>
# include <list>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		list<char> l;
		list<char>::iterator ptr=l.begin();
		char str[1000001];
		scanf("%s", str);
		for(int i=0 ; str[i] ; i++)
			if(str[i]=='<') {
				if(ptr!=l.begin())
					ptr--;
			} else if(str[i]=='>') {
				if(ptr!=l.end())
					ptr++;
			} else if(str[i]=='-') {
				if(ptr!=l.begin()) {
					ptr--;
					ptr=l.erase(ptr);
				}
			} else {
				l.insert(ptr, str[i]);
			}
		for(char c : l)
			printf("%c", c);
		puts("");
	}
	return 0;
}

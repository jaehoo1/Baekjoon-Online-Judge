# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m, n, money;
	string s;
	unordered_map<string, int> um;
	cin>>m>>n;
	while(m--) {
		cin>>s>>money;
		um[s]=money;
	}
	while(n--) {
		money=0;
		while(cin>>s) {
			if(s==".")
				break;
			if(um.find(s)!=um.end())
				money+=um[s];
		}
		cout<<money<<'\n';
	}
	return 0;
}
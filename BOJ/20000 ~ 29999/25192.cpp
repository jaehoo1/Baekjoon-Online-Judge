# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, cnt=0;
	string s;
	unordered_set<string> um;
	cin>>N;
	while(N--) {
		cin>>s;
		if(s=="ENTER")
			um.clear();
		else if(um.find(s)==um.end()) {
			cnt++;
			um.insert(s);
		}
	}
	cout<<cnt;
	return 0;
}

# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	int T, n, L, F, cou;
	string W;
	cin>>T;
	while(T--) {
		cou=0;
		unordered_map<string, int> um;
		cin>>n>>L>>F;
		while(n--) {
			cin>>W;
			um[W.substr(W.length()-F)]++;
		}
		for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
			cou+=iter->second/2;
		cout<<cou<<'\n';
	}
	return 0;
}
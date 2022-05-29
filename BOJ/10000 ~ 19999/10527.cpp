# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, res=0;
	string s;
	unordered_map<string, int> um1, um2;
	cin>>n;
	for(int i=0 ; i<n ; i++) {
		cin>>s;
		um1[s]++;
	}
	for(int i=0 ; i<n ; i++) {
		cin>>s;
		um2[s]++;
	}
	for(unordered_map<string, int>::iterator iter=um1.begin() ; iter!=um1.end() ; iter++)
		res+=min(iter->second, um2[iter->first]);
	cout<<res;
	return 0;
}

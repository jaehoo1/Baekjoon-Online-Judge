# include <iostream>
# include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, C;
	unordered_map<int, int> um;
	cin>>n>>k;
	while(n--) {
		cin>>C;
		um[C]++;
	}
	for(unordered_map<int, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
		if(iter->second%k) {
			cout<<iter->first;
			return 0;
		}
	return 0;
}
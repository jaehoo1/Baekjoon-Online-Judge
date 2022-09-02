# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, cou=0;
	string s;
	unordered_map<string, bool> um;
	cin>>N;
	for(int i=0 ; i<N ; i++) {
		cin>>s;
		um.insert({s, false});
	}
	cin>>M;
	for(int i=0 ; i<M ; i++) {
		cin>>s;
		if(um.find(s)!=um.end()&&!um[s]) {
			um[s]=true;
			cou++;
		}
		if(cou>=(N+1)/2) {
			cout<<i+1;
			break;
		}
	}
	return 0;
}
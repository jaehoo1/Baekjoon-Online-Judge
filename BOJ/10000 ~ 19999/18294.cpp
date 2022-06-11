# include <iostream>
# include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, max=0, sum=0;
	string s;
	unordered_map<string, int> um;
	cin>>N;
	while(N--) {
		cin>>s;
		um[s]++;
	}
	for(unordered_map<string, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++) {
		if(iter->second>max) {
			max=iter->second;
			s=iter->first;
		}
		sum+=iter->second;
	}
	if(max>sum-max)
		cout<<s;
	else
		cout<<"NONE";
	return 0;
}
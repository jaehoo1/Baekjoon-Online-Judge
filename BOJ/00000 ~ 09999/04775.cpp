# include <iostream>
# include <vector>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, T;
	string s;
	unordered_set<string> us;
	cin>>N;
	while(N--) {
		cin>>s;
		us.insert(s);
	}
	cin>>T;
	for(int t=1 ; t<=T ; t++) {
		vector<string> v;
		while(cin>>s) {
			if(s=="-1")
				break;
			if(us.find(s)==us.end())
				v.push_back(s);
		}
		if(v.size()) {
			cout<<"Email "<<t<<" is not spelled correctly."<<'\n';
			for(int i=0 ; i<v.size() ; i++)
				cout<<v[i]<<'\n';
		} else
			cout<<"Email "<<t<<" is spelled correctly."<<'\n';
	}
	cout<<"End of Output";
	return 0;
}
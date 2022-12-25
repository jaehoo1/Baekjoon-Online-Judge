# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int W, N, point;
	string name, code;
	while(cin>>W>>N) {
		if(!W&&!N)
			break;
		unordered_map<string, int> um;
		unordered_set<string> us;
		vector<string> v, confiscated;
		while(N--) {
			cin>>name>>code;
			if(code=="TT")
				point=75;
			else if(code=="TX")
				point=50;
			else if(code=="PR")
				point=80;
			else if(code=="RT")
				point=30;
			else if(code=="AP")
				point=25;
			else if(code=="PX")
				point=60;
			um[name]+=point;
			v.push_back(name);
		}
		for(string s : v)
			if(um[s]>=100&&us.find(s)==us.end()) {
				us.insert(s);
				confiscated.push_back(s);
			}
		cout<<"Week "<<W<<' ';
		if(confiscated.empty())
			cout<<"No phones confiscated"<<'\n';
		else {
			for(int i=0 ; i<confiscated.size()-1 ; i++)
				cout<<confiscated[i]<<',';
			cout<<confiscated.back()<<'\n';
		}
	}
	return 0;
}
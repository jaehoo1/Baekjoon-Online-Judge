# include <iostream>
# include <string>
# include <vector>
# include <unordered_set>
# include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t=1, n;
	string var1, var2, op;
	while(cin>>n) {
		if(!n)
			break;
		unordered_set<string> us;
		us.insert("a");
		while(n--) {
			cin>>var1>>op>>var2;
			if(us.find(var2)==us.end())
				us.erase(var1);
			else
				us.insert(var1);
		}
		cout<<"Program #"<<t++<<'\n';
		vector<string> v(us.begin(), us.end());
		sort(v.begin(), v.end());
		if(v.size())
			for(int i=0 ; i<v.size() ; i++)
				cout<<v[i]<<' ';
		else
			cout<<"none";
		cout<<'\n'<<'\n';
	}
	return 0;
}
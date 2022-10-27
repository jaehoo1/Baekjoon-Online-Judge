# include <iostream>
# include <vector>
# include <string>
# include <sstream>

using namespace std;

vector<string> split(string str, char delim) {
	vector<string> v;
	stringstream ss(str);
	string temp;
	while(getline(ss, temp, delim))
		v.push_back(temp);
	return v;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int page, cou;
	string s;
	while(cin>>page) {
		if(!page)
			break;
		cou=0;
		bool print[1001]={false, };
		cin>>s;
		vector<string> v=split(s, ',');
		for(int i=0 ; i<v.size() ; i++) {
			vector<string> range=split(v[i], '-');
			int low=stoi(range[0]);
			int high=stoi(range[range.size()>1?1:0]);
			for( ; low<=high&&low<=page ; low++)
				print[low]=true;
		}
		for(int i=1 ; i<=1000 ; i++)
			if(print[i])
				cou++;
		cout<<cou<<'\n';
	}
	return 0;
}
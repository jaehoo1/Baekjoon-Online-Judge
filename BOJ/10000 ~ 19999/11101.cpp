# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <unordered_map>

using namespace std;

vector<string> split(string str, char delim) {
	vector<string> v;
	stringstream ss(str);
	string temp;
	while(getline(ss, temp, delim))
		v.push_back(temp);
	return v;
}

using namespace std;

int main(void) {
	int T;
	string s;
	cin>>T;
	while(T--) {
		int min=1000;
		unordered_map<string, int> um;
		cin>>s;
		vector<string> times=split(s, ',');
		for(string s : times) {
			vector<string> time=split(s, ':');
			um[time[0]]=stoi(time[1]);
		}
		cin>>s;
		vector<string> combinations=split(s, '|');
		for(string s : combinations) {
			int max=0;
			vector<string> combination=split(s, '&');
			for(string condition : combination)
				if(um[condition]>max)
					max=um[condition];
			if(max<min)
				min=max;
		}
		cout<<min<<'\n';
	}
	return 0;
}
# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	int c, g1, g2;
	string t1, t2;
	scanf("%d", &c);
	while(c--) {
		unordered_map<string, bool> um;
		for(int i=0 ; i<16 ; i++) {
			cin>>t1>>t2>>g1>>g2;
			if(um.find(t1)==um.end())
				um[t1]=true;
			if(um.find(t2)==um.end())
				um[t2]=true;
			um[g1<g2?t1:t2]=false;
		}
		for(unordered_map<string, bool>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
			if(iter->second)
				cout<<iter->first<<'\n';
	}
	return 0;
}
# include <iostream>
# include <string>
# include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, cou=0;
	string s, arr[1000];
	unordered_map<string, int> um;
	cin>>N;
	for(int i=0 ; i<N ; i++) {
		cin>>s;
		um[s]=i;
	}
	for(int i=0 ; i<N ; i++)
		cin>>arr[i];
	for(int i=0 ; i<N ; i++)
		for(int j=i+1 ; j<N ; j++) {
			if(um[arr[i]]>um[arr[j]]) {
				cou++;
				break;
			}
		}
	cout<<cou;
	return 0;
}

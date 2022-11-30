# include <iostream>
# include <string>
# include <unordered_set>

using namespace std;

int main(void) {
	int N;
	string A, B;
	unordered_set<string> us;
	cin>>N;
	while(N--) {
		cin>>A>>B;
		if(A=="ChongChong"||B=="ChongChong"||us.find(A)!=us.end()||us.find(B)!=us.end()) {
			us.insert(A);
			us.insert(B);
		}
	}
	printf("%d", us.size());
	return 0;
}
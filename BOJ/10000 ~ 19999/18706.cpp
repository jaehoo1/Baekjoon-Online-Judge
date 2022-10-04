# include <iostream>
# include <string>
# include <unordered_map>
# include <tuple>

using namespace std;

int round(int money) {
	int last=money%10;
	if(last==1||last==6)
		money--;
	else if(last==4||last==9)
		money++;
	return money;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, C, P, S, M, L;
	string N, X, Y, Z;
	cin>>T;
	while(T--) {
		unordered_map<string, tuple<int, int, int>> um;
		cin>>C>>P;
		while(C--) {
			cin>>N>>S>>M>>L;
			um[N]=make_tuple(S, M, L);
		}
		int delivery=100/P;
		while(P--) {
			cin>>X>>Y>>Z;
			int fee=delivery;
			if(Y=="small")
				fee+=get<0>(um[Z]);
			else if(Y=="medium")
				fee+=get<1>(um[Z]);
			else if(Y=="large")
				fee+=get<2>(um[Z]);
			cout<<X<<' '<<round(fee)<<'\n';
		}
	}
	return 0;
}
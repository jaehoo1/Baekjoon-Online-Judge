# include <cstdio>
# include <unordered_map>

using namespace std;

int main(void) {
	int N, h, max;
	while(scanf("%d", &N)) {
		if(!N)
			break;
		unordered_map<int, int> um;
		max=0;
		while(N--) {
			scanf("%d", &h);
			um[h]++;
		}
		for(unordered_map<int, int>::iterator iter=um.begin() ; iter!=um.end() ; iter++)
			if(iter->second>max)
				max=iter->second;
		printf("%d\n", max);
	}
	return 0;
}
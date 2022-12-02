# include <cstdio>
# include <unordered_map>

using namespace std;

int main(void) {
	int n, x, y, cou=0;
	unordered_map<int, int> xmap, ymap;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &x, &y);
		xmap[x]++;
		ymap[y]++;
	}
	for(unordered_map<int, int>::iterator iter=xmap.begin() ; iter!=xmap.end() ; iter++)
		if(iter->second>=2)
			cou++;
	for(unordered_map<int, int>::iterator iter=ymap.begin() ; iter!=ymap.end() ; iter++)
		if(iter->second>=2)
			cou++;
	printf("%d", cou);
	return 0;
}
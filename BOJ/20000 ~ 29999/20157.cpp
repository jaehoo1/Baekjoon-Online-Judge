# include <cstdio>
# include <unordered_map>

using namespace std;

int main(void) {
	int N, x, y, max=0;
	unordered_map<double, int> um[8];
	scanf("%d", &N);
	while(N--) {
		scanf("%d%d", &x, &y);
		if(!x&&y>0)
			um[0][0]++;
		else if(!x&&y<0)
			um[1][0]++;
		else if(x>0&&!y)
			um[2][0]++;
		else if(x<0&&!y)
			um[3][0]++;
		else if(x>0&&y>0)
			um[4][(double)y/x]++;
		else if(x<0&&y>0)
			um[5][(double)y/x]++;
		else if(x<0&&y<0)
			um[6][(double)y/x]++;
		else if(x>0&&y<0)
			um[7][(double)y/x]++;
	}
	for(int i=0 ; i<8 ; i++)
		for(unordered_map<double, int>::iterator iter=um[i].begin() ; iter!=um[i].end() ; iter++)
			if(iter->second>max)
				max=iter->second;
	printf("%d", max);
	return 0;
}
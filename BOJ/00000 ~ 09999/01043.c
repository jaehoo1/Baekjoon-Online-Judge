# include <stdio.h>

int parent[51];

int find(int x) {
	if(x==parent[x])return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)parent[b]=a;
	else	parent[a]=b;
}

int main(void) {
	int N, M, truth[51], i, j, party[50][51], truth_attend, cou=0;
	scanf("%d%d%d", &N, &M, &truth[0]);

	//data structure initialization
	for(i=1 ; i<=N ; i++)
		parent[i]=i;

	//진실 아는사람들 입력 & union
	for(i=1 ; i<=truth[0] ; i++) {
		scanf("%d", &truth[i]);
		if(i>1)
			union_set(truth[1], truth[i]);
	}

	//파티 멤버를 입력받고 그 중에 진실 아는 사람이 있다면 진실 집합에, 없다면 자기들끼리 합침
	for(i=0 ; i<M ; i++) {
		truth_attend=0;
		scanf("%d", &party[i][0]);
		for(j=1 ; j<=party[i][0] ; j++) {
			scanf("%d", &party[i][j]);
			if(truth[0])
				if(find(truth[1])==find(party[i][j]))
					truth_attend=1;
		}

		if(truth_attend)
			for(j=1 ; j<=party[i][0] ; j++)
				union_set(truth[1], party[i][j]);
		else
			for(j=1 ; j<=party[i][0] ; j++)
				if(j>1)
					union_set(party[i][j-1], party[i][j]);
	}

	//파티를 돌면서 모든 멤버가 진실멤버가 아닐 때 cou++
	for(i=0 ; i<M ; i++) {
		truth_attend=0;
		if(truth[0])
			for(j=1 ; j<=party[i][0] ; j++)
				if(find(truth[1])==find(party[i][j])) {
					truth_attend=1;
					break;
				}
		if(!truth_attend)
			cou++;
	}
	printf("%d", cou);
	return 0;
}

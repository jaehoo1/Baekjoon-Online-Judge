# include <stdio.h>
# include <string.h>

int n, parent[100];
char namedict[100][21];

int find(int x) {
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}
void union_set(int a, int b) {
	a=find(a);
	b=find(b);
	if(a<b)
		parent[b]=a;
	else
		parent[a]=b;
}
int map(char *name) {
	int i;
	for(i=0 ; i<n ; i++)
		if(!strcmp(name, namedict[i]))
			return i;
}

int main(void) {
	int m, i, cou=0;
	char a[21], b[21];
	scanf("%d", &n);
	for(i=0 ; i<n ; i++) {
		parent[i]=i;
		scanf("%s", namedict[i]);
	}
	scanf("%d", &m);
	while(m--) {
		scanf("%s%s", a, b);
		if(map(a)!=map(b))
			union_set(map(a), map(b));
	}
	for(i=0 ; i<n ; i++)
		if(i==parent[i])
			cou++;
	printf("%d", cou);
	return 0;
}
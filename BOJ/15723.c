# include <stdio.h>

typedef enum {
	false, true
}bool;

int main(void) {
	int n, m, i, j, k;
	char a, b;
	bool G[26][26]={false, };
	scanf("%d", &n);
	getchar();
	while(n--) {
		scanf("%c is %c", &a, &b);
		getchar();
		G[a-'a'][b-'a']=true;
	}
	for(k=0 ; k<26 ; k++)
		for(i=0 ; i<26 ; i++)
			for(j=0 ; j<26 ; j++)
				if(G[i][k]&&G[k][j])
					G[i][j]=true;
	scanf("%d", &m);
	getchar();
	while(m--) {
		scanf("%c is %c", &a, &b);
		getchar();
		puts(G[a-'a'][b-'a']?"T":"F");
	}
	return 0;
}

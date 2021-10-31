# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char arr[15], str[15];
int L, C, visited[26];

int check(void) {
	int vowel=0, conso=0, i;
	for(i=0 ; i<L ; i++)
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			vowel++;
		else
			conso++;
	if(vowel&&conso>=2)
		return 1;
	return 0;
}
void dfs(int depth) {
	int i;
	if(depth==L) {
		if(check()) {
			for(i=0 ; i<L ; i++)
				printf("%c", str[i]);
			puts("");
		}
		return;
	}
	for(i=depth ; i<C ; i++) {
		if(depth)
			if(arr[i]<str[depth-1])
				continue;
		if(!visited[arr[i]-'a']) {
			visited[arr[i]-'a']=1;
			str[depth]=arr[i];
			dfs(depth+1);
			visited[arr[i]-'a']=0;
		}
	}
}

int main(void) {
	int i, j;
	scanf("%d%d", &L, &C);
	getchar();
	for(i=0 ; i<C ; i++) {
		scanf("%c", &arr[i]);
		getchar();
	}
	qsort(arr, C, 1, (int(*)(const void*, const void*))strcmp);
	dfs(0);
	return 0;
}

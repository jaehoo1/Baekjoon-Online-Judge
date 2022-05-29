# include <stdio.h>

typedef struct __tnode {
	struct __tnode *left, *right;
	char data;
}tnode;

tnode createtree(const char d, tnode *left, tnode *right) {
	tnode t;
	t.data=d;
	t.left=left;
	t.right=right;
	return t;
}
void preorder(const tnode *t) {
	if(!t)return;
	printf("%c", t->data);
	preorder(t->left);
	preorder(t->right);
}
void inorder(const tnode *t) {
	if(!t)return;
	inorder(t->left);
	printf("%c", t->data);
	inorder(t->right);
}
void postorder(const tnode *t) {
	if(!t)return;
	postorder(t->left);
	postorder(t->right);
	printf("%c", t->data);
}

int main(void) {
	int N, i, j;
	char cmd[3];
	tnode tree[26], *left, *right;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<3 ; j++) {
			getchar();
			scanf("%c", &cmd[j]);
		}
		if(cmd[1]=='.')left=NULL;
		else	left=&tree[cmd[1]-'A'];
		if(cmd[2]=='.')right=NULL;
		else	right=&tree[cmd[2]-'A'];
		tree[cmd[0]-'A']=createtree(cmd[0], left, right);
	}
	preorder(&tree[0]);puts("");
	inorder(&tree[0]);puts("");
	postorder(&tree[0]);
	return 0;
}

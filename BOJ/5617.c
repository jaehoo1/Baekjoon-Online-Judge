# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int a, b, c;
}tri;

int intcmp(const int *a, const int *b) {
	if(*a<*b)return -1;
	else if(*a>*b)return 1;
	else	return 0;
}
tri input(void) {
	tri temp;
	int arr[3], i;
	for(i=0 ; i<3 ; i++)
		scanf("%d", &arr[i]);
	qsort(arr, 3, 4, (int(*)(const void*, const void*))intcmp);
	temp.a=arr[0];
	temp.b=arr[1];
	temp.c=arr[2];
	return temp;
}
int istri(const tri t) {
	if(t.c>=t.a+t.b)return 0;
	else if(t.c*t.c<t.a*t.a+t.b*t.b)return 1;
	else if(t.c*t.c==t.a*t.a+t.b*t.b)return 2;
	else if(t.c*t.c>t.a*t.a+t.b*t.b)return 3;
}

int main(void) {
	tri triangle;
	int temp, A=0, B=0, C=0;
	while(1) {
		triangle=input();
		temp=istri(triangle);
		if(!temp)break;
		else if(temp==1)A++;
		else if(temp==2)B++;
		else if(temp==3)C++;
	}
	printf("%d %d %d %d", A+B+C, B, A, C);
	return 0;
}

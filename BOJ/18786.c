# include <stdio.h>
# include <math.h>

typedef struct {
	int x, y;
}pos;
typedef struct {
	pos A, B, C;
}tri;

int xaxis(const tri t) {
	if(t.A.y==t.B.y)
		return abs(t.A.x-t.B.x);
	else if(t.B.y==t.C.y)
		return abs(t.B.x-t.C.x);
	else if(t.A.y==t.C.y)
		return abs(t.A.x-t.C.x);
	return 0;
}
int yaxis(const tri t) {
	if(t.A.x==t.B.x)
		return abs(t.A.y-t.B.y);
	else if(t.B.x==t.C.x)
		return abs(t.B.y-t.C.y);
	else if(t.A.x==t.C.x)
		return abs(t.A.y-t.C.y);
	return 0;
}
int S(const tri t) {
	return xaxis(t)*yaxis(t);
}

int main(void) {
	int N, i, j, k, max=0, area;
	pos arr[100];
	tri temp;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &arr[i].x, &arr[i].y);
	for(i=0 ; i<N-2 ; i++)
		for(j=i+1 ; j<N-1 ; j++)
			for(k=j+1 ; k<N ; k++) {
				temp.A=arr[i];
				temp.B=arr[j];
				temp.C=arr[k];
				area=S(temp);
				if(area>max)
					max=area;
			}
	printf("%d", max);
	return 0;
}

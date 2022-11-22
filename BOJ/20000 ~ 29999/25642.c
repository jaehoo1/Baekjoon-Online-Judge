# include <stdio.h>

int main(void) {
	int A, B, turn;
	scanf("%d%d", &A, &B);
	for(turn=0 ; A<=4&&B<=4 ; turn++)
		if(turn%2)
			A+=B;
		else
			B+=A;
	puts(A<=4?"yt":"yj");
	return 0;
}
# include <stdio.h>
# include <string.h>

int i, ptr;
char pw1[11], pw2[11], temp[11];

int capsnum(void) {
	int check=0;
	ptr=0;
	for(i=0 ; pw1[i] ; i++) {
		if(pw1[i]>='A'&&pw1[i]<='Z')
			temp[ptr++]=pw1[i]+32;
		else if(pw1[i]>='a'&&pw1[i]<='z')
			temp[ptr++]=pw1[i]-32;
		if(pw1[i]>='0'&&pw1[i]<='9')
			check=1;
	}
	temp[ptr]=0;
	return !strcmp(pw2, temp)&&check;
}
int caps(void) {
	ptr=0;
	for(i=0 ; pw1[i] ; i++)
		if(pw1[i]>='A'&&pw1[i]<='Z')
			temp[ptr++]=pw1[i]+32;
		else if(pw1[i]>='a'&&pw1[i]<='z')
			temp[ptr++]=pw1[i]-32;
		else
			temp[ptr++]=pw1[i];
	temp[ptr]=0;
	return !strcmp(pw2, temp);
}
int num(void) {
	ptr=0;
	for(i=0 ; pw1[i] ; i++)
		if(pw1[i]>='0'&&pw1[i]<='9')
			continue;
		else
			temp[ptr++]=pw1[i];
	temp[ptr]=0;
	return !strcmp(pw2, temp);
}

int main(void) {
	int t, T;
	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%s%s", pw1, pw2);
		printf("Case %d: ", t);
		if(!strcmp(pw1, pw2))puts("Login successful.");
		else if(capsnum())puts("Wrong password. Please, check your caps lock and num lock keys.");
		else if(caps())puts("Wrong password. Please, check your caps lock key.");
		else if(num())puts("Wrong password. Please, check your num lock key.");
		else	puts("Wrong password.");
	}
	return 0;
}

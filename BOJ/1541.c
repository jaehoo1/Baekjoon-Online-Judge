# include <stdio.h>

int ptr;
char buf[6];

int bufint(void) {
	int temp;
	buf[ptr]=0;
	ptr=0;
	sscanf(buf, "%d", &temp);
	return temp;
}

int main(void) {
	char str[51], op[25];
	int arr[25], arr_ptr=0, op_ptr=1, i, j, sum, temp;
	scanf("%s", str);
	for(i=0 ; str[i] ; i++)
		if(str[i]>='0'&&str[i]<='9')
			buf[ptr++]=str[i];
		else if(str[i]=='+'||str[i]=='-') {
			arr[arr_ptr++]=bufint();
			op[op_ptr++]=str[i];
		}
	arr[arr_ptr++]=bufint();
	sum=arr[0];
	for(i=1 ; i<arr_ptr ; i++)
		if(op[i]=='+')
			sum+=arr[i];
		else if(op[i]=='-') {
			temp=arr[i];
			for(j=i+1 ; j<arr_ptr ; j++) {
				if(op[j]=='-')
					break;
				temp+=arr[j];
			}
			sum+=-temp;
			i=j-1;
		}
	printf("%d", sum);
	return 0;
}

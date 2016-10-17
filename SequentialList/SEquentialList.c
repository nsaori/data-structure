
#include<stdio.h>
#include<stdlib.h>
#define N 5

int insert();
int deleat();
int find(int n);
int printData();
int isEnpty();

int data[N] = {0};
int count=-1;

void main(){
	int choice;
	int n,index;

	while(1){
		//system("cls");
		printf("1.삽입	\n2.삭제	\n3.검색	\n4.출려	\n5.종료	\n");
		printf("숫자를 입력해주세요: ");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice){
		case 1:
			insert();
			break;
		case 2:
			deleat();
			break;
		case 3:
			if(isEnpty())break;
			printf("찾는 숫자를 입력하시오: ");
			fflush(stdin);
			scanf("%d",&n);
			index = find(n);
			if(index == -1){
				printf("찾는 데이터는 없습니다.\n");
			}else{
				printf("%d번지에 있습니다.",index);
			}
			break;
		case 4:
			printData();
			break;
		case 5:
			printf("the end.\n");
			exit(1);
		default:
			printf("숫차1~5를 입력해주세요..\n");
			break;
		}
		printf("\n");
	}
}

int insert(){
	int n,j,k;
	if(count >= N){
		printf("포화상태입니다.\n");
		return 0;
	}
	if(count == -1){
		printf("삽입할 숫자를 입력하시오: ");
		fflush(stdin);
		scanf("%d",&data[++count]);
		//count++; 
		return 1;
	}
	printf("삽입할 숫자를 입력하시오: ");
	fflush(stdin);
	scanf("%d",&n);
	j=0;
	while(data[j] < n) j++; //삽입할 직전을 찾는다.
	for(k=count+1; k >= j; k--) data[k+1] = data[k];   //데이터 한나씩 이동시킨다.
	data[j+1] = n;    //data를 삽입한다. 
	count++;
	//printf("count = %d",count);
	return 1;
	
	/*
	int i=0,j,k,n;
	scanf("%d",&data[0]);

	while(i<N){
		scanf("%d",&n);
		j=0;
		while(data[j] <= n) j++;   //삽입할 위치를 찾는다
		for( k = i+1; k >= j ; k--) data[k+1] = data[k];   //한간씩 이동한다
		data[j] = n;  //삽입한다
		i++;
	}
	*/
}
int deleat(){
	int index,n,i;
	if(isEnpty()) return 0;
	printf("삭제할 숫자를 입력하시오: ");
	fflush(stdin);
	scanf("%d",&n);

	if( (index = find(n)) == -1){
		printf("찾는 데이터는 없습니다.\n");
		return 0;
	}
	for(i=index; i<=count; i++){
		data[i] = data[i+1];   //data를 하나씩 이동한다.
	}

	data[count--] = 0; 
	return 1;
}
int find(int n){
	int i;
	//if(isEnpty()) return 0;
	for(i = 0; i<=count && data[i]<=n ; i++){
		if(data[i] == n){
			return i;
		}
	}
	return -1;
}
int printData(){
	int i;

	if(isEnpty()) return 0;
	for( i = 0; i <= count ; i++){
		printf("%d  ",data[i]);
	}
	printf("\n");
}
int isEnpty(){
	if(count <= -1){
		printf("공백 입니다.\n");
		return 1;
	}
	return 0;
}
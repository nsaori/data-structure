
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
		printf("1.����	\n2.����	\n3.�˻�	\n4.���	\n5.����	\n");
		printf("���ڸ� �Է����ּ���: ");
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
			printf("ã�� ���ڸ� �Է��Ͻÿ�: ");
			fflush(stdin);
			scanf("%d",&n);
			index = find(n);
			if(index == -1){
				printf("ã�� �����ʹ� �����ϴ�.\n");
			}else{
				printf("%d������ �ֽ��ϴ�.",index);
			}
			break;
		case 4:
			printData();
			break;
		case 5:
			printf("the end.\n");
			exit(1);
		default:
			printf("����1~5�� �Է����ּ���..\n");
			break;
		}
		printf("\n");
	}
}

int insert(){
	int n,j,k;
	if(count >= N){
		printf("��ȭ�����Դϴ�.\n");
		return 0;
	}
	if(count == -1){
		printf("������ ���ڸ� �Է��Ͻÿ�: ");
		fflush(stdin);
		scanf("%d",&data[++count]);
		//count++; 
		return 1;
	}
	printf("������ ���ڸ� �Է��Ͻÿ�: ");
	fflush(stdin);
	scanf("%d",&n);
	j=0;
	while(data[j] < n) j++; //������ ������ ã�´�.
	for(k=count+1; k >= j; k--) data[k+1] = data[k];   //������ �ѳ��� �̵���Ų��.
	data[j+1] = n;    //data�� �����Ѵ�. 
	count++;
	//printf("count = %d",count);
	return 1;
	
	/*
	int i=0,j,k,n;
	scanf("%d",&data[0]);

	while(i<N){
		scanf("%d",&n);
		j=0;
		while(data[j] <= n) j++;   //������ ��ġ�� ã�´�
		for( k = i+1; k >= j ; k--) data[k+1] = data[k];   //�Ѱ��� �̵��Ѵ�
		data[j] = n;  //�����Ѵ�
		i++;
	}
	*/
}
int deleat(){
	int index,n,i;
	if(isEnpty()) return 0;
	printf("������ ���ڸ� �Է��Ͻÿ�: ");
	fflush(stdin);
	scanf("%d",&n);

	if( (index = find(n)) == -1){
		printf("ã�� �����ʹ� �����ϴ�.\n");
		return 0;
	}
	for(i=index; i<=count; i++){
		data[i] = data[i+1];   //data�� �ϳ��� �̵��Ѵ�.
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
		printf("���� �Դϴ�.\n");
		return 1;
	}
	return 0;
}
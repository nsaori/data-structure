//StackTest.c
//2013110023 노다 사오리

#include<stdio.h>
#include<stdlib.h>
#define N 100000

 int push();
int pop();
int printData();
char s[N]={' '};
int top = -1;

int main(){
		char choice;
		printf("1. 삽입  \n2. 삭제  \n3출력  \n4. 종료 \n");
		printf("숫차를 선택하시오: \n");
		scanf("%c", &choice);

		while(1){
			switch(choice){
			case '1':
				push();
				break;
			case '2':
				pop();
				break;
			case '3':
				printData();
				break;
			case '4':
				printf("종료합니다.\n");
				system("pause");
				return 0;
			default:
				printf("1~4의 숫차를 입력하세요:");
				break;
			}
		}
}

int push(){
	if(top >= N ){
		printf("error: overflow");
		return 0;
	}
	printf("값을 입력하시오: ");
	while(s[top] != '\n'){    // enter key = \n = 10 (askii code)
		s[++top] = getchar();
	}
	return 1;
}
int pop(){
	if(top <= -1){
		printf("error: 공백 스택입니다.\n");
		return 0;
	}
	return s[top--];
	/*
	while(top <= -1){
		printf("%c",s[top]);
		top -= 1;
	} */
}
int printData(){
	int i;
	if(top <= -1){
			printf("공백 스택입니다.\n");
			return 1;
		}
	for( i = top; i <= -1; i-- ){
		printf("%c",s[i]);
	}
	return 1;
}




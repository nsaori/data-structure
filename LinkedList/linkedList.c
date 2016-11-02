/*프로젝트 1
    다음과 같은 메유를 가진
    연결리스트의 삽입(데이터의 크기 순으로 저장), 삭제 프로그램을 C언어로 작성하시오. 
         메뉴:      1. 삽 입
                    2. 삭 제
                    3. 출 력
                    4. 종 료
    소스프로그램(*.c 프로그램)을 이 e-강의동에 업로드하시오.
	오름차순으로 정렬
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int num;
	struct Node *next;
}node;

node *head = NULL;

int insert();
int del();
void print();

int main(){
	int choice;
	while(1){
		printf("1. 삽 입\n");
		printf("2. 삭 제\n");
		printf("3. 출 력\n");
		printf("4. 종 료\n");
		printf("숫자입력: ");
		scanf("%d",&choice);

		/*if(1>choice || choice > 4){
			printf("1~4를 입력해주세요\n");
			break;
		}*/
		switch(choice){
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			print();
			break;
		case 4:
			return 0;
		default: 
			printf("1~4를 입력해주세요\n");
			break;
		}
		printf("\n");
	}
}
// insert ------------------------------------
int insert(){
	int n;
	node *tmp =NULL;
	node *p=NULL;
	node *q=NULL;
	
	printf("삽입할 데이터? ");
	scanf("%d",&n);
	
	tmp = (node*)malloc(sizeof(node));
	tmp->num = n;
	tmp->next =NULL;

	if(head == NULL){	//0.요소가 없는 경우

		head = tmp;
		//free(tmp);
		return 1;

	}else{

		if(n < head->num){	// 맨앞에 삽입 하는 경우
			tmp->next = head;
			head = tmp;
			return 1;
		}
		if(head->next == NULL){	//1.요소가 하나인 경우
			if(head->num == n){	// 숫자가 중복하는 경우
				printf("이미 존재하는 숫자입니다.\n");
				free(tmp);
				return 0;
			}
			head->next = tmp;
			return 1;
		}
		//2.요소가 2개이상인 경우
		p = head;
		//q->next =p;
		while(n > p->num ){	// 삽입할 위치를 찾는다
			if(p->next == NULL){ // 맨뒤에 삽입 하는 경우
				p->next = tmp;
				return 1;
			}
			if(q==NULL){
				q = head;
			}else{
				q = q->next;
			}
			p = p->next;
		}
		if(p->num == n){		// 숫자가 중복하는 경우
				printf("이미 존재하는 숫자입니다.\n");
				free(tmp);
				return 0;
		}
		q->next = tmp;
		tmp->next = p;
		//free(tmp);
		return 1;
	}
}

//delete---------------------------------------
int del(){
	int n;
	node *p=NULL;
	node *q=NULL;
	
	if(head == NULL){	//0.요소가 없는 경우
		printf("공백 리스트입니다\n");
		return 0;
	}

	printf("삭제할 데이터? ");
	scanf("%d",&n);

	if(head->next == NULL){	//1. 요소가 하나인 경우
		if(head->num == n){
			head = NULL;
			return 1;
		}
		printf("존재하지 않는 숫자입니다.\n");
		return 0;
	}

	p = head;
	//q->next =p;
	
	while( p->num <= n){	//2. 요소가 2개이상인 경우
		if(head->num == n){	//맨앞 요소를 삭제하는 경우
			head = head->next;
			return 1;
		}

		if(p==head){
			q = head;
		}else{
			q = q->next;
		}
		p = p->next;

		if(p->num == n){	//delete
			q->next = p->next;
			return 1;
		}	
	}
	printf("존재하지 않는 숫자입니다.\n");
	return 0;
}
//print out --------------------------------------------
void print(){
	node *p=NULL;
	p = head;

	if(head == NULL)	//0.요소가 없을 때 ----------
	{
		printf("공백 리스트입니다\n");

	}else if(head->next == NULL) //1.요소가 하나일 때-----
	{
		printf("%d\n",head->num);

	}else //2.요소가 2개이상일 때---------
	{ 
		while(p->next != NULL){
			printf("%d\t",p->num);
			p=p->next;
		}
		printf("%d\t",p->num);
	}
}


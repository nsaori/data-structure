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
	p = head;
	//q->next =head;
	
	printf("삽입할 데이터? ");
	scanf("%d",&n);
	
	tmp = (node*)malloc(sizeof(node));
	tmp->num = n;
	tmp->next =NULL;

	if(head == NULL){
		head = tmp;
		//free(tmp);
		return 1;
	}
	else if(head->num < n){
		if(head->num == n){
			printf("이미 존재하는 숫자입니다.\n");
			free(tmp);
			return 0;
		}
		else {
			head->next = tmp;
			//free(tmp);
			return 1;
		}
	}
	else{
		while(p->num < n && p->next != NULL){
		p = p->next;
		q = q->next;
		}
		if(p->num == n){
				printf("이미 존재하는 숫자입니다.\n");
				free(tmp);
				return 0;
		}else{
			q->next = tmp;
			tmp->next = q;
			//free(tmp);
			return 1;
		}
	}
}
//delete---------------------------------------
int del(){
	int n;
	node *p=NULL;
	node *q=NULL;
	
	if(head == NULL){
		printf("공백 리스트입니다\n");
		return 0;
	}

	printf("삭제할 데이터? ");
	scanf("%d",&n);

	p = head;
	q->next =head;
	
	while(p->next !=NULL && p->num <= n){
		if(p->num == n){
			q->next = p->next;
			return 1;
		}
		p=p->next;
		q=q->next;
	}
	printf("존재하지 않는 숫자입니다.\n");
	return 0;
}
//print out --------------------------------------------
void print(){
	node *p=NULL;
	p = head;

	if(head == NULL){
		printf("공백 리스트입니다\n");
	}else{
		while(p->next != NULL){
			printf("%d\n",p->num);
			p=p->next;
		}
	}
}


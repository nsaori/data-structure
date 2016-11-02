/*������Ʈ 1
    ������ ���� ������ ����
    ���Ḯ��Ʈ�� ����(�������� ũ�� ������ ����), ���� ���α׷��� C���� �ۼ��Ͻÿ�. 
         �޴�:      1. �� ��
                    2. �� ��
                    3. �� ��
                    4. �� ��
    �ҽ����α׷�(*.c ���α׷�)�� �� e-���ǵ��� ���ε��Ͻÿ�.
	������������ ����
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
		printf("1. �� ��\n");
		printf("2. �� ��\n");
		printf("3. �� ��\n");
		printf("4. �� ��\n");
		printf("�����Է�: ");
		scanf("%d",&choice);

		/*if(1>choice || choice > 4){
			printf("1~4�� �Է����ּ���\n");
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
			printf("1~4�� �Է����ּ���\n");
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
	
	printf("������ ������? ");
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
			printf("�̹� �����ϴ� �����Դϴ�.\n");
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
				printf("�̹� �����ϴ� �����Դϴ�.\n");
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
		printf("���� ����Ʈ�Դϴ�\n");
		return 0;
	}

	printf("������ ������? ");
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
	printf("�������� �ʴ� �����Դϴ�.\n");
	return 0;
}
//print out --------------------------------------------
void print(){
	node *p=NULL;
	p = head;

	if(head == NULL){
		printf("���� ����Ʈ�Դϴ�\n");
	}else{
		while(p->next != NULL){
			printf("%d\n",p->num);
			p=p->next;
		}
	}
}


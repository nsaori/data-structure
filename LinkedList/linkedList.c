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
	
	printf("������ ������? ");
	scanf("%d",&n);
	
	tmp = (node*)malloc(sizeof(node));
	tmp->num = n;
	tmp->next =NULL;

	if(head == NULL){	//0.��Ұ� ���� ���

		head = tmp;
		//free(tmp);
		return 1;

	}else{

		if(n < head->num){	// �Ǿտ� ���� �ϴ� ���
			tmp->next = head;
			head = tmp;
			return 1;
		}
		if(head->next == NULL){	//1.��Ұ� �ϳ��� ���
			if(head->num == n){	// ���ڰ� �ߺ��ϴ� ���
				printf("�̹� �����ϴ� �����Դϴ�.\n");
				free(tmp);
				return 0;
			}
			head->next = tmp;
			return 1;
		}
		//2.��Ұ� 2���̻��� ���
		p = head;
		//q->next =p;
		while(n > p->num ){	// ������ ��ġ�� ã�´�
			if(p->next == NULL){ // �ǵڿ� ���� �ϴ� ���
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
		if(p->num == n){		// ���ڰ� �ߺ��ϴ� ���
				printf("�̹� �����ϴ� �����Դϴ�.\n");
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
	
	if(head == NULL){	//0.��Ұ� ���� ���
		printf("���� ����Ʈ�Դϴ�\n");
		return 0;
	}

	printf("������ ������? ");
	scanf("%d",&n);

	if(head->next == NULL){	//1. ��Ұ� �ϳ��� ���
		if(head->num == n){
			head = NULL;
			return 1;
		}
		printf("�������� �ʴ� �����Դϴ�.\n");
		return 0;
	}

	p = head;
	//q->next =p;
	
	while( p->num <= n){	//2. ��Ұ� 2���̻��� ���
		if(head->num == n){	//�Ǿ� ��Ҹ� �����ϴ� ���
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
	printf("�������� �ʴ� �����Դϴ�.\n");
	return 0;
}
//print out --------------------------------------------
void print(){
	node *p=NULL;
	p = head;

	if(head == NULL)	//0.��Ұ� ���� �� ----------
	{
		printf("���� ����Ʈ�Դϴ�\n");

	}else if(head->next == NULL) //1.��Ұ� �ϳ��� ��-----
	{
		printf("%d\n",head->num);

	}else //2.��Ұ� 2���̻��� ��---------
	{ 
		while(p->next != NULL){
			printf("%d\t",p->num);
			p=p->next;
		}
		printf("%d\t",p->num);
	}
}


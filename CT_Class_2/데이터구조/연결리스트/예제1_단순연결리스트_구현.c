#include <stdio.h>
#include <stdlib.h>

typedef int DataType; // ����� ������ Ÿ���� �����ϸ� ���߿� �ϳ��ϳ� �ٲ����. 

typedef struct Node { // ��ü ���� ����ü
	DataType data;
	struct Node* link; //Q �׳� Node* link; �� �����ϸ� �ȵ�? 
} Node;

Node* create_node(DataType data){ //��� ���� �Լ�
	Node* new1 = (Node*)malloc(sizeof(Node));
	if(!new1){
		printf("��� ������ �����Ͽ����ϴ�.");
		exit(1);
	}
	new1->data = data;
	new1->link = NULL;
	return new1;
}

int count_nodes(Node* head){ //��� ���� ��� �Լ� 
	int count = 0;
	Node* ptr = head;
	
	while(ptr){
		count++;
		ptr = ptr->link;
	}
	
	return count;
} 

Node* search_node(Node* from, DataType data) {//��� Ž�� �� �� 
//Q �� from���� ���? head���� ���ʴ�� Ž���ؾ� �ϴ� �� �ƴѰ�? 
	Node* ptr = from;
	while(ptr){
		if(ptr->data == data){
			break;
		}
		ptr = ptr->link;
	}
	
	return ptr;
}

void insert_node(Node** p2head, Node* before, Node* new1){
	if(*p2head == NULL){
		new1->link = NULL;
		*p2head = new1;
	}
	
	else if(before == NULL){
		new1->link = *p2head;
		*p2head = new1;
	}
	
	else{
		new1->link = before->link;
		before->link = new1;
	}
} 

Node* delete_node(Node** p2head, Node* before, Node* deleted){
	if(*p2head != NULL){
		if(before == NULL){
			*p2head = (*p2head)->link;
		}//Q�ּҸ� ��ũ�� �Ѱܼ� ��������? 
		//Q �Ҵ���� ��� ���� ó����? 
		else{
			before->link = deleted->link;
		}
		return deleted;
	}
	else{
		printf("�� ���Ḯ��Ʈ �Դϴ�.");
		return NULL; 
	}
}

Node* concatenate_lists(Node* head1, Node* head2){
	Node* last;
	
	if(head1 == NULL){
		return head2;
	}
	else if(head2 == NULL){
		last = head1;
		while(last->link){
			last = last->link;
		}
		last->link = head2;
		return head1;
	}
}

Node* reverse_list(Node* head){
	Node* new_head = NULL;
	Node* tmp_head;
	
	while(head){
		tmp_head = new_head;
		new_head = head;
		head = head->link;
		new_head->link = tmp_head;
	}
	
	return new_head;
}

int main () {
	Node* head;
	Node* temp;
	
	head = (Node*)malloc(sizeof(Node));
	if(!head){
		exit(1);
	}
	head->data = 10;
	head->link = NULL;
	
	temp = (Node*)malloc(sizeof(Node));
	if(!temp){
		exit(1);
	}
	temp->data = 20;
	temp->link = NULL;
	head->link = temp;
	
	printf("head-->%d-->%d\n", head->data, head->link->data);
	
	free(temp);
	temp = NULL;
	free(head);
	head = NULL;
}

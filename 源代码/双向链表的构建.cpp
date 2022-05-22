#include<iostream>
using namespace std;

typedef struct _Node {
	int data;//数据域 
	struct _Node * next, *prev;//两个指针域，一个指向后继结点，一个指向前驱结点 
} Node;
struct List {
	Node* head;//存放链表的头指针 
} list;
Node* createNode() {//创建双向链表的头指针 
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->prev = NULL;
	return head;
}
void insertNode(int data) {
	Node* x = createNode();
	if (list.head->next == NULL) {
		x->data = data;
		x->next = list.head->next;
		x->prev = list.head;
		list.head->next = x;
	} else {
		x->data = data;
		x->next = list.head->next;
		list.head->next->prev = x;
		x->prev = list.head;
		list.head->next = x;
	}

}
void deteleNode(int data) {
	Node* x = list.head->next;
	while (x) {
		if(x->data==data){
			if(x->next==NULL){
				x->prev->next=NULL;
				free(x);
				return;
			}
			else{
				x->prev->next=x->next;
				x->next->prev=x->prev;
				free(x);
				return;
			}
		}
		x = x->next;
	}
	cout<<"error"<<endl;
}
int main() {
	list.head = createNode();
	insertNode(5);
	insertNode(2);
	insertNode(3);
	insertNode(1);
	deteleNode(3);
	insertNode(6);
	deteleNode(5);
	Node* x = list.head->next;
	while (x) {
		cout << x->data << ' ';
		x = x->next;
	}


	return 0;
}

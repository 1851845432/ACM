#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int s[1000], top;
bool isEmpty() {
	return top == 0;
}
bool isFull() {
	return top >= 1000;
}

void push(int x) {
	if (isFull()) {
		cout << "´íÎó" << endl;
		return ;
	}
	s[++top] = x;
}
int pop() {
	if (isEmpty()) {
		cout << "´íÎó" << endl;
		return 0;
	}
	return s[top--];
}

int main() {
	int a, b;
	char x[10];
	while (1) {
		scanf("%s", x);
		if(x[0]=='0'){
			break;
		}
		if (x[0] == '+') {
			a = pop();
			b = pop();
			push(a + b);
		} else if (x[0] == '-') {
			b = pop();
			a = pop();
			push(a - b);
		} else if (x[0] == '*') {
			a = pop();
			b = pop();
			push(a * b);
		}
		else{
			push(atoi(x));
		}
	}
	cout<<pop()<<endl;

	return 0;
}

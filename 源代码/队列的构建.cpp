#include<iostream>
#include<string.h>
#define MAX 10000
using namespace std;
int head, tail;
struct plan {
	string name;
	int time;
} q[MAX];

bool isFull() {
	//return (tail-head)>=100;
	return head == (tail + 1) % MAX;
}
bool isEmpty() {
	return head == tail;
}
void enqueue(plan x) {
	if (isFull()) {
		cout << "错误" << endl;
		return ;
	}
	q[tail] = x;
//	if (tail + 1 == MAX) {
//		tail = 0;
//	} else
//		tail++;
	tail = (tail + 1) % MAX;

}
struct plan dequeue() {
	if (isEmpty()) {
		cout << "错误" << endl;
		exit(0);
	}
	struct plan x = q[head];
//	if (head + 1 == MAX) {//使数组形成循环有效利用内存
//		head = 0;
//	} else {
//		head++;
//	}
	head = (head + 1) % MAX;
	return x;
}


int main() {
	int n, p;
	cin >> n >> p;
	struct plan x;
	for (int i = 0; i < n; i++) {
		cin >> x.name >> x.time;
		enqueue(x);
	}
	int time = 0;
	while (!isEmpty()) {
		x = dequeue();
		if (p >= x.time) {
			time += x.time;
			cout << x.name << ' ' << time << endl;
		} else {
			time += p;
			x.time -= p;
			enqueue(x);
		}
	}
	return 0;
}

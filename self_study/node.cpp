#include<iostream>
using namespace std;
template<typename T> class List;
template<typename T> class node {
	T info;
	node<T> *link;
public:
	node();
	node(const T&data);
	void InsertAfter(node<T> *p);
	node<T> *RemoveAfter();
	friend class List<T>;
};
template<typename T> node<T>::node() { link = NULL; }
template<typename T> node<T>::node(const T&data) {
	info = data;
	link = NULL;
}
template<typename T> void node<T>::InsertAfter(node<T> *p) {
	p->link = link;
	link = p;
}
template<typename T> node<T>* node<T>::RemoveAfter() {
	node<T> *tempP = link;
	if (link == NULL) tempP = NULL;
	else link = tempP->link;
	return tempP;
}
template<typename T>class List {
	node<T> *head, *tail;
public:
	List();
	List(const List& L1);
	~List();
	void MakeEmpty();
	node<T> *Find(T data);
	int Length();
	List<T> operator=(const List&L1);
	List<T> reverse();
	void PrintList();
	void InsertFront(node<T> *p);
	void InsertRear(node<T> *p);
	void InsertOrder(node<T> *p);
	node<T> *CreateNode(T data);
	node<T> *DeleteNode(node<T> *p);
	List<T> operator+(const List&L1);
};
template<typename T> List<T>::List() {
	head = tail = new node<T>();
}
template<typename T> List<T>::List(const List& L1) {
	node<T> *tempP, *tempQ;
	tempQ =L1.head->link;
	while (tempQ != NULL) {
		tempP = CreateNode(tempQ->info);
		InsertRear(tempP);
		tempQ = tempQ->link;
	}
}
template<typename T> List<T> List<T>::operator=(const List&L1) {
	node<T> *tempP, *tempQ;
	tempP = head->link; tempQ = L1.head->link;
	while (tempP != NULL && tempQ != NULL) {
		tail= tempP;
		tempP->info = tempQ->info;
		tempP = tempP -> link;
		tempQ = tempQ->link;
	}
	if (tempP == NULL && tempQ != NULL) {
		while(tempQ!=NULL){
			tempP = CreateNode(tempQ->info);
			InsertRear(tempP);
			tempQ = tempQ->link;
		}
		tempP->link = NULL;
	}
	else if (tempP != NULL && tempQ == NULL) {
		tempQ = tempP->link;
		while (tempQ != NULL) {
			tempP->link = tempQ->link;
			delete tempQ;
			tempQ = tempP->link;
		}
		delete tempP;
		tempP = NULL;
	}
	return *this;
}
template<typename T> List<T> List<T>::reverse() {
	node<T> *tempP, *tempQ, *tempK, *temp;
	tempP = head; tempQ = head->link; tempK = head; temp = head;
	while (tempQ != NULL) {
		tempP = tempQ;
		tempQ = tempQ->link;
		tempP->link = tempK;
		tempK = tempP;
	}
	head->link = NULL;
	head = tail; tail = temp;
}
template<typename T> List<T>::~List() {
	MakeEmpty();
	delete head;
}
template<typename T> void List<T>::MakeEmpty() {
	node<T> *tempP;
	while (head->link != NULL) {
		tempP = head->link;
		head->link = tempP->link;
		delete tempP;
	}
	tail = head;
}
template<typename T> node<T>* List<T>::Find(T data) {
	node<T> *tempP = head->link;
	while (tempP != NULL && tempP->info != data) tempP = tempP->link;
	return tempP;
}
template<typename T> int List<T>::Length() {
	node<T> *tempP = head->link;
	int count = 0;
	while (tempP != NULL) {
		tempP = tempP->link;
		count++;
	}
	return count;
}
template<typename T> void List<T>::PrintList() {
	node<T> *tempP = head->link;
	while (tempP != NULL) {
		cout << tempP->info << '\t';
		tempP = tempP->link;
	}
	cout << endl;
}
template<typename T> void List<T>::InsertFront(node<T> *p) {
	p->link = head->link;
	head->link = p;
	if (tail == head) tail = p;
}
template<typename T> void List<T>::InsertRear(node<T> *p) {
	p->link = tail->link;
	tail->link = p;
	tail = p;
}
template<typename T> void List<T>::InsertOrder(node<T> *p) {
	node<T> *tempP = head->link, *tempQ = head;
	while (tempP != NULL) {
		if (p->info < tempP->info)break;
		tempQ = tempP;
		tempP = tempP->link;
	}
	tempQ->InsertAfter(p);
	if (tail == tempQ) tail = tempQ->link;
}
template<typename T> node<T>* List<T>::CreateNode(T data) {
	node<T> *tempP = new node<T>(data);
	return tempP;
}
template<typename T> node<T>* List<T>::DeleteNode(node<T> *p) {
	node<T>* tempP = head;
	while (tempP->link != NULL && tempP->link != p) tempP = tempP->link;
	if (tempP->link == tail) tail = tempP;
	return tempP->RemoveAfter();
}
template<typename T> List<T> List<T>:: operator+(const List&L1){
	node<T> *tempP=head->link,*tempQ=L1.head->link,*p;
	List<T> L2;
	int Flag;
	while(tempP!=NULL){
		Flag=1;
		p=L2.head->link;
		while(p!=NULL){
			if(p->info==tempP->info) Flag=0;
			p=p->link;
		}
		if(Flag) L2.InsertRear(L2.CreateNode(tempP->info));
		tempP=tempP->link;
	}
	while(tempQ!=NULL){
		Flag=1;
		p=L2.head->link;
		while(p!=NULL){
			if(p->info==tempQ->info) Flag=0;
			p=p->link;
		}
		if(Flag) L2.InsertRear(L2.CreateNode(tempQ->info));
		tempQ=tempQ->link;
	}
	return L2;
}
int main()
{
	List<int> L1,L2,L3;
	node<int> *p1,*p2,*p3;
	p1=L1.CreateNode(10);
	L1.InsertRear(p1);
	p2=L1.CreateNode(20);
	L1.InsertRear(p2);
	p3=L1.CreateNode(30);
	L1.InsertRear(p3);
	cout<<"L1: ";
	L1.PrintList();
	p1=L2.CreateNode(20);
	L2.InsertRear(p1);
	p2=L2.CreateNode(40);
	L2.InsertRear(p2);
	p3=L2.CreateNode(50);
	L2.InsertRear(p3);
	cout<<"L2: ";
	L2.PrintList();
	L3=L1+L2;
	cout<<"L3: ";
	L3.PrintList();
	return 0;
}
#include<iostream> 
using namespace std;
struct Node{
	int data;
	Node* next;
};
void Print(Node* p){
	if(p == NULL){
		return;
	}
	cout<<"%d"<<p->data<<endl;
	Print(p->next);
}

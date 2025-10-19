#include<iostream> 
using namespace std;
struct Node{
	int data;
	Node* next;
	
	Node(int x): data(x).next(nullptr); 
};
class LinkedList{
	private:
		Node* head;
	public:
		LinkedList():head(nullptr){}
		~LinkedList(){
			while(head!=nullptr){
				Node* temp=head;
				head=head->next;
				delete temp;
			}
		}
}; 
void Print(Node* p){
	if(p == NULL){
		return;
	}
	cout<<"%d"<<p->data<<endl;
	Print(p->next);
}  
//	Print(p->next);
// cout<<"%d"<<p->data<<endl;
//这样递归会逆向打印 
void deleteAtTail() {
    if (head == nullptr) return;
    
    // 如果只有一个节点
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    
    // 找到倒数第二个节点
    ListNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    
    delete current->next;
    current->next = nullptr;
}
void deleteByValue(int val) {
    if (head == nullptr) return;
    
    // 如果要删除的是头节点
    if (head->val == val) {
        deleteAtHead();
        return;
    }
    
    ListNode* current = head;
    
    // 找到要删除节点的前一个节点
    while (current->next != nullptr && current->next->val != val) {
        current = current->next;
    }
    
    // 如果找到要删除的节点
    if (current->next != nullptr) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}
void insertAthead(int val){
	Node* newnode =new Node(val);
	newnode ->next=head;
	head=newnode;
}
//开始通过递归反转链表
//考虑 向前遍历，然后遍历列表在后退方向
Node* head;
void Reverse(Node* p){
	if(p->next == NULL){
		head=p;
		return;
	}
	Reverse(p->next);
	Node* q=p->next;
	q->next=p;
	p->next=NULL;
}
//此时head是全局变量，但当其为局部变量时，每次应返回修改后的值 

void insertAtTail(int val){
	Node* newnode = new Node(val);
	if(head=nullptr) {
		head=newcode;
		return;
	}
	Node* current=head;
	while(current ->next !=nullptr){
		current=current->next;
	}
	current ->next=newnode;
};

 

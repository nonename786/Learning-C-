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
//�����ݹ�������ӡ 
void deleteAtTail() {
    if (head == nullptr) return;
    
    // ���ֻ��һ���ڵ�
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    
    // �ҵ������ڶ����ڵ�
    ListNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    
    delete current->next;
    current->next = nullptr;
}
void deleteByValue(int val) {
    if (head == nullptr) return;
    
    // ���Ҫɾ������ͷ�ڵ�
    if (head->val == val) {
        deleteAtHead();
        return;
    }
    
    ListNode* current = head;
    
    // �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
    while (current->next != nullptr && current->next->val != val) {
        current = current->next;
    }
    
    // ����ҵ�Ҫɾ���Ľڵ�
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
//��ʼͨ���ݹ鷴ת����
//���� ��ǰ������Ȼ������б��ں��˷���
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
//��ʱhead��ȫ�ֱ�����������Ϊ�ֲ�����ʱ��ÿ��Ӧ�����޸ĺ��ֵ 

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

 

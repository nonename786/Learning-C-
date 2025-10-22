#include<iostream>
using namespace std;
//������ʵ�ֶ��� 
ʹ�� ǰ����������front rearָʾ 
ÿ����ɾʱ�ı�����������
������IsFull() IsEmpty() ���λ�ü���Ƿ����
 ͨ��������������Ϊ-1 
 ���Ҫɾ��Ԫ�� �ͽ�front��ǰ��
 �������ᵼ��front��ߵĵ�Ԫ����Զ�˷�
 �����ʩ�� ʹ�û�������ĸ���  
 ������ʹ�õ�i����������Ӧ����һ��������Ϊ
 (i+1)%(array.length) ��������ת��ȥ��
  ͬ�����������ֻ��εĶ�frontɾ��ʱ��Ҳ��������������ʽ
class ArrayQueue {
private:
    int *arr;       // �洢����Ԫ�ص�����
    int capacity;   // ��������
    int front;      // ��������
    int rear;       // ��β����
    int size;       // ��ǰ���д�С

public:
    // ���캯��
    ArrayQueue(int cap = 10) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    
    // ��������
    ~ArrayQueue() {
        delete[] arr;
    }
    
    // ���
    void enqueue(int value) {
        if (isFull()) {
            cout << "����������" << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // ѭ������
        arr[rear] = value;
        size++;
    }
    
    // ����
    int dequeue() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;  // ѭ������
        size--;
        return value;
    }
    
    // ��ȡ����Ԫ��
    int getFront() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        return arr[front];
    }
    
    // ��ȡ��βԪ��
    int getRear() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        return arr[rear];
    }
    
    // �������Ƿ�Ϊ��
    bool isEmpty() {
        return size == 0;
    }
    
    // �������Ƿ�����
    bool isFull() {
        return size == capacity;
    }
    
    // ��ȡ���д�С
    int getSize() {
        return size;
    }
    
    // ��ӡ����
    void display() {
        if (isEmpty()) {
            cout << "����Ϊ��" << endl;
            return;
        }
        cout << "����Ԫ��: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

// ʹ��ʾ��
int main() {
    ArrayQueue q(5);
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();  // ���: ����Ԫ��: 1 2 3
    
    cout << "����: " << q.dequeue() << endl;  // ���: ����: 1
    q.display();  // ���: ����Ԫ��: 2 3
    
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();  // ���: ����Ԫ��: 2 3 4 5 6
    
    return 0;
}

//����ʵ�ֶ��� 
�������head����Ϊͷ��ɾ��Ԫ�أ�ĩβ��Ϊβ�������ڳ�Ԫ��
�������ͷ��������O��1��������
�����β�������ɾ��ʱΪO(n) 
����Ҫ���� ��ΪO(1) �͵�������������
 �ؼ�������β����Ҫ�������½���ϣ��͵���ֱ������������ 
�� ��ʹ��һ����headһ����ָ�룬ʹ��rearָ��
ָ��ĩβ��ÿ����ɾ��Ҳ�ı�ĩβ��λ��
rear->next=temp;
rear=temp;

Dequeue:  Node* temp=front;
front=front->next;
free(temp);

#include <iostream>
using namespace std;

// ����ڵ�
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* front;  // ����ָ��
    Node* rear;   // ��βָ��
    int count;    // Ԫ�ؼ���

public:
    // ���캯��
    LinkedListQueue() {
        front = rear = nullptr;
        count = 0;
    }
    
    // ��������
    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    // ���
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    
    // ����
    int dequeue() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        count--;
        return value;
    }
    
    // ��ȡ����Ԫ��
    int getFront() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        return front->data;
    }
    
    // ��ȡ��βԪ��
    int getRear() {
        if (isEmpty()) {
            cout << "����Ϊ�գ�" << endl;
            return -1;
        }
        return rear->data;
    }
    
    // �������Ƿ�Ϊ��
    bool isEmpty() {
        return front == nullptr;
    }
    
    // ��ȡ���д�С
    int getSize() {
        return count;
    }
    
    // ��ӡ����
    void display() {
        if (isEmpty()) {
            cout << "����Ϊ��" << endl;
            return;
        }
        cout << "����Ԫ��: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// ʹ��ʾ��
int main() {
    LinkedListQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // ���: ����Ԫ��: 10 20 30
    
    cout << "����Ԫ��: " << q.getFront() << endl;  // ���: 10
    cout << "��βԪ��: " << q.getRear() << endl;   // ���: 30
    
    cout << "����: " << q.dequeue() << endl;       // ���: 10
    q.display();  // ���: ����Ԫ��: 20 30
    
    return 0;
}

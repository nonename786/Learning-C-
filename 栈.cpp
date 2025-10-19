//һ������ȳ��Ķ��� 
//����������push(x) �ƽ�ȥ
//pop() ��ջ���Ƴ�����ڵ�Ԫ��
//Top() �Ƴ�����Ԫ�� 
//IsEmpty() ����Ƿ�գ�����true��false
//ջʵ������һ��������Լ��������򼯺�
 //ʵ�ʽṹ����һ�������һ����ʾջ���߶ȵ�top
 //ÿ��push��pop���Ǹ���Ԫ�ص�ͬʱ���� topλ��
 //���ұ�֤������� 
 //���������1��ʹ�ö�̬���飬���˾ͽ���һ������ģ��ٸ��ƹ�ȥ
 //2��ʹ��vector�������� 
 #include <iostream>
#include <stdexcept>

template<typename T> //����һ��ģ������ 
class ArrayStack {
private:
    T* data;           // �洢ջԪ�ص�����
    int capacity;      // ջ������
    int topIndex;      // ջ������

public:
    // ���캯��
    ArrayStack(int size = 10) : capacity(size), topIndex(-1) {
        data = new T[capacity];
    }
    
    // ��������
    ~ArrayStack() {
        delete[] data;
    }
    
    // �������캯��
    ArrayStack(const ArrayStack& other) : capacity(other.capacity), topIndex(other.topIndex) {
        data = new T[capacity];
        for (int i = 0; i <= topIndex; i++) {
            data[i] = other.data[i];
        }
    }
    
    // ��ֵ�����
    ArrayStack& operator=(const ArrayStack& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            topIndex = other.topIndex;
            data = new T[capacity];
            for (int i = 0; i <= topIndex; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    // ��ջ����
    void push(const T& value) {
        if (topIndex == capacity - 1) {
            // ջ������Ҫ����
            resize(capacity * 2);
        }
        data[++topIndex] = value;
    }
    
    // ��ջ����
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("ջΪ�գ��޷�ִ��pop����");
        }
        topIndex--;
        
        // ���ջԪ�غ��٣���С�����Խ�ʡ�ռ�
        if (topIndex > 0 && topIndex == capacity / 4) {
            resize(capacity / 2);
        }
    }
    
    // ��ȡջ��Ԫ��
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("ջΪ�գ��޷���ȡջ��Ԫ��");
        }
        return data[topIndex];
    }
    
    // ���ջ�Ƿ�Ϊ��
    bool isEmpty() const {
        return topIndex == -1;
    }
    
    // ��ȡջ�Ĵ�С
    int size() const {
        return topIndex + 1;
    }
    
    // ��ȡջ������
    int getCapacity() const {
        return capacity;
    }

private:
    // ���������С
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};

//���������ʵ�� ÿ�μ����ɾ��
//���ñ����������ڶ����ڵ� 
#include <iostream>
#include <stdexcept>

template<typename T>
class LinkedListStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* n = nullptr) : data(value), next(n) {}
    };
    
    Node* topNode;    // ջ���ڵ�
    int stackSize;    // ջ�Ĵ�С

public:
    // ���캯��
    LinkedListStack() : topNode(nullptr), stackSize(0) {}
    
    // ��������
    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // �������캯��
    LinkedListStack(const LinkedListStack& other) : topNode(nullptr), stackSize(0) {
        if (!other.isEmpty()) {
            // ʹ����ʱջ��������ͬ��˳��
            LinkedListStack temp;
            Node* current = other.topNode;
            while (current != nullptr) {
                temp.push(current->data);
                current = current->next;
            }
            
            // ����ʱջ��Ԫ�ص�����ѹ����ջ���ָ�ԭʼ˳��
            while (!temp.isEmpty()) {
                this->push(temp.top());
                temp.pop();
            }
        }
    }
    
    // ��ֵ�����
    LinkedListStack& operator=(const LinkedListStack& other) {
        if (this != &other) {
            // ��յ�ǰջ
            while (!isEmpty()) {
                pop();
            }
            
            // ������һ��ջ
            if (!other.isEmpty()) {
                LinkedListStack temp;
                Node* current = other.topNode;
                while (current != nullptr) {
                    temp.push(current->data);
                    current = current->next;
                }
                
                while (!temp.isEmpty()) {
                    this->push(temp.top());
                    temp.pop();
                }
            }
        }
        return *this;
    }
    
    // ��ջ����
    void push(const T& value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        stackSize++;
    }
    
    // ��ջ����
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("ջΪ�գ��޷�ִ��pop����");
        }
        
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }
    
    // ��ȡջ��Ԫ��
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("ջΪ�գ��޷���ȡջ��Ԫ��");
        }
        return topNode->data;
    }
    
    // ���ջ�Ƿ�Ϊ��
    bool isEmpty() const {
        return topNode == nullptr;
    }
    
    // ��ȡջ�Ĵ�С
    int size() const {
        return stackSize;
    }
};

//ջ������
//��ת�ַ�������ת���� 
��ת�ַ���ʱ������ջ���棬�ٷų���
Ҳ��������ָ�� ��һǰһ��ÿ�ν������𲽿���

��ת����ʱ ��ʱ����ѭ����ݹ� 
stack<Node*> S;
Node* temp = head;
while(temp != NULL){
	S.push(temp);
	temp=temp->next;
}

������ʱ �������Ƴ�ȥ��
Node *temp=S.top();
head=temp;
S.pop();
whiel(!S.empty()){
	temp->next=S.top();
	S.pop();
	temp=temp->next;
}
temp->next=NULL; 

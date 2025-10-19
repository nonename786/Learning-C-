//一个后进先出的东西 
//有两个操作push(x) 推进去
//pop() 从栈中移除最近期的元素
//Top() 移除顶部元素 
//IsEmpty() 检查是否空，返回true和false
//栈实际上是一个有特殊约束的数组或集合
 //实际结构就是一个数组和一个表示栈顶高度的top
 //每次push，pop就是更改元素的同时更改 top位置
 //并且保证不会溢出 
 //解决方法：1、使用动态数组，满了就建造一个更大的，再复制过去
 //2、使用vector这种容器 
 #include <iostream>
#include <stdexcept>

template<typename T> //这是一个模板声明 
class ArrayStack {
private:
    T* data;           // 存储栈元素的数组
    int capacity;      // 栈的容量
    int topIndex;      // 栈顶索引

public:
    // 构造函数
    ArrayStack(int size = 10) : capacity(size), topIndex(-1) {
        data = new T[capacity];
    }
    
    // 析构函数
    ~ArrayStack() {
        delete[] data;
    }
    
    // 拷贝构造函数
    ArrayStack(const ArrayStack& other) : capacity(other.capacity), topIndex(other.topIndex) {
        data = new T[capacity];
        for (int i = 0; i <= topIndex; i++) {
            data[i] = other.data[i];
        }
    }
    
    // 赋值运算符
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
    
    // 入栈操作
    void push(const T& value) {
        if (topIndex == capacity - 1) {
            // 栈满，需要扩容
            resize(capacity * 2);
        }
        data[++topIndex] = value;
    }
    
    // 出栈操作
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法执行pop操作");
        }
        topIndex--;
        
        // 如果栈元素很少，缩小容量以节省空间
        if (topIndex > 0 && topIndex == capacity / 4) {
            resize(capacity / 2);
        }
    }
    
    // 获取栈顶元素
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法获取栈顶元素");
        }
        return data[topIndex];
    }
    
    // 检查栈是否为空
    bool isEmpty() const {
        return topIndex == -1;
    }
    
    // 获取栈的大小
    int size() const {
        return topIndex + 1;
    }
    
    // 获取栈的容量
    int getCapacity() const {
        return capacity;
    }

private:
    // 调整数组大小
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

//如果用链表实现 每次加入和删除
//都得遍历到倒数第二个节点 
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
    
    Node* topNode;    // 栈顶节点
    int stackSize;    // 栈的大小

public:
    // 构造函数
    LinkedListStack() : topNode(nullptr), stackSize(0) {}
    
    // 析构函数
    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // 拷贝构造函数
    LinkedListStack(const LinkedListStack& other) : topNode(nullptr), stackSize(0) {
        if (!other.isEmpty()) {
            // 使用临时栈来保持相同的顺序
            LinkedListStack temp;
            Node* current = other.topNode;
            while (current != nullptr) {
                temp.push(current->data);
                current = current->next;
            }
            
            // 将临时栈的元素弹出并压入新栈，恢复原始顺序
            while (!temp.isEmpty()) {
                this->push(temp.top());
                temp.pop();
            }
        }
    }
    
    // 赋值运算符
    LinkedListStack& operator=(const LinkedListStack& other) {
        if (this != &other) {
            // 清空当前栈
            while (!isEmpty()) {
                pop();
            }
            
            // 复制另一个栈
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
    
    // 入栈操作
    void push(const T& value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        stackSize++;
    }
    
    // 出栈操作
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法执行pop操作");
        }
        
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }
    
    // 获取栈顶元素
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法获取栈顶元素");
        }
        return topNode->data;
    }
    
    // 检查栈是否为空
    bool isEmpty() const {
        return topNode == nullptr;
    }
    
    // 获取栈的大小
    int size() const {
        return stackSize;
    }
};

//栈的作用
//反转字符串，反转链表 
反转字符串时可以用栈储存，再放出来
也可以两个指针 ，一前一后，每次交换，逐步靠近

反转链表时 临时变量循环或递归 
stack<Node*> S;
Node* temp = head;
while(temp != NULL){
	S.push(temp);
	temp=temp->next;
}

再连结时 ，倒着推出去连
Node *temp=S.top();
head=temp;
S.pop();
whiel(!S.empty()){
	temp->next=S.top();
	S.pop();
	temp=temp->next;
}
temp->next=NULL; 

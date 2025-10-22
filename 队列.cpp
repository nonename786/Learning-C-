#include<iostream>
using namespace std;
//用数组实现队列 
使用 前后两个索引front rear指示 
每次增删时改变这两个变量
可以有IsFull() IsEmpty() 检查位置检测是否空满
 通常将这两个设置为-1 
 如果要删除元素 就将front向前移
 但这样会导致front左边的单元格被永远浪费
 处理措施： 使用环形数组的概念  
 这样会使得第i个的索引对应的下一个的索引为
 (i+1)%(array.length) 这样就能转回去了
  同样，对于这种环形的对front删除时，也用这种索引处理方式
class ArrayQueue {
private:
    int *arr;       // 存储队列元素的数组
    int capacity;   // 队列容量
    int front;      // 队首索引
    int rear;       // 队尾索引
    int size;       // 当前队列大小

public:
    // 构造函数
    ArrayQueue(int cap = 10) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    
    // 析构函数
    ~ArrayQueue() {
        delete[] arr;
    }
    
    // 入队
    void enqueue(int value) {
        if (isFull()) {
            cout << "队列已满！" << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // 循环队列
        arr[rear] = value;
        size++;
    }
    
    // 出队
    int dequeue() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;  // 循环队列
        size--;
        return value;
    }
    
    // 获取队首元素
    int getFront() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        return arr[front];
    }
    
    // 获取队尾元素
    int getRear() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        return arr[rear];
    }
    
    // 检查队列是否为空
    bool isEmpty() {
        return size == 0;
    }
    
    // 检查队列是否已满
    bool isFull() {
        return size == capacity;
    }
    
    // 获取队列大小
    int getSize() {
        return size;
    }
    
    // 打印队列
    void display() {
        if (isEmpty()) {
            cout << "队列为空" << endl;
            return;
        }
        cout << "队列元素: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

// 使用示例
int main() {
    ArrayQueue q(5);
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();  // 输出: 队列元素: 1 2 3
    
    cout << "出队: " << q.dequeue() << endl;  // 输出: 出队: 1
    q.display();  // 输出: 队列元素: 2 3
    
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();  // 输出: 队列元素: 2 3 4 5 6
    
    return 0;
}

//链表实现队列 
将链表的head出作为头部删除元素，末尾作为尾部，用于出元素
在链表的头部插入是O（1），而在
链表的尾部插入或删除时为O(n) 
但想要两端 都为O(1) 就得有其他操作：
 关键是链表尾部的要能连到新结点上，就得能直接有他的引用 
即 多使用一个像head一样的指针，使用rear指针
指向末尾，每次增删后也改变末尾的位置
rear->next=temp;
rear=temp;

Dequeue:  Node* temp=front;
front=front->next;
free(temp);

#include <iostream>
using namespace std;

// 链表节点
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* front;  // 队首指针
    Node* rear;   // 队尾指针
    int count;    // 元素计数

public:
    // 构造函数
    LinkedListQueue() {
        front = rear = nullptr;
        count = 0;
    }
    
    // 析构函数
    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    // 入队
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
    
    // 出队
    int dequeue() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
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
    
    // 获取队首元素
    int getFront() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        return front->data;
    }
    
    // 获取队尾元素
    int getRear() {
        if (isEmpty()) {
            cout << "队列为空！" << endl;
            return -1;
        }
        return rear->data;
    }
    
    // 检查队列是否为空
    bool isEmpty() {
        return front == nullptr;
    }
    
    // 获取队列大小
    int getSize() {
        return count;
    }
    
    // 打印队列
    void display() {
        if (isEmpty()) {
            cout << "队列为空" << endl;
            return;
        }
        cout << "队列元素: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// 使用示例
int main() {
    LinkedListQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // 输出: 队列元素: 10 20 30
    
    cout << "队首元素: " << q.getFront() << endl;  // 输出: 10
    cout << "队尾元素: " << q.getRear() << endl;   // 输出: 30
    
    cout << "出队: " << q.dequeue() << endl;       // 输出: 10
    q.display();  // 输出: 队列元素: 20 30
    
    return 0;
}

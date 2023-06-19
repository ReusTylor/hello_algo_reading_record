/*
    push()
    pop()
    peek()
*/

//基于链表的实现
struct ListNode(){
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){};
}

class LinkedListQueue
{
private:
    ListNode* front;
    ListNode* rear;
    int queSize;
public:
    LinkedListQueue(){
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }
    ~LinkedListQueue(){
        freeMemoryLinkedList(front);
    }

    int size(){
        return queSize;
    }

    bool empty(){
        return queSize == 0;
    }
    void push(int num){
        ListNode* node = new ListNode(num);
        if(front == nullptr){
            front = node;
            rear = node;
        }else{
            rear->next = node;
            rear = node;
        }
        queSize++;
    }

    void pop(){
        
        ListNode* node = front;
        front = front -> next;
        delete node;
        queSize--;
    }
    int peek(){
        if(queSize == 0)
            throw out_of_range("队列空")
        return front->val;
    }
};

// 基于数组的实现
/* 
    删除数组首元素的时间复杂度为O(n)，导致出队效率低。可以避免这种问题
    使用一个front元素指向对手元素的索引，并维护一个queSize用于记录队列长度，定义rear = front + queSize
    计算出的rear指向队尾元素的下一个位置
    由此 数组中包含的有效区间为[front, rear - 1]
        - 入队操作：将输入元素赋值给rear索引处，将queSize + 1;
        - 出队操作：将front + 1, 将queSize - 1

    在入队和出队过程中，front和rear都向右移动，到达数组尾部后就无法继续移动。为此可以将数组视为首尾相接的环形数组
*/

// 对于环形数组，需要让front和rear越过数组尾部时，直接返回数组头部继续进行遍历。这种周期性规律可以通过 取余操作 实现


// 可以将数组替换为动态数组，从而引入扩容机制。
class ArrayQueue{
private:
    int *nums;
    int front;
    int queSize;
    int queCapacity;    
public:
    ArrayQueue(int capacity){
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }
    ~ArrayQueue(){
        delete [] nums;
    }

    int capacity(){
        return queCapacity;
    }

    int size(){
        return queSize;
    }

    bool empty(){
        return queSize == 0;
    }

    void push(int num){
        if(queSize == queCapacity)
            cout << "队列已满" << endl;
            return;
        int rear = (front + queSize) % queCapacity; // 取余操作，实现rear越过数组尾部后回到头部
        num[rear] = num;
        queSize++;
    }

    void pop(){
        int num = peek();
        front = (front + 1) % queCapacity; // 队首指针后移一位，若越过尾部则返回到数组头部
        queSize--;
    }
    int peek(){
        if(empty())
            throw out_of_range("队列为空");
        return nums[front];
    }
}

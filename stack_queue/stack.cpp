/*
    1. 基于数组实现的栈在处罚扩容时效率会降低，但由于扩容是低频操作，因此平均效率更高。
    2. 基于链表实现的栈可以提供更加稳定的效率表现
    栈典型应用：
        浏览器中的后退与前进，软件中的撤销与反撤销
*/

// 基于链表的实现
class LinkedListStack{
private:
    ListNode* stackTop;
    int stkSize;
public:
    LinkedListStack(){
        stackTop = nullptr;
        stkSize = 0;
    }
    ~LinkedListStack(){
        freeMemoryLinkedList(stackTop);
    }

    int size(){
        return stkSize;
    }

    bool empty(){
        return (stkSize == 0);
    }

    void push(int num){
        ListNode* node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    void pop(){
        int num = top();
        ListNode* tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stkSize--;
    }

    int top(){
        if(size() == 0)
            throw out_of_range("栈为空")
        return stackTop->val;
    }
};

// 基于数组实现
// 动态数组也可以实现即时的扩容
class ArrayStack
{
private:
    vector<int> stack;
public:
    int size(){
        return stack.size();
    }

    bool empty(){
        return stack.empty();
    }

    void push(){
        stack.push_back(num);
    }

    void pop(){
        int oldTop = top();
        stack.pop_back();
    }

    void top(){
        if(empty())
            throw out_of_range("栈为空");
        return stack.back();
    }

};


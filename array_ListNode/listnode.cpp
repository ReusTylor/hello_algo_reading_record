/*
    可以在非连续的内存空间
    链表优点：
     1.插入和删除节点效率高
    缺点：
     1.节点访问效率低
     2.内存占用较大
*/
struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(),next(nullptr){};
    ListNode(int x):val(x), next(nullptr){};
};

// 初始化方法
ListNode* n0 = new ListNode(1);
ListNode* n1 = new ListNode(2);
ListNode* n2 = new ListNode(3);
ListNode* n3 = new ListNode(4);
ListNode* n4 = new ListNode(5);

//n0->next = n1;构建引用指向


// 插入
void insert(ListNode* n0, ListNode *p){
    p->next = n0->next;
    n0->next = p;
}

// 删除n0之后的首个节点
void remove(ListNode* n0){
    if(n0->next == nullptr){
        return;
    }
    ListNode* p = new ListNode();
    p = n0->next;
    n0->next = p->next;
    delete p;
}

// 访问索引为index的节点
ListNode* access(ListNode* head, int index){
    for(int i = 0; i < index; i++){
        if(head = nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}


// 常用操作：
// 遍历链表查找
int find(ListNode* head, int target){
    int index = 0;
    while(head != nullptr){
        if(head -> val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}
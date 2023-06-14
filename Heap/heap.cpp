#include<iostream>
using namespace std;

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

int parent(int i){
    return (i - 1) / 2;
}

// 访问堆顶元素
int peek(){
    return maxHeap[0];
}

// 元素入堆
// 给定元素val，先添加到堆底，然后对堆进行修复
// 从堆底开始，从底至顶执行堆化
// 设总节点为n，则树的高度为O(logn)，由此可知，堆化操作的循环轮数最多为O(logn),元素入堆操作的时间复杂度为O(logn)

void push(int val){
    maxHeap.push_back(val);
    sifUp(size() - 1);
}

void sifUp(int i){
    while(true){
        // 获取节点i的父节点
        int p = parent(i);
        if(p < 0 || maxHeap[i] <= maxHeap(p))
            break;
        // 交换父节点和子节点
        swap(maxHeap[i], maxHeap[p]);
        // 循环向上堆化
        i = p;
    }
}

/*
    堆顶元素出栈
    如果直接删除的话，会导致所有节点的索引都发生变化，为了减少元素索引引起的变动，采取以下步骤：
    1. 交换堆顶与堆底元素
    2. 交换完成后，将堆底从列表中删除
    3. 从根节点开始，从顶至底进行堆化
    复杂度也为O(logn)
*/

void pop(){
    if(empty())
        throw out_of_range("error");
    swap(maxHeap[0], maxHeap[size() - 1]);
    maxHeap.pop_back();
    sifDown(0);
}

// 从节点i开始，从顶至底堆化
void sifDown(int i){
    while (true)
    {
        int l = left(i);
        int r = right(i);
        int ma = i;
        if(l < size() && maxHeap[l] > maxHeap[ma])
            ma = l;
        if(r < size() && maxHeap[r] > maxHeap[ma])
            ma = r;
        if(ma == i)
            break;
        swap(maxHeap[ma], maxHeap[i]);
        // 继续向下堆化
        i = ma;
    }
    
}
#include<iostream>
#include<algorithm>


using namespace std;

void max_heapify(int arr[], int start, int end){
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end){
        if(son + 1 <= end && arr[son] < arr[son + 1])
            son++;  // 更新son的值为右节点的值 因为右节点的值更大
        if(arr[dad] > arr[son]) // 检查父节点的值是否已经大于子节点的值，如果成立的话，说明已经调整完成，从函数中返回
            return;
        else{
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len){
    for(int i = len / 2 - 1; i >= 0; i--){
        max_heapify(arr, i, len - 1);
    }
    for(int i = len - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main(){
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr); // 数组总长度/单个元素的字节数
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;   
}
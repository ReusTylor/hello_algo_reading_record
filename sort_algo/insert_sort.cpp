/*
    插入排序
    基于数组插入操作的算法，选择一个待排序的元素作为基准值base，将base与左侧已经排序的元素进行逐一比较，并将其插入到正确的位置上。
    流程：
    1. 将数组中第二个元素作为base，执行插入操作后，数组的前两个元素已排序
    2. 将第三个数作为base
    3. 以此类推，直到选取数组最末尾的元素

    时间复杂度：O(n^2)
    空间复杂度：O(1)
    稳定排序

    优势：
        1. 冒泡操作基于元素交换实现，需要借助一个临时变量，共涉及3个单元的操作
        2. 插入操作基于元素赋值实现，只涉及一个单元的操作
        因此，插入排序的代价更小。

        对于长数组，直接使用分治的排序，如快排等，时间复杂度O(nlogn)
        对于短数组，直接使用插入排序，时间复杂度O(n^2)

        与线性查找和二分查找的情况相似
    
*/

#include<iostream>
#include<vector>

using namespace std;

void insert_sort(vector<int> &nums){
    //外循环，依次选取数组中的数
    for(int i = 1; i < nums.size(); i++){
        // 内循环，进行排序
        int base = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > base){
            nums[j + 1] = nums[j]; // nums[j] 右移一位
            j--;
        }
        nums[j + 1] = base; // 将base放在正确的位置上
    }
}


int main(){
    vector<int> nums = {5,1,2,3,4};
    insert_sort(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}
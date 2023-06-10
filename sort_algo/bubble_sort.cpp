/*
    冒泡排序
    具体做法为：从数组的最左端开始遍历，依次比较相邻的元素大小，如果左元素 > 右元素，就交换，遍历完成后最大的元素会被移动到数组的最右端。
    在完成一个冒泡排序后，最大元素已经确定，接下来只需要对剩下的n - 1个元素进行排序.
    通过n - 1轮冒泡操作，整个数组完成排序
*/
#include<iostream>
#include<vector>
using namespace std;
void bubble_sort_with_flag(vector<int> & nums);

void bubble_sort(vector<int> &nums){
    // 外循环：需要进行循环的次数， n个数需要进行n - 1次冒泡
    for(int i = nums.size() - 1; i > 0; i--){
        //内循环：冒泡操作
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

int main(){
    vector<int> nums = {5,1,2,3,4};
    bubble_sort_with_flag(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 遇到相等的元素不交换，所以是稳定的

// 效率优化
// 如果在某轮冒泡中没有发现任何交换，则说明已经完成排序，可以直接返回结果。
// 使用一个flag来检测这种情况

void bubble_sort_with_flag(vector<int> & nums){
    // 外循环
    for(int i = nums.size() - 1; i > 0; i--){
        //内循环
        bool flag = false;
        for(int j = 0; j < i; j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if(flag == false)
            break;
    }
}


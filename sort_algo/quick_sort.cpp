/*
    基于分治思想的算法
    核心操作是 哨兵划分
    目标是 选择数组中的某个元素作为基准，将所有小于基准的元素移动到其左侧，大于基准数的元素移动到其右侧。具体流程为
        1. 选择数组最左端的元素作为基准数，初始化指针i j分别指向数组的两端
        2. 设置一个循环，在每轮中使用i（j）分别寻找第一个比基准数大（小）的元素， 然后交换这两个元素
        3. 循环执行步骤2,直到i和j相遇时停止，最后将基准数交换至两个子数组的分界线
    哨兵划分完成后，原数组被分成三个部分，左子数组，基准数，右子数组，且满足左子数组任意元素 <= 基准数 <= 右子数组任意元素
    因此接下来只需要对这两个数组进行排序。


    算法流程：
    1. 首先对原数组执行一次 哨兵划分 ，得到待排序的左子数组和右子数组
    2. 然后，对左边和右边分别递归执行 哨兵划分
    3. 持续递归， 直至子数组长度为1时终止，从而完成整个数组的排序


    时间复杂度O(nlogn)
    空间复杂度O(n)
    非稳定排序

    快排为什么快：
        快排的平均时间复杂度和归并排序 堆排序相同，但通常快排的效率更高，因为
            1. 出现最差情况的概率很低。
            2. 缓存使用率高，执行哨兵划分时，系统可以将整个子数组加载到缓存，因此访问元素的效率较高，像堆排序这类算法需要跳跃式的访问元素，从而缺乏这一特性
            3. 复杂度的常数系数低，快排的比较 赋值 交换等操作的总数量最少。
*/

#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> &nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int partition(vector<int>& nums, int left, int right){
    int i = left;
    int j = right;

    while(i < j){
        while(i < j && nums[j] >= nums[left]) j--; // 从右向左找第一个小于基准数的元素
        while(i < j && nums[i] <= nums[left]) i++; // 从左往右找第一个大于基准数的元素
        swap(nums, i, j); // 交换这两个元素
    }
    swap(nums, i, left); // 将基准数交换至两个子数组的分界线。
    return i; // 返回基准数的索引
}

void quickSort(vector<int> &nums, int left, int right){
    if(left >= right)
        return;
    // 哨兵划分
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

int main(){
    vector<int> nums = {5,1,2,3,4};
    int right = nums.size() - 1;
    int left = 0;
    quickSort(nums, left, right);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    return 0;
}
#include<iostream>
#include<vector>

int binarySearch(std::vector<int>& nums, int target){
    int i = 0;
    int j = nums.size() - 1;
    while(i <= j){
        int mid = i + (j - i) / 2;
        if(nums[mid] > target){
            j = mid - 1;
        }else if(nums[mid] < target){
            i = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(){
    std::vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;
    int result = binarySearch(nums, target);

    if(result != -1){
        std::cout<<"found index :" << result << std::endl;
    }else{
        std::cout << "not found" << std::endl;
    }
    return 0;
}

// 时间：O(logn) 空间O(1)
/*
    二分局限性：
        适合有序数据
        仅适用于数组
        小数据量下线性查找效率更高
*/
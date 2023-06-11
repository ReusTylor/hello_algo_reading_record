/*
    数组优点：
     1. 访问元素更高效

    数组缺点：
     1. 初始化后长度不可变
     2. 插入或者删除元素效率低下
*/

/*
    数组典型应用
     1. 随机访问
     2. 二分查找
     3. 深度学习
*/
// 存储在栈上
int arr[5];
int nums[5] = {1, 2, 3, 4, 5};

// 存储在堆上
int* arr1 = new int[5];
int* arr2 = new int[5]{1, 2, 3, 4, 5};


// 返回一个特定的元素
int randomAccess(int* nums, int size){
    // 在区间[0, size)随机抽取一个数字
    int randomIndex = rand() % size;
    // 获取并返回随机元素
    int result = nums[randomIndex];
    return result;
}




// 扩展数组的大小
int* extend(int* nums, int size, int enlarge){
    // 初始化一个扩展长度之后的数组
    int* newarray = new int[size + enlarge];
    // 原数组复制过来
    for(int i = 0; i < size; i++){
        newarray[i] = nums[i];
    }
    delete[] nums;
    return newarray;
}


// 向数组中插入元素
void insert(int* nums, int size, int index, int num){
    for(int i = size - 1; i > size; i--){
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
    size++;
}
// 删除元素
void remove(int* nums, int size, int index, int num){
    for(int i = index; i < size - 1; i++){
        nums[i] = nums[i + 1];
    }
    size--;
}
// 插入和删除具有一些缺点 时间复杂度高，丢失元素（超出数组长度范围的元素会丢失），内存浪费

//数组遍历
void traverse(int* nums, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        count++;
    }
}


//数组查找
int find(int* nums, int size, int target){
    for(int i = 0; i < size; i++){
        if(nums[i] == target)
            return i;
    }
    return -1;
}
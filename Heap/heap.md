### 分类
大顶堆
小顶堆

### 常用操作
堆常用来实现优先队列。
push()

pop()

peek() 获取堆顶元素

size()

isEmpty()

实际应用中可以使用编程语言提供的堆类（或者优先队列类）

初始化小顶堆/大顶堆
`priority_queue<int, vector<int>, greater<int>> minHeap;`

`priority_queue<int, vector<int>, less<int>> maxHeap;`
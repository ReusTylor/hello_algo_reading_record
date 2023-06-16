/*
    Bread-first traversal
    BFS通常借助队列实现
        1. 将遍历起点startVet加入队列，开启循环
        2. 在循环的每轮迭代中，弹出队首顶点并记录访问，然后该顶点的所有邻接顶点加入到队列尾
            通过一个visited数组来记录已经被访问的节点，避免出现重复访问的问题
        3. 循环步骤2, 直到所有顶点被访问完成后结束
        为了防止重复遍历节点，借助一个哈希表visited来记录哪些节点已被访问

        广度优先的顺序并不唯一
        时间复杂度O(V + E)
        空间复杂度O(V)
*/
//使用邻接表表示图，以便获取指定顶点的所有邻接顶点
vector<Vertex *> graphBFS(GraphAdjList& graph, Vertex *startVet){
    // 最终的遍历序列
    vector<Vertex*> res;
    // hash用于记录已经遍历过的节点
    unordered_set<Vertex*> visited = {
        startVet;
    }
    // 队列用于实现BFS
    queue<Vertex*>que;
    que.push(startVet);
    while (!que.empty())    
    {
        Vertex* vet = que.front();
        que.pop();
        res.push_back(vet)//记录已经访问过的节点
        //遍历该顶点的所有邻接顶点，通过邻接表实现
        for(auto adjVet : graph.adjList[vet]){
            if(visited.count(adjVet))
                continue;  // 跳过已经被访问的顶点
            que.push(adjVet); // 只入队未访问的顶点
            visited.emplace(adjVet); // 标记已经被访问过
        }
    }
    return res;
    
}

/*
    深度优先是一种走到头+回溯的算法，基于递归来实现
    也需要借助一个hash表visited来记录已经被访问的顶点

    时间复杂度O(V + E)
    空间复杂度O(V)
*/

void dfs(GraphAdjList& graph, unordered_set<Vertex*> &visited, Vector<Vertex*> &res, Vertex* vet){
    res.push_back(vet);
    visited.emplace(vet);

    for(Vertex* adjVet : graph.adjList[vet]){
        if(visited.count(adjVet))
            continue;
        dfs(graph, visited, res, adjVet);
    }
}

// 使用邻接表来表示图，
vector<Vector*> graphDFS(GraphAdjList& graph, Vertex* startVet){
    vector<Vertex* > res;
    unordered_set<Vertex*> visited;
    dfs(graph, visited, res, startVet);
    return res; 
}
#include<iostream>
#include<vector>
using namespace std;

class GraphAdjMat
{
private:
    vector<int> vertices;  // 
    vector<vector<int>> adjMat; // 
public:
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges){
        // 添加顶点
        for(int val : vertices)
            addVertex(val);
        
        // 添加边
        // edges元素代表顶点索引，即对应verticles元素索引
        for(const vector<int> &edge:edges){
            addEdge(edge[0], edge[1]);
        }
    }

    //获取顶点值
    int size() const{
        return vertices.size();
    }

    void addVertex(int val){
        int n = size();
        vertices.push_back(val);
        adjMat.emplace_back(n, 0);
        for(vector<int>& row : adjMat){
            row.push_back(0);
        }
    }

    void removeVertex(int index){
        if(index >= size())
            throw out_of_range("顶点不存在");
        vertices.erase(vertices.begin() + index);
        adjMat.erase(adjMat.begin() + index);
        for(vector<int> &row:adjMat){
            row.erase(row.begin() + index);
        }

    }

    void addEdge(int i, int j){
        if(i < 0 || j < 0 || i >= size() || j >= size() || i == j){
            throw out_of_range("顶点不存在");
        }

        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }


    void removeEdge(int i, int j){
        if(i < 0 || j < 0 || i >= size() || j >= size() || i == j){
            throw out_of_range("顶点不存在");
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    void print(){
        cout << "顶点列表 = ";
        printVector(vertices);
        printVectorMatrix(adjMat);
    }

};

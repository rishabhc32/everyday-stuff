// Problem Statement -- https://www.geeksforgeeks.org/find-k-cores-graph/

#include <bits/stdc++.h>

using namespace std;

struct node {
    bool visited = false;
    list<int> l;
    int degree ;
};

void addEdge(vector<node>& graph, int u, int v) {
    graph.at(u).l.push_back(v);
    graph.at(v).l.push_back(u);
}

bool doDfs(int v, vector<node>& Graph, const int& k) {
    Graph.at(v).visited = true;

    for(const auto& i : Graph.at(v).l) {
        if(Graph.at(v).degree < k)
            --Graph.at(i).degree;

        if(!Graph.at(i).visited) {
            bool ans = doDfs(i, Graph, k);
            if(ans)
                --Graph.at(v).degree;
        }
    }

    return (Graph.at(v).degree < k);
}

void printKCores(int k, vector<node>& Graph) {
    int n = Graph.size();

    int minDegree = INT_MAX, startVertex = 0;

    for(int i = 0; i < n; ++i) {
        Graph.at(i).degree = Graph.at(i).l.size();
        if(minDegree > Graph.at(i).degree) {
            minDegree = Graph.at(i).degree;
            startVertex = i;
        }
    }
    
    doDfs(startVertex, Graph, k);

    for(int i = 0; i < n; ++i) {
        if(Graph.at(i).degree >= k) {
            cout<<"["<<i<<"]"<<" ";
            for(auto& j : Graph.at(i).l) {
                if(Graph.at(j).degree >= k)
                    cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}

int main() {
    int k = 3;

    vector<node> Graph(9);

    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 2);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 5);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 2, 4);
    addEdge(Graph, 2, 5);
    addEdge(Graph, 2, 6);
    addEdge(Graph, 3, 4);
    addEdge(Graph, 3, 6);
    addEdge(Graph, 3, 7);
    addEdge(Graph, 4, 6);
    addEdge(Graph, 4, 7);
    addEdge(Graph, 5, 6);
    addEdge(Graph, 5, 8);
    addEdge(Graph, 6, 7);
    addEdge(Graph, 6, 8);

    printKCores(k, Graph);

    return 0;
}
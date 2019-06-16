// Problem Statement -- https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

struct node {
    bool visited = false;
    list<int> l;
};

void addEdge(vector<node>& graph, int u, int v) {
    graph.at(u).l.push_back(v);
}

void doDfs(int v, vector<node>& Graph, stack<int>& s) {
    Graph.at(v).visited = true;

    for(auto& i : Graph.at(v).l) 
        if(!Graph.at(i).visited)
            doDfs(i, Graph, s);
    
    s.push(v);
}

int findMother(vector<node>& Graph) {
    int n = Graph.size();
    stack<int> s;

    for(int i = 0 ; i < n ; ++i) {
        if(!Graph.at(i).visited)
            doDfs(i, Graph, s);
    }

    return s.top();
}

int main() {

    vector<node> Graph(7);

    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 4, 1);
    addEdge(Graph, 6, 4);
    addEdge(Graph, 5, 6);
    addEdge(Graph, 5, 2);
    addEdge(Graph, 6, 0);

    cout<<"Mother Vertex: "<<findMother(Graph)<<endl;

    return 0;
}

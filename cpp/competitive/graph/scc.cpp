// Problem Statement -- https://www.geeksforgeeks.org/strongly-connected-components/

#include <iostream>
#include <stack>
#include <vector>
#include <list>

#define addEdge(x,y) assign(graph,x,y)

using namespace std;

struct node {
    bool visited = false;
    list<int> l;
};

void assign(vector<node>& graph, int u, int v) {
    graph.at(u).l.push_back(v);
}

void dfsStore(int v, vector<node>& graph, stack<int>& s) {
    graph.at(v).visited = true;

    for(auto i : graph.at(v).l) 
        if(!graph.at(i).visited)
            dfsStore(i, graph, s);
    
    s.push(v);
}

vector<node> reverseGraph(const vector<node>& v) {
    int n = v.size();

    vector<node> Graph(n);

    for(int i = 0 ; i < n ; ++i) {
        for(auto& j : v.at(i).l)
            Graph.at(j).l.push_back(i);
    }

    return Graph;
}

void doDfs(int i, vector<node>& Graph) {
    cout<<i<<" ";
    Graph.at(i).visited = true;

    for(auto& j : Graph.at(i).l) 
        if(!Graph.at(j).visited)
            doDfs(j, Graph);
}

void printScc(vector<node>& graph) {
    stack<int> s;
    dfsStore(0, graph, s);

    vector<node> ReverseGraph = reverseGraph(graph);

    while(!s.empty()) {
        int i = s.top();
        s.pop();

        if(!ReverseGraph.at(i).visited) {
            doDfs(i, ReverseGraph);
            cout<<endl;
        }
    }
}

int main() {
    vector<node> graph(11);
    
    addEdge(0,1);addEdge(0,3);
    addEdge(1,2);addEdge(1,4);
    addEdge(2,0);addEdge(2,6);
    addEdge(3,2);
    addEdge(4,5);addEdge(4,6);
    addEdge(5,6);addEdge(5,7);addEdge(5,8);addEdge(5,9);
    addEdge(6,4);
    addEdge(7,9);
    addEdge(8,9);
    addEdge(9,8);

    printScc(graph);

    return 0;
}

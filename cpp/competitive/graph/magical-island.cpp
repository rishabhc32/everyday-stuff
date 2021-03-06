// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/magical-islands/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <list>

#define addEdge(x,y) assign(graph,x,y)

using namespace std;

struct node {
    bool visited = false;
    list<unsigned int> l;
    unsigned int value = 0;
};

void assign(vector<node>& graph, unsigned int u, unsigned int v) {
    graph.at(u).l.push_back(v);
}

void dfsStore(unsigned int v, vector<node>& graph, stack<unsigned int>& s) {
    graph.at(v).visited = true;

    for(auto i : graph.at(v).l) 
        if(!graph.at(i).visited)
            dfsStore(i, graph, s);
    
    s.push(v);
}

vector<node> reverseGraph(const vector<node>& v) {
    unsigned int n = v.size();

    vector<node> Graph(n);

    for(unsigned int i = 0 ; i < n ; ++i) {
        for(auto& j : v.at(i).l)
            Graph.at(j).l.push_back(i);
    }

    return Graph;
}

void doDfs(unsigned int i, vector<node>& Graph, unsigned int& cnt) {
    Graph.at(i).visited = true;
    ++cnt;
    Graph.at(i).value = 1;

    for(auto& j : Graph.at(i).l) 
        if(!Graph.at(j).visited)
            doDfs(j, Graph, cnt);
}

void printScc(vector<node>& graph, unsigned int n) {
    stack<unsigned int> s;

    for(unsigned int i = 0 ; i < n ; ++i) {
        if(!graph.at(i).visited)
            dfsStore(i, graph, s);
    }

    vector<node> ReverseGraph = reverseGraph(graph);

    unsigned int X = 0;

    while(!s.empty()) {
        unsigned int i = s.top();
        s.pop();

        if(!ReverseGraph.at(i).visited) {
            unsigned int cnt;
            cnt = 0;

            doDfs(i, ReverseGraph, cnt);
            
            X = max(X, cnt);
            
        }
    }

    cout<<X;
}

int main() {
    unsigned int n, m;
    cin>>n>>m;

    vector<node> graph(n);

    while(m--) {
        unsigned int u, v;
        cin>>u>>v;
        addEdge(--u, --v);
    }

    printScc(graph, n);

    return 0;
}

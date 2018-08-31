#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    bool visited = false;
    list<ll> l;
};

void addEdge(vector<node>& Graph, ll u, ll v) {
    Graph.at(u).l.push_back(v);

    if(u != v)
        Graph.at(v).l.push_back(u);
}

void dfs(vector<node>& Graph, ll index, ll& count) {
    Graph.at(index).visited = true;

    count += Graph.at(index).l.size();

    for(const int& y : Graph.at(index).l) {
        if(y == index)
            count += 1;
        if(!Graph.at(y).visited) {
            dfs(Graph, y, count);
        }
    }
}

int main() {
    ll n, m, u, v, count, Max = LONG_LONG_MIN;
    cin>>n>>m;

    vector<node> Graph(n);

    while(m--) {
        cin>>u>>v;

        addEdge(Graph, --u, --v);
    }

    for(ll i = 0; i < n; ++i) {
        count = 0;

        if(!Graph.at(i).visited) {
            dfs(Graph, i, count);

            Max = max(Max, count);
        }
    }

    cout<<Max/2;

    return 0;
}
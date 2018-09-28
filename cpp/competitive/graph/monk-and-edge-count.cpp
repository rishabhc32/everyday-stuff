#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll m[1000];

struct node {
    bool visited = false;
    list< pair<ll, ll> > l;
};

void assign(vector<node>& Graph, int u, int v, int w) {
    Graph.at(u).l.push_back(make_pair(v, w));
    Graph.at(v).l.push_back(make_pair(u, w));
}

void dfs(vector<node>& Graph, ll v) {
    Graph.at(v).visited = true;

    for(const pair<ll, ll>& i : Graph.at(v).l) {
        if(!Graph.at(i.first).visited) {
            m[i.second]++;
            dfs(Graph, i.first);
        }
    }
}

void makeFalse(vector<node>& Graph) {
    for(node& i : Graph) {
        i.visited = false;
    }
}

void doStuff(vector<node>& Graph) {
    for(ll i = 1; i < Graph.size(); ++i) {
        if(!Graph.at(i).visited)
        dfs(Graph, i);
        //makeFalse(Graph);
    }
}

int main() {
    ll n, q;
    cin>>n>>q;

    vector<node> Graph(n+1);

    for(ll i = 1; i < n; ++i) {
        ll u, v;
        cin>>u>>v;

        assign(Graph, u, v, i);
    }

    doStuff(Graph);

    return 0;
}

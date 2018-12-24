#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    bool visited  = false;
    list < pair<ll, ll> > l;
};

void addEdge(vector<node>& Graph, ll u, ll v, ll w) {
    Graph.at(u).l.push_back({v, w});
}

void doDfs(vector<node>& Graph, ll u, ll& Max, ll& Min) {
    Graph.at(u).visited = true;

    for(auto& i : Graph.at(u).l) {
        Max = max(Max, i.second);
        Min = min(Min, i.second);

        if(! Graph.at(i.first).visited) {
            doDfs(Graph, i.first, Max, Min);
        }
    }
}

int main() {
    ll n, m;
    cin>>n>>m;

    vector<node> Graph(n+1);

    while(m--) {
        ll u, v, w;
        cin>>u>>v>>w;

        addEdge(Graph, u, v, w);
    }

    ll Max = LONG_LONG_MIN, Min = LONG_LONG_MAX;
    ll pre_max = Max, pre_min = Min;

    for(ll i = 1; i <= n; ++i) {
        doDfs(Graph, i, Max, Min);

        if(Max >= pre_max && Min <= pre_min) {
            pre_max = Max;
            pre_min = Min;
        }

        Max = LONG_LONG_MIN;
        Min = LONG_LONG_MAX;

        for_each(Graph.begin()+1, Graph.end(), [](node& i){i.visited = false;});
    }

    cout<<(pre_max-pre_min);

    return 0;
}
// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/travelling-tom-7eadedb7/

// NOT COMPLETED

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
    ll weight;
    pair<ll, ll> edgde;
};

struct CCnode {
    bool visited = false;
    vector<ll> l;
};

struct el {
    ll val;
    ll size;
};

bool comparator(const node& node1, const node& node2) {
    return node1.weight < node2.weight;
}

vector<el> Arr;

void init(ll n) {
    for(ll i = 0; i < n; ++i) {
        el temp;
        temp.val = i;
        temp.size = 1;

        Arr.push_back(temp);
    }
}

ll root(ll i) {
    while(Arr.at(i).val != i) {
        Arr.at(i).val = Arr.at(Arr.at(i).val).val;
        i = Arr.at(i).val;
    }

    return i;
}

void WeightedUnion(ll a, ll b) {
    ll r_a = root(a);
    ll r_b = root(b);

    if(r_a == r_b) 
        return;

    if(Arr.at(r_a).size < Arr.at(r_b).size) {
        Arr.at(r_a).val = Arr.at(r_b).val;
        Arr.at(r_b).size +=  Arr.at(r_a).size;
    }
    else {
        Arr.at(r_b).val = Arr.at(r_a).val;
        Arr.at(r_a).size +=  Arr.at(r_b).size;
    }
    
}

ll Find(ll a, ll b) {
    return root(a) == root(b);
}

void doDfs(vector<CCnode>& Graph, int u, ll& count) {
    Graph.at(u).visited = true;
    ++count;

    for(const auto& i : Graph.at(u).l) {
        if(!Graph.at(i).visited)
            doDfs(Graph, i, count);
    }
}

bool checkDisconnected(vector<CCnode>& Graph) {
    ll count = 0;

    doDfs(Graph, 1, count);

    return !(++count == Graph.size());
}

ll Kruskal(vector<node>& Graph) {
    ll minCost = 0;

    for(auto& i : Graph) {

        if(!Find(i.edgde.first, i.edgde.second)) {
            WeightedUnion(i.edgde.first, i.edgde.second);
            minCost += i.weight;
        }    
    }

    return minCost;
}

int main() {
    ll n, m, k;
    cin>>n>>m>>k;

    vector<node> Graph(m+1);
    vector<CCnode> ConnectedGraph(n+1);

    init(n+1);

    unordered_map<ll, ll> map;

    for(ll i = 1; i <= k; ++i) {
        ll t;
        cin>>t;
        map[i] = t;
    }

    for(ll i = 1; i <= m; ++i) {
        ll x, y, t;
        cin>>x>>y>>t;

        ll w = 0;

        while(t--) {
            ll c;
            cin>>c;

            w += map.at(c);
        }

        Graph.at(i).weight = w;
        Graph.at(i).edgde = make_pair(x, y);

        ConnectedGraph.at(x).l.push_back(y);
        ConnectedGraph.at(y).l.push_back(x);
    }

     if(checkDisconnected(ConnectedGraph)) {
        cout<<"-1";
        return 0;
    }

    sort(Graph.begin(), Graph.end(), comparator);

    cout<<Kruskal(Graph)<<endl;
    
    return 0;
}

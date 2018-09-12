// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/

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

ll Kruskal(vector<node>& Graph, ll k) {
    ll minCost = 0;
    vector<ll> mst;

    for(auto& i : Graph) {

        if(!Find(i.edgde.first, i.edgde.second)) {
            WeightedUnion(i.edgde.first, i.edgde.second);
            minCost += i.weight;
            mst.push_back(i.weight);
        }    
    }

    if(minCost <= k)
        return 0;
    if(mst.size() > k)
        return -1;
    
    ll count = 0;

    for(ll it = mst.size()-1; it >= 0; --it) {
        if(minCost <= k)
            return count;
            
        minCost = minCost - mst.at(it) + 1;
        ++count;
    }

    return count;
}

int main() {
    ll nodes, edges, k;
    cin>>nodes>>edges>>k;

    vector<node> Graph(edges+1);
    vector<CCnode> ConnectedGraph(nodes+1);

    init(nodes+1);

    for(ll i = 1; i <= edges; ++i) {
        ll x, y, w;
        cin>>x>>y>>w;

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

    cout<<Kruskal(Graph, k);
    
    return 0;
}

// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/quantitative-coefficient/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    ll weight;
    pair<ll, ll> edgde;
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
    Arr.resize(n);

    for(ll i = 0; i < n; ++i) {
        Arr.at(i) = {i, 1};
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

const unsigned int M = 1000000007; 

ll Kruskal(vector<node>& Graph) {
    ll minCost = 1;

    for(ll j = 1; j < Graph.size(); ++j) {
        const node& i = Graph.at(j);

        if(!Find(i.edgde.first, i.edgde.second)) {
            WeightedUnion(i.edgde.first, i.edgde.second);
            minCost = (minCost * i.weight) % M;
        }    
    }

    return minCost;
}

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n, m;
        cin>>n>>m;

        init(n+1);
        vector<node> Graph(m+1);

        for(ll i = 1; i <= m; ++i) {
            ll x, y, w;
            cin>>x>>y>>w;

            Graph.at(i).weight = w;
            Graph.at(i).edgde = make_pair(x, y);
        }

        sort(Graph.begin()+1, Graph.end(), comparator);

        cout<<Kruskal(Graph)<<endl;
    }
    
    return 0;
}

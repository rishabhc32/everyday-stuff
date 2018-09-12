// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/monk-and-tree-1/

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
    return node1.weight > node2.weight;
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

ll Kruskal(vector<node>& Graph) {
    ll minCost = 0;

    for(ll j =1; j < Graph.size(); ++j) {
        const node& i = Graph.at(j);

        if(!Find(i.edgde.first, i.edgde.second)) {
            WeightedUnion(i.edgde.first, i.edgde.second);
        } 
        else 
            minCost += i.weight;   
    }

    for(int i = 1; i < Arr.size(); ++i) {
        if(i == Arr.at(i).val)
           ++minCost;
    }

    return minCost - 1LL;
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
            ll x, y;
            cin>>x>>y;

            Graph.at(i).weight = abs(x-y);
            Graph.at(i).edgde = make_pair(x, y);
        }

        sort(Graph.begin()+1, Graph.end(), comparator);
    
        cout<<Kruskal(Graph)<<endl;
    }
    
    return 0;
}

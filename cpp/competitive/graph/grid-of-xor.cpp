// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/grid-of-many-xors-de84b766/

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

ll Kruskal(vector<node>& Graph) {
    ll minCost = 0;

    for(ll j = 1; j < Graph.size(); ++j) {
        const node& i = Graph.at(j);

        if(!Find(i.edgde.first, i.edgde.second)) {
            WeightedUnion(i.edgde.first, i.edgde.second);
            minCost += i.weight;
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

        ll e = (2*n*m) - (n+m);

        ll r1, c1, r2, c2;
        cin>>r1>>r2>>c1>>c2;

        init((n*m)+1);
        vector<node> Graph(e+1);

        ll arr[n+1][m+1], cnt = 1;

        for(ll i = 1; i <= n; ++i) 
            for(ll j = 1; j <= m; ++j) 
                cin>>arr[i][j];

        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m-1; ++j) {
                ll node_no = ((i-1)*m) + j;

                Graph.at(cnt).weight = arr[i][j] ^ arr[i][j+1];
                Graph.at(cnt).edgde = make_pair(node_no, ((i-1)*m) + j+1);

                ++cnt;
            }
        }

        for(ll j = 1; j <= m; ++j) {
            for(ll i = 1; i <= n-1; ++i) {
                ll node_no = ((i-1)*m) + j;

                Graph.at(cnt).weight = arr[i][j] ^ arr[i+1][j];
                Graph.at(cnt).edgde = make_pair(node_no, ((i+1-1)*m) + j);

                ++cnt;
            }
        }

        sort(Graph.begin()+1, Graph.end(), comparator);

        cout<<Kruskal(Graph)<<endl;
    }
    
    return 0;
}

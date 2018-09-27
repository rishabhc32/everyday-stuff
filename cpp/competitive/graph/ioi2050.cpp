// Problem Statement -- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/ioi-2050-2/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    ll weight;
    pair<ll, ll> edgde;
};

struct CCnode {
    bool visited = false;
    vector< pair<ll, ll> > l;
};

struct el {
    ll val;
    ll size;
};

bool comparator(const node& node1, const node& node2) {
    return node1.weight < node2.weight;
}

vector<el> Arr(1001);

void init(ll n) {
    for(ll i = 0; i < n; ++i) {
        el temp;
        temp.val = i;
        temp.size = 1;

        Arr.at(i) = temp;
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

ll distArr[1001][1001];

void doDfs(vector<CCnode>& Graph, ll u, ll dist, const ll org) {
    Graph.at(u).visited = true;
    distArr[org][u] = dist;

    for(const auto& i : Graph.at(u).l) {
        if(!Graph.at(i.first).visited) {
            doDfs(Graph, i.first, dist+i.second, org);
        }
    }
}

void Kruskal(vector<node>& Graph, ll q, ll n) {
    vector<CCnode> mst(n+1);

    for(auto& i : Graph) {

        if(!Find(i.edgde.first, i.edgde.second)) {
            WeightedUnion(i.edgde.first, i.edgde.second);
            
            mst.at(i.edgde.first).l.push_back({i.edgde.second, i.weight});
            mst.at(i.edgde.second).l.push_back({i.edgde.first, i.weight});
        }    
    }

    memset(distArr, 0, (n+1)*(n+1)*sizeof(ll));

    
    for(ll i = 1; i <= n; ++i) {
        doDfs(mst, i, 0, i);
        for_each(mst.begin(), mst.end(), [](CCnode& i) {i.visited = false;} );
    }

    while(q--) {
        ll u, v;
        scanf("%lld %lld", &u, &v);

        printf("%lld\n", distArr[u][v]);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    scanf("%lld", &t);

    for(ll j = 1; j <= t; ++j) {
        ll n, p, m;
        scanf("%lld %lld %lld", &n, &p, &m);

        vector<node> Graph(p+1);

        init(n+1);

        for(ll i = 1; i <= p; ++i) {
            ll x, y, w;
            scanf("%lld %lld %lld", &x, &y, &w);

            Graph.at(i).weight = w;
            Graph.at(i).edgde = {x, y};
        }

        sort(Graph.begin(), Graph.end(), comparator);

       printf("Case: %lld\n", j);
        Kruskal(Graph, m, n);
    }
    
    return 0;
}

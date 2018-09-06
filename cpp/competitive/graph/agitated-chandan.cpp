// Problem Statment -- https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/agitated-chandan/editorial/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    bool visited = false;
    list< pair<ll, ll> > l;
};

void addEdge(vector<node>& Graph) {
    ll u, v, w;
    cin>>u>>v>>w;

    Graph.at(u).l.push_back(make_pair(v, w));
    Graph.at(v).l.push_back(make_pair(u, w));
}

ll dodfs(vector<node>& Graph, ll u, ll& Max) {
    Graph.at(u).visited = true;

    ll f_max = 0, s_max = 0;

    for(auto& i : Graph.at(u).l) {
        if(!Graph.at(i.first).visited) {
            ll ans = dodfs(Graph, i.first, Max);
            ans += i.second;

            if(ans > f_max) {
                s_max = f_max;
                f_max = ans;
            }
            else if(ans > s_max) 
                s_max = ans;
        }
    }

    Max = max(Max, s_max + f_max);
    return f_max;
}

ll get_cost(const ll& dist) {
    if(dist > 10000)
        return 10000;
    if(dist > 1000)
        return 1000;
    if(dist > 100)
        return 100;
    if(dist < 100)
        return 0;
} 

ll find_max(vector<node>& Graph) {
    ll Max = 0;

    dodfs(Graph, 1, Max);

    return Max;
}

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<node> Graph(n+1);
        --n;

        while(n--)
            addEdge(Graph);

        ll dist = find_max(Graph);
        ll cost = get_cost(dist);

        cout<<cost<<" "<<dist<<endl;
    }

    return 0;
}

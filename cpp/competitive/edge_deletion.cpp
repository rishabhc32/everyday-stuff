#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> value(100002);
vector<bool> visited (100002, false); 
ll k;
ll delete_num = 0;

ll DFS(ll node, vector< vector<ll> > &G) {
    visited[node] = true;
    ll sum = value.at(node);
    
    vector<ll> v;
    
    for (auto i = G[node].begin(); i != G[node].end(); ++i) {
        if (!visited.at(*i)) {
            ll curr_sum = DFS(*i, G);
            
            v.push_back(curr_sum);
        }
    }
    
    if(!v.empty()) {
        sort(v.begin(), v.end());
        
        for(ll i = 0; i < v.size(); ++i) {
            if(sum + v.at(i) <= k)
                sum += v.at(i);
            else {
                delete_num += (v.size() - i);
                break;
            }
        }
        
        
    }

    
    return sum;
}

int main() {
    ll n;
    
    cin>>n>>k;
    
    for(ll i = 1; i <= n; ++i) {
        cin>>value.at(i);
    }
    
    vector< vector<ll> > G(n+1);
    
    for(ll i = 0; i < n-1; ++i) {
        ll u, v;
        cin>>u>>v;
        
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    DFS(1, G);
    cout<<delete_num;
    
    return 0;
    
}
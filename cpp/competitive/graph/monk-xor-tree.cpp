#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    bool visited = false;
    ll value;
    list<ll> l;
};

void checkAndCopy(vector<ll>& A, vector<ll>& B, const ll& v, const ll& k, ll& count) {
    for(ll i : B) {
        ll p = i ^ v;
        if(p == k)
            ++count;
        
        A.push_back(p);
    }
}

vector<ll> doDfs(vector<node>& Graph, ll v, ll Xor, ll& count, const ll& k) {
    vector<ll>  currentCumulativeXor;

    currentCumulativeXor.push_back(Graph.at(v).value);
    if(Graph.at(v).value == k)
        ++count;
    
    Graph.at(v).visited = true;
    
    for(const int& i : Graph.at(v).l) {
        if(!Graph.at(i).visited) {
            vector<ll> copyVector = doDfs(Graph, i, Xor, count, k);
            checkAndCopy(currentCumulativeXor, copyVector, Graph.at(v).value, k, count);
        }
    }

    return currentCumulativeXor;
}

void printPairs(vector<node>& Graph, ll k) {
    ll count = 0;

    for(int i = 1; i < Graph.size(); ++i) {
        if(!Graph.at(i).visited)
            doDfs(Graph, i, 0, count, k);
    }

    cout<<count;
}

int main() {
    ll n, k;
    cin>>n>>k;

     vector<node> Graph(n+1);
    
    for(ll i = 1; i<= n; ++i) {
        ll t;
        cin>>t;

        Graph.at(i).value = t;
    }

    for(ll i = 1; i <= n-1; ++i) {
        ll t;
        cin>>t;

        Graph.at(t).l.push_back(i+1);
    }

    printPairs(Graph, k);

    return 0;
}

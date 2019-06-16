// Problem Statement -- https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-champions-league/

#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll  n,m;

    priority_queue<ll> q;

    cin>>m>>n;

    while(m--) {
        ll t;

        cin>>t;
        q.push(t);
    }

    ll sum = 0;

    while(n--) {
        ll t = q.top();

        sum += t;
        
        q.pop();
        q.push(--t);
    }

    cout<<sum<<endl;

    return 0;
}
// Poblem Statement -- https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-some-queries/

#include <iostream>
#include <set>

typedef long long ll;

using namespace std;

int main() {
    ll q;
    cin>>q;

    multiset<ll> s;

    while(q--) {
        ll x;
        cin>>x;

        if(x == 1) {
            ll n;
            cin>>n;

            s.insert(n);
        }
        else if(x == 2) {
            ll n;
            cin>>n;

            auto it = s.find(n);

            if(it == s.end())
                cout<<"-1\n";
            else   
                s.erase(it);
        }
        else if(x == 3)
            if(s.empty())
                cout<<"-1\n";
            else    
                cout<<*(--s.end())<<endl;

        else if(x == 4)
            if(s.empty())
                cout<<"-1\n";
            else    
                cout<<*s.begin()<<endl;
    }

    return 0;
}
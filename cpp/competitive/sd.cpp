#include <bits/stdc++.h>

using namespace std;

typedef double ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n, sd;
        cin>>n>>sd;

        if( (long long)n%2 == 0) {
            for(ll i=0 ; i < n/2; ++i)
                if(sd != 0)
                cout<<"-"<<sd<<" "<<sd<<" ";
                else cout<<"0 0 ";
        }
        else {
            ll  x = sd * sqrt(n/(n-1));
            cout<<"0 ";
        
            for(long long  i=0 ; i < (long long)n/2; ++i)
            if(x != 0)
                cout<<"-"<<x<<" "<<x<<" ";
            else cout<<"0 0 ";
        }
        cout<<endl;
    }

    return 0;
}
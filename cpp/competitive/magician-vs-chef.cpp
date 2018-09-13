#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n, x, s;
        cin>>n>>x>>s;

        while(s--) {
            ll a, b;
            cin>>a>>b;

            if(a == x)
                x = b;
            else if(b == x)
                x = a;
        }

        cout<<x<<endl;
    }

    return 0;
}

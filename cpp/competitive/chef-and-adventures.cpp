#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n, m, x, y;
        cin>>n>>m>>x>>y;

        if( (n-1) % x == 0 && (m-1) % y == 0)
            cout<<"Chefirnemo\n";
        else if( 2 > n || 2 > m )
            cout<<"Pofik\n";
        else if( (n-2) % x == 0 && (m-2) % y == 0 )
            cout<<"Chefirnemo\n";
        else    
            cout<<"Pofik\n";
    }

    return 0;
}
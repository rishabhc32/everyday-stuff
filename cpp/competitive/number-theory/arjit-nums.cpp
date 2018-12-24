#include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    ll M = 1000000007;
    ll d, x, y;
    void extendedEuclid(ll A, ll B) {
        if(B == 0) {
            d = A;
            x = 1;
            y = 0;
        }
        else {
            extendedEuclid(B, A%B);
            long long temp = x;
            x = y;
            y = temp - (A/B)*y;
        }
    }

    ll modpow(ll a,ll n,ll temp){
        ll res=1,y=a;
        
        while(n>0){
            if(n&1)
                res=(res*y)%temp;
            y=(y*y)%temp;
            n/=2;
        }

        return res%temp;
    }

    ll modInverse(ll A, ll M)
    {    
        extendedEuclid(A,M);
        return (x%M+M)%M;    //x may be negative
    }

    void f(const ll n) {
        ll arr[n];
        long long a[n-1];

        for(ll i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        
        for(ll i=n-2; i>=0; i--){
            a[i] = ((arr[i+1])*(modInverse(arr[i], M)%M))%M;
        }


        long long sum = 0;

        for(ll i = 0; i < n-1; ++i) {
            sum += (((a[i]%M * (a[i]+1)%M)%M)*(modInverse(2, M)%M))%M;
        }

        ll ans = (((sum%M * (sum+1)%M)%M)*(modInverse(2,M)%M))%M;
        cout<<ans<<endl;
    }

    int main() {
        ll t;
        cin>>t;

        while(t--) {
            ll n;
            cin>>n;
            f(n);
        }
    }
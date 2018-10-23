#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin>>t;
    
    while(t--) {
        ll n, k, hi, cnt;
        
        hi = 0;
        cnt = 0;
        
        cin>>n>>k;

        while(n--) {
            ll hf,hf_c;
            cin>>hf;
            hf_c = hf;

            if(hf - hi > k) 
                while(hf-hi > k) {
                    hf -= k;
                    ++cnt;
                } 
            hi = hf_c;
        }

        cout<<cnt<<endl;
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> arr(100002);

void solve(ll n, ll high) { 

  
    vector<ll> divisor(high+1, 0);
    vector< vector<ll> > index(high+1);

    for (ll i = 0; i < n; i++) {
        divisor[arr[i]]++; 
        index[arr[i]].push_back(i+1);
    }
       
  
    ll counter = 0;
    ll max_ans = -1;
  

    for (ll i = high; i >= 1; i--) { 
        ll j = i;
        counter = 0; 

        ll one = -1, two = -1;
        while (j <= high) {
            if(divisor[j] >=2) {
                one = index[j][0];
                two = index[j][index[j].size()-1];
                max_ans = max(j + llabs(two-one), max_ans) ; 
                counter++;

            }
               
  
            else if (divisor[j] == 1) {    
                counter++;      

                if(one > -1)
                    two = index[j][0];
                else
                    one =  index[j][0];
            }

            j += i;

            if (counter >= 2) {
                max_ans = max(i + llabs(two-one), max_ans) ;
            } 

        }
    } 

    cout<<max_ans<<endl;
} 

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;
        
        ll maxi = -1;
        for(ll i = 0; i < n; ++i) {
            cin>>arr[i];
            maxi = max(maxi, arr[i]);
        }

        solve(n, maxi);
    }
}
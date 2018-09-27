// INCOMPLETE

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void makeTree(ll tree[], ll start, ll end, ll index, ll arr[]) {
    if(start == end) {
        tree[index] = arr[start];
        return;
    }

    ll mid = (start + end) / 2;

    makeTree(tree, start, mid, 2*index+1, arr);
    makeTree(tree, mid+1, end, 2*index+2, arr);

    tree[index] = tree[2*index+1] & tree[2*index+2];
}

bool isPerfectSquare(long double x) {   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 

ll cnt = 0;

ll getMin(ll tree[], ll start, ll end, ll index, ll l, ll r) {
    if(l <= start && r >= end)
        return tree[index];
    
    if(r < start || l > end)
        return INT_MAX;
    

    int mid = (start + end) / 2;
    return min(
        getMin(tree, start, mid, 2*index+1, l, r),
        getMin(tree, mid+1, end, 2*index+2, l, r)
    );
}

int main() {
   ll t;
   cin>>t;

    while(t--) {
        ll n, q;
        cin>>n>>q;

        ll arr[n], tree[2*n-1];

        for(ll i = 0; i < n; ++i) {
            cin>>arr[i];
        }

        makeTree(tree, 0, n-1, 0, arr);

        while(q--) {
            ll l, r;
            ::cnt = 0;
            cin>>l>>r;

            getMin(tree, 0, n-1, 0, --l, --r);
            cout<<cnt<<endl;
        }
    }

    return 0;
}

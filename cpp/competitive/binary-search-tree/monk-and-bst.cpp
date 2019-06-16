//Problem Statement -- https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-bst/

#include <iostream>
#include <cmath>

#define ll long long
#define me_pow(x, n) (1ULL << n)

inline ll square(ll n) {
    // Base case
    if (n==0) return 0;
 
    // Get floor(n/2) using right shift
    ll x = n>>1;
 
    // If n is odd
    if (n&1)
        return ((square(x)<<2) + (x<<2) + 1);
    else // If n is even
        return (square(x)<<2);
}

using namespace std;
 
void printNode(ll t, ll x, ll k) {
    ll l = ceil( log((double)k + 1.0) / log(2.0) ), a;
 
    if(t - l == 0)
        a = x;
    else 
        a = x + me_pow(2, t-l-1) - 1;
        
    ll d = me_pow(2, t-l);
    ll n = k - me_pow(2, l-1) + 1;
 
    cout<<(a + (n-1)*d);
}
 
void printPath(ll start, ll end, ll& val, ll& x) {    
    ll mid = (start + end) / 2;
    ll temp = mid / 2;
 
    if(start >= end || x+temp == val)
        return;
 
    if(x+temp > val) {
        cout<<"l";
        printPath(start, mid-1, val, x);
    }
    
    else {
        cout<<"r";
        printPath(mid+1, end, val, x);
    }
    
}
 
ll findX(ll l, ll s) {
    double n = (me_pow(2, l) - 2) / 2;
    double x = ( (2*s) - (square(n) * 2) + 1) / ((2*n) + 1);
 
    ll t = ceil(++x)/2;

    return t;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll l, s, q;
 
    cin>>l>>s>>q;
 
    ll x = l == 1 ? s+1 : findX(l, s);
    
    while(q--) {
        ll type, k;
 
        cin>>type>>k;
 
        ll n = pow(2, l) - 1;
 
        if(type == 0) {
            if( ((n-1)/4)+x == k )
                cout<<"root";
            else {
                printPath(0, n-1, k, x);
            }
        }
        else
            printNode(l, x, k);
 
        cout<<endl;
    }
 
    return 0;
}

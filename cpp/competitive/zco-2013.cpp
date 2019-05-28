#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ll num, n;

    cin>> num;
    n = num - 1;
    
    vector<ll> arr(num);


    for(ll i = 0; i < num; ++i) {
        cin>>arr.at(i);
    }

    sort(arr.begin(), arr.end());

    ll sum = 0, last_sum = -arr.at(0);
    for(ll i = 1; i < num; ++i) {
        sum += ((i * arr.at(i)) + last_sum );
        last_sum += -arr.at(i);
    }

    cout<<sum;

    return 0;
}
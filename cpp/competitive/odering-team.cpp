#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct X {
    ll a, b, c;
};

void input(vector<X>& arr) {
    cin>>arr[0].a>>arr[0].b>>arr[0].c;
    cin>>arr[1].a>>arr[1].b>>arr[1].c;
    cin>>arr[2].a>>arr[2].b>>arr[2].c;
}

bool check(vector<X>& arr) {
    ll sub[3];

    sub[0] = arr[0].a - arr[1].a;
    sub[1] = arr[0].b - arr[1].b;
    sub[2] = arr[0].c - arr[1].c;

    if(sub[0] == 0 && sub[1] == 0 && sub[2] == 0)
        return false;

    if (!((sub[0] <= 0 && sub[1] <= 0 && sub[2] <= 0) || (sub[0] >= 0 && sub[1] >= 0 && sub[2] >= 0) ))
        return false;

    sub[0] = arr[0].a - arr[2].a;
    sub[1] = arr[0].b - arr[2].b;
    sub[2] = arr[0].c - arr[2].c;

    if(sub[0] == 0 && sub[1] == 0 && sub[2] == 0)
        return false;

    if (!((sub[0] <= 0 && sub[1] <= 0 && sub[2] <= 0) || (sub[0] >= 0 && sub[1] >= 0 && sub[2] >= 0) ))
        return false;

    sub[0] = arr[1].a - arr[2].a;
    sub[1] = arr[1].b - arr[2].b;
    sub[2] = arr[1].c - arr[2].c; 

   if(sub[0] == 0 && sub[1] == 0 && sub[2] == 0)
        return false;

    if (!((sub[0] <= 0 && sub[1] <= 0 && sub[2] <= 0) || (sub[0] >= 0 && sub[1] >= 0 && sub[2] >= 0) ))
        return false;

    return true;   
}

int main() {
    ll t;
    cin>>t;

    while(t--) {
        vector<X> arr(3);

        input(arr);

        if(check(arr))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#define front first
#define back second



using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
void flip_l_r(vector< pair<p, bool> >& s) {
    ll l, r;
    cin>>l>>r;

    for(ll i = l-1; i < (r-l)/2 ; ++i) {
        s[i].second = !s[i].second;
        s[r-l-i].second = !s[r-l-i].second;

        swap(s[i], s[r-l-i]);
    }
}

void flip_k(vector< pair<p, bool> >& s) {
    ll l = 1, r;
    cin>>r;

    for(ll i = l-1; i < (r-l)/2 ; ++i) {
        s[i].second = !s[i].second;
        s[r-l-i].second = !s[r-l-i].second;

        swap(s[i], s[r-l-i]);
    }
}

void prestige(vector< pair<p, bool> >& f, vector< pair<p, bool> >& s) {
    ll a, b, c, d;
    cin>>a>>b>>c>>d;

    ll i=c-1, j=a-1;
    ll sum=0;

    for( ; i < d && j < b; ++i,++j) {
        ll x, y;

        if(f[i].second == false) {
            x = f[i].first.front;
        }
        else {
             x = f[i].first.back;
        }

        if(f[j].second == false) {
            y = s[j].first.front;
        }
        else {
            y = s[j].first.back;
        }
        sum+= (x*y);
    }

    cout<<sum<<endl;
}

int main() {
    ll n, m;
    cin>>n>>m;

    vector< pair<p, bool> >f(n), s(n);

    for(ll i = 0; i < n; ++i) {
        cin>>s[i].first.front;
        s[i].second = false;
        s[i].second = false;
        f[i].first.front = 1;
    }

    
    for(ll i = 0; i < n; ++i) {
        cin>>s[i].first.back;
        f[i].first.back = -1;
    }

    while(m--) {
        ll p;
        cin>>p;

        if(p == 1) {
            flip_l_r(s);
        }
        if(p == 2) {
            flip_k(f);
        }
        if(p == 3) {
            prestige(f, s);
        }
    }

    return 0;
}
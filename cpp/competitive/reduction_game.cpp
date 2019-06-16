#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long *arr = new long long[n];
        for (long long i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for (long long i = 1; i < n; ++i)
        {
            if(min(arr[i-1], arr[i]) > k){
                arr[i] = arr[i] - (arr[i-1] - k);
                arr[i-1] = k;
            }
        }

        long long s = 0;
        for (long long i = 0; i < n; ++i)
        {
            s += arr[i];
        }

        cout << s << "\n";
    }
}
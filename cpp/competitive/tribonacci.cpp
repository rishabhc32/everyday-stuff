#include <iostream>

using namespace std;

void trib(int n) {
    int arr[n];

    arr[0] = arr[1] = 0;
    arr[2] = 1;

    for(int i = 3; i < n; ++i) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    for(auto& i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    trib(10);

    return 0;
}
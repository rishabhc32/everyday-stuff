// Problem Statement -- https://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void makeTree(int tree[], int start, int end, int index, int arr[]) {
    if(start == end) {
        tree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    makeTree(tree, start, mid, 2*index+1, arr);
    makeTree(tree, mid+1, end, 2*index+2, arr);

    tree[index] = min(tree[2*index+1], tree[2*index+2]);
}

int getMin(int tree[], int start, int end, int index, int l, int r) {
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
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int t[2*n-1];
    makeTree(t, 0, n-1, 0, arr);

    cout<<getMin(t, 0, n-1, 0, 1, 5)<<endl;

    return 0;
}
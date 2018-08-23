#include <iostream> 
#include <cstring>

using namespace std;

void update(int tree[], int n, int index, int val) {
    ++index;

    while(index <= n) {
        tree[index] += val;
        index += index & (-index);
    }
}

int getSum(int tree[], int index) {
    int sum = 0;

    ++index;

    while(index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }

    return sum;
}

int* construTree(int  arr[], int n) {
    int *tree = new int[n+1];
    memset(tree, 0, n+1);

    for(int i = 0 ; i < n ; ++i) 
        update(tree, n+1, i, arr[i]);

    return tree;
}

int main() {
    int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    int *tree = construTree(arr, n);
    
    cout<<getSum(tree, 5)<<endl;
    update(tree, n+1, 3, 6);

    cout<<getSum(tree, 5)<<endl;

    return 0;
}
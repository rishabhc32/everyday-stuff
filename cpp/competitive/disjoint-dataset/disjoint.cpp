// Problem Statement -- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/

#include <bits/stdc++.h>

using namespace std;

vector<int> Arr;

void init() {
    for(int i = 0; i < Arr.size(); ++i) {
        Arr.at(i) = i;
    }
}

int root(int i) {
    while(Arr.at(i) != i)
        i = Arr.at(i);
    
    return i;
}

void Union(int a, int b) {
    int r_a = root(a);
    int r_b = root(b);

    Arr.at(r_a) = r_b;
}

int Find(int a, int b) {
    return root(a) == root(b);
}

int main() {
    Arr = {0, 1, 2, 3, 4, 5};
    init();

    Union(1, 0);
    Union(0, 2);
    Union(3, 4);
    Union(1, 4);

    cout<<Find(1, 4)<<endl;
    cout<<Find(3, 5)<<endl;

    return 0;
}

// Problem Statement -- https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/

#include <bits/stdc++.h>

using namespace std;

struct el {
    int val;
    int size;
};

vector<el> Arr;

void init(int n) {
    for(int i = 0; i < n; ++i) {
        el temp;
        temp.val = i;
        temp.size = 1;

        Arr.push_back(temp);
    }
}

int root(int i) {
    while(Arr.at(i).val != i)
        i = Arr.at(i).val;
    
    return i;
}

void WeightedUnion(int a, int b) {
    int r_a = root(a);
    int r_b = root(b);

    if(Arr.at(r_a).size < Arr.at(r_b).size) {
        Arr.at(r_a).val = Arr.at(r_b).val;
        Arr.at(r_b).size +=  Arr.at(r_a).size;
    }
    else {
        Arr.at(r_b).val = Arr.at(r_a).val;
        Arr.at(r_a).size +=  Arr.at(r_b).size;
    }
    
}

int Find(int a, int b) {
    return root(a) == root(b);
}

int main() {
    init(6);

    WeightedUnion(0, 1);
    WeightedUnion(1, 2);
    WeightedUnion(3, 2);

    cout<<Find(0, 3)<<endl;
    cout<<Find(3, 5)<<endl;

    return 0;
}

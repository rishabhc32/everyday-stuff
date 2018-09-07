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

/*
int root(int i) {
    while(Arr.at(i).val != i)
        i = Arr.at(i).val;
    
    return i;
}
*/

// Root with path compression
int root(int i) {
    while(Arr.at(i).val != i) {
        Arr.at(i).val = Arr.at(Arr.at(i).val).val;
        i = Arr.at(i).val;
    }

    return i;
}

void WeightedUnion(int a, int b) {
    int r_a = root(a);
    int r_b = root(b);

    if(r_a == r_b) 
        return;

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

void printCCSize() {
    multiset<int> s;

    for(int i = 0; i < Arr.size(); ++i) {
        if(i == Arr.at(i).val)
            s.insert(Arr.at(i).size);
    }

    for(const auto& i : s)
        cout<<i<<" ";
    
    cout<<endl;
}

int main() {
    int n, m;
    cin>>n>>m;

    init(n);

    while(m--) {
        int a, b;
        cin>>a>>b;

        WeightedUnion(--a, --b);
        printCCSize();
    }

    return 0;
}

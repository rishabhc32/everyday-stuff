//Problem Statement -- https://www.geeksforgeeks.org/query-ancestor-descendant-relationship-tree/

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> make_map(int edges[][2], int i) {
    unordered_map<int, int> m;

    for(int j = 0 ; j < i ; ++j) {
        m[edges[j][1]] = edges[j][0];
    }

    return m;
}

void isAncestor(int edges[][2], const int size, const int badaBaap, const int child) {
    static unordered_map<int, int> m = make_map(edges, size);
    int immediate_parent = m.at(child);

    while( m.find(immediate_parent) != m.end() ) {
        immediate_parent = m.at(immediate_parent);

        if(immediate_parent == badaBaap) {
            cout<<"Yes"<<endl;
            return;
        }
    }

    cout<<"No"<<endl;
}

int main() {
    int edges[][2] = {
        { 0, 1 },
        { 0, 2 },
        { 1, 3 },
        { 1, 4 },
        { 2, 5 },
        { 4, 6 },
        { 5, 7 }
    };

    int size = sizeof(edges) / sizeof(edges[0]);

    isAncestor(edges, size, 1, 6);
    isAncestor(edges, size, 1, 7);

    return 0;
}

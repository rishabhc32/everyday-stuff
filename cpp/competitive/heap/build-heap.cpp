#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void print(const vector<int>& v) {
    for_each(v.begin()+1, v.end(), [](int a) {
        cout<<a<<" ";
    });

    cout<<endl;
}

void max_heapify(vector<int>& v, int i) {
    int left = 2*i;
    int right = 2*i + 1;
    int largest = i;

    if(left <= v.size()-1 && v.at(left) > v.at(i))
        largest = left;
    
    if(right <= v.size()-1 && v.at(right) > v.at(largest))
        largest = right;
    
    if(largest != i) {
        swap(v.at(i), v.at(largest));
        max_heapify(v, largest);
    }
}   

void buildHeap(vector<int>& v) {
    for(int i = (v.size()-1 / 2) ; i>=1 ; --i )
        max_heapify(v, i);
}

void insert(vector<int>& v, int key) {
    v.push_back(key);

    int i = v.size() - 1;

    while(i > 1 && v.at(i/2) < v.at(i)) {
        swap(v.at(i/2), v.at(i));
        i = i/2;
    }
}

void extract(vector<int>& v) {
    v.at(1) = v.at(v.size()-1);
    v.erase(v.end()-1);

    max_heapify(v, 1);
}

int main() {
    vector<int> v{INT_MIN, 1, 4, 3, 7, 8, 9, 10};

    buildHeap(v);
    print(v);

    insert(v,11);
    print(v);

    extract(v);
    print(v);

    return 0;
}

// Poblem Statement -- https://www.geeksforgeeks.org/maximum-unique-element-every-subarray-size-k/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> v{2, 4, 4, 2, 1};
    unordered_map<int, int> m;
    set<int, std::greater<int> > s;

    int k = 3, del_pos = 0, n = v.size();

    for(int i = 0 ; i < k-1 ; ++i) {
        m[v.at(i)]++;
        if(m[v.at(i)] == 1)
            s.insert(v.at(i));
    }

    for(int i = k-1 ; i < n ; ++i) {
        m[v.at(i)]++;

        if(m[v.at(i)] == 1)
            s.insert(v.at(i));
        else 
            s.erase(v.at(i));
        
        if(s.size() == 0)
            cout<<"Nothing\n ";
        else    
            cout<<*s.begin()<<" ";
        
        m[v.at(del_pos)]--;

        if(m[v.at(del_pos)] == 1)
            s.insert(v.at(del_pos));
        if(m[v.at(del_pos)] == 0)
            s.erase(v.at(del_pos));
        
        ++del_pos;
    }

    cout<<endl;
    return 0;
}

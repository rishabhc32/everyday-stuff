// Poblem Statement -- https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mirror-image-2/

#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> arr(2002, INT_MIN);

int main() {
    int n,q;

    cin>>n>>q;

    unordered_map <int, int> m, m_mirrror;
    arr[0] = 1;
    m[1] = 0;
    m_mirrror[1] = 0;
    
    for (int i = 1 ; i < n ; ++i) {
        int parent, child;
        char c;

        cin>>parent>>child>>c;

        if(c == 'R') {
            int index = (2 * m_mirrror.at(parent)) + 1;
            m_mirrror[child] = index;
            arr[index] = child;

            index = (2 * m.at(parent)) + 2;
            m[child] = index;
        }
        else if(c == 'L') {
            int index = (2 * m_mirrror.at(parent)) + 2;
            m_mirrror[child] = index;
            arr[index] = child;

            index = (2 * m.at(parent)) + 1;
            m[child] = index;
        }
    }

    for(int i = 0 ; i < q ; ++i) {
        int key;
        cin>>key;

        int ans = arr[m.at(key)];

        if(ans == INT_MIN) 
            cout<<"-1\n";
        else 
            cout<<ans<<endl;
        
    }

    return 0;
}
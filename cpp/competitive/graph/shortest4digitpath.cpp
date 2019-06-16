//Problem Statement -- https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/

#include <bits/stdc++.h>

using namespace std;

vector<int> Prime;

struct node {
    int visited = 0;
    list<int> l;
};

void addEdge(vector<node>& graph, int u, int v) {
    graph.at(u).l.push_back(v);
    graph.at(v).l.push_back(u);
}

void getPrime() {
    int n = 9999;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 1000; p <= n; p++)
        if (prime[p])
            Prime.push_back(p); 
}

bool compare(int i, int j) {
    string s1 = to_string(i);
    string s2 = to_string(j);

    int c = 0;
    
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;
 
    return (c == 1);
}

int bfs(vector<node>& Graph, int start, int end) {
    //Graph.at(start).visited = true;
    queue<int> q;
    q.push(start);

    Graph.at(start).visited = 1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int& i : Graph.at(v).l) {
            if(!Graph.at(i).visited) {
                Graph.at(i).visited = Graph.at(v).visited + 1;
                q.push(i);
            }
            if(i == end)
                return Graph.at(i).visited - 1;
        }
    }

}

int shortestPath(int num1, int num2) {
    getPrime();
    
    vector<node> Graph(Prime.size());

    int index_num1, index_num2;

    for(int i = 0; i < Prime.size(); ++i) {
        if(Prime.at(i) == num1)
            index_num1 = i;
        if(Prime.at(i) == num2)
            index_num2 = i;
        
        for(int j = i+1; j < Prime.size(); ++j) {
            if(compare(Prime.at(i), Prime.at(j)))
                addEdge(Graph, i, j);
        }
    }

    return bfs(Graph, index_num1, index_num2);
}

int main() {
    int num1 = 1033, num2 = 8179;

    cout << shortestPath(num1, num2)<<endl;

    return 0;
}
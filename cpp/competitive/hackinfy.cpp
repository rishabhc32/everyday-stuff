#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'solveMountain' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY mountain as parameter.
 */

int rows;
int cols;

struct comp {
    bool operator() ( pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
        return a.first >= b.first;
    }
};


void solve_for_one_node(vector<vector<int> > &mountain, vector<vector<int> > &value_vector, int ii, int jj) {
    priority_queue <pair<int , pair<int, int> >, vector< pair<int , pair<int, int> > >, comp > pq; 
    vector<vector<int> > visited(rows, vector<int>(cols));

    int i = ii, j = jj;
    visited[i][j] = true;

    while(true) {
        int cnt;
        cnt = 0;

        if(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            i = top.second.first;
            j = top.second.second;
        }

        if((i-1) >= 0 && visited[i-1][j] != true ) {
            visited[i-1][j] = true; 
            if (mountain[i-1][j] <= mountain[i][j]) {
                auto p1 = make_pair(i-1, j);
                auto p2 = make_pair(value_vector[i-1][j], p1);
                pq.push(p2);
                visited[i-1][j] = true;
                ++cnt;
            }
        }
        if((i+1) < rows && visited[i+1][j] != true ) {
            visited[i+1][j] = true;
                if(mountain[i+1][j] <= mountain[i][j]) {
                auto p1 = make_pair(i+1, j);
                auto p2 = make_pair(value_vector[i+1][j], p1);
                pq.push(p2);
                visited[i+1][j] = true;
                ++cnt;
            }
        }
        if((j-1) >= 0 && visited[i][j-1] != true ) {
            visited[i][j-1] = true;
            if(mountain[i][j-1] <= mountain[i][j]) {
                auto p1 = make_pair(i, j-1);
                auto p2 = make_pair(value_vector[i][j-1], p1);
                pq.push(p2);
                visited[i][j-1] = true;
                ++cnt;
            }
        }
        if((j+1) < cols && visited[i][j+1] != true ) {
            visited[i][j+1] = true;
            if(mountain[i][j+1] <= mountain[i][j]) {
                auto p1 = make_pair(i, j+1);
                auto p2 = make_pair(value_vector[i][j+1], p1);
                pq.push(p2);
                visited[i][j+1] = true;
                ++cnt;
            }
        }

        if(cnt <= 0) {
            value_vector[ii][jj] = value_vector[i][j];
            
            return;
        }
    }
    
}

vector<vector<int>> solveMountain(vector<vector<int>> mountain) {
    auto value_vector = mountain;
    rows = mountain.size();
    cols = mountain.at(0).size();

    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            solve_for_one_node(mountain, value_vector, i, j);
        }
    }
    
    return value_vector;
}

int main()
{

    string mountain_rows_temp;
    getline(cin, mountain_rows_temp);

    int mountain_rows = stoi(ltrim(rtrim(mountain_rows_temp)));

    string mountain_columns_temp;
    getline(cin, mountain_columns_temp);

    int mountain_columns = stoi(ltrim(rtrim(mountain_columns_temp)));

    vector<vector<int>> mountain(mountain_rows);

    for (int i = 0; i < mountain_rows; i++) {
        mountain[i].resize(mountain_columns);

        string mountain_row_temp_temp;
        getline(cin, mountain_row_temp_temp);

        vector<string> mountain_row_temp = split(rtrim(mountain_row_temp_temp));

        for (int j = 0; j < mountain_columns; j++) {
            int mountain_row_item = stoi(mountain_row_temp[j]);

            mountain[i][j] = mountain_row_item;
        }
    }

    vector<vector<int>> result = solveMountain(mountain);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

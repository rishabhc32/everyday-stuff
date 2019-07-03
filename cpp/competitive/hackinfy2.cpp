#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



const int M = 1000000007;
/*
 * Complete the 'drawingEdge' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int modularExponentiation(int x,int n)
{
    if(n<=0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2))%M;

}

int drawingEdge(int n) {
    int num = ((n%M) - (1%M) + M)%M;
    num = ((n%M) * (num%M)) % M;
    int two = (500000004%M);
    num = ((num%M) * two) % M;

    return modularExponentiation(2, num);
}

int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = drawingEdge(n);

    cout << result << "\n";


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

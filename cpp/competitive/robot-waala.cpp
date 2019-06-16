#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  long long val,T;
  bool flag = false;
  string str;

  cin>>T;

  while(T--)
  {
    cin>>str;

    val = -1;
    flag = false;

    for(long long i=0;i<str.length();i++)
    {
      if(str.at(i) != '.')
      {
          long long bada_val = (i - (int)(str.at(i) - '0'));
          bada_val = bada_val < 0 ? 0 : bada_val;
        if(bada_val > val)
        {
          val = i + (int)(str.at(i) - '0');
        }
        else
        {
          flag = true;
          break;
        }
      }
    }
    if(flag == true)
    {
      cout<<"unsafe"<<endl;
    }
    else
    {
      cout<<"safe"<<endl;
    }
  }

  return 0;
}
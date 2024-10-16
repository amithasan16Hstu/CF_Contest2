#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int x,y;
      cin>>x>>y;
      if(y*2>x)
      cout<<0<<endl;
      else
      cout<<x/(y*2)<<endl;
   }
}
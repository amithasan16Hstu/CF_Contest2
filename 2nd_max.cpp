#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int a,b,c;
      cin>>a>>b>>c;
      if((a>b && a<c) || (a<b && a>c))
      cout<<a<<endl;
      else if((b>a && b<c) || (b<a && b>c))
      cout<<b<<endl;
      else
      cout<<c<<endl;
   }

}
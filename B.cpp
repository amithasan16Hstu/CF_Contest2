#include <bits/stdc++.h>
using namespace std;
void Result()
{
   string str;
   cin >> str;
   int n = str.size();
   for (int j = 1; j < n; j++)
   {
      if (str[j] != str[j - 1])
      {
         swap(str[j], str[j- 1]);
         cout << "YES" << endl
              << str << endl;
         return;
      }
   }
   cout << "NO" << endl;
}
int main()
{
   int tst;
   cin >> tst;
   while (tst--)
   {
      Result();
   }
}
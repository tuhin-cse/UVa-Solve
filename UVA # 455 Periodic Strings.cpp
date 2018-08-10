#include <bits/stdc++.h>

using namespace std;

int solveZ(string s)
{
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;++i)
    {
       if(i<=r)
         z[i]=min(r-i+1,z[i-l]);
       while(i+z[i]<n && s[z[i]]==s[i+z[i]])
          ++z[i];
       if(i+z[i]-1>r)
         l=i , r=i+z[i]-1;
       if(i+z[i]==n && z[i]%i==0)
         return i;
    }
    return n;
}

int solveKMP(string s)
{
    int n=s.size(),c;
    vector<int> a(n);
    a[0]=0;
    for(int i=1;i<n;++i)
    {
       int j=a[i-1];
       while(j>0 && s[j]!=s[i])
          j=a[j];
       if(s[i]==s[j])
          j++;
       a[i]=j;
       if(j==1)
         c=i;
    }
    for(int i=0;i<n;i++)
       cout << a[i] << " ";
    cout << "c = " << c << endl;
    if(c+a[n-1]==n && a[n-1]%c==0)
      return c;
    return n;
}

int main()
{
    int n ;
    cin >> n ;
    string s;
    while(n-- && cin >> s)
       n==0 ?  cout << solveKMP(s) << "\n" : cout << solveKMP(s) << "\n\n";
    return 0;
}

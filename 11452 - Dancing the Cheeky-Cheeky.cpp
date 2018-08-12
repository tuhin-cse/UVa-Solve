#include <bits/stdc++.h>

using namespace std;

int solveKMP(string s)
{
    reverse(s.begin(),s.end());
    int n=s.size(),x=0;
    vector<int> a(n);
    a[0]=0;
    for(int i=1;i<n;++i)
    {
        int j=a[i-1];
        while(j>0 && s[j]!=s[i])
            j=a[j-1];
        if(s[i]==s[j])
            j++;
        a[i]=j;
        if(((a[i]*2)==(i+1)) && ((i+1)*3)>n)
            return a[i];
    }
    return n;
}
int solveZ(string s)
{
    reverse(s.begin(),s.end());
    int n=s.size();
    vector<int> z(n);
    for(int i=0,l=0,r=0;i<n;++i)
    {
        if(i<=r)
          z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
        {
            ++z[i];
        }
       if(i<=z[i] && i*3>n)
                return i;
        if(i+z[i]-1>r)
            l=i,r=i+z[i]-1;
    }

    return n;
}
int main()
{
    string s;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> s;
        int z = solveZ(s);
        string ss="";
        //cout << s.size() << " " << z << endl;
        for(int i=s.size()-z;i<s.size();i++)
            ss+=s[i];
        while(ss.size()<9)
            ss+=ss;
        for(int i=0;i<8;i++)
            cout << ss[i] ;
        cout << "..." << endl;
    }
    return 0;
}

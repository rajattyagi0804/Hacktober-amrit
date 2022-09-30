#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,c;
    cout<<"Enter the string :";
    cin>>s;
    cout<<"Enter the pattern to be searched :";
    cin>>c;
    int n,m,i,f=0,r,j;
    n=s.length();
    m=c.length();
    int map[26];
    for(j=0;j<26;j++)
     map[j]=m;
     m--;
    i=m;
    for(j=0;j<m;j++)
    {
        if(c[j]>='A' && c[j]<='Z')
         map[c[j]-'A']=m-j;
        else if(c[j]>='a' && c[j]<='z')
         map[c[j]-'a']=m-j;
    }
    
    while(i<=n)
    {
         r=0;
        while(r<=m && (s[i-r]==c[m-r])){
        r++;
        }
       // cout<<ctr<<" ";
        if(r==(m+1))
        {
            f=1;
            break;
        }
        if(s[i]=='_' || s[i]==' ')
        i+=(m+1);
        else if(s[i]>='a' && s[i]<='z')
        i+=map[s[i]-'a'];
        else if(s[i]>='A' && s[i]<='Z')
        i+=map[s[i]-'A'];
    }
    if(f==0)
    cout<<"\nPattern not found in the given string\n";
    else{
    cout<<"\nPattern found at starting index: "<<i-m<<" and ending index: "<<i<<" in the given string";
        cout<<s[i-m]<<"to"<<s[i];
    }
    return 0;
}

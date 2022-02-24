#include<bits/stdc++.h>
using namespace std;

int Solution::solve(vector<string> &s) {
    int n=s.length();
  int freq[26];
  memset(freq,0,sizeof(freq));
  for(int i=0;i<n;i++)
  {
      if(s[i]!=' ')
      {
          freq[s[i]-'a']++;
      }
  }
  int temp=0;
  for(int i=0;i<26;i++)
  {
      if(freq[i]==0)
      {
          temp=1;
          break;
      }
  }
  if(temp==1)
  {
      return 0;
  }
  else
  {
     return 1;
  }
}

#include<bits/stdc++.h>
using namespace std;

/* node for a trie */
struct trie{
  bool isLast; 
  trie* a[26];
  trie(){
      isLast=false;
      for(int i=0;i<26;i++)
      a[i]=NULL;
  }
};

/* insert a string */
void insert(string &s,trie* &root)
{
    trie *p=root;
    for(int i=0;i<s.size();i++)
    {
        int ind=s[i]-'a';
        if(!p->a[ind])
        p->a[ind]=new trie();
        
        p=p->a[ind];
    }
    p->isLast=true;
}
 
/* search a string*/
bool search(trie* &root,string &s)
{
    trie* p=root;
    for(int i=0;i<s.size();i++)
    {
        int ind=s[i]-'a';
        if(!p->a[ind])
        return false;
        else
        p=p->a[ind];
    }
    return p->isLast;
}

int main()
{
  
}

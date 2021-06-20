#include<bits/stdc++.h>
using namespace std;

/* struct for node of a trie */
struct trie{
  bool isLast; //true if a string is ending here
  trie* a[26]; //pointer to next 26 nodes (26 is no of alphabets)
  //making all pointers NULL in default constructor
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
bool search(string &s,trie* &root)
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
  trie* root=new trie();  //creating root node for tree
  
  //inserting strings
  insert("anant",root);
  insert("github",root);
  
  //searching strings
  bool ans=search("anant",root);
  
}

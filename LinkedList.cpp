#include <bits/stdc++.h>
using namespace std;

//node for linked list
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {} //constructor
};
 
typedef ListNode ln;

/*insert node at end of list in O(n)*/
void insertBack(ln* &head,int data)
{
	ln* temp=new ln(data);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	ln* p=head;
	while(p->next!=NULL)
	p=p->next;
    p->next=temp;
}

/*reverse a linked list*/
void reverse(ln* &A)
{
    ln* cur=A;
    ln* prev=NULL;
    while(cur!=NULL)
    {
        ln* temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    A=prev;
}

/*insertion sort for linked list in O(n*n)*/
void insertionSort(ListNode* &A) {
    ln* head=A;
    if(head==NULL)
    return A;
    A=A->next;
    head->next=NULL;
    while(A!=NULL)
    {
        ln* temp=A;
        A=A->next;
        ln* cur=head;
        ln* prev=NULL;
        while(cur!=NULL&&temp->val>cur->val)
        {
            prev=cur;
            cur=cur->next;
        }
        if(prev==NULL)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            temp->next=cur;
            prev->next=temp;
        }
    }
    A=head;
}

/*finding middle node of linked list in O(n)*/
/*returns (n/2)th element if n is even*/
ln* middle(ln* head)
{
    if(head==NULL)
    return NULL;
    ln* s=head,* f=head;
    while(f->next!=NULL&&f->next->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

/*merge used in merge sort*/
ln* merge(ln* a,ln* b)
{
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    
    ln* head=NULL;
    ln* cur=NULL;
    while(a!=NULL&&b!=NULL)
    {
        if(a->val>b->val)
        {
            if(head==NULL)
            {
                head=b;
                b=b->next;
                head->next=NULL;
                cur=head;
            }
            else
            {
                cur->next=b;
                cur=b;
                b=b->next;
                cur->next=NULL;
            }
        }
        else
        {
            if(head==NULL)
            {
                head=a;
                a=a->next;
                head->next=NULL;
                cur=head;
            }
            else
            {
                cur->next=a;
                cur=a;
                a=a->next;
                cur->next=NULL;
            }
        }
    }
    if(a==NULL)
    cur->next=b;
    else
    cur->next=a;
    return head;
}

/*merge sort for linked list in O(n*log(n))*/
void mergeSort(ListNode* &A){
    if(A==NULL||A->next==NULL)
    return;
    
    ln* mid=middle(A);
    ln* md=mid->next;
    mid->next=NULL;
    mergeSort(A);
    mergeSort(md);
    
    A = merge(A,md);
}

/* to detect cycle in list and return first node of cycle in O(2*n) */
ListNode* detectCycle(ListNode* A) {
    if(A==NULL)
    return A;
    ListNode* s=A->next,*f;
    if(s!=NULL)
    f=s->next;
    else
    return NULL;
    
    bool b=false;
    
    while(s!=NULL&&f!=NULL&&f->next!=NULL)
    {
        if(s==f)
        {
            b=true;
            break;
        }
        s=s->next;
        f=f->next->next;
    }
    if(!b)
    return NULL;
    
    f=A;
    
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    return f;
}

/*print linked list O(n)*/
void print(ln* head)
{
	ln* p=head;
	while(p!=NULL)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    
    ListNode* head=NULL;
    
    /*insertion*/
    insertBack(head,1);
    insertBack(head,5);
    insertBack(head,4);
    insertBack(head,3);
    insertBack(head,2);
    
    ln* mid=middle(head); //finding middle node
    cout<<mid->val<<"\n";  //printing middle value
    
    print(head);//printing all elements
    cout<<"\n";
    
    // mergeSort(head);
    // reverse(head);
    // insertionSort(head);

    print(head);
    return 0;        
}

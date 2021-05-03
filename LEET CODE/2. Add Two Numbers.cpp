#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;

struct ListNode {
      int val;
      ListNode *next;
  };

ListNode *root=NULL;
ListNode *l1 = NULL;
ListNode *l2 = NULL;

void append(int val)
{
	if(root==NULL) //If the list is empty
	{
		root=new ListNode();
		root->val=val;
		root->next=NULL;
	}
	else
	{
		ListNode *current_node=root; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		ListNode *newnode = new ListNode(); //create a new node
		newnode->val=val;
		newnode->next=NULL;
		current_node->next=newnode; //link the last node with new node
	}
}

void append1(int val)
{
	if(l1==NULL) //If the list is empty
	{
		l1=new ListNode();
		l1->val=val;
		l1->next=NULL;
	}
	else
	{
		ListNode *current_node=l1; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		ListNode *newnode = new ListNode(); //create a new node
		newnode->val=val;
		newnode->next=NULL;
		current_node->next=newnode; //link the last node with new node
	}
}
void print1()
{
		ListNode *current_node=l1;
		while(current_node!=NULL) //loop until you reach null
		{
			printf("%d\n",current_node->val);
			current_node=current_node->next;
		}
}

void append2(int val)
{
	if(l2==NULL) //If the list is empty
	{
		l2=new ListNode();
		l2->val=val;
		l2->next=NULL;
	}
	else
	{
		ListNode *current_node=l2; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		ListNode *newnode = new ListNode(); //create a new node
		newnode->val=val;
		newnode->next=NULL;
		current_node->next=newnode; //link the last node with new node
	}
}
void print2()
{
		ListNode *current_node=l2;
		while(current_node!=NULL) //loop until you reach null
		{
			printf("%d\n",current_node->val);
			current_node=current_node->next;
		}
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        ListNode *current_node1=l1;
        ListNode *current_node2=l2;
        int carry = 0;
		while(true) //loop until you reach null
		{
		    if(current_node1==NULL && current_node2==NULL)
                break;
            if(current_node1==NULL)
            {
                int x = current_node2->val+carry;
                carry = x/10;
                append(x%10);
                current_node2=current_node2->next;
            }
            else if(current_node2==NULL)
            {
                int x = current_node1->val+carry;
                carry = x/10;
                append(x%10);
                current_node1=current_node1->next;
            }
            else
            {
                int x = current_node1->val+current_node2->val+carry;
                carry = x/10;
                append(x%10);
                current_node1=current_node1->next;
                current_node2=current_node2->next;
            }

		}
		if(carry!=0)
            append(carry);
		return root;
    }

int main()
{
    FAST
    int n1, n2;
    cin>>n1;
    for(int i = 0;i<n1;i++)
    {
        int x;
        cin>>x;
        append1(x);
    }
    cin>>n2;
    for(int i = 0;i<n2;i++)
    {
        int x;
        cin>>x;
        append2(x);
    }
   // print1();
  //  print2();
    ListNode *x = addTwoNumbers(l1,l2);
    ListNode *current_node= x;
		while(current_node!=NULL) //loop until you reach null
		{
			printf("%d\n",current_node->val);
			current_node=current_node->next;
		}
    return 0;
}
/*
7
9 9 9 9 9 9 9
4
9 9 9 9
*/

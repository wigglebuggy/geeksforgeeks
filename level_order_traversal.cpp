#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

struct Node
{
	struct Node *left,*right;
	int data;
};
struct Node *newNode(int data)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
struct Node* insert(struct Node *node,int data)
{
	if(node == NULL)
	{
		return newNode(data);
	}
	if(node->data<data)
	{
		node->right=insert(node->right,data);
	}
	else
	{
		node->left=insert(node->left,data);
	}
	return node;
}
void inorder(struct Node *node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		printf("%d  ",node->data);
		inorder(node->right);
	}
}
int getHeight(struct Node *node)
{
	if(node==NULL)
	{
		return -1;
	}
	else
	{
		return (1 + max(getHeight(node->left),getHeight(node->right)));
	}
}
deque<Node*> q;
void LevelOrder(struct Node * root)
{
    if(root)
    {
    	q.pb(root);
    }
    while(!q.empty())
    {
    	struct Node *tree = q.front();
    	q.pop_front();
    	cout<< tree->data <<" ";
    	if(tree->left)
    	{
    		q.pb(tree->left);
    	}
    	if(tree->right)
    	{
    		q.pb(tree->right);
    	}
    }
}
int main()
{
    fast;
    struct Node *root=NULL;
    root=insert(root,3);
    insert(root,1);
    insert(root,2);
    insert(root,4);
    insert(root,5);
    insert(root,6);
    insert(root,7);
    inorder(root);
    printf("\n");
    printf("Height %d\n",getHeight(root));
    LevelOrder(root);
    printf("\n");
    return 0;
}
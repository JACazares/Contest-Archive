#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node
{
	ll val;
	Node *lchild, *rchild;
	
	Node()
	{
		val = 0;
		lchild = nullptr;
		rchild = nullptr;
	}
};

int N;
vi a;

Node* build ( Node* node, int l = 1, int r = N )
{
	if ( node == nullptr )
		node = new Node();
	
	if ( l == r )
	{
		node -> val = a[l];
		return node;
	}
	
	int mid = (l + r) / 2;
	node -> lchild = build ( node -> lchild, l, mid );
	node -> rchild = build ( node -> rchild, mid + 1, r );
	node -> val = node -> lchild -> val + node -> rchild -> val;
	return node;
}

Node* upd ( int pos, int x, Node* node, int l = 1, int r = N )
{
	if ( r < pos || pos < l )
		return node;
	if ( l == r )
	{
		auto tmp = new Node();
		tmp -> val = x;
		return tmp;
	}
	
	int mid = (l + r) / 2;
	auto tmp = new Node();
	tmp -> lchild = upd ( pos, x, node -> lchild, l, mid );
	tmp -> rchild = upd ( pos, x, node -> rchild, mid + 1, r );
	tmp -> val = tmp -> lchild -> val + tmp -> rchild -> val;
	return tmp;
}

ll qry ( int L, int R, Node* node, int l = 1, int r = N )
{
	if ( R < l || r < L )
		return 0;
	if ( L <= l && r <= R )
		return node -> val;
	
	int mid = (l + r) / 2;
	return qry ( L, R, node -> lchild, l, mid ) + qry ( L, R, node -> rchild, mid + 1, r );
}

int main ()
{
	int Q;
	cin >> N >> Q;
	a.resize ( N + 1 );
	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
	
	int type, K, l, r;
	vector < Node* > roots ( 1, new Node() );
	roots[0] = build ( roots[0] );
	for ( int i = 0; i < Q; i++ )
	{
		cin >> type >> K;
		if ( type == 1 )
		{
			cin >> l >> r;
			roots[K - 1] = upd ( l, r, roots[K - 1] );
		}
		else if ( type == 2 )
		{
			cin >> l >> r;
			cout << qry ( l, r, roots[K - 1] ) << "\n";
		}
		else if ( type == 3 )
			roots.push_back ( roots[K - 1] );
	}
	return 0;
}

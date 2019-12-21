#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node
{
	int val;
	Node *lchild, *rchild;
	
	Node()
	{
		val = 0;
		lchild = nullptr;
		rchild = nullptr;
	}

	Node(int x)
	{
		val = x;
		lchild = nullptr;
		rchild = nullptr;
	}
};

int N, Q;
vi a;

Node* build ( Node* node, int l = 1, int r = N )
{
	if ( node == nullptr )
		node = new Node();

	if ( l == r )
	{
		node -> val = 0;
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
	if ( pos < l || r < pos )
		return node;
	if ( l == r )
	{
		Node* tmp = new Node(x);
		return tmp;
	}
	
	int mid = (l + r) / 2;
	Node* tmp = new Node();
	tmp -> lchild = upd ( pos, x, node -> lchild, l, mid );
	tmp -> rchild = upd ( pos, x, node -> rchild, mid + 1, r );
	tmp -> val = tmp -> lchild -> val + tmp -> rchild -> val;
	return tmp;
}

int qry ( int L, int R, Node* node, int l = 1, int r = N )
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
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> Q;
	a.resize ( N + 1 );
	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
	
	map < int, int > freq;
	Node* roots[N + 1];
	roots[N] = new Node();
	roots[N] = build ( roots[N] );
	roots[N] = upd ( N, 1, roots[N] );
	freq[a[N]] = N;
	for ( int i = N - 1; i >= 1; i-- )
	{
		roots[i] = roots[i + 1];
		if ( freq[a[i]] != 0 )
			roots[i] = upd ( freq[a[i]], 0, roots[i] );
		roots[i] = upd ( i, 1, roots[i] );
		freq[a[i]] = i;
	}
	
	int l, r;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> l >> r;
		cout << qry ( l, r, roots[l] ) << "\n";
	}
	return 0;
}

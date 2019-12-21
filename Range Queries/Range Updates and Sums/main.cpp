#include <iostream>
#include <algorithm>
#include <vector>
#define VARS int mid = (l + r) / 2, lchild = 2*node + 1, rchild = 2*node + 2

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int N;
vi a, ST, lazy, dest;

void build ( int node = 0, int l = 1, int r = N )
{
	lazy[node] = 0;
	if ( l == r )
	{
		ST[node] = a[l];
		return;
	}
	
	VARS;
	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );
	ST[node] = ST[lchild] + ST[rchild];
}

void propagate ( int node, int l, int r )
{
	if ( dest[node] )
		ST[node] = 0;
	ST[node] += (r - l + 1) * lazy[node];
	if ( l != r )
	{
		VARS;
		if ( dest[node] )
			lazy[lchild] = 0, dest[lchild] = 1;
		lazy[lchild] += lazy[node];
		if ( dest[node] )
			lazy[rchild] = 0, dest[rchild] = 1;
		lazy[rchild] += lazy[node];
	}
	lazy[node] = 0;
	dest[node] = 0;
}

void upd1 ( int L, int R, int x, int node = 0, int l = 1, int r = N )
{
	propagate ( node, l, r );
	if ( L <= l && r <= R )
	{
		lazy[node] = x;
		propagate ( node, l, r );
		return;
	}
	
	if ( r < L || R < l )
		return;
	
	VARS;
	upd1 ( L, R, x, lchild, l, mid );
	upd1 ( L, R, x, rchild, mid + 1, r );
	ST[node] = ST[lchild] + ST[rchild];
}

void upd2 ( int L, int R, int x, int node = 0, int l = 1, int r = N )
{
	propagate ( node, l, r );
	if ( L <= l && r <= R )
	{
		dest[node] = 1;
		lazy[node] = x;
		propagate ( node, l, r );
		return;
	}
	
	if ( r < L || R < l )
		return;
	
	VARS;
	upd2 ( L, R, x, lchild, l, mid );
	upd2 ( L, R, x, rchild, mid + 1, r );
	ST[node] = ST[lchild] + ST[rchild];
}

ll qry ( int L, int R, int node = 0, int l = 1, int r = N )
{
	propagate ( node, l, r );
	if ( L <= l && r <= R )
		return ST[node];
	if ( r < L || R < l )
		return 0;
	
	VARS;
	return qry ( L, R, lchild, l, mid ) + qry ( L, R, rchild, mid + 1, r );
}

int main ()
{
	int Q;
	cin >> N >> Q;
	a.resize ( N + 1 );
	ST.resize ( 4*N + 5 );
	lazy.resize ( 4*N + 5 );
	dest.resize ( 4*N + 5 );

	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
	build();

	int type, l, r, x;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> type;
		if ( type == 1 )
		{
			//increase
			cin >> l >> r >> x;
			upd1 ( l, r, x );
		}
		else if ( type == 2 )
		{
			//set
			cin >> l >> r >> x;
			upd2 ( l, r, x );
		}
		else if ( type == 3 )
		{
			//sum
			cin >> l >> r;
			cout << qry ( l, r ) << "\n";
		}
	}
	return 0;
}

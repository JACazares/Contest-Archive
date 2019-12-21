#include <iostream>
#include <algorithm>
#include <vector>
#define VARS int mid = (l + r) / 2, lchild = 2*node + 1, rchild = 2*node + 2

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int N;
vi a, ST, lazy, lazy2;

ll sum ( ll x ) { return x * (x + 1) / 2; }

void build ( int node = 0, int l = 1, int r = N )
{
	lazy[node] = 0, lazy2[node] = 0;
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
	ST[node] += lazy2[node] * (sum(r) - sum(l - 1));
	ST[node] -= (r - l + 1) * lazy[node];
	if ( l != r )
	{
		VARS;
		lazy[lchild] += lazy[node];
		lazy2[lchild] += lazy2[node];

		lazy[rchild] += lazy[node];
		lazy2[rchild] += lazy2[node];
	}
	
	lazy[node] = 0;
	lazy2[node] = 0;
}

void upd ( int L, int R, int x, int node = 0, int l = 1, int r = N )
{
	propagate ( node, l, r );
	if ( R < l || r < L )
		return;
	if ( L <= l && r <= R )
	{
		lazy[node] += x;
		lazy2[node]++;
		propagate ( node, l, r );
		return;
	}
	
	VARS;
	upd ( L, R, x, lchild, l, mid );
	upd ( L, R, x, rchild, mid + 1, r );
	ST[node] = ST[lchild] + ST[rchild];
}

ll qry ( int L, int R, int node = 0, int l = 1, int r = N )
{
	propagate ( node, l, r );
	if ( R < l || r < L )
		return 0;
	if ( L <= l && r <= R )
		return ST[node];
	
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
	lazy2.resize ( 4*N + 5 );
	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
	build();
	
	int type, l, r;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> type;
		if ( type == 1 )
		{
			cin >> l >> r;
			upd ( l, r, l - 1 );
		}
		else if ( type == 2 )
		{
			cin >> l >> r;
			cout << qry ( l, r ) << "\n";
		}
	}
	return 0;
}

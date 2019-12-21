#include <iostream>
#include <algorithm>
#include <vector>
#define VARS int mid = (l + r) / 2, lchild = 2*node + 1, rchild = 2*node + 2

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 200005;

int N, a[MAXN], ST[4 * MAXN];

void build ( int node = 0, int l = 0, int r = N - 1 )
{
	if ( l == r )
	{
		ST[node] = a[l];
		return;
	}
	
	VARS;
	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );
	ST[node] = max ( ST[lchild], ST[rchild] );
}

void upd ( int pos, int x, int node = 0, int l = 0, int r = N - 1 )
{
	if ( pos < l || r < pos )
		return;
	if ( l == r )
	{
		ST[node] -= x;
		return;
	}
	
	VARS;
	upd ( pos, x, lchild, l, mid );
	upd ( pos, x, rchild, mid + 1, r );
	ST[node] = max ( ST[lchild], ST[rchild] );
}

int qry ( int x, int node = 0, int l = 0, int r = N - 1 )
{
	if ( ST[node] < x )
		return -1;
	if ( l == r )
		return l;
	
	VARS;
	int L = qry ( x, lchild, l, mid );
	if ( L != -1 )
		return L;
	else
		return qry ( x, rchild, mid + 1, r );
}

int main ()
{
	int M;
	cin >> N >> M;
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	build();
	for ( int i = 0; i < M; i++ )
	{
		int x;
		cin >> x;
		
		int aux = qry ( x );
		upd ( aux, x );
		cout << aux + 1 << " ";
	}
	cout << "\n";
	return 0;
}

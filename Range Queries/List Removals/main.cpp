#include <iostream>
#include <algorithm>
#include <vector>
#define VARS int mid = (l + r) / 2, lchild = 2*node + 1, rchild = 2*node + 2

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 200005;

int N, a[MAXN];
pii ST[4 * MAXN];

void build ( int node = 0, int l = 1, int r = N )
{
	if ( l == r )
	{
		if ( a[l] != 0 )
			ST[node] = {a[l], 1};
		else
			ST[node] = {a[l], 0};
		return;
	}
	
	VARS;
	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );
	ST[node].second = ST[lchild].second + ST[rchild].second;
}

void upd ( int pos, int node = 0, int l = 1, int r = N )
{
	if ( pos < l || r < pos )
		return;
	if ( l == r )
	{
		ST[node] = {0, 0};
		return;
	}

	VARS;
	upd ( pos, lchild, l, mid );
	upd ( pos, rchild, mid + 1, r );
	ST[node].second = ST[lchild].second + ST[rchild].second;
}

pii qry ( int x, int node = 0, int l = 1, int r = N )
{
	if ( l == r )
		return {l, ST[node].first};

	VARS;
	if ( x <= ST[lchild].second )
		return qry ( x, lchild, l, mid );
	else
		return qry ( x - ST[lchild].second, rchild, mid + 1, r );
}

int main ()
{
	cin >> N;
	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
	build();
	for ( int i = 0; i < N; i++ )
	{
		int x;
		cin >> x;
		pii aux = qry ( x );
		upd ( aux.first );
		cout << aux.second << " ";
	}
	cout << "\n";
	return 0;
}

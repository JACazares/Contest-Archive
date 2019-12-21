#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	int N, Q;
	cin >> N >> Q;
	int a[N];
	ll BIT[N];
	for ( int i = 1; i <= N; i++ )
		cin >> a[i], BIT[i] = 0;
	for ( int i = 0; i < Q; i++ )
	{
		int type;
		cin >> type;
		if ( type == 1 )
		{
			int l, r, x;
			cin >> l >> r >> x;
			for ( ; l <= N; l += (l & -l) )
				BIT[l] += x;
			for ( r++; r <= N; r += (r & -r) )
				BIT[r] -= x;
		}
		else if ( type == 2 )
		{
			ll x, upd = 0;
			cin >> x; 
			for ( int pos = x; pos; pos -= (pos & -pos) )
				upd += BIT[pos];
			cout << a[x] + upd << "\n";
		}
	}
	return 0;
}

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
	ll ST[2 * N];
	for ( int i = 0; i < N; i++ )
		cin >> ST[i + N];
	for ( int i = N - 1; i; i-- )
		ST[i] = min ( ST[2*i], ST[2*i + 1] );
	
	for ( int i = 0; i < Q; i++ )
	{
		int type, l, r;
		cin >> type;
		cin >> l >> r;
		if ( type == 1 )
		{
			ST[l+N-1] = r;
			for ( l = (l + N - 1)/2; l; l /= 2 )
				ST[l] = min ( ST[2*l], ST[2*l+1] );
		}
		else if ( type == 2 )
		{
			ll ans = (1LL << 60LL);
			for ( l += N - 1, r += N; l < r; l/=2, r/=2 )
			{
				if ( l & 1 )
					ans = min ( ans, ST[l++] );
				if ( r & 1 )
					ans = min ( ans, ST[--r] );
			}
			cout << ans << "\n";
		}
	}
	return 0;
}


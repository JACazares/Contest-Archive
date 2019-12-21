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
	vi a(N + 1), ST(2*N + 1);
	for ( int i = 0; i < N; i++ )
		cin >> ST[i + N];
	for ( int i = N - 1; i; i-- )
		ST[i] = min ( ST[2*i], ST[2*i + 1] );

	for ( int i = 0; i < Q; i++ )
	{
		int x, y;
		cin >> x >> y;
		int ans = (1 << 30);
		for ( int l = x + N - 1, r = y + N; l < r; l /= 2, r /= 2 )
		{
			if ( l & 1 )
				ans = min ( ans, ST[l++] );
			if ( r & 1 )
				ans = min ( ans, ST[--r] );
		}
		cout << ans << "\n";
	}
	return 0;
}

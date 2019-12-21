#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, Q;
	cin >> N >> Q;

	vi pre_map;
	int sal[N];
	for ( int i = 1; i <= N; i++ )
		cin >> sal[i], pre_map.push_back ( sal[i] );

	char type[Q];
	int a[N], b[N];
	for ( int i = 0; i < Q; i++ )
	{
		cin >> type[i] >> a[i] >> b[i];
		if ( type[i] == '?' )
		{
			pre_map.push_back ( a[i] );
			pre_map.push_back ( b[i] );
		}
		else if ( type[i] == '!' )
			pre_map.push_back ( b[i] );
	}
	sort ( pre_map.begin(), pre_map.end() );
	map < int, int > MP;
	int BIT[pre_map.size() + 1];
	for ( int i = 0; i < pre_map.size(); i++ )
		MP[pre_map[i]] = i + 1, BIT[i + 1] = 0;
	for ( int i = 1; i <= N; i++ )
	{
		sal[i] = MP[sal[i]];
		for ( int pos = sal[i]; pos <= pre_map.size(); pos += (pos & -pos) )
			BIT[pos]++;
	}
	for ( int i = 0; i < Q; i++ )
	{
		if ( type[i] == '?' )
		{
			a[i] = MP[a[i]];
			b[i] = MP[b[i]];
			
			ll ans = 0;
			for ( int pos = b[i]; pos; pos -= (pos & -pos) )
				ans += BIT[pos];
			for ( int pos = a[i] - 1; pos; pos -= (pos & -pos) )
				ans -= BIT[pos];
			cout << ans << "\n";
		}
		else if ( type[i] == '!' )
		{
			b[i] = MP[b[i]];
			for ( int pos = sal[a[i]]; pos <= pre_map.size(); pos += (pos & -pos) )
				BIT[pos]--;
			sal[a[i]] = b[i];
			for ( int pos = sal[a[i]]; pos <= pre_map.size(); pos += (pos & -pos) )
				BIT[pos]++;
		}
	}
	return 0;
}

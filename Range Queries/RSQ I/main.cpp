#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ll N, Q;
	cin >> N >> Q;
	ll a[N + 1], pre[N + 1];
	pre[0] = 0;
	for ( int i = 1; i <= N; i++ )
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	
	ll x, y;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> x >> y;
		cout << pre[y] - pre[x - 1] << "\n";
	}
	return 0;
}

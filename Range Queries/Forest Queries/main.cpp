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
	int pre[N + 1][N + 1];
	for ( int i = 0; i <= N; i++ )
		for ( int j = 0; j <= N; j++ )
			pre[i][j] = 0;
	char a;
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= N; j++ )
			cin >> a, pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (a == '*');
	
	int x1, y1, x2, y2;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << "\n";
	}
	return 0;
}

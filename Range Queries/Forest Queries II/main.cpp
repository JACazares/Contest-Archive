#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector < vi > BIT;

int qry ( int x, int y )
{
	int ans = 0;
	while ( x > 0 )
	{
		int pos = y;
		while ( pos > 0 )
		{
			ans += BIT[x][pos];
			pos -= (pos & -pos);
		}
		x -= (x & -x);
	}

	return ans;
}

int main ()
{
	int N, Q;
	cin >> N >> Q;
	int a[N + 1][N + 1];
	char c;
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= N; j++ )
			cin >> c, a[i][j] = (c == '*');
	
	BIT.resize ( N + 1, vi ( N + 1 ) );
	int x, y;
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= N; j++ )
			if ( a[i][j] == 1 )
			{
				x = i;
				while ( x <= N )
				{
					y = j;
					while ( y <= N )
					{
						BIT[x][y]++;
						y += (y & -y);
					}
					x += (x & -x);
				}
			}
	
	int pos, type;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> type;
		if ( type == 1 )
		{
			cin >> x >> y;
			int s = a[x][y];
			a[x][y] ^= 1;
			while ( x <= N )
			{
				pos = y;
				while ( pos <= N )
				{
					BIT[x][pos] += (s ? -1 : 1);
					pos += (pos & -pos);
				}
				x += (x & -x);
			}
		}
		else if ( type == 2 )
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << qry ( x2, y2 ) - qry ( x1-1, y2 ) - qry ( x2, y1-1 ) + qry ( x1-1, y1-1 ) << "\n";
		}
	}
	return 0;
}

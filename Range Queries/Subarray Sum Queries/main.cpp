#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct node
{
	int best = 0, pre = 0, suf = 0, tot = 0;
};

node combine ( node A, node B )
{
	node tmp;
	tmp.best = max ( A.suf + B.pre, max ( A.best, B.best ) );
	tmp.pre = max ( A.pre, A.tot + B.pre );
	tmp.suf = max ( B.suf, A.suf + B.tot );
	tmp.tot = A.tot + B.tot;
	return tmp;
}

int main ()
{
	int N, Q;
	cin >> N >> Q;
	int a[N];
	node ST[2*N + 5];
	for ( int i = 0; i < N; i++ )
	{
		cin >> a[i];
		ST[i + N].best = max ( a[i], 0 );
		ST[i + N].pre = max ( a[i], 0 );
		ST[i + N].suf = max ( a[i], 0 );
		ST[i + N].tot = a[i];
	}
	
	for ( int i = N - 1; i; i-- )
		ST[i] = combine ( ST[2*i], ST[2*i + 1] );

	for ( int i = 0; i < Q; i++ )
	{
		int pos, x;
		cin >> pos >> x;
		ST[pos + N - 1].best = max ( x, 0 );
		ST[pos + N - 1].pre = max ( x, 0 );
		ST[pos + N - 1].suf = max ( x, 0 );
		ST[pos + N - 1].tot = x;
		for ( pos = (pos + N - 1) / 2; pos; pos /= 2 )
			ST[pos] = combine ( ST[2*pos], ST[2*pos + 1] );

		node leftR, rightR;
		for ( int l = N, r = 2*N; l < r; l/=2, r/=2 )
		{
			if ( l & 1 )
				leftR = combine ( leftR, ST[l++] );
			if ( r & 1 )
				rightR = combine ( ST[--r], rightR );
		}
		
		cout << combine(leftR, rightR).best << "\n";
	}
	return 0;
}

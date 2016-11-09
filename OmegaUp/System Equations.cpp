#include <iostream>
#include <cstdio>
using namespace std;
int x, x1, y1, r1, x2, y2, r2, y, r, g1, g2, c;
char c1, c2;

int GCD(int a, int b)
{
	if(b == 0)
		return a;
	return GCD(b, a%b);
}

int main()
{
	scanf("%dx %dy = %d", &x1, &y1, &r1);
	scanf("%dx %dy = %d", &x2, &y2, &r2);
	g1 = GCD(x1, GCD(y1, r1));
	g2 = GCD(x2, GCD(y2, r2));
	x1/= g1;
	y1/= g1;
	r1/= g1;
	x2/= g2;
	y2/= g2;
	r2/= g2;
	x = x1;
	x1*= x2;
	y1*= x2;
	r1*= x2;
	x2*= x;
	y2*= x;
	r2*= x;
	if((x1 > 0 && x2 > 0) || (x1 < 0 && x2 < 0))
	{
		x1*= -1;
		y1*= -1;
		r1*= -1;
	}
	y = y1+y2;
	r = r1+r2;
	r/= y;
	y/= y;
	y = r;
	c = (y1*y);
	r1-= c;
	r1 /= x1;
	cout << "(" << r1 << ", " << y << ")";
}

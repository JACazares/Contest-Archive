#include <iostream>
using namespace std;
int T, N, X, Y, A, x1, x2, y1, y2;
int BIT[1025][1025];

void UpdateY(int x, int y, int a){
	while(y <= N) {
		BIT[x][y]+= a;
		y+= (y&-y);
	}
}

void UpdateX(int x, int y, int a) {
	while(x <= N) {
		UpdateY(x, y, a);
		x+= (x&-x);
	}
}

int LookupY(int x, int y) {
	if(y < 1)
		return 0;
	int sum=0;
	while(y > 0) {
		sum+= BIT[x][y];
		y-= (y&-y);
	}
	return sum;
}


int LookupX(int x, int y) {
	if(x < 1)
		return 0;
	int sum=0;
	while(x > 0) {
		sum+= LookupY(x, y);
		x-= (x&-x);
	}
	return sum;
}

int LookupRange() {
	return LookupX(x2+1, y2+1) - LookupX(x2+1, y1) - LookupX(x1, y2+1) + LookupX(x1, y1);
}

int main () {
	while(T != 3) {
		cin >> T;
		if(T == 0) {
			cin >> N;
		} else if(T == 1) {
			cin >> X >> Y >> A;
			UpdateX(X+1, Y+1, A);
		} else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << LookupRange() << "\n";
		}
	}
	return 0;
}

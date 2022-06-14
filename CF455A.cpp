

#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1e5 + 9;

long long _myArray[MAXN];
long long _dpMap[MAXN][9];

void CparseIn () {
	
	int maxi = 0;
	int curInt = 0;
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curInt;
		
		_myArray[curInt] += curInt;
	}
	
}

void Core () {
	
	for (int i = 1; i < 1e5 + 1; i++) {
		_dpMap[i][0] = max(_dpMap[i - 1][0], _dpMap[i - 1][1]);
		_dpMap[i][1] = _dpMap[i - 1][0] + _myArray[i]; 
	}
	
}

void CwriteOut () {
	
	cout << max(_dpMap[(int) 1e5][0], _dpMap[(int) 1e5][1]) << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
}

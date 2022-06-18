

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 9;

int _myArray[MAXN];
int _dpMap[MAXN][9][9];

void CparseIn () {
	
	int maxi = 0;
	int curInt = 0;
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curInt;
		
		_myArray[curInt]++;
	}
	
}

void Core () {
	
	memset(_dpMap, 0x80, sizeof(_dpMap));
	
	_dpMap[0][0][0] = 0;
	 
	for (int i = 1; i < (int) 1e5 + 3; i++) {
		for (int a = 0; a < 3; a++) {
			for (int m = 0; m < 3; m++) {
				for (int k = 0; k < 3; k++) {
					if (_myArray[i] > a + m + k - 1) {
						_dpMap[i][m][k] = max(_dpMap[i][m][k], _dpMap[i - 1][a][m] + k + (_myArray[i] - a - m - k) / 3);
					}
				}
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[(int) 1e5 + 2][0][0] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut(); 
	return 0;
	
} 

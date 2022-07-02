

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _count = 0;
int _num = 0;
int _myMap[209][209];
int _dpMap[209][209][209];
int _res = 0;

void CparseIn () {
	
	cin >> _maxi >> _count >> _num;
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = 1; m < i + 1; m++) {
			cin >> _myMap[i][m];
		}
	}
	
}

void Core () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = 1; m < i + 1; m++) {
			for (int k = 0; k < _count + 1; k++) {
				_dpMap[i][m][k] = max(_dpMap[i - 1][m][k], _dpMap[i - 1][m - 1][k]) + _myMap[i][m];
				
				if (k) {
					_dpMap[i][m][k] = max(_dpMap[i][m][k], max(_dpMap[i - 1][m][k - 1], _dpMap[i - 1][m - 1][k - 1]) + _num);
				}
				
				if (i == _maxi) {
					_res = max(_res, _dpMap[i][m][k]);
				}
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _res << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

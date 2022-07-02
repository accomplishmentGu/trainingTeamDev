

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _maxi = 0;
int _num = 0;
int _myArray[2009];
int _dpMap[2009][1009];

void CparseIn () {
	
	cin >> _maxi >> _num;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _myArray[i];
	}
	
}

void Core () {
	
	memset(_dpMap, 0x80, sizeof(_dpMap));
	
	_dpMap[0][0] = 0;
	
	for (int i = 1; i < _maxi + 1; i++) {
		if (i == 1) {
			_dpMap[1][1] = _myArray[i];
		}
		
		for (int m = 0; m < _num + 1; m++) {
			_dpMap[i][m] = max(_dpMap[i][m], _dpMap[i - 1][m]);
			
			if (m && i > 1) {
				_dpMap[i][m] = max(_dpMap[i][m], _dpMap[i - 2][m - 1] + _myArray[i]);
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[_maxi][_num] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

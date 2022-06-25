

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _line = 0;
int _cell = 0;
int _myMap[109][109];
int _dpMap[109][109][109];
int _suffixMap[109][109][109];
int _res = 0x80808080;

void CparseIn () {
	
	cin >> _line >> _cell;
	
	for (int i = 1; i < _line + 1; i++) {
		for (int m = 1; m < _cell + 1; m++) {
			cin >> _myMap[i][m];
			
			_myMap[i][m] += _myMap[i][m - 1]; 
		}
	}
	
}

void Core () {
	
	memset(_dpMap, 0x80, sizeof(_dpMap));
	memset(_dpMap[0], 0, sizeof(_dpMap[0]));
	memset(_suffixMap, 0x80, sizeof(_suffixMap));
	memset(_suffixMap[0], 0, sizeof(_suffixMap[0]));
	
	for (int i = 1; i < _line + 1; i++) {
		for (int L = 1; L < _cell + 1; L++) {
			for (int R = _cell; R > L - 1; R--) {
				for (int k = 1; k < L + 1; k++) {
					if (k == L) {
						_dpMap[i][L][R] = max(_dpMap[i][L][R], _suffixMap[i - 1][k][R + 1] + _myMap[i][R] - _myMap[i][L - 1]); 
					}
					
					if (k != L) {
						_dpMap[i][L][R] = max(_dpMap[i][L][R], _suffixMap[i - 1][k][R] + _myMap[i][R] - _myMap[i][L - 1]); 
					}
					
					_suffixMap[i][L][R] = max(_suffixMap[i][L][R + 1], _dpMap[i][L][R]);
					
					if (i == _line) {
						_res = max(_res, _dpMap[i][L][R]); 
					}
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

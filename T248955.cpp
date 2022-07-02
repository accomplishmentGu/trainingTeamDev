

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _myArray[609];
int _dpMap[609][609];
int _dpMap2[609][609];

void CparseIn () {
	
	cin >> _maxi;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _myArray[i];
		
		_myArray[i] += _myArray[i - 1];
	}
	
}

void Core () {
	
	for (int len = 2; len < _maxi + 1; len++) {
		for (int L = 1; L + len - 1 < _maxi + 1; L++) {
			int R = L + len - 1;
			
			for (int k = L; k < R; k++) {
				_dpMap[L][R] = max(_dpMap[L][R], _dpMap2[L][k] + _dpMap[k + 1][R] + (L != k && _myArray[k] - _myArray[L - 1] == _myArray[R] - _myArray[k] ? _myArray[R] - _myArray[k] : 0));
				_dpMap[L][R] = max(_dpMap[L][R], _dpMap[L][k] + _dpMap[k + 1][R]);
				_dpMap2[L][R] = max(_dpMap2[L][R], _dpMap[L][k] + _dpMap[k + 1][R]);
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[1][_maxi] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

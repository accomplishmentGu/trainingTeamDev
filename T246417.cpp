

#include <iostream>
#include <fstream>

using namespace std;

int _line = 0;
int _cell = 0;
int _myMap[309][309];
int _dpMap[309][309];
int _res = 0;

void CparseIn () {
	
	cin >> _line >> _cell;
	
	for (int i = 1; i < _line + 1; i++) {
		for (int m = 1; m < _cell + 1; m++) {
			cin >> _myMap[i][m];
		}
	}
	
}

void Core () {
	
	for (int i = 1, len = _cell; i < _line + 1; i++, len--) {
		int sumArray[309] = {0};
		
		for (int m = 1; m < _cell + 1; m++) {
			sumArray[m] = sumArray[m - 1] + _myMap[i][m];
		}
		
		for (int L = 1; L + len - 1 < _cell + 1; L++) {
			int R = L + len - 1;
			 
			_dpMap[i][L] = max(_dpMap[i - 1][L - 1], _dpMap[i - 1][L]) + sumArray[R] - sumArray[L - 1];
			
			if (i == _line) {
				_res = max(_res, _dpMap[i][L]);
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

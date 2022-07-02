

#include <iostream>
#include <fstream>

using namespace std;

int _line = 0;
int _cell = 0;
int _myMap[2009][2009];
int _suffixMap[2009][2009];
int _dpMap[2009][2009];
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
	
	for (int i = 1; i < _line + 1; i++) {
		int last = 0x80808080;
		
		for (int m = _cell; m > 0; m--) {
			_suffixMap[i][m] = _suffixMap[i][m + 1] + _myMap[i][m];
		}
		
		for (int m = 1; m < _cell + 2; m++) {
			last = max(last, _dpMap[i - 1][m]);
			_dpMap[i][m] = last + _suffixMap[i][m];
			
			if (i == _line) {
				_res = max(_res, _dpMap[i][m]);
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

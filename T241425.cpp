

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _myMap[509][509];
int _myArray[509];
int _dpArray[509];
int _energy[509];
int _line = 0;
int _cell = 0;
int _num = 0;

void CparseIn () {
	
	cin >> _line >> _cell >> _num;
	
	memset(_myMap, 0x3f, sizeof(_myMap));
	memset(_dpArray, 0x3f, sizeof(_dpArray));
	
	_dpArray[0] = 0;
	
	for (int i = 1; i < _line + 1; i++) {
		string theStr = "";
		int starti = _cell + 1;
		int endi = 0;
		
		cin >> theStr;
		
		for (int m = 0; m < theStr.length(); m++) {
			_myArray[m + 1] = _myArray[m] + theStr[m] - '0';
			
			if (theStr[m] == '1') {
				starti = min(starti, m + 1);
				endi = max(endi, m + 1);
			}
		}
		
		if (starti == _cell + 1) {
			_energy[i] = 0;
		}
		
		if (starti != _cell + 1) {
			_energy[i] = endi - starti + 1;
		}
		
		_dpArray[0] += _energy[i];
		_myMap[i][_myArray[_cell]] = 0;
		
		for (int L = 1; L < _cell + 1; L++) {
			for (int R = L; R < _cell + 1; R++) {
				_myMap[i][_myArray[_cell] - (_myArray[R] - _myArray[L - 1])] = min(_myMap[i][_myArray[_cell] - (_myArray[R] - _myArray[L - 1])], R - L + 1);
			}
		}
	}
	
}

void Core () {
	
	for (int i = 1; i < _line + 1; i++) {
		for (int m = _num; m > -1; m--) {
			for (int k = 1; k < min(_cell, m) + 1; k++) {
				_dpArray[m] = min(_dpArray[m], _dpArray[m - k] - (_energy[i] - _myMap[i][k]));
			}
		}
	}
	
}

void CwriteOut ()  {
	
	cout << _dpArray[_num] << '\n';
	
} 

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
}

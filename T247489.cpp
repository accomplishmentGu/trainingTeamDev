

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _maxi = 0;
int _num = 0;
int _myArray[309];
int _sumArray[309];
int _dpMap[309][309]; 

void CparseIn () {
	
	cin >> _maxi >> _num;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _myArray[i];
	}
	
}

int Calculate (int left, int right) {
	
	int mid = (left + right) / 2;
	
	return _myArray[mid] * (mid - left + 1) - (_sumArray[mid] - _sumArray[left - 1]) + (_sumArray[right] - _sumArray[mid]) - _myArray[mid] * (right - mid);
	
} 

void Core () {
	
	memset(_dpMap, 0x3f, sizeof(_dpMap));
	
	_dpMap[0][0] = 0;
	
	for (int i = 1; i < _maxi + 1; i++) {
		_sumArray[i] = _sumArray[i - 1] + _myArray[i];
		
		for (int m = 1; m < min(i, _num) + 1; m++) {
			for (int k = 0; k < i; k++) {
				_dpMap[i][m] = min(_dpMap[i][m], _dpMap[k][m - 1] + Calculate(k + 1, i));
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

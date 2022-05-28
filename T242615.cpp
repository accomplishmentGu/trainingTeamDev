

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _time = 0;
int _maxi = 0;
int _count2[209];
int _count5[209];
int _dpMap[209][29 * 209];
int _num = 0;
int _res = 0;

void CparseIn () {
	
	int curInt = 0;
	
	cin >> _maxi >> _time;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> curInt;
		
		while (curInt % 2 == 0) {
			_count2[i]++;
			curInt /= 2;
		}
		
		while (curInt % 5 == 0) {
			_count5[i]++;
			curInt /= 5;
		}
		
		_num += _count5[i];
	}
	
} 

void Core () {
	
	memset(_dpMap, 0x80, sizeof(_dpMap));
	
	_dpMap[0][0] = 0;
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = _time; m > 0; m--) {
			for (int k = _num; k > _count5[i] - 1; k--) {
				_dpMap[m][k] = max(_dpMap[m][k], _dpMap[m - 1][k - _count5[i]] + _count2[i]);
			}
		}
	}
	
	for (int i = 0; i < _num + 1; i++) {
		_res = max(_res, min(i, _dpMap[_time][i]));
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

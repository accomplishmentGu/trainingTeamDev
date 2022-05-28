

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int _maxi = 0;
int _time = 0;
int _num = 0;
int _timeMap[109][109];
long long _weightMap[109][109];
long long _dpArray[109];

void CparseIn () {
	
	cin >> _maxi >> _num >> _time;
	
	memset(_dpArray, 0x80, sizeof(_dpArray));
	_dpArray[0] = 0;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _weightMap[i][0];
		
		_dpArray[0] += _weightMap[i][0];
	}
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = 1; m < _num + 1; m++) {
			cin >> _timeMap[i][m];
		}
	}
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = 1; m < _num + 1; m++) {
			cin >> _weightMap[i][m];
			
			_weightMap[i][m] = -_weightMap[i][m] - _weightMap[i][0];
		}
	}
	
}

void Core () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = _time; m > -1; m--) {
			for (int k = 1; k < _num + 1; k++) {
				_dpArray[min(_time, m + _timeMap[i][k])] = max(_dpArray[min(_time, m + _timeMap[i][k])], _dpArray[m] + _weightMap[i][k]);
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpArray[_time] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	 
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 



#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int _myArray[209];
int _sumArray[209];
int _dpMinMap[209][209];
int _dpMaxMap[209][209];
int _resMin = 1e9;
int _resMax = 0;

void CparseIn () {
	
	cin >> _maxi;
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _myArray[i];
		
		_myArray[i + _maxi] = _myArray[i];
	}	
	
}

void Core () {
	
	for (int i = 1; i < _maxi * 2 + 1; i++) {
		_sumArray[i] = _sumArray[i - 1] + _myArray[i];
	}
	
	for (int i = 2; i < _maxi + 1; i++) {
		for (int L = 1; L + i - 1 < _maxi * 2 + 1; L++) {
			int R = L + i - 1;
			
			_dpMinMap[L][R] = 1e9;
			
			for (int k = L; k < R; k++) {
				_dpMinMap[L][R] = min(_dpMinMap[L][R], _dpMinMap[L][k] + _dpMinMap[k + 1][R] + _sumArray[R] - _sumArray[L - 1]);
				_dpMaxMap[L][R] = max(_dpMaxMap[L][R], _dpMaxMap[L][k] + _dpMaxMap[k + 1][R] + _sumArray[R] - _sumArray[L - 1]);
			}
			
			if (i == _maxi) {
				_resMin = min(_resMin, _dpMinMap[L][R]);
				_resMax = max(_resMax, _dpMaxMap[L][R]); 
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _resMin << '\n';
	cout << _resMax << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

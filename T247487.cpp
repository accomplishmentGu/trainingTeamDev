

#include <iostream>
#include <fstream>

using namespace std;

const int mod = 1e9 + 7;

int _maxi = 0;
int _dpMap[409][80009];

void CparseIn () {
	
	cin >> _maxi;
	
}

void Core () {
	
	_dpMap[0][0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		long long myArray[80009];
		
		myArray[0] = _dpMap[i - 1][0];
		
		for (int m = 1; m < _maxi * (_maxi - 1) / 2 + 1; m++) {
			myArray[m] = (myArray[m - 1] + _dpMap[i - 1][m]) % mod;
		}
		
		for (int m = 0; m < _maxi * (_maxi - 1) / 2 + 1; m++) {
			_dpMap[i][m] = (myArray[m] - myArray[m - i] + mod) % mod;
		}
	}
	
} 

void CwriteOut () {
	
	for (int i = 0; i < _maxi * (_maxi - 1) / 2 + 1; i++) {
		cout << _dpMap[_maxi][i] << '\n';
	}
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	 
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

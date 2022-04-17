

#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 3e6 + 9;

int _maxi = 0;
long long _mod = 0;
long long _facArray[MAXN];
long long _invArray[MAXN]; // _invArray[i] -> inverse of i!

long long QuickPow (long long base, long long index, long long mod) {
	
	long long res = 1;
	
	while (index) {
		if (index & 1) {
			res = (res * base) % mod;
		}
		 
		base = (base * base) % mod;
		index >>= 1;
	}
	
	return res;
	
}

void CparseIn () {
	
	cin >> _maxi >> _mod;
	
}

void Core () {
	
	_facArray[0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		_facArray[i] = _facArray[i - 1] * i % _mod;
	}
	
	_invArray[_maxi] = QuickPow(_facArray[_maxi], _mod - 2, _mod);
	
	for (int i = _maxi - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * (i + 1) % _mod; 
	}
	
}

void CwriteOut () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		cout << _facArray[i - 1] * _invArray[i] % _mod << '\n';
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

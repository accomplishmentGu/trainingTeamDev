

#include <iostream>
#include <fstream>

using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 9;

int _num = 0;
int _maxi = 0;
long long _facArray[MAXN];
long long _invArray[MAXN];
long long _res = 0;

long long QuickPow (long long base, long long index) {
	
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

long long C (long long all, long long choose) {
	
	return _facArray[all] * _invArray[choose] % mod * _invArray[all - choose] % mod;
	
}

void CparseIn () {
	
	cin >> _num >> _maxi;
	
}

void Core () {
	
	_facArray[0] = 1;
	
	for (int i = 1; i < 1e6 + 1; i++) {
		_facArray[i] = _facArray[i - 1] * i % mod;
	}
	
	_invArray[1000000] = QuickPow(_facArray[1000000], mod - 2);
	
	for (int i = 1e6 - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * (i + 1) % mod; 
	}
	
	for (int i = 1; i < _num + 1; i++) {
		_res = (_res + C(_maxi - 1, i - 1) * C(_maxi - 1, _num - i)) % mod;
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

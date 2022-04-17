

#include <iostream>
#include <fstream>

using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 3e6 + 9;

long long _facArray[MAXN];
long long _invArray[MAXN]; 
int _posX = 0;
int _posY = 0;
int _posZ = 0;
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
	
	cin >> _posX >> _posY >> _posZ;
	
}

void Init () {
	
	_facArray[0] = 1;
	
	for (int i = 1; i < 3e6 + 1; i++) {
		_facArray[i] = _facArray[i - 1] * i % mod;
	}
	
	_invArray[3000000] = QuickPow(_facArray[3000000], mod - 2);
	
	for (int i = 3e6 - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * (i + 1) % mod; 
	}
	
}

void Core () {
	
	Init();
	
	_res = C(_posX + _posY + _posZ - 3, _posX - 1) * C(_posY + _posZ - 2, _posY - 1) * C(_posZ - 1, _posZ - 1) % mod;
	
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

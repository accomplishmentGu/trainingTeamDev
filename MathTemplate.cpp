

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 9;
 
long long _facArray[MAXN];
long long _invArray[MAXN]; 

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

long long C (long long all, long long choose) {
	
	return _facArray[all] * _invArray[choose] % MOD * _invArray[all - choose] % MOD;
	
}

void Init () {
	
	_facArray[0] = 1;
	
	for (int i = 1; i < 2e6 + 1; i++) {
		_facArray[i] = _facArray[i - 1] * i % MOD;
	}
	
	_invArray[2000000] = QuickPow(_facArray[2000000], MOD - 2, MOD);
	
	for (int i = 2e6 - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * (i + 1) % MOD; 
	}
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
 	
	Init();
	return 0;
	
}

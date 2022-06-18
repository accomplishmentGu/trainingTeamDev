

#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 1e6 + 9;
const int mod = 1e9 + 7;

int _maxi = 0;
int _num = 0;
long long _dpArray[MAXN];
long long _sumArray[MAXN];

void CparseIn () {
	
	cin >> _maxi >> _num;
	
}

void Core () {
	
	_maxi = (_maxi + 1) / 2;
	_num /= 2;
	
	_dpArray[1] = _sumArray[1] = 1;
	
	for (int i = 2; i < _maxi + 1; i++) {
		_dpArray[i] = (_sumArray[i - 1] - _sumArray[max(0, i - _num - 1)]) % mod;
		_sumArray[i] = (_sumArray[i - 1] + _dpArray[i]) % mod;
	} 
	
}

void CwriteOut () {
	
	cout << (_dpArray[_maxi] + mod) % mod << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

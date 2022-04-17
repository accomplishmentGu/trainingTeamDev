

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 9;

struct Code {
	
	int _line;
	int _cell;
	int _num;
	
};

long long _facArray[MAXN];
long long _invArray[MAXN];
vector<Code> _myList;
vector<int> _resList;

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
	
	int maxi = 0;
	Code solo;
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> solo._line >> solo._cell >> solo._num;
		
		_myList.push_back(solo);
	}
	
}

void Init () {
	
	_facArray[0] = 1;
	
	for (int i = 1; i < 1e6 + 1; i++) {
		_facArray[i] = _facArray[i - 1] * i % mod;
	}
	
	_invArray[1000000] = QuickPow(_facArray[1000000], mod - 2);
	
	for (int i = 1e6 - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * (i + 1) % mod; 
	}
	
}

int Solve (Code curCode) {
	
	int res = 1;
	
	res = C(curCode._line, curCode._num) * C(curCode._cell, curCode._num) % mod * _facArray[curCode._num] % mod;
	
	return res;
	
}

void Core () {
	
	Init();
	
	for (int i = 0; i < _myList.size(); i++) {
		_resList.push_back(Solve(_myList[i]));
	}
	
}

void CwriteOut () {
	
	for (int i = 0; i < _resList.size(); i++) {
		cout << _resList[i] << '\n';
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



#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 2e6 + 9;

struct Code {
	
	int _line;
	int _cell;
	
};

vector<Code> _myList;
vector<int> _resList;
long long _facArray[MAXN];
long long _invArray[MAXN]; 

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
		cin >> solo._line >> solo._cell;
		
		_myList.push_back(solo);
	}
	
}

void Init () {
	
	_facArray[0] = 1;
	
	for (int i = 1; i < 2e6 + 1; i++) {
		_facArray[i] = _facArray[i - 1] * i % mod;
	}
	
	_invArray[2000000] = QuickPow(_facArray[2000000], mod - 2);
	
	for (int i = 2e6 - 1; i > -1; i--) {
		_invArray[i] = _invArray[i + 1] * (i + 1) % mod; 
	}
	
}

void Core () {
	
	Init();
	
	for (int i = 0; i < _myList.size(); i++) {
		int res = C(_myList[i]._line + _myList[i]._cell - 4, _myList[i]._line - 2);
		
		_resList.push_back(res);
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

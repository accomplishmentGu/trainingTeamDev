

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN = 1e5 + 9;

int _weight = 0;
vector<int> _myList;
bitset<MAXN> _dpBitset;
int _res = 0;

void CparseIn () {
	
	int maxi = 0;
	int curInt = 0;
	
	cin >> _weight >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> curInt;
		
		_myList.push_back(curInt);
	}
	
}

void Core () {
	
	_dpBitset[0] = 1;
	
	for (int i = 0; i < _myList.size(); i++) {
		_dpBitset = _dpBitset | (_dpBitset << _myList[i]);
	}
	
	for (int i = _weight; i > -1; i--) {
		if (_dpBitset[i]) {
			_res = _weight - i;
			return;
		}
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

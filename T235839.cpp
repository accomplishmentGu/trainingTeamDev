

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 2e6 + 9;

struct Dual {
	
	int _left;
	int _right;
	
};

vector<Dual> _myList;
vector<long long> _resList;
long long _myArray[MAXN];

void CparseIn () {
	
	int maxi = 0;
	Dual solo;
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> solo._left >> solo._right;
		
		_myList.push_back(solo);
	}
	
}

void Init () {
	
	for (int i = 1; i < 2e6 + 1; i++) {
	    for (int m = i; m < 2e6 + 1; m += i) {
	        _myArray[m] += i;
		}
		
	    _myArray[i] += _myArray[i - 1];
	}
	
}

void Core () {
	
	Init();
	
	for (int i = 0; i < _myList.size(); i++) {
		_resList.push_back(_myArray[_myList[i]._right] - _myArray[_myList[i]._left - 1]);
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

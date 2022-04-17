

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Dual {
	
	string _myStr;
	int _num;
	
};

const int MAXN = 1e6 + 9;
const int mod = 1e9 + 7;

vector<Dual> _myList;
vector<int> _resList;
int _myArray[19][MAXN];

void CparseIn () {
	
	int maxi = 0;
	Dual solo;
	
	cin >> maxi;
	
	for (int i = 0; i < maxi; i++) {
		cin >> solo._myStr >> solo._num;
		_myList.push_back(solo);
	}
	
}

void Core () {
	
	for (int m = 0; m < 1e6 + 1; m++) {
		for (int i = 0; i < 10; i++) {
			if (i + m < 10) {
				_myArray[i][m] = 1;
				continue;
			} 
			
			_myArray[i][m] = (_myArray[1][m - (10 - i)] + _myArray[0][m - (10 - i)]) % mod;
		}
	}
	
	for (int i = 0; i < _myList.size(); i++) {
		int res = 0;
		
		for (int m = 0; m < _myList[i]._myStr.length(); m++) {
			res = (res + _myArray[_myList[i]._myStr[m] - '0'][_myList[i]._num]) % mod;
		}	
		
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

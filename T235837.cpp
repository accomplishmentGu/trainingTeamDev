

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int _maxi = 0;
int _num = 0;
vector<int> _resList;
long long _myMap[5009][5009];

void CparseIn () {
	
	cin >> _maxi >> _num;
	
}

void Core () {
	
	_myMap[0][0] = 1;
	
	for (int i = 1; i < _num + 1; i++) {
		for (int m = 1; m < _maxi + 1; m++) {
			if (i > m) {
				continue;
			}
			
			_myMap[i][m] = (_myMap[i - 1][m - 1] + _myMap[i][m - 1] * i) % mod;
		}
	}
	
}

void CwriteOut () {
	
	cout << _myMap[_num][_maxi] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
}

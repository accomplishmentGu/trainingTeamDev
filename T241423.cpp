

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int _maxi = 0;
int _num = 0;
vector<int> _timeList;
int _dpMap[10009][1009];

void CparseIn () {
	
	int time = 0;
	
	cin >> _maxi;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> time;
		
		_timeList.push_back(time);
	}
	
	cin >> _num;
	
} 

void Core () {
	
	_dpMap[0][0] = 1;
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = 0; m < 1000; m++) {
			_dpMap[i][m] = (_dpMap[i - 1][m] + _dpMap[i - 1][(m - _timeList[i - 1] + 1000) % 1000]) % mod;
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[_maxi][_num] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

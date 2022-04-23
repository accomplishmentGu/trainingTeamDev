

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int _num = 0;
int _maxi = 0;
vector<int> _volumeList;
vector<int> _weightList;
int _dpMap[59][15009];

void CparseIn () {
	
	int volume = 0;
	int weight = 0;
	
	cin >> _maxi >> _num;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> weight >> volume;

		_volumeList.push_back(volume);
		_weightList.push_back(weight);
	}
	
} 

void Core () {
	
	memset(_dpMap, 0x80, sizeof(_dpMap));
	
	_dpMap[0][12500] = 0;
	
	for (int i = 1; i < _maxi + 1; i++) {
		int need = _weightList[i - 1] - _volumeList[i - 1] * _num;
		 
		for (int m = 0; m < 15001; m++) {
			if (m - need > -1 && m - need < 15001) {
				_dpMap[i][m] = max(_dpMap[i - 1][m], _dpMap[i - 1][m - need] + _weightList[i - 1]);
				continue;
			}
			
			_dpMap[i][m] = _dpMap[i - 1][m];
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpMap[_maxi][12500] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

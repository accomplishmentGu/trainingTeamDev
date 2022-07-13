

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

using namespace std;

int _line = 0;
int _cell = 0;
int _myMap1[19][19];
int _myMap2[19][19];
int _res = 0;

struct Count {
	
	int _countArray[19];
	
	bool operator < (const Count &_theCount) const {
		for (int i = 0; i < _line; i++) {
			if (_countArray[i] != _theCount._countArray[i]) {
				return _countArray[i] < _theCount._countArray[i];
			}
		}
		
		return 0;
	}
	
};

map<Count, int> _theMap;

int Dfs (const Count &cur, bool player) {
	
	bool flag = 0;
	
	if (_theMap.count(cur)) {
		return _theMap[cur];
	}
	
	if (player) {
		_theMap[cur] = -1e9;
	}
	
	if (!player) {
		_theMap[cur] = 1e9;
	}
	
	for (int i = 0; i < _line; i++) {
		if (cur._countArray[i] != _cell && (i == 0 || cur._countArray[i] < cur._countArray[i - 1])) {
			Count solo = cur;
			
			solo._countArray[i]++;
			flag = 1;
			
			if (player) {
				_theMap[cur] = max(_theMap[cur], _myMap1[i][solo._countArray[i] - 1] + Dfs(solo, 0));
			}
			
			if (!player) {
				_theMap[cur] = min(_theMap[cur], -_myMap2[i][solo._countArray[i] - 1] + Dfs(solo, 1));
			}
		}
	}
	
	if (!flag) {
		_theMap[cur] = 0;
	}
	
	return _theMap[cur];
	
}

void CparseIn () {
	
	cin >> _line >> _cell;
	
	for (int i = 0; i < _line; i++) {
		for (int m = 0; m < _cell; m++) {
			cin >> _myMap1[i][m];
		}
	}
	
	for (int i = 0; i < _line; i++) {
		for (int m = 0; m < _cell; m++) {
			cin >> _myMap2[i][m];
		}
	}
	
}

void Core () {
	
	Count cur;
	
	memset(cur._countArray, 0, sizeof(cur._countArray));
	
	_res = Dfs(cur, 1);
	
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

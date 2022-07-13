

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long long _maxi = 0;
long long _height = 0;
long long _radius = 0; 
long long _posXArray[1009];
long long _posYArray[1009];
long long _posZArray[1009];
bool _myMap[1009][1009];
bool _visArray[1009];

void CparseIn () {
	
	cin >> _maxi >> _height >> _radius;
	
}

unsigned long long Square (long long num) {
	
	return num * num;
	
}

void Dfs (int cur) {
	
	if (_visArray[cur]) {
		return;
	}
	
	_visArray[cur] = 1;
	
	for (int i = 1; i < _maxi + 2; i++) {
		if (_myMap[cur][i]) {
			Dfs(i);
		}
	}
	
}

void Core () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		cin >> _posXArray[i] >> _posYArray[i] >> _posZArray[i];
		
		if (_posZArray[i] < _radius + 1) {
			_myMap[0][i] = 1;
		}
		
		if (_posZArray[i] + _radius > _height - 1) {
			_myMap[i][_maxi + 1] = 1;
		}
		
		for (int m = 1; m < i; m++) {
			if (Square(_posXArray[i] - _posXArray[m]) + Square(_posYArray[i] - _posYArray[m]) + Square(_posZArray[i] - _posZArray[m]) < Square(2 * _radius) + 1) {
				_myMap[i][m] = _myMap[m][i] = 1;
			}
		}
	}
	
	Dfs(0);
	
}

void CwriteOut () {
	
	cout << (_visArray[_maxi + 1] ? "Yes" : "No") << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int _codeNum = 0;
	
	cin >> _codeNum;
	
	while (_codeNum--) {
		memset(_myMap, 0, sizeof(_myMap));
		memset(_visArray, 0, sizeof(_visArray));
		
		CparseIn();
		Core();
		CwriteOut();
	}
	
	return 0;
	
}



#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int _weight = 0;
int _maxi = 0;
int _num = 0; 
vector<int> _weightList;
vector<int> _valueList;
vector<int> _resWeight;
vector<int> _resValue;
int _ccArray1[1009]; 
int _myMap1[1009][1009];
int _ccArray2[1009]; 
int _myMap2[1009][1009];
int _dpMap[109][1009];
int _dpArray[1009];
int _tot = 0;

void CparseIn () {
	
	int value = 0;
	int weight = 0;
	int group = 0;
	
	cin >> _maxi >> _weight >> _num;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> weight >> value >> group;
		
		_weightList.push_back(weight);
		_valueList.push_back(value);
		
		_ccArray1[group]++;
		_myMap1[group][_ccArray1[group]] = i;
	}
	
} 

void Solve (int group) {
	
	memset(_dpMap, 0, sizeof(_dpMap));
	
	for (int i = 1; i < _ccArray1[group] + 1; i++) {
		for (int m = _num; m; m--) {
			for (int k = _weight; k > _weightList[_myMap1[group][i]] - 1; k--) {
				_dpMap[m][k] = max(_dpMap[m][k], _dpMap[m - 1][k - _weightList[_myMap1[group][i]]] + _valueList[_myMap1[group][i]]);
			}
		}
	}
	
	for (int i = _weight; i; i--) {
		_resWeight.push_back(i);
		_resValue.push_back(_dpMap[_num][i]);
		_ccArray2[group]++;
		_myMap2[group][_ccArray2[group]] = _tot;
		_tot++;
	}
	
}

void Core () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		if (_ccArray1[i]) {
			Solve(i);
		}
	}
	
	for (int k = 1; k < _maxi + 1; k++) {
		for (int i = _weight; i; i--) {
			for (int m = 1; m < _ccArray2[k] + 1; m++) {
				if (i >= _resWeight[_myMap2[k][m]]) {	
					_dpArray[i] = max(_dpArray[i], _dpArray[i - _resWeight[_myMap2[k][m]]] + _resValue[_myMap2[k][m]]);
				}
			}
		}
	}
	
}

void CwriteOut () {
	
	cout << _dpArray[_weight] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

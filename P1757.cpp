

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _weight = 0;
int _maxi = 0;
int _groupNum = 0;
vector<int> _weightList;
vector<int> _valueList;
int _ccArray[1009]; 
int _myMap[1009][1009];
int _dpArray[1009];

void CparseIn () {
	
	int value = 0;
	int weight = 0;
	int group = 0;
	
	cin >> _weight >> _maxi;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> weight >> value >> group;
		
		_weightList.push_back(weight);
		_valueList.push_back(value);
		
		_ccArray[group]++;
		_myMap[group][_ccArray[group]] = i;
		_groupNum = max(_groupNum, group);
	}
	
} 

void Core () {
	
	for (int k = 1; k < _groupNum + 1; k++) {
		for (int i = _weight; i > -1; i--) {
			for (int m = 1; m < _ccArray[k] + 1; m++) {
				if (i >= _weightList[_myMap[k][m]]) {
					_dpArray[i] = max(_dpArray[i], _dpArray[i - _weightList[_myMap[k][m]]] + _valueList[_myMap[k][m]]);
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

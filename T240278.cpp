

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _weight = 0;
int _maxi = 0;
vector<int> _weightList;
vector<int> _valueList;
vector<int> _numList;
int _dpArray[1009];
vector<int> _primeList; 
bool _primeArray[1009];

void Init () {
	
	for (int i = 2; i < 1001; i++) {
		if (!_primeArray[i]) {
			_primeList.push_back(i);
			
			for (int m = i; m < 1001; m += i) {
				_primeArray[m] = true;
			}
		}
	} 
	
}

void CparseIn () {
	
	int value = 0;
	int weight = 0;
	int num = 0;
	
	Init();
	
	cin >> _maxi >> _weight;
	
	for (int i = 0; i < _maxi; i++) {
		cin >> weight >> value >> num;
		
		_weightList.push_back(weight);
		_valueList.push_back(value);
		_numList.push_back(num);
	}
	
} 

void Core () {
	
	for (int i = 1; i < _maxi + 1; i++) {
		for (int m = _weight; m; m--) {
			for (int k = 0; k < _primeList.size() && _primeList[k] < _numList[i - 1] + 1 && _primeList[k] * _weightList[i - 1] < m + 1; k++) {
				_dpArray[m] = max(_dpArray[m], _dpArray[m - _weightList[i - 1] * _primeList[k]] + _valueList[i - 1] * _primeList[k]);
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

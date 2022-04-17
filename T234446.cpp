

#include <iostream>
#include <fstream>

using namespace std;

const int mod = 1e9 + 7;

string _myStr = "";
string _subStr = "";
int _myMap[5009][5009];
 
void CparseIn () {
	
	cin >> _myStr >> _subStr;	
	
}

void Core () {
	
	_myMap[0][0] = 1;
	
	for (int i = 1; i < _myStr.length() + 1; i++) {
		_myMap[i][0] = _myMap[i - 1][0];
		
		for (int m = 1; m < _subStr.length() + 1; m++) {
			if (_myStr[i - 1] == _subStr[m - 1]) {
				_myMap[i][m] = (_myMap[i - 1][m] + _myMap[i - 1][m - 1]) % mod;
				
				continue;
			}
			
			_myMap[i][m] = _myMap[i - 1][m];
		}
	}
	
} 

void CwriteOut () {
	
	cout << _myMap[_myStr.length()][_subStr.length()] << '\n';
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

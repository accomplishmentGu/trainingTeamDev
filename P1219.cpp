

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
bool _visArray1[19];
bool _visArray2[19];
bool _visArray3[29];
int _myArray[19];
int _res = 0;

void CparseIn () {
	
	cin >> _maxi;
	
}

void Dfs (int cur) {
	
	if (cur == _maxi + 1) {
		_res++;
		
		if (_res < 4) {
			for (int i = 1; i < _maxi + 1; i++) {
				cout << _myArray[i] << ' ';
			}
			
			cout << '\n';
		}
		
		return;
	}
	
	for (int i = 1; i < _maxi + 1; i++) {
		if (!_visArray1[i] && !_visArray2[i + cur] && !_visArray3[cur - i + _maxi]) {
			_visArray1[i] = _visArray2[i + cur] = _visArray3[cur - i + _maxi] = 1;
			_myArray[cur] = i;
			
			Dfs(cur + 1);
			
			_visArray1[i] = _visArray2[i + cur] = _visArray3[cur - i + _maxi] = 0;
		}
	}
	
}

void Core () {
	
	Dfs(1);
	
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



#include <iostream>
#include <fstream>

using namespace std;

int _problem = 0;
int _minister = 0;
int _myMap[1009][1009];
int _myArray[1009];
int _res = 0;

void CparseIn () {
	
	cin >> _problem >> _minister;
	
	for (int i = 0; i < _minister; i++) {
		for (int m = 0; m < _problem; m++) {
			cin >> _myMap[i][m];
		}
	}
	
	for (int i = 0; i < _problem; i++) {
		cin >> _myArray[i];
	}
	
}

void Core () {
	
	for (int i = 0; i < _problem; i++) {
		int count = 0;
		
		for (int m = 0; m < _minister; m++) {
			if (_myMap[m][i] == _myArray[i]) {
				count++;
			}
		}
		
		if (count > _minister / 2) {
			_res++;
		}
	}
	
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

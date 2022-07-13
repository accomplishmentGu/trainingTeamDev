

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long long _numA = 0;
long long _numB = 0;
long long _numC = 0;
long long _resMap[29][29][29];

long long Function (long long numA, long long numB, long long numC) {
	
	if (numA < 1 || numB < 1 || numC < 1) {
		return 1;
	}	
	
	if (numA > 20 || numB > 20 || numC > 20) {
		return Function(20, 20, 20);
	}
	
	if (_resMap[numA][numB][numC] != -1e18) {
		return _resMap[numA][numB][numC];
	}
	
	if (numA < numB && numB < numC) {
		return _resMap[numA][numB][numC] = Function(numA, numB, numC - 1) + Function(numA, numB - 1, numC - 1) - Function(numA, numB - 1, numC);
	}
	
	return _resMap[numA][numB][numC] = Function(numA - 1, numB, numC) + Function(numA - 1, numB - 1, numC) + Function(numA - 1, numB, numC - 1) - Function(numA - 1, numB - 1, numC - 1);
	
}

void CparseIn () {
	
	for (int i = 0; i < 21; i++) {
		for (int m = 0; m < 21; m++) {
			for (int k = 0; k < 21; k++) {
				_resMap[i][m][k] = -1e18;
			}
		}
	}
	
	while ((cin >> _numA >> _numB >> _numC) && (_numA != EOF || _numB != EOF || _numC != EOF)) {
		if (_numA == -1 && _numB == -1 && _numC == -1) {
			return;
		}
		
		cout << "w(" << _numA << ", " << _numB << ", " << _numC << ") = " << Function(_numA, _numB, _numC) << '\n';
	}
	
}

void Core () {
	
	// nothing
	
}

void CwriteOut () {
	
	// nothing
	
}

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	CparseIn();
	Core();
	CwriteOut(); 
	return 0;
	
} 

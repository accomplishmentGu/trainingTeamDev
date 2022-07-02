

#include <iostream>
#include <fstream>

using namespace std;

int _res = 0;

void CparseIn () {
	
	// nothing
	
}

int Dfs () {
	
	char curChar = 0;
	int res = 0;
	
	while (cin >> curChar && curChar != EOF) {
		if (curChar == 'a') {
			res++;
		}
		
		else if (curChar == '(') {
			res += Dfs();
		}
		
		else if (curChar == ')') {
			return res;
		}
		
		else if (curChar == '|') {
			return res = max(res, Dfs());
		}
	}
	
	return res;
	
}

void Core () {
	
	_res = Dfs();
	
}

void CwriteOut () {
	
	cout << _res << '\n';
	
}

int main () {
	
	CparseIn();
	Core();
	CwriteOut();
	return 0;
	
} 

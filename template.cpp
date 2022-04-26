/*
 * Author: guzheran @YYXX
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define register rg
#define mp make_pair
#define pb push_back
#define pf push_front

#define rep(i, s, t) for (int i = s; i <= t; i++)
#define per(i, s, t) for (int i = t; i >= s; i--)

namespace IO {
	
	template <typename type>
	inline void Read (type &theNum) {
	
		char theChar = 0;
		int negative = 0; 
		
		theNum = 0;
		theChar = getchar();
		negative = 1;
		
		while (theChar < '0' || theChar > '9') {
			if (theChar == '-') {
				negative = -1;
			}
			
			theChar = getchar();
		}
		
		theNum = theChar ^ 48;
		
		while ((theChar = getchar()) > '0' - 1 && theChar < '9' + 1) {
			theNum = (theNum << 3) + (theNum << 1) + (theChar ^ 48);
		}
		
		theNum *= negative;
		
	}
	
	template <typename type>
	inline void RecursionWrite (type theNum) {
		
		if (theNum) {
			RecursionWrite(theNum / 10);
			putchar(theNum % 10 + 48);
		}
		
	}
	
	template <typename type1, typename type2>
	inline void Write (type1 theNum, type2 endChar) {
		
		if (!theNum) {
			putchar('0');
		}
		
		if (theNum < 0) {
			putchar('-');
			theNum *= -1;
		}
		
		if (theNum) {
			RecursionWrite(theNum / 10);
			putchar(theNum % 10 + 48);
		}
		
		putchar(endChar);
		
	}
	
}

using namespace IO;

#define OK debug("OK!\n");
#ifndef ONLINE_JUDGE

namespace debuger {
	
	void debug (const char *s) {
		
		cerr << s;
		
	}
	
	template <typename T1, typename... T2>
	void debug (const char *s, const T1 x, T2...ls) { 
	
		int p = 0; 
		
		while (*(s + p) != '\0') {
			if (*(s + p) == '{' && *(s + p + 1) == '}') {
				cerr << x;
				debug(s + p + 2, ls...);
				return;
			}
			
			cerr << *(s + p++);
		}
		
	}
	
}

using debuger::debug;

#else
#define debug(...) void(0)
#endif

// const ll mod = 1e9 + 7;
const ll mod = 998244353;
const int inf = 0x3f3f3f3f;

template <typename T>
inline void chkadd (T &x, T y) {
	
	x = x + y >= mod ? x + y - mod : x + y;
	
}

template <typename T>
inline void chkadd (T &x, T y, T z) {
	
	x = y + z >= mod ? y + z - mod : y + z;
	
}

template <typename T>
inline void chkmns (T &x, T y) {
	
	x = x - y < 0 ? x - y + mod : x - y;
	
}

template <typename T>
inline void chkmns (T &x, T y, T z) {
	
	x = y - z < 0 ? y - z + mod : y - z;
	
}

template <typename T>
inline void chkmax (T &x, T y) {
	
	x = x < y ? y : x;
	
}

template <typename T>
inline void chkmax (T &x, T y, T z) {
	
	x = y > z ? y : z;
	
}

template <typename T>
inline void chkmin (T &x, T y) {
	
	x = x < y ? x : y;
	
}

template <typename T>
inline void chkmin (T &x, T y, T z) {
	
	x = y < z ? y : z;
	
}

ll QuickPow (ll x, ll p) {
	
	ll base = x, res = 1;
	
	while (p) {
		if (p & 1) {
			res = (res * base) % mod;
		}
		 
		base = (base * base) % mod;
		p >>= 1;
	}
	
	return res;
	
}

string tobinary (ll S, int len) {
	
	string res;
	
	for (int i = 0; i < len; i++) {
		res = char((S & 1) + '0') + res;
		S >>= 1;
	}
	
	return res;
	
}

mt19937_64 mtrnd(std::chrono::system_clock::now().time_since_epoch().count());

/* template ends here */

int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cout << fixed << setprecision(15); 
	cerr << fixed << setprecision(15);
	
	
	
	return 0;
	
}

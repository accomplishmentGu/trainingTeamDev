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

namespace nqio {
	
	const unsigned R = 4e5, W = 4e5;
	char *a, *b, i[R], o[W], *c = o, *d = o + W, h[40], *p = h, y;
	bool s;
	
	struct q {
		
		void r (char &x) {
			
			x = a == b && (b = (a = i) + fread(i, 1, R, stdin), a == b) ? -1 : *a++;
			
		}
		
		void f () {
			
			fwrite(o, 1, c - o, stdout);
			c = o;
			
		}
		
		~q () {
			
			f();
			
		}
		
		void w (char x) {
			
			*c = x;
			
			if (++c == d) {
				f();
			}
			
		}
		
		q &operator >> (char &x) {
			
			do r(x);
			while (x <= 32);
			
			return *this;
			
		}
		
		q &operator >> (char *x) {
			
			do r(*x);
			while (*x <= 32);
			
			while (*x > 32){
				r(*++x);
			}
			
			*x = 0;
			
			return *this;
			
		}
		
		template <typename t>
		q &operator >> (t &x){
			
			for (r(y), s = 0; !isdigit(y); r(y)) {
				s |= y == 45;
			}
			
			if (s) {
				for (x = 0; isdigit(y); r(y)){
					x = x * 10 - (y ^ 48);
				}
			}
				
			else {
				for (x = 0; isdigit(y); r(y)) {
					x = x * 10 + (y ^ 48);
				}
			}
			
			return *this;
			
		}
		
		q &operator << (char x) {
			
			w(x);
			
			return *this;
			
		}
		
		q &operator << (char *x) {
			
			while (*x) {
				w(*x++);
			}
			
			return *this;
			
		}
		
		q &operator << (const char *x) {
			
			while (*x) {
				w(*x++);
			}
			
			return *this;
			
		}
		
		template <typename t>
		q &operator << (t x) {
			
			if (!x) {
				w(48);
			}
			
			else if (x < 0) {
				for (w(45); x; x /= 10) {
					*p++ = 48 | -(x % 10);
				}
			}
			
			else {
				for (; x; x /= 10) {
					*p++ = 48 | x % 10;
				}
				
				while (p != h) {
					w(*--p);
				}
			}
			
			return *this;
			
		}
		
	}
	qio;
	
}

using nqio::qio;

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

ll qpow (ll x, ll p) {
	
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

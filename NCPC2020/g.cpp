#include <bits/stdc++.h>

using namespace std;
#define ll long long 

const int maxN = 1e6 + 100;
const long long MOD = 1e9 + 7;

int n;
int a[maxN];

ll f[maxN];

ll powM(ll a, ll n, ll M = MOD) {
	if (n == 0)
		return 1 % M;

	ll t = powM(a, n/2, M);
	t = t*t % M;
	if (n % 2)
		t = t*a % M;

	return t;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	ll c = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 2)
			c += 1;
		if (a[i] == 1)
			f[i] = c;
	}

	ll t = 0;
	ll s = 0;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			t += 1;
			s = (s + powM(2, f[i])) % MOD;
		}
		if (a[i] == 2)
			c -= 1;
		if (a[i] == 3) {
			ll y = powM(2, c);
			res = (res + s*powM(y, MOD - 2) - t + MOD) % MOD;
		}

	}

	cout << res << "\n";
}

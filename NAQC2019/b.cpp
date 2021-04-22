#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	ll n, m;
	cin >> n >> m;
	if (n < m)
		swap(n, m);

	ll u = gcd(n, m);
	ll x = n/u, y = m/u;

	ll res = 0;
	if (x&1)
		res = u;

	cout << res << "\n";

}

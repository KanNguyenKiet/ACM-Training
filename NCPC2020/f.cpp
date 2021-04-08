#include <bits/stdc++.h>

#define ll long long
#define ar array

using namespace std;


const int maxN = 200;

int n, m, k;
ar<int, 2> a[maxN];

ar<int, 2> b[maxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0];
		a[i][1] = i + 1;
	}

	if (k % m != 0) {
		cout << "impossible\n";
		return 0;
	}
	k = k / m;
	cerr << k << "\n";

	sort(a, a + n);
	swap(a[0], a[k - 1]);
	sort(a + 1, a + n - k, greater<ar<int, 2>>());

	vector<int> v(k);
	iota(v.begin(), v.end(), n - k + 1);
	sort(v.begin(), v.end(), [](int i, int j) {
		return (ll)(i)*(n - k + j) < (ll)(j)*(n - k + i);
	});

	copy(a + n - k, a + n, b);
	for (int i = 0; i < k; ++i)
		a[v[i] - 1] = b[k - i - 1];

	for (int i = 0; i < n; ++i)
		cout << a[i][1] << ' ';
	cout << "\n";

	int x = 1;
	for (int i = 1; i < n; ++i) {
		if ((ll)(x)*m <= (ll)(a[i][0])*i)
			x += 1;
	}
	if (x != k) {
		cout << "impossible\n";
		return 0;
	}

	for (int i = 0; i < n; ++i)
		cout << a[i][1] << ' ';
	cout << "\n";
}

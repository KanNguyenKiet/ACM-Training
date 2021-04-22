#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<double> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	double l = 0, r = 1e9;
	vector<double> b(n + 1), d(n + 1);
	d.push_back(-1e9);
	for (int c = 1; c < 64; c++) {
		double mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			b[i] = a[i] - mid;
		}
		double suf = 0;
		for (int i = n; i; i--) {
			suf += b[i];
			d[i] = max(d[i + 1], suf);
		}
		int check = 0;
		double sum = 0;
		if (d[1] >= 0) {
			check = 1;
		}
		for (int i = 1; i <= n; i++) {
			sum += b[i];
			if (sum + max(d[i + 1], 0.0) >= 0) {
				check = 1;
				break;
			}
		}
		if (check) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
}

int main() {
	cout << fixed << setprecision(10);
	solve();
}

#include<bits/stdc++.h>

using namespace std;

void solve() {
	int k;
	cin >> k;
	vector<long long> t(k + 1), a(k + 1), b(k + 1);
	for (int i = 1; i <= k; i++) {
		cin >> t[i] >> a[i] >> b[i];
	}
	vector<int> pos(k + 1);
	for (int i = 1; i <= k; i++) {
		pos[i] = i;
	}
	sort(pos.begin(), pos.end(), [&](int x, int y) {
		return t[x] < t[y];
	});
	int q;
	cin >> q;
	while (q--) {
		long long x, y;
		cin >> x >> y;
		long long maxf = 0, minf = 0;
		for (int i = 1; i <= k; i++) {
			maxf += b[i];
			minf += a[i];
		}
		if (y < minf || y > maxf) {
			cout << "no" << endl;
			continue;
		}
		long long dt = x * y;
		long long base = 0;
		for (int i = 1; i <= k; i++) {
			base += a[i] * t[i];
			y -= a[i];
		}
		int cur = 1;
		long long curf = y, mint = base;
		while (curf) {
			long long tmp = min(curf, b[pos[cur]] - a[pos[cur]]);
			mint += tmp * t[pos[cur]];
			curf -= tmp;
			cur++;
		}
		long long maxt = base;
		curf = y;
		cur = k;
		while (curf) {
			long long tmp = min(curf, b[pos[cur]] - a[pos[cur]]);
			maxt += tmp * t[pos[cur]];
			curf -= tmp;
			cur--;
		}
		// cout << mint << " " << maxt << endl;
		if (mint <= dt && dt <= maxt) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}

int main() {
	solve();
}
			

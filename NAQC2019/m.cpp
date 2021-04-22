#include<bits/stdc++.h>

using namespace std;

double sqr(double s) {
	return s * s;
}

void solve() {
	double w, g, h, r;
	cin >> w >> g >> h >> r;
	if (g < h)
		swap(h, g);

	double ans1 = sqr(abs(g - h)) + sqr(w);
       	ans1 = sqrt(ans1);
	g -= r;
 	h -= r;
	if (h == 0 && g == 0) {
		cout << w << " " << w << endl;
		return;
	}

	double a = w / (1 + h / g);
	double b = w - a;
	double ans2 = sqrt(sqr(a) + sqr(g)) + sqrt(sqr(b) + sqr(h));
	cout << ans1 << " " << ans2 << endl;
}

int main() {
	int q;
	cin >> q;
	cout << fixed << setprecision(10);
	while (q--) {
		solve();
	}
}


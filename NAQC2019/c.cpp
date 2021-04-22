#include <bits/stdc++.h>

using namespace std;

long long a[1001][5], x, y, z, n, d, t;

int main(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		cin >> x >> y >> z;
		a[x][0] += y;
		a[x][1] += z;
		t += y + z;
	}
	double ansa = 0, ansb = 0;
	for (int i=1; i <= d; i++){
		if (a[i][0] > a[i][1]){
			ansa += max((a[i][0]-a[i][1]-1)/2, 0ll);
			ansb += a[i][1];
			cout << "A " << max((a[i][0]-a[i][1]-1)/2, 0ll) << " " << a[i][1] << endl;
		} else {
			ansa += a[i][0];
			ansb += max((a[i][1]-a[i][0]-1)/2,0ll);
			cout << "B " << a[i][0] << " " << max((a[i][1]-a[i][0]-1)/2, 0ll) << endl;
		}
	}
	double ans = abs(ansa-ansb)/t;
	cout << fixed << setprecision(10) << ans;
}

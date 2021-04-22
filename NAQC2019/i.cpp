#include <bits/stdc++.h>

using namespace std;

struct cmp{
	long long dis, cost, id;
	bool operator< (const cmp &a) const &{
		return dis < a.dis || (dis == a.dis && cost > a.cost);
	}
} d[505];

const long long maxDis = 1e18;
long long n, m, t, s, fix[505];

int main(){
	cin >> n >> m >> t >> s;
	for (int i = 1; i <= t; i++){
		int x;
		cin >> x;
		fix[x] = 1;
	}
	vector<cmp> a[505]; 
	for (int i = 1; i <= m; i++){
		long long x, y, z;
		cin >> x >> y >> z;
		a[x].push_back({y, z});
		a[y].push_back({x, z});
	}
	priority_queue<cmp> pq;
	for (int i = 2; i <= n; i++){
		d[i].dis = maxDis;
		d[i].cost = 0;
		d[i].id = i;
	}
	d[1].dis = 0;
	d[1].cost = s;
	d[1].id = 1;
	pq.push(d[1]);
	cmp c;
	long long c1, c2, c3;
	while (!pq.empty()){
		c = pq.top();
		c1 = c.id;
		c2 = c.dis;
		c3 = c.cost;
		pq.pop();
		for (int i = 0; i < a[c1].size(); i++){
			if (c3 - a[c1][i].cost >= 0){
				if (a[c1][i].dis == n){
					if (d[a[c1][i].dis].dis > c2 + a[c1][i].cost){
						d[a[c1][i].dis].dis = c2 + a[c1][i].cost;
						d[a[c1][i].dis].cost = c3 - a[c1][i].cost;
					}
				} else {
					if (fix[c1] == 1)
						pq.push({c2 + a[c1][i].cost, s, c1});
					else
						pq.push({c2 + a[c1][i].cost, c3 - a[c1][i].cost, c1});
				}
			}
		}	
	}
	if (d[n].dis == maxDis){
		cout << "stuck";
	} else {
		cout << d[n].dis;
	}
}

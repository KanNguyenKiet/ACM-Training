#include <bits/stdc++.h>

using namespace std;

long long maxDis = 1e18;

long long fix[505], a[505][505], n, m, t, s, b[505][505];

int main(){
    cin >> n >> m >> t >> s;
    for (int i = 1; i <= t; i++){
        int x;
        cin >> x;
        fix[x] = 1;
    }
    fix[1] = fix[n] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = maxDis;
            b[i][j] = maxDis;
        }
        a[i][i] = 0;
        b[i][i] = 0;
    }
    for (int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j){
                if (fix[i] == 1 && fix[j] == 1 && a[i][j] <= s){
                    b[i][j] = a[i][j];
                }
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (b[i][j] > b[i][k] + b[k][j]){
                    b[i][j] = b[i][k] + b[k][j];
                }
            }
        }
    }
    if (b[1][n] == maxDis){
        cout << "stuck";
    } else {
        cout << b[1][n];
    }
}

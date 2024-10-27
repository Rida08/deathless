#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;

int main() {
    const int N = 1e5 + 1;

    vector < ll > a[N];
    ll n, m;
    cin >> n >> m;
    ll x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int s = 0;
    for (int i = 1; i <= m; ++i) {
        int d[N];
        memset(d, -1, N);
        d[i] = 0;
        queue < int > q;
        q.push(i);
        while (q.size() > 0) {
            int u = q.front();
            q.pop();
            for (int v: a[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    s += d[v];
                    q.push(v);
                }
            }
        }
    }
    cout << s / 2;
}

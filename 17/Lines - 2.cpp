#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
using ll = long long;

const int N = 260;
const int dc[] = { 0, 0, 1, -1 };
const int dr[] = { 1, -1, 0, 0 };

int n, d[N];

string g[N][N];

void bfs() {
    memset(d, -1, sizeof d);
    d[1] = 0;
    queue<int>q;
    q.push(1);
    while (q.size() > 0) {
        int u = q.front();
        q.pop();
        for(int v=0; v<n && g[u][v]!=""; ++v) if (d[v] == -1 && g[u][v] == ".") {
            d[v] = d[v - 1] + 1;
            q.push(v);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> g[i][j];
    bfs();
    int u = n;
    while (u != 1) {
        for (int v = 0; v < n && g[u][v] != ""; ++v) if (d[v] == d[u] + 1) {
            g[u][v] = "+";
            u = v;
        }

        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cout << g[i][j];
    }
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int n,k, k1, l=0, an=-1;
const int N = 250;
char a[N][N], b[N][N];
bool used[N][N];
int dr[] = {-1, 0, 1, 0}, dc[] = { 0, 1, 0, -1 };

void dfc(int r, int c) {
    if (a[r][c] == '@') {
        if (an < 0 || (an > l && an >= 0)) {
              an = l;
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
                if (used[i][j] == 1) b[i][j] = '+';
                else b[i][j] = a[i][j];
            }
            return;
        }
    }
    used[r][c] = 1;
    int r1 = r, c1 = c;
    for (int i = 0; i < 4; ++i) {
        r = r1 + dr[i];
        c = c1 + dc[i];
        if ((r>-1 && r<n) && (c>-1 && c<n) && a[r][c]=='.' && !used[r][c]) {
            l++;
            dfc(r, c);
            l--;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j){
        cin >> a[i][j];
        if (a[i][j] == 'X') {
            k = i;
            k1 = j;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << b[i][j];
        }
        cout << "\n";
    }

    

}

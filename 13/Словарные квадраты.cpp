#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int n;
vector<string> a, b;

string ans[20], an1[20], an[20];

const int N = 1e4;
bool us[N], us1[N];

void bt() {
    bool c = 1;
    for (int i = 0; i < n; ++i) if (an1[i] == "") c = 0;
    if (c) {
        bool ch = 1;
        for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) if (an1[i][j] != an1[j][i]) ch = 0;
        if (ch) {
            for (int i = 0; i < n; ++i) ans[i] = an1[i];
        }
        return;
    }
    else {
        bool ch = 1;
        for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) {
            if (an1[i] != "" && an1[j] != "") {
                if (an1[i][j] != an1[j][i]) ch = 0;
            }
        }
        if (ch == 0) return;
    }
    for (int i = 0; i < n; ++i) if (an1[i] == "") if(!us[i]){
        us[i] = 1;
        for (int j = 0; j < 2 * n; j++) if(!us1[j]){
            us1[j] = 1, an1[i] = a[j];
            bt();
            an1[i] = "", us1[j] = 0;
        }
        us[i] = 0;
    }
}
void dt() {
    bool c = 1;
    for (int i = 0; i < n; ++i) if (an1[i] == "") c = 0;
    if (c) {
        bool ch = 1;
        for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) if (an1[i][j] != an1[j][i]) ch = 0;
        if (ch) {
            for (int i = 0; i < n; ++i) an[i] = an1[i];
        }
        return;
    }
    else {
        bool ch = 1;
        for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) {
            if (an1[i] != "" && an1[j] != "") {
                if (an1[i][j] != an1[j][i]) ch = 0;
            }
        }
        if (ch == 0) return;
    }
    for (int i = 0; i < n; ++i) if (an1[i] == "") if (!us[i]) {
        us[i] = 1;
        for (int j = 0; j < n; j++) if (!us1[j]) {
            us1[j] = 1, an1[i] = b[j];
            bt();
            an1[i] = "", us1[j] = 0;
        }
        us[i] = 0;
    }
}
int main() {
    cin >> n;
    string x;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    bt();
    for (int i = 0; i < 2 * n; ++i) {
        if (find(ans, ans + 20, a[i]) == ans + 20) b.push_back(a[i]);
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) cout << ans[i] << "\n";
    cout << "\n";
    dt();
    for (int i = 0; i < n; ++i) cout << ans[i] << "\n";

}

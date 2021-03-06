#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, pii> piii;
typedef tuple <int, int, int> ti3;

clock_t start_time, end_time;

void open() {
    TEST(freopen("input.txt", "r", stdin));
    TEST(freopen("output.txt", "w", stdout));
    TEST(freopen("debug.txt", "w", stderr));
    TEST(start_time = clock());
}

void close() {
    TEST(end_time = clock());
    TEST(printf("Total time : %Lf seconds\n", (long double)(end_time - start_time) / CLOCKS_PER_SEC));
}

const int MAX = 2e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, y, x, d[MAX];
vector<piii> v;
set<int> s;

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d", &n, &y, &x);
    for (int i = 1, xx, ylo, yhi; i <= n; ++i) {
        scanf("%d %d %d", &xx, &ylo, &yhi);
        v.push_back({xx, {ylo, yhi}});
    }
    sort(v.begin(), v.end());
    memset(d, 0x3f, sizeof(d));

    s.insert(y); d[y] = 0;
    for (int i = 0; i < v.size(); ++i) {
        auto lower = s.upper_bound(v[i].Y.X);
        auto upper = s.upper_bound(v[i].Y.Y - 1);
        for (auto it = lower; it != upper; ++it) {
            d[v[i].Y.X] = min(d[v[i].Y.X], d[*it] + *it - v[i].Y.X);
            d[v[i].Y.Y] = min(d[v[i].Y.Y], d[*it] + v[i].Y.Y - *it);
            d[*it] = INF;
        }
        s.erase(lower, upper);
        s.insert(v[i].Y.X);
        s.insert(v[i].Y.Y);
    }

    int mn = INF;
    vector<int> ans; 
    for (int i = 0; i < MAX; ++i) {
        if (d[i] < mn) {
            mn = d[i];
            ans.clear();
            ans.push_back(i);
        } else if (d[i] == mn) {
            ans.push_back(i);
        }
    }

    printf("%d\n%lu ", mn + x, ans.size());
    for (int pos: ans) printf("%d ", pos); puts("");

    close();
    return 0;
}

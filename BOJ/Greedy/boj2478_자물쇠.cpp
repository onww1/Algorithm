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

const int MAX = 5e2 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int n, a[MAX], v[MAX];

int main(int argc, char *argv[]) {
    open();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        if ((a[i] + 1) % n == a[(i + 1) % n]) 
            v[a[i]] = v[a[(i + 1) % n]] = 1;
    }
    int len = 0, st = -1;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            len++;
            if (st == -1) st = i;
        }
    }
    if (!st && len < n && !v[n - 1]) {
        st = n - 1;
        while (!v[st - 1]) st--;
    }
    printf("%d\n", (st + len) % n == 0 ? n : (st + len) % n);
    printf("%d %d\n", n - len + 1, n);
    int idx = 0;
    for (int i = 0; i < n; ++i) if (a[i] == st) idx = i;
    printf("%d\n", (n - 1 - idx + n) % n == 0 ? n : (n - 1 - idx + n) % n);

    close();
    return 0;
}

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

const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const db PI = acos(-1);
const ldb ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int a, b, c, d, e, f, x, y;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }
int _lcm(int a, int b) { return a / _gcd(a, b) * b; }

int main(int argc, char *argv[]) {
    open();
    
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if (a < 0) a *= -1, b *= -1, c *= -1;
    if (d < 0) d *= -1, e *= -1, f *= -1;
    x = y = INF;
    if (a && b && d && e) {
        int lcm = _lcm(a, d);
        b *= lcm / a; c *= lcm / a;
        e *= lcm / d; f *= lcm / d;
        a = d = lcm;
        y = (c - f) / (b - e);
        x = (c - b * y) / a;
    } else {
        if (!d || !e) swap(a, d), swap(b, e), swap(c, f);
        if (a == 0) {
            y = c / b;
            x = (f - e * y) / d;
        } else if (b == 0) {
            x = c / a;
            y = (f - d * x) / e;
        }
    }
    printf("%d %d\n", x, y);

    close();
    return 0;
}




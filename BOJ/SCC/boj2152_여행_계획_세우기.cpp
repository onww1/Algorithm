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

struct SCC_Tarjan {
    int size, scc_count, visit_count;
    vector<vector<int>> edges, scc;
    vector<int> _stack, visit, group;

    void init(int _size) {
        this->size = _size;
        scc_count = visit_count = 0;
        edges.clear(); scc.clear();
        _stack.clear(); visit.clear(); group.clear();
        edges.resize(this->size + 1);
        visit.resize(this->size + 1, 0);
        group.resize(this->size + 1, -1);
    }

    void add_edge(int u, int v) {
        edges[u].push_back(v);
    }

    int dfs(int node) {
        visit[node] = ++visit_count;
        int low = visit[node];
        _stack.push_back(node);
        for (int next: edges[node]) {
            if (!visit[next]) 
                low = min(low, dfs(next));
            else if (group[next] == -1) 
                low = min(low, visit[next]);
        }
        if (low == visit[node]) {
            scc.push_back(vector<int>());
            while (!_stack.empty()) {
                int pop_node = _stack.back();
                _stack.pop_back();
                scc.back().push_back(pop_node);
                group[pop_node] = scc_count;
                if (node == pop_node) break;
            }
            scc_count++;
        }
        return low;
    }

    void strongly_connected_component() {
        for (int node = 1; node <= this->size; ++node) 
            if (!visit[node])
                dfs(node);
    }
} SCC;

int n, m, s, t;

int main(int argc, char *argv[]) {
    open();

    scanf("%d %d %d %d", &n, &m, &s, &t);
    SCC.init(n);
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        SCC.add_edge(u, v);
    }
    SCC.strongly_connected_component();

    vector<int> dp(SCC.scc_count, 0);
    vector<int> in(SCC.scc_count, 0);
    vector<bool> visit(SCC.scc_count, false);

    queue<int> q; 
    q.push(SCC.group[s]); 
    visit[SCC.group[s]] = true;

    while (!q.empty()) {
        int grp = q.front(); q.pop();
        for (int node: SCC.scc[grp])
            for (int next: SCC.edges[node])
                if (SCC.group[node] != SCC.group[next]) {
                    in[SCC.group[next]]++;
                    if (!visit[SCC.group[next]]) {
                        q.push(SCC.group[next]);
                        visit[SCC.group[next]] = true;
                    }
                }
    }

    q.push(SCC.group[s]);
    while (!q.empty()) {
        int grp = q.front(); q.pop();
        dp[grp] += SCC.scc[grp].size();
        for (int node: SCC.scc[grp])
            for (int next: SCC.edges[node])
                if (SCC.group[node] != SCC.group[next]) {
                    dp[SCC.group[next]] = max(dp[SCC.group[next]], dp[grp]);
                    if (--in[SCC.group[next]] == 0) 
                        q.push(SCC.group[next]);
                }
    }

    printf("%d\n", dp[SCC.group[t]]);

    close();
    return 0;
}

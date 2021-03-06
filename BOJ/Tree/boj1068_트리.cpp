// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <map>
// #define MOD 1000000007LL
// #define INF 1023456789LL
// using namespace std;

// typedef long long ll;
// typedef double db;

// ll get_pow(ll base, ll exp);
// ll get_min(ll a, ll b);
// ll get_max(ll a, ll b);
// ll get_abs(ll a);

// void count(vector< vector<int> >& edges, int node, int &cnt) {
//   if (edges[node].size() == 0) {
//     ++cnt;
//     return;
//   }

//   for (auto &it : edges[node]) {
//     count(edges, it, cnt);
//   }
// }

// int main(int argc, char *argv[]) {
//     int n, pa[50], r, i, root;
//     scanf("%d", &n);
//     for (i = 0; i < n; ++i) scanf("%d", &pa[i]);
//     scanf("%d", &r);

//     vector< vector<int> > edges(n);
//     for (i = 0; i < n; ++i) {
//       if (pa[i] == -1) root = i;
//       else if (i != r) {
//         edges[pa[i]].push_back(i);
//       }
//     }

//     int cnt = 0;
//     count(edges, root, cnt);
//     printf("%d\n", r == root ? 0 : cnt);

//     return 0;
// }

// ll get_pow(ll base, ll exp) {
//     ll ret = 1LL;
//     while (exp > 0) {
//         if (exp % 2) {
//             ret *= base;
//             ret %= MOD;
//         }
//         base *= base;
//         base %= MOD;
//         exp /= 2;
//     }
//     return ret;
// }

// ll get_min(ll a, ll b) { return a < b ? a : b; }
// ll get_max(ll a, ll b) { return a > b ? a : b; }
// ll get_abs(ll a) { return a < 0 ? -a : a; }

#include <cstdio>
#include <vector>
using namespace std;

vector <int> edges[50];
int main(int argc, char *argv[]) {
  int n, p, i, r, rt;
  
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &p);
    if (p == -1) rt = i;
    else edges[p].push_back(i);
  }
  scanf("%d", &r);
  if (r == rt) return !printf("0\n");

  vector <int> stack;
  stack.push_back(rt);

  int cnt = 0, node;
  while (!stack.empty()) {
    node = stack.back();
    stack.pop_back();

    if (edges[node].size() == 0 || (edges[node].size() == 1 && edges[node][0] == r)) ++cnt;
    else {
      for (auto it : edges[node]) {
        if (it != r) stack.push_back(it);
      }
    }
  }

  return !printf("%d\n", cnt);
}
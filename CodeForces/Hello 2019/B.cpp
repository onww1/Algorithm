#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;

int in[15];
int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", &in[i]);
  for (i = 0; i < (1 << n); ++i) {
    int sum = 0;
    for (j = 0; j < n; ++j) {
      if (i & (1 << j)) sum += in[j];
      else sum -= in[j];
    }
    if (sum % 360);
    else return !printf("YES\n");
  }
  return !printf("NO\n");
}
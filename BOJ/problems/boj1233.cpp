#include <cstdio>
int cnt[16001];
int S1, S2, S3;
int main() {
	scanf("%d %d %d", &S1, &S2, &S3);
	for (int i = 1; i <= S1; ++i) {
		for (int j = 1; j <= S2; ++j) {
			for (int k = 1; k <= S3; ++k) {
				cnt[i + j + k]++;
			}
		}
	}

	int mx = 0, val = 1;
	for (int i = 1; i <= 16000; ++i) {
		if (mx < cnt[i]) {
			mx = cnt[i];
			val = i;
		}
	}
	return !printf("%d\n", val);
}
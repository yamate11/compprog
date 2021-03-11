#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 18;
const int MAXM = 1000000;
int S[MAXM + 5];
bool vis[MAXM + 5];
int main() {
	int N, M; scanf("%d", &N), M = (1<<N);
	for(int i=1;i<=M;i++)
		scanf("%d", &S[i]);
	sort(S + 1, S + M + 1);
	int cnt = 1; vis[M] = true;
	for(int i=1;i<=N;i++) {
		int tot = 0;
		for(int j=M;j>=1;) {
			int p = j, del = 0;
			while( S[j] == S[p] ) p--;
			for(int k=p+1;k<=j;k++) {
				if( vis[k] ) del++;
				else {
					if( tot ) {
						cnt++, tot--;
						vis[k] = true;
					}
				}
			}
			tot += del, j = p;
		}
	}
	if( cnt == M ) puts("Yes");
	else puts("No");
}

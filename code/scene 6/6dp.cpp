#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define maxm 6005
#define maxn 1010
#define inf 2147483647
#define maxw 13000
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define loop(i, a, b) for(int i = a; i >= b; i--)
#define sqr(x) ((x) * (x))

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = s * 10 + ch - '0'; ch = getchar();}
	return s * w;
}

 /**
  * ============================================================================
  @Author:      Cool_Ball
  @DateTime:    2019-08-05 22:12:41
  * ============================================================================
 */

int dp[maxn][maxn];
int n, m;

void init(){
	n = read(), m = read();
}

void solve(){
	rep(i, 1, n){
		rep(j, 1, m){
			if(i < j) continue;
			if(i == 1 || j == 1) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[n][m] << endl;
}

int main(){
	init();
	solve();
	return 0;
}
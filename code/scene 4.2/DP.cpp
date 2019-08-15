#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define maxm 6005
#define maxn 510
#define inf 2147483647
#define maxk 500
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
  @DateTime:    2019-08-05 21:15:28
  * ============================================================================
 */

int dp[maxn][maxn][maxk][2];//4th-D：0(down) 1(horizonal)
int n, m;
int k;

int cal(int n, int m){
	int ans;
	if(n < m) swap(n, m);
	if(n >= m + 1){
		n = m + 1;
		ans = (m - 1) * 2;
	}
	if(n == m) ans = (n - 2) * 2 + 1;
	return ans;
}

void init(){
	n = read(), m = read(), k = read();
}

void solve(){
	dp[1][1][0][1] = dp[1][1][0][0] = 1;
	rep(i, 1, n){
		rep(j, 1, m){
			if(i == 1) dp[i][j][0][0] = 1;
			else if(j == 1) dp[i][j][0][1] = 1;
			rep(q, 0, min(cal(i, j),k)){
				if(q == 0) {dp[i][j][q][0] = dp[i - 1][j][q][0]; dp[i][j][q][1] = dp[i][j - 1][q][1];}
				else{
					dp[i][j][q][0] = dp[i - 1][j][q][0] + dp[i][j - 1][q - 1][1]; 
					dp[i][j][q][1] = dp[i][j - 1][q][1] + dp[i - 1][j][q - 1][0];
				}
			}
		}
	}
	int ans = 0;
	rep(i, 0, k) ans += dp[n][m][i][0] + dp[n][m][i][1];
	cout << ans << endl;
}

int main(){
	init();
	solve();
	return 0;
}

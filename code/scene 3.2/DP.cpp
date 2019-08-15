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
  @DateTime:    2019-08-05 17:56:36
  * ============================================================================
 */

int dp[maxn][maxn];
int n, m1;
int k2, m[maxn][maxn], a, b;//k2:有人位置的数量

void init(){
	n = read(), m1 = read(), k2 = read();
	rep(i, 1, k2){
		a = read(), b = read();
		m[a][b] = 1;//不可走
	}
}

void solve(){
	rep(i, 1, n){
		rep(j, 1, m1){
			if(m[i][j] == 1) continue;
			if(i == 1 && j == 1) dp[i][j] = 1;
			else if(i == 1 && (m[i][j - 1] == 0) && dp[i][j - 1] != 0) dp[i][j] = 1;
			else if(j == 1 && (m[i - 1][j] == 0) && dp[i - 1][j] != 0) dp[i][j] = 1;
			else{
				 if((m[i - 1][j] == 0)) dp[i][j] += dp[i - 1][j];
				 if((m[i][j - 1] == 0)) dp[i][j] += dp[i][j - 1];
			}
		}
	}
	cout << dp[n][m1] << endl;
}

int main(){
	init();
	solve();
	return 0;
}

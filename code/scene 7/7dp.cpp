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
  @DateTime:    2019-08-05 22:22:05
  * ============================================================================
 */

struct node{
	int x, y;
}a[maxn];

bool cmp(node c, node b){
	if(c.x < b.x) return true;
	else if(c.x == b.x && c.y < b.y) return true;
	return false;
}

int n, m1, dp[maxn][maxn];
int k1, k2, m[maxn][maxn];//k1:必须经过的位置的数量 k2:有人位置的数量
int dis;

void init(){
	n = read(), m1 = read(), k1 = read();
	rep(i, 1, k1){
		a[i].x = read(), a[i].y = read();
	}
	rep(i, 1, k2){
		int a1 = read(), b = read();
		m[a1][b] = 1;//不可走
	}
	sort(a + 1, a + k1 + 1, cmp);
	a[0].x = 1, a[0].y = 1;
	a[k1 + 1].x = n, a[k1 + 1].y = m1;
}

void solve(){
	dp[1][1] = 1;
	rep(k, 1, k1 + 1){
		rep(i, a[k - 1].x, a[k].x){
			rep(j, a[k - 1].y, a[k].y){
				if(i < j) continue;
			    if(m[i][j] == 1) continue;
			    if(i == a[k - 1].x && m[i][j - 1] == 0) dp[i][j] = dp[i][a[k - 1].y];
			    else if
                    (j == a[k - 1].y && m[i - 1][j] == 0) dp[i][j] = dp[a[k - 1].x][j];
			    else{
				    if(m[i - 1][j] == 0) dp[i][j] += dp[i - 1][j];
				    if(m[i][j - 1] == 0) dp[i][j] += dp[i][j - 1];
			}
		}
		dis += a[k].x - a[k - 1].x + a[k].y - a[k - 1].y;
	}
	if(dis > m1 + n - 2) cout << 0 << endl;
	else cout << dp[n][m1] << endl;
}

int main(){
	init();
	solve();
	return 0;
}
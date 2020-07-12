#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char s[502];
int minA[501][501],minC[501][501],d[501][501],dA[501][501],dC[501][501];
bool isA[501][501],isC[501][501];
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			isA[i][j]=isA[i][j-1];
			isC[i][j]=isC[i][j-1];
			if(s[j]=='A')isA[i][j]|=1;
			if(s[j]=='C')isC[i][j]|=1;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+k;
			if(j>n)break;
			d[i][j]=dA[i][j]=dC[i][j]=k+1;
			for(int t=i;t<=j;t++)
			{
				if(s[t]=='B' && isA[i][t-1] && isC[t+1][j])
					d[i][j]=min(d[i][j],1+dA[i][t-1]+dC[t+1][j]);
				if(s[t]=='A')dA[i][j]=min(dA[i][j],d[i][t-1]+d[t+1][j]);
				if(s[t]=='C')dC[i][j]=min(dC[i][j],d[i][t-1]+d[t+1][j]);
			}
		}
	}
	printf("%d",d[1][n]);
}
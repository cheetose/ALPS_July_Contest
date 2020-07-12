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

bool chk[200005];
priority_queue<Pi> x_p,y_p;
priority_queue<Pi,VPi,greater<Pi> > x_n,y_n;
int main(){
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		char c;
		scanf(" %c",&c);
		if(c=='+'){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x_p.push({x1,i});x_n.push({x2,i});
			y_p.push({y1,i});y_n.push({y2,i});
		}
		else{
			int ii;
			scanf("%d",&ii);
			chk[ii]=1;
		}
		while(!x_p.empty() && chk[x_p.top().Y])x_p.pop();
		while(!x_n.empty() && chk[x_n.top().Y])x_n.pop();
		while(!y_p.empty() && chk[y_p.top().Y])y_p.pop();
		while(!y_n.empty() && chk[y_n.top().Y])y_n.pop();
		if(x_p.empty())puts("0");
		else printf("%d\n",max({0,x_p.top().X-x_n.top().X,y_p.top().X-y_n.top().X}));
	}
}
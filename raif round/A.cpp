#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
typedef long long int lli;

lli M=1000000007;
lli mod(lli a){
    return ((a%M+M)%M);
} 
lli add(lli a,lli b){
    return mod(mod(a)+mod(b));
}
lli multiply(lli a,lli b){
    return mod(mod(a)*mod(b));
}
lli min(lli a,lli b){
    if(a<b) return a;
    return b;
}
lli max(lli a,lli b){
    return (a>b)?a:b;
}
lli modexpo(lli a,lli b){
    lli res = 1;
    while(b>0){
    	if(b&1) res = (res*a)%M;
    	a = (a*a)%M;
    	b/=2;
    }
    return res;
}
float rec(int n,int sum,int target){
    if(n==0){
        if(sum==target) return 1.0;
        return 0;
    }
    float ans=0;
    ans=rec(n-1,sum+1,target)+rec(n-1,sum-1,target);
    return ans;
}
void solve(){
    lli x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    lli ans=0;
    ans=abs(x2-x1)+abs(y2-y1);
    if((x2-x1)!=0 && (y2-y1)!=0) ans+=2;
    cout<<ans<<"\n";
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r" ,stdin);
		freopen("output.txt", "w" ,stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    // solve();
    int t;
    cin>>t;
    while(t--) solve();
    auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
		cerr << "Time: " << duration.count() / 1000.0 << endl;
	    cout<<duration.count()/1000.0<<endl;
    #endif
    return 0;
}
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
void dpmatrix(vector<lli> &dp,unordered_set<lli> &s){
    
    lli sum=0;
    dp.push_back(0);
    lli i=1;
    
    while(sum<1e10){
        sum+=(i*2)+(i-1);
        dp.push_back(sum);
        s.insert(sum);
        i++;
    }
}
void solve(vector<lli> &dp,unordered_set<lli> &s){
    lli n;
    cin>>n;
    
    // for(lli i=0;i<dp.size();i++) cout<<dp[i]<<" ";
    lli ans=0;
    while(n>=2){
        if(s.find(n)!=s.end()){
            ans++;
            break;
        }
        auto it=lower_bound(dp.begin(),dp.end(),n);
        it--;
        // cout<<*it<<" ";
        n-=*it;
        ans++;
    }
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
    unordered_set<lli> s;
    vector<lli> dp;
    dpmatrix(dp,s);
    while(t--) solve(dp,s);
    auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
		cerr << "Time: " << duration.count() / 1000.0 << endl;
	    cout<<duration.count()/1000.0<<endl;
    #endif
    return 0;
}
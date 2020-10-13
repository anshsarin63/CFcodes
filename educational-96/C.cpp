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
 
void solve(){
    lli n;
    cin>>n;
    vector<pair<lli,lli>> ans;
    lli a=n;
    for(int i=n;i>1;i--){
        lli b=i-1;
        lli sum=a+b;
        if((a+b)%2!=0){
            sum=(a+b+1)/2;
        }
        else{
            sum=(a+b)/2;
        }
        ans.push_back({b,a});
        a=sum;
    }
    cout<<a<<"\n";
    for(pair<lli,lli> &a:ans){
        cout<<a.first<<" "<<a.second<<"\n";
    }
}
 
int main(){
    // #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r" ,stdin);
	// 	freopen("output.txt", "w" ,stdout);
	// #endif
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
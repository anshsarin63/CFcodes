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
    int n,k;
    cin>>n>>k;
    vector<lli> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    lli sum=0,maxe,mine;
    for(lli i=arr.size()-2;i>=0 && k!=0;i--){
        sum+=arr[i];
        k--;
    }
    maxe=arr[arr.size()-1]+sum;
    cout<<maxe<<"\n";
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
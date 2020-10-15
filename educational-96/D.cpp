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
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<lli> freq;
    char a=str[0];
    lli val=0;
    for(char c:str){
        if(c!=a){
            freq.push_back(val);
            val=1;
            a=c;
            continue;
        }
        val++;
    }
    freq.push_back(val);
    // for(int i=0;i<freq.size();i++) cout<<freq[i]<<" ";
    // cout<<"\n";
    lli tot=0,debt=0;
    for(int a:freq){
        tot+=a-1;
    }

    lli ans=0;
    bool kill_next=0;
    bool next=0;
    for(int a:freq){
        if(kill_next){
            if(next) ans++;
            next^=1;
            continue;
        }
        ans++;
        a--;
        if(debt<tot){
            debt++;
        }
        else{
            kill_next=1;
        }
        debt-=min(a,debt);
        tot-=a;
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
    while(t--) solve();
    auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
    // #ifndef ONLINE_JUDGE
	// 	cerr << "Time: " << duration.count() / 1000.0 << endl;
	//     cout<<duration.count()/1000.0<<endl;
    // #endif
    return 0;
}
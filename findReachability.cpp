#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pb push_back
#define read {freopen("input.txt", "r", stdin);} 
#define write {freopen("output.txt", "w", stdout);}
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld pi = 3.14159265358979323846;
const ll mod = 1000000007;


vector<int> adj[1000001];
void solve(int src,int dest,unordered_map<int,int>&mp){
    mp[src]=1;
    for(int i=0;i<adj[src].size();i++){
        if(!mp[adj[src][i]]){
            solve(adj[src][i],dest,mp);
        }
    }
}

int main()
{
    send help 
    int n;cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]=0;
    }

    int e;cin>>e;
    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }

    int src,dest;
    cin>>src>>dest;
    solve(src,dest,mp);
    cout<<mp[dest]<<"\n";
    return 0;
}





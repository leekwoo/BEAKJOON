#include<iostream>
#include<vector>

using namespace std;
using ll= long long;

class segtree{
public:
    vector<ll> tree;
    vector<ll> lazy;
    int size;

    segtree();
    segtree(int n){
        for (size =1; size<n; size*=2);
            tree.resize(2*size);
            lazy.resize(2*size);
    }

    void update_plus(int now, int start, int end, int idx,ll diff){

        if (idx<start || idx> end) return;
        tree[now] += diff;

        if (start != end){
            int mid =(start +end)/2;
            update_plus(now*2,  start, mid, idx,diff);
            update_plus(now*2+1, mid+1, end,idx,diff);

        }
    
        
    }
    void update_lazy(int now, int start, int end){
        if (lazy[now] != 0){
            tree[now]+=(end - start+1)*lazy[now];
            if(start != end){
                lazy[now*2]+=lazy[now];
                lazy[now*2+1]+=lazy[now];
            }
        }
            lazy[now]=0;
        
    }

    void update_range(int now, int start, int end, int L ,int R, ll diff){
         update_lazy(now,start,end);

        int mid=(start +end)>>1;
        if(L>end || R<start)return;
        if(L<=start&&end<=R){
            tree[now]+=(end-start+1)* diff;

            if (start != end){
                lazy[now*2]+=diff;
                lazy[now*2+1]+=diff;
            }
            return;
        }
        update_range(now*2,start, mid,L,R,diff);
        update_range(now*2+1,mid+1, end,L,R,diff);

        tree[now]=tree[now*2]+tree[now*2+1];
    }
    ll getSum(int now, int start, int end, int L ,int R){
        update_lazy(now,start,end);
        if(L>end || R< start) return 0;
        if(L <= start && end<=R)return tree[now];
        int mid=(start +end)/2;
        return getSum(now*2, start ,mid, L ,R)+getSum(now*2+1,mid+1, end,L ,R);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K;
    cin>> N>>M>>K;

    segtree T(N);

    for(int i=1; i<=N; i++){
            int t;
            cin>>t;
            T.update_plus(1,1,T.size,i,t);

            

    }
    for (int i=1; i<=M+K; i++){
                int tmp; cin>>tmp;
                if(tmp==1){
                    ll b,c,d; cin>>b>>c>>d;
                    T.update_range(1,1,T.size,b,c,d);

                }
                else{
                    ll a,b;cin>> a>>b;
                    cout << T.getSum(1,1,T.size,a,b)<<"\n";
                }
            }
}
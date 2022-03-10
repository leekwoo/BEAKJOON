#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dou;
typedef pair<ll, ll> pii;
const ll MOD = 1e9+7;
ll t;
dou a,b,c,d;
ll D(dou p, dou q, dou r){
    dou ret=q*q-4*p*r;
    return ret;
}
int main()
{
    cin >> t;
    cout.precision(9);
    cout << fixed;
    while(t--){
        dou x;
        cin >> a >> b >> c >> d;
        for(dou i=0; i<=2000000; i+=1){
            if(a*i*i*i+b*i*i+c*i+d==0){
                x=i;
                break;
            }
            if(-a*i*i*i+b*i*i-c*i+d==0){
                x=-i;
                break;
            }
        }
        d = a*x*x+b*x+c;
        c = a*x+b;
        b = a;
        if(D(b,c,d)<0){
            cout << x << '\n';
        }
        else{
            set<dou> s;
            s.insert(x);
            s.insert((-c+sqrt(D(b,c,d)))/(2*b));
            s.insert((-c-sqrt(D(b,c,d)))/(2*b));
            for(set<dou>::iterator it=s.begin(); it!=s.end(); ++it)
                cout << *it << ' ';
            cout << '\n';
        }
    }
}
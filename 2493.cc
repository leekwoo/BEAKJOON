#include <iostream>
#include <stack>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<pair<int,int>> ms;

    ms.push({2147483647,0});

    int h;
    for (int i = 1; i <= n;i++){
        cin >> h;
        while (ms.top().first < h){
            ms.pop();
        }
        cout << ms.top().second << " ";
        ms.push({h,i});
    }


}
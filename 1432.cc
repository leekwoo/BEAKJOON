#include <iostream>
#include <functional>
#include <string>
#include <queue>
#include <vector>
using namespace std;
 
vector<int> adj[301];
int ind[301];
int ans[301];
 
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string cur;
        cin >> cur;
        for (int k = 1; k <= N; k++) if (cur[k - 1] == '1') {
            adj[k].push_back(i);
            ind[i]++;
        }
    }
 
    priority_queue<int> pq;
 
    for (int i = 1; i <= N; i++) if (ind[i] == 0) {
        pq.push(i);
    }
 
    int m = N;
    while (!(pq.empty())) {
        int cur = pq.top(); pq.pop();
        ans[cur] = m--;
 
        for (int next : adj[cur]) {
            ind[next]--;
            if (ind[next] == 0) {
                pq.push(next);
            }
        }
    }
 
    if (m != 0) {
        cout << -1;
        return 0;
    }
 
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
 
    /*for (int i = 1; i <= N; i++) {
    for (int k = 1; k <= N; k++) {
    cout << adj[i][k] << ' ';
    }
    cout << endl;
    }*/
 
    return 0;
}
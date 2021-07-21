#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
int main(void) {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    while (n--) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int total = 0;
    while (pq.size() != 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        total += x + y;
        pq.push(x + y);
    }
    cout << total;
    return 0;
}

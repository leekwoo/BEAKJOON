#include <iostream>
 
using namespace std;
 
long long a[100001];
long long tree[1000001];
 
long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
 
void update(int node, int start, int end, int i, long long diff) {
    if (i < start || end < i) {
        return;
    }
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node * 2, start, (start + end) / 2, i, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
    }
}
 
long long sum(int node, int start, int end, int i, int j) {
    if (j < start || end < i) {
        return 0;
    }
    if (i <= start && end <= j) {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, i, j) + sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    init(1, 0, n - 1);
 
    for (int i = 0; i < q; i++) {
        int x, y, index; 
        long long b;
        cin >> x >> y >> index >> b;
 
        if (x > y) {
            swap(x, y);
        }
 
        long long diff = b - a[index - 1];
 
        a[index - 1] = b;
 
        cout << sum(1, 0, n - 1, x - 1, y - 1) << '\n';
        update(1, 0, n - 1, index - 1, diff);
    }
 
    return 0;
}
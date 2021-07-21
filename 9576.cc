#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.second < b.second){
        return true;
    }
    else {
        if (a.second == b.second) {
            if (a.first < b.first){
                return true;
            }
        }
        return false;
    }
}
 
int main(void) {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        pair<int, int> student[1000];
        bool chose[1000] = { false };
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            student[i] = make_pair(a, b);
        }
        sort(student, student + m, cmp);
        int max_cnt = 0;
 
        for (int i = 0; i < m; i++) {
            for (int j = student[i].first; j <= student[i].second; j++) {
                if (!chose[j]) {
                    chose[j] = true;
                    max_cnt++;
                    break;
                }
            }
        }
        cout << max_cnt << endl;
    }
    return 0;
}

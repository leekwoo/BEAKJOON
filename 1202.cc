#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 300000;
int N, K;
int B[MAX];

pair<int, int> J[MAX];
priority_queue<int> pq;

int main(void){
  ios_base::sync_with_stdio(0);
  cin >> N >> K;
  for (int i = 0; i < N; i++)
   cin >> J[i].first >> J[i].second;
  for (int i = 0; i < K; i++)
   cin >> B[i];

  sort(J, J + N);      
  sort(B, B + K);
  long long result = 0;    
  int idx = 0;     

  for (int i = 0; i < K; i++){              
    while (idx < N && J[idx].first <= B[i])         
    pq.push(J[idx++].second);
  
    if (!pq.empty()){       
      result += pq.top();     
      pq.pop();       
    }       
  }        
  cout << result << endl;  
  return 0;        
}
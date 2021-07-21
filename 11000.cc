#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool ascendingOrderByStartTime(const pair<int,int> &a, const pair<int,int> &b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

struct ascendingOrderByEndTime{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b){
		if(a.second==b.second){
			return a.first>b.first;
		}
		return a.second>b.second;
	}
};

int main(){
	vector<pair<int, int> > vec;
	priority_queue<pair<int, int>, vector<pair<int,int> >, ascendingOrderByEndTime > pq;
	
	int N, S, T, cnt=1;
	scanf("%d", &N);
	vec.resize(N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &S, &T);
		vec[i]={S,T};
	}
	
	sort(vec.begin(), vec.end(), ascendingOrderByStartTime);
	pq.push(vec[0]);
	for(int i=1; i<N; i++){
		if(pq.top().second>vec[i].first){
			pq.push(vec[i]);
			cnt++;
		} else {
			pq.pop();
			pq.push(vec[i]);
		}
	}
	
	printf("%d", cnt);
	return 0;
}
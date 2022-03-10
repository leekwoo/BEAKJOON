#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct conference{
    int start;
    int finish;
    conference(int a,int b):start(a),finish(b){}
};
bool operator<(conference a,conference b){
    if(a.finish==b.finish){
        return a.start<b.start;
    }
    return a.finish<b.finish;
}

int main(){
    int n;
    cin >> n;
    vector<conference> vec;
    for( int i=0;i<n;i++){
      
        int starttime, endtime;
        cin >> starttime>> endtime;
        vec.push_back(conference(starttime,endtime));
    }
    sort(vec.begin(),vec.end());
    int answer=1;
    int last=0;

    for(int i=1;i<n;i++){
        if(vec[i].start>=vec[last].finish){
            last=i;
            answer++;
        }
    }
    cout << answer <<endl;
}
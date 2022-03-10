#include <iostream>
#include <vector>
using namespace std;

int n, number, arr[500000];
long long time=0;

vector<int> vec;

void bubbleSort(vector<int> vec){
    int temp;
    for(int j=vec.size(); j>0; j--){
        for(int i=0; i<j; i++){
            if(vec[i]>vec[i+1]){
                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
                time++;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> number; 
        vec.push_back(number);
    }
    bubbleSort(vec);
    cout<< time << endl;
}
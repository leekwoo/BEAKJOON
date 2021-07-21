#include<iostream>
#include<algorithm>
using namespace std;
 
 
int GetSum(const int *arr){
    int sum =0;
    for(int i=0; i<9; i++){
        sum += arr[i];
    }
    return sum;
}
 

int Solution(int *arr){
    int sum = GetSum(arr);
 
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum - (arr[i] + arr[j]) == 100){
                arr[i] = -1;
                arr[j] = -1;
                return 0;
            }
        }
    }
 
    return -1;
}
 
int main(void){
 
    int arr[9];
    for(int i=0; i<9; i++){
        cin>>arr[i];
    }
 
 
    Solution(arr);
 
    sort(arr, arr+9);
 
    for(int i=2; i<9; i++){
        cout << arr[i] << endl;
    }
 
    return 0;
}

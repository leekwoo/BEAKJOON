#include <iostream>
#include <string>

using namespace std;

int main(){
    string get;

    while(1){
        bool check=true;
        int strlen;

        cin>>get;
        if(get=="0"){
            break;
        }
        strlen=get.length();
        int n=strlen/2;
        for(int i=0;i<n;i++){
            if(get[i]!=get[strlen-i-1]){
                check=false;
                break;
            }
        }
        if(check){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }

    }
    while(true);
    
    return 0;
}

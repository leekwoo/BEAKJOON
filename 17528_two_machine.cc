#include<iostream>

void work(int t){
    int a[t];
    int b[t];
    int work_a[t];
    int work_b[t];
    for(int i; i<t+1;t++){
        std::cin>>a[i];
        std::cin>>b[i];
        a[i]=work_a[i];
        b[i]=work_b[i];
    }
}

void compare(int u){
    int w;
    std::cin>>w;
    work(w);
}

int main(){
    

}
//아직 완성 못함
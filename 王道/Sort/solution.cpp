/*
王道上机考试第29页
*/
#include<iostream>
using namespace std;
int main(){
    int n, m, curNumber;
    while(cin>>n&&cin>>m){
        int arr[1000001] = {0};
        for(int i=0; i<n; i++){
            cin >> curNumber;
            arr[curNumber+500000] = 1;
        }
        for(int i=1000000; i>0; i--){
            if(arr[i]==1){
                m--;
                cout << i-500000 << " ";
            } 
            if(!m) break;
        }
        cout << "\n";
    }
    return 0;
}


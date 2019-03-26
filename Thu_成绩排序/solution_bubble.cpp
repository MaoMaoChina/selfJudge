#include<iostream>
using namespace std;
int main(){
    int number;
    while(cin>>number){
        int position[number];
        int mark[number];
        for(int i=0;i<number;i++){
            cin >> position[i] >> mark[i];
        }
        bool flag;
        for(int i=0;i<number-1;i++){
            flag = true;
            for(int j=0;j<number-1-i;j++){
                // 先比较成绩的大小
                if(mark[j]>mark[j+1]){
                    int temp = mark[j];
                    mark[j] = mark[j+1];
                    mark[j+1] = temp;
                    temp = position[j];
                    position[j] = position[j+1];
                    position[j+1] = temp;
                    flag = false;
                }
                // 成绩相同比较学号
                else if (mark[j]==mark[j+1]){
                    if(position[j]>position[j+1]){
                        int temp = mark[j];
                        mark[j] = mark[j+1];
                        mark[j+1] = temp;
                        temp = position[j];
                        position[j] = position[j+1];
                        position[j+1] = temp;
                        flag = false;
                    }
                }
            }
            if(flag) break;
        }
        for(int i=0;i<number;i++){
            cout << position[i] <<" "<< mark[i]<<" "<<endl;
        }
    }
}
#include<iostream>
using namespace std;
int main(){
    int size, given, count;
    int mark; //每次输入的分数
    while(cin>>size&&size!=0){
        //每次均初始化为0
        int marks[101] = {0} ;
        // 运用Hash的思想
        for(int i=0; i<size; i++){
            cin >> mark;
            marks[mark]++;
        }
        cin >> given;
        cout << marks[given]<<endl;
    }
} 


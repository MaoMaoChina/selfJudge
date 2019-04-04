#include<iostream>
using namespace std;
int main(){
    // 分别为数据大小、给定数字、查找到的人数。
    int size;
    int given;
    int count;
    while(cin>>size&&size!=0){
        count = 0;
        int marks[size];
        for(int i=0; i<size; i++) cin>>marks[i];
        cin >>given;
        for(int i=0; i<size; i++){
            // 找到了加一
            if(marks[i]==given) count++;
        }
        cout << count<<endl;
    }
}
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
     /*
     王道第一题
     冒泡排序来解决此题
     */
    int number;
    while(cin>>number){ //用while来保证多组数据的成功测试
        int arr[number];
        for(int i=0;i<number;i++){
            cin >> arr[i];
        }
        bool flag = true; //给定flag，减少判定次数
        int temp;
        for(int i=0;i<number-1&&flag==true;i++){
            flag = false;
            for(int j=0;j<number-i-1;j++){
                if(arr[j]>arr[j+1]){
                    flag = true;       //交换
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        for(int i=0;i<number;i++){ //输出格式要正确
            cout << arr[i]<<" ";
        }
        cout << "\n";
    }
}

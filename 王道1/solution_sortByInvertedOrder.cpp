#include <iostream> 
#include <algorithm> 
using namespace std; 

// 倒序
bool inverted(int x, int y){
    return x > y;
}

int main () {  
    int number;   
    while (cin>>number) {   
        int arr[number];
        for (int i = 0;i < number;i ++) {    
            cin >> arr[i];
    }   // ·sort函数：首地址，尾地址，排序格式(可选)
        sort (arr,arr + number,inverted); 
        //使用该重载形式,表明将要使用自己定义的排列规则   
        for (int i = 0;i < number;i ++) {    
            cout << arr[i] << " " ;  
        }   
        cout<< "\n" ;  
    }  
    return 0; 
}
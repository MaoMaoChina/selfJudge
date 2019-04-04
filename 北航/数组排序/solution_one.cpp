#include<iostream>
using namespace std;
int main(){
    int size,x,y;  //数据量大小以及x和y
    while(cin>>size){
        int arrX[size];  //储存x
        int arrY[size];  //储存y
        for(int i=0;i<size;i++){
            cin>>x>>y;
            arrX[i] = x;
            arrY[i] = y;
        }
        // minX初始为最大值
        int minX = 0x7fffffff;
        // 找出x的最小值
        for(int i=0;i<size;i++){
            if(minX > arrX[i]) minX = arrX[i];
        }
        // 在找出x的最小值的前提下找出y的最小值
        // minY初始为最大值
        int minY = 0x7fffffff;
        for(int i=0;i<size;i++){
            if(arrX[i]==minX){
                if(minY > arrY[i]) minY = arrY[i];
            }
        }
        cout <<minX<<" "<<minY<<"\n";
    }
    
    
}
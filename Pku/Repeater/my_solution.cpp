#include<iostream>
using namespace std;
int main(){
    int size,level,pictureSize;
    while(cin>>size&&size!=0){  //size只可能为3，4，5
        pictureSize = size;
        char temp [size][size];
        for(int i=0; i<size; i++) for(int j=0; j<size; j++)  iftemp[i][j] = getchar();
        cin >> level; //level最大为7
        for(int i=1; i<level; i++) pictureSize *= pictureSize; //算出图片尺寸大小
        char pictureTemp[pictureSize][pictureSize];
        for(int i=0; i<size; i++) for(int j=0; j<size; j++) pictureTemp[i][j] = temp[i][j];
        // for(int i=2; i<=level; i++){
            
        // }
        for(int i=0;i<pictureSize; i++){ 
            for(int j=0; j<pictureSize; j++) 
                cout << pictureTemp[i][j];
            cout<<"\n";
        }
    }
    
}
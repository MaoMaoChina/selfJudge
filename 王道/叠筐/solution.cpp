#include<iostream>
using namespace std;

int main(){
    int width;
    char a,b;
    while(cin>>width){
        string arr[width/2+1]; //存储前半行+1的数据
        string cow;
        cin >> a >> b;
        for(int i=0; i<width-2; i++) cow+=a;
        arr[0] = " " + cow + " "; //现将第一行存储下来;
        cow = "";
        for(int i=0; i<width; i++){
            if((i+1)%2) cow+=a;
            else cow+=b;
        }
        arr[width/2] = cow; //将中间的一行存下来
        // 接下来画除了第一行的上半部分
        for(int i=2; i<(width+1)/2; i++){
            cow = "";
            for(int j=0; j<i/2; j++) cow = cow + a + b;  //开头相同
            if(!(i%2)){ //如果行数为偶数
                for(int j=0; j<width-2*i; j++) cow += b;
            }
            else{  //行数为奇数
                for(int j=0; j<width-2*(i-1); j++) cow += a;
            }
            for(int j=0; j<i/2; j++) cow = cow + b + a;  //结尾相同
            arr[i-1] = cow;
        }
        for(int i=0; i<width/2; i++) cout << arr[i] << "\n";
        cout << arr[width/2] << "\n";
        //上半部分和下半部分相同
        for(int i=width/2-1; i>=0; i--) cout << arr[i] << "\n";
    }

}
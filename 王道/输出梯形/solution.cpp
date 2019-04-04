#include<iostream>
using namespace std;

int main(){
    int width;
    while(cin>>width){
        for(int i=0; i<width;i++){
            for(int j=0; j<(width-1-i)*2; j++) cout<<" ";
            for(int j=0; j<width+i*2; j++) cout<<"*";
            cout<<"\n";
        }
    }

}
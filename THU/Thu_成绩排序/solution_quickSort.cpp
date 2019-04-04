#include <iostream>
using namespace std;
int devide (int low, int high, int position[], int mark[]){
    int povitPosition = position[low];
    int povitMark = mark[low];
    while(low<high){
        // 首先判定成绩，若成绩相同则判定位置，
        while(low<high&&((mark[high]>povitMark)||(mark[high]==povitMark&&position[high]>povitPosition))) high--;
        position[low] = position[high];
        mark[low] = mark[high];
        while(low<high&&((mark[low]<povitMark)||(mark[low]==povitMark&&position[low]<povitPosition))) low++;
        position[high] = position[low];
        mark[high] = mark[low];
    }
    position[low] = povitPosition;
    mark[low] = povitMark;
    return low;
}
void quickSort(int low, int high, int position[], int mark[]){
    int povitloc;
    if(low<high){
        povitloc = devide(low, high, position, mark);
        quickSort(low, povitloc-1, position, mark);
        quickSort(povitloc+1, high, position, mark);
    }

}
int main(){
    int number;
    while(cin>>number){
        // 输入位置和成绩
        int position[number];
        int mark[number];
        for(int i=0;i<number;++i) cin >> position[i] >> mark[i];
        // 排序
        quickSort(0, number-1, position, mark);
        for(int i=0;i<number;++i) cout << position[i] << " " << mark[i] << "\n";
    }

}
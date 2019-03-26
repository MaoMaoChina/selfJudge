/*
quickSort
*/
#include<iostream>
using namespace std;
int Partition(int arr[], int low, int high){
    //对数组进行排序
    int pivotkey = arr[low];
    while(low<high){
        //小的向左移，大的向右移
        while(low<high&&arr[high]>=pivotkey) high--;
        arr[low] = arr[high];
        while(low<high&&arr[low]<=pivotkey) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivotkey;
    return low;
}
void quickSort(int arr[], int low, int high){ 
    //选定排序的数组
    int pivotloc;
    if(low<high){
        pivotloc = Partition(arr, low, high);
        quickSort(arr, low, pivotloc-1);
        quickSort(arr, pivotloc+1, high);
    }
}
int main(){
    int number;
    while(cin>>number){
        int arr[number];
        for(int i=0;i<number;i++){
            cin >> arr[i];
        }
        quickSort(arr, 0, number-1);
        for(int i=0;i<number;i++){
            cout << arr[i]<<" ";
        }
        cout << "\n";
    }
    
}


#include<iostream>
using namespace std;
#define none "No Answer!";
// 快速排序函数2
int partition(int low, int high, int index[], string student[], string sex[], string age[]){
    string tempStudent = student[low], tempSex = sex[low], tempAge = age[low];
    int partitionFlag = index[low];
    while(low<high){
        while(low<high&&index[high]>partitionFlag) high--;
        index[low] = index[high];
        student[low] = student[high];
        sex[low] = sex[high];
        age[low] = age[high];
        while(low<high&&index[low] < partitionFlag) low ++;
        index[high] = index[low];
        student[high] = student[low];
        sex[high] = sex[low];
        age[high] = age[low];
    }
    index[low] = partitionFlag;
    student[low] = tempStudent;
    sex[low] = tempSex;
    age[low] = tempAge;
    return low;
}
// 快速排序函数2
void quickSort(int low, int high, int index[], string student[], string sex[], string age[]){
    int partitionFlag;
    if(low<high){
       partitionFlag = partition(low, high, index, student, sex, age);
       quickSort(low, partitionFlag-1, index, student, sex, age);
       quickSort(partitionFlag+1, high, index, student, sex, age);
    }
}
// 二分查找函数
int queryStudent(int query, int index[],int low, int high ){
    int flag = (low+high)/2;
    while(low<high&&query!=index[flag]){
        if(query>index[flag]) low = flag+1;
        else high = flag-1;
        flag = (low+high)/2;
    }
    if(query==index[flag]) return flag;
    return -1;
}
int main(){
    //  学生数量  查询数量     查询的具体学生   
    int size,    querySize,  query;
    while(cin>>size){
        int index[size];
        string student[size];
        string sex[size];
        string age[size];
        for(int i=0; i<size; i++){
            cin >> index[i]>>student[i]>>sex[i]>>age[i];
        }
        // 先进行排序
        quickSort(0,size-1,index, student, sex, age);
        // 再进行查询
        cin >> querySize;
        for(int i=0; i<querySize; i++){
            cin >> query;
            // 使用二分查找法
            int result = queryStudent(query, index, 0 ,size-1);
            if(result==-1){
                cout << "No Answer!" <<endl;
            } 
            else{
                if(result<10) cout << "0" << index[result]<<" "<<student[result]<<" "<<sex[result]<<" "<<age[result]<<"\n";
                else cout << index[result]<<" "<<student[result]<<" "<<sex[result]<<" "<<age[result]<<"\n";
            }
        }
    }
}
#include <iostream>
#include <string>
using namespace std;
int Partition(int low, int high, int score[], int age[], string names[]){
    int pivotScore = score[low];
    int pivotAge   = age[low];
    string pivotNames = names[low];
while(low<high){
    while(low<high&&score[high]>pivotScore) high--;
    if(score[high]==pivotScore){
        if(names[high].compare(pivotNames)<0){
            score[low] = score[high];
            age[low] = age[high];
            names[low] = names[high];
        }
        else if(names[high].compare(pivotNames)==0){
            if(age[high]<pivotAge) {
                score[low] = score[high];
                age[low] = age[high];
                names[low] = names[high];
            }
        }
    }
    while(low<high&&pivotScore>score[low]) low++;
    if(pivotScore==score[low]){
        if(names[low].compare(pivotNames)>0){
            score[high] = score[low];
            age[high] = age[low];
            names[high] = names[low];
        }
        else if(names[low].compare(pivotNames)==0){
            if(age[low]>pivotAge) {
                score[high] = score[low];
                age[high] = age[low];
                names[high] = names[low];
            }
        }
    }
}
score[low] = pivotScore;
age[low] = pivotAge;
names[low] = pivotNames;
return low;
}
void quickSort(int low, int high, int score[], int age[], string names[]){
    cout<<"maomao";
    int pivotkey;
    if(low<high){
        cout <<1;
        pivotkey =  Partition(low, high, score, age, names);
        quickSort(low, pivotkey-1, score, age, names);
        quickSort(pivotkey+1, high, score, age, names);
    }
}

int main(){
    int number ;
    while(cin>>number){
        string names[number];
        int age[number];
        int score[number];
        
        for(int i=0; i<number;i++){
            cin >> names[i] >> age[i] >> score[i];
        }
        quickSort(0, number-1, score, age, names);
        for(int i=0;i<number;++i){
            cout<<score[i]<<" "<<age[i]<<" "<<names[i]<<"\n";
     }
    }
}
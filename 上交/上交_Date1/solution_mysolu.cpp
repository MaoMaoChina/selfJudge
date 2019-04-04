#include<iostream>
using namespace std;
// 预定义每个月含有的天数
int dayOfmonth[12][2] = {
    31,31, 
    28,29,  
    31,31,  
    30,30,  
    31,31,  
    30,30,  
    31,31,  
    31,31,  
    30,30,  
    31,31,  
    30,30,  
    31,31 
};
int contributeDay(int y, int m, int d){
    int count=0;
    // flag代表选择闰年还是平年
    int flag=0;
    if((y%4==0&&y%100!=0)||y%400==0) flag=1;
    for(int i=0; i<m-1; i++) count+=dayOfmonth[i][flag];
    count += d;
    return count;
}
int contributeYear(int y1, int y2){  // 其中y1 > y2
 int leapY1, leapY2;
 int commonY1, commonY2;
 // 计算有多少个闰年和平年;
 leapY1 = y1/4 - y1/100 + y1/400;
 leapY2 = y2/4 - y2/100 + y2/400;
 commonY1 = y1-leapY1;
 commonY2 = y2-leapY2;
 return 366*(leapY1-leapY2) + 365*(commonY1-commonY2);
}
int main(){
    int d1, m1, y1;
    int d2, m2, y2;
    int count;
    while (scanf ("%4d%2d%2d",&y1,&m1,&d1) != EOF) {
        scanf ("%4d%2d%2d",&y2,&m2,&d2); //读入要计算的两个日期  
        // 若y1 < y2 则交换两个输入的日期
        if(y1<y2){
            int tempy = y1, tempm = m1, tempd = d1;
            y1 = y2;
            m1 = m2;
            d1 = d2;
            y2 = tempy;
            m2 = tempm;
            d2 = tempd;
        }
        count = contributeDay(y1,m1,d1) - contributeDay(y2,m2,d2);
        if(y1==y2){
            count = count < 0? -count:count;
        }
        else{
            count += contributeYear(y1-1,y2-1);
        }
        cout << count+1<<endl; 
    }
}
#include<iostream>
using namespace std;
// 预定义宏，判断是否为闰年。
#define ISLEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0 

int dayOfmonth[13][2] = {
    0 ,0,
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
};  //预存每月的天数

struct Date {
    int Day;
    int Month;
    int Year;

    void nextDay(){
        Day ++;
        
    }
}
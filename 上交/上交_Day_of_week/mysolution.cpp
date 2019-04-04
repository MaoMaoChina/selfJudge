#include <iostream>
using namespace std;
//定义12个月份含有的天数
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
//定义12个月的英文
string months[12] ={
"January",
"Feburary",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December"
};
string Day[7] ={
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday",
"Sunday"
};
int countDay(int y, int m, int d){
    int count=0;
    // flag代表选择闰年还是平年
    int flag=0;
    if((y%4==0&&y%100!=0)||y%400==0) flag=1;
    for(int i=0; i<m-1; i++) count+=dayOfmonth[i][flag];
    count += d;
    return count;
}
int countYear(int y1, int y2){  // 其中y1 > y2
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
    int date, t_date, year, t_year, t_month;
    string month;
    int IntegerMonth;
    int count;
    bool less ; //判定当前日期是否小于给定日期
while(cin>>date){
    count = 0;
    t_year = 2019;
    t_month = 4;
    t_date = 1;
    less = 0;
    // 输入数据额
    cin >> month >> year;
    //判定当前是哪一月
    for(int i=0; i<12; i++){
        if(months[i]==month){
            IntegerMonth = i+1;
            break;
        }
    }
    // cout << IntegerMonth <<" "<< year << " "<<date<<endl;
    // 大于今天,交换
    if(year>2019){
        less=1;
        t_year  = year;
        t_month = IntegerMonth;
        t_date  = date;
        year = 2019;
        IntegerMonth = 4;
        date = 1;
    }
    if(year == t_year){
        // 计算相差的天数
        count += countDay(t_year, t_month, t_date) - countDay(year, IntegerMonth, date);
        // 检验今天是否小于所给日期
        less = count < 0 ? 1 : 0;
        // 小于
        if(less){
            count = -count;
            count = count%7;
            cout << Day[count] <<endl;
        }
        else{
            count = count % 7;
            cout << Day[(7-count)%7]<<endl;
        }
    }
    else{
        //计算相差的年份和天数
        count += countYear(t_year-1, year-1) + countDay(t_year, t_month, t_date) - countDay(year, IntegerMonth, date);
        // cout << countDay(t_year, t_month, t_date) - countDay(year, IntegerMonth, date)<<endl;
        count = count%7;
        if(less){
            cout << Day[count] <<endl;
        }
        else{
            cout << Day[(7-count)%7]<<endl;
        }

    }
    
}
   
}
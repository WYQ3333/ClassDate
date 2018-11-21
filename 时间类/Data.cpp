#include<iostream>
using namespace std;

class Date{
public:
	//构造函数，完成成员变量的初始化
	Date(int year=1900, int month=1, int day=1){
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	//日期加days后的日期
	Date operator+(int days)
	{
		int array[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };
		if ((this->_year % 4 == 0 && this->_year % 100 != 0) || (this->_year % 400 == 0))//闰年
		{
			array[1] = 29;//2月有29天
		}
		else
		{
			array[1] = 28;
		}
		Date d(this->_year,this->_month,this->_day);
		d._day = d._day + days;
		while (d._day > array[d._month-1])
		{
			d._day = d._day + array[d._month-1];
			d._month++;
			if (d._month > 12)
			{
				d._month = d._month % 12;
				d._year++;
				if ((this->_year % 4 == 0 && this->_year % 100 != 0) || (this->_year % 400 == 0))//闰年
				{
					array[1] = 29;//2月有29天
				}
			}
		}
		return d;
	}
	//日期减去days后的日子
	Date operator-(int days)
	{
	}
	//打印
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//析构函数，完成资源的清理工作
	~Date(){
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 11, 21);
	cout << "d1的日期为：";
	d1.PrintDate();
	Date d2(d1);
	cout << "拷贝d2的日期为：";
	d2.PrintDate();
	Date d3 = d1;
	cout << "d3被d1赋值的日期为：";
	d3.PrintDate();
	Date d4 = d3 + 10;
	cout << "d4+2的日期为：";
	d4.PrintDate();
	system("pause");
	return 0;
}
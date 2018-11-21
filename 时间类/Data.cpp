#include<iostream>
using namespace std;

class Date{
public:
	//���캯������ɳ�Ա�����ĳ�ʼ��
	Date(int year=1900, int month=1, int day=1){
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ���������
	Date& operator=(const Date& d)
	{
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	//���ڼ�days�������
	Date operator+(int days)
	{
		int array[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((this->_year % 4 == 0 && this->_year % 100 != 0) || (this->_year % 400 == 0))//����
		{
			array[1] = 29;//2����29��
		}
		else
		{
			array[1] = 28;
		}
		Date d(this->_year,this->_month,this->_day);
		d._day = d._day + days;
		while (d._day > array[d._month-1])
		{
			d._day = d._day - array[d._month-1];
			d._month++;
			if (d._month > 12)
			{
				d._month = 1;
				d._year++;
				if ((d._year % 4 == 0 && d._year % 100 != 0) || (d._year % 400 == 0))//����
				{
					array[1] = 29;//2����29��
				}
				else
				{
					array[1] = 28;
				}
			}
		}
		return d;
	}
	//���ڼ�ȥdays�������
	Date operator-(int days)
	{
		int array[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((this->_year % 4 == 0 && this->_year % 100 != 0) || (this->_year % 400 == 0))//����
		{
			array[1] = 29;//2����29��
		}
		else
		{
			array[1] = 28;
		}
		Date d(this->_year, this->_month, this->_day);
		int tmp = d._day;
		int count = 1;
		d._day = d._day - days;
		while (d._day <=0)
		{
			/*if (count == 1)
			{
				d._day = d._day + tmp;
				d._month--;
				count = 0;
			}*/
			d._month--;
			if (d._month <= 0)
			{
				d._year--;
				if ((d._year % 4 == 0 && d._year % 100 != 0) || (d._year % 400 == 0))//����
				{
					array[1] = 29;//2����29��
				}
				else
				{
					array[1] = 28;
				}
				d._month = 12;
			}
			d._day = d._day + array[d._month - 1];
		}
		return d;
	}
	//��ӡ
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//���������������Դ��������
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
	cout << "d1������Ϊ��";
	d1.PrintDate();
	Date d2(d1);
	cout << "����d2������Ϊ��";
	d2.PrintDate();
	Date d3 = d1;
	cout << "d3��d1��ֵ������Ϊ��";
	d3.PrintDate();
	Date d4 = d3 + 1;
	cout << "d3+10000������Ϊ��";
	d4.PrintDate();
	Date d5 = d3 - 100;
	cout << "d3-10000������Ϊ��";
	d5.PrintDate();
	system("pause");
	return 0;
}
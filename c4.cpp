#include <iostream>
using namespace std;

// 建议：尽量不要使用成员初始化成员
//      初始化列表中成员的出现次序最好与其在类中的声明次序保持一致

// Date总共创建了多少个有效对象？
// 构造构造  拷贝构造函数 析构函数  
// 最终需要结果：对象的个数---计数--int
#if 0
int _count = 0;
class Date{
public:
	Date(int year,int month,int day)
	:_year(year)
	, _month(_day)//初始化?
	,_day(day){
		_count++;

}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day){
		++_count;//先后次序
	}
	~Date(){
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate(){
	Date d3(2019,9,16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << _count << endl;
}

int main(){
	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << _count << endl;
	_count = 0;//?
	TestDate();
	_count = 100;//?
	cout << _count << endl;//调用析构函数98??
	return 0;
}
#endif

#if 0
class Date{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(_day)//?
		, _day(day){
		_count++;

	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day){
		++_count;
	}
	~Date(){
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;
public:
	static int _count;

};
int Date::_count = 0;
void TestDate(){

	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::_count << endl;
}
int main(){
	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << &d1._count << " " << &d2._count << endl;//?
	cout << Date::_count << endl;
	cout << sizeof(Date) << endl;//?
	TestDate();
	return 0;
}
#endif


#if 0
class Date{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(_day)//?
		, _day(day){
		_count++;

	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day){
		++_count;
	}
	~Date(){
		_count--;
	}
	void Testfun(){
		_day++;
		cout <<_count << endl;
	}
	static int Getcount(){
		//TestFunc();
		//cout << this << endl;
		//_day++;//?
		return _count;
	}
private:
	int _year;
	int _month;
	int _day;
public:
	static int _count;
	
};
int Date::_count = 0;

void TestDate(){
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::Getcount << endl;
	
	
}
int main(){
	cout << Date::Getcount << endl;
	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << Date::Getcount << endl;
	TestDate();
	cout << Date::Getcount << endl;//不进入函数?
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(_day)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		_day++;
		cout << _count << endl;
		GetCount();
	}


	static int GetCount()
	{
		//TestFunc();
		//cout << this << endl;
		//_day++;
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};



int Date::_count = 0;


int main()
{
	int sum = 0;

	Date d1(2019, 9, 16);
	sum += Date::GetCount();

	Date d2(d1);
	sum += Date::GetCount();

	Date d3(d1);
	sum += Date::GetCount();//sum值为6
	return 0;
}
#endif

#if 0
//友元问题
class Date{
public:Date(int year, int month, int day) 
	   :_year(year)
	   ,_month(month)
	   ,_day(day){

}
	   ostream& operator<<(ostream& _cout){
		   _cout << d.year << d.month << d.day
			   return _cout;//?
	   }
private:
	int _year;
	int _month;
	int _day;
};
int main(){
	Date d(2019,10,6);
	d << cout;
	return 0;

}
#endif

//友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加friend关键字
class Date{
	friend ostream& operator<<(ostream& _cout,const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
public:Date(int year, int month, int day)
	   :_year(year)
	   , _month(month)
	   , _day(day){

}
	  
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d){
	_cout << d._year << d._month << d._day;
	return _cout;
}
// istream& operator>>(istream& _cin, const Date& d){
//	_cin >> d._year;  
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}


int main(){
	Date d(2019, 10, 6);
    cout << d<<endl;
	return 0;

}
#include <iostream>
using namespace std;

// ���飺������Ҫʹ�ó�Ա��ʼ����Ա
//      ��ʼ���б��г�Ա�ĳ��ִ���������������е��������򱣳�һ��

// Date�ܹ������˶��ٸ���Ч����
// ���칹��  �������캯�� ��������  
// ������Ҫ���������ĸ���---����--int
#if 0
int _count = 0;
class Date{
public:
	Date(int year,int month,int day)
	:_year(year)
	, _month(_day)//��ʼ��?
	,_day(day){
		_count++;

}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day){
		++_count;//�Ⱥ����
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
	cout << _count << endl;//������������98??
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
	cout << Date::Getcount << endl;//�����뺯��?
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
	sum += Date::GetCount();//sumֵΪ6
	return 0;
}
#endif

#if 0
//��Ԫ����
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

//��Ԫ��������ֱ�ӷ������˽�г�Ա�����Ƕ��������ⲿ����ͨ�������������κ��࣬����Ҫ������ڲ�����������ʱ��Ҫ��friend�ؼ���
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
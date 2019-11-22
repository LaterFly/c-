#include <iostream>
using namespace std;
#include <string>

#if 0
class Person{
public:
	Person(const string& name, const string& gender, int age)
		:_name(name)
		,_gender(gender)
		,_age(age)
	{}
	virtual void BuyTicket(){
		cout << "ȫ��Ʊ" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};


class Student :public Person{
public:
	Student(const string& name, const string& gender, int age,int StuId)
		:Person(name, gender, age)
		, _StuId(StuId)
	{}
	virtual void BuyTicket(){
		cout << "���Ʊ" << endl;
	}
protected:
	int _StuId;
};

class Soilder :public Person{
public:
	Soilder(const string& name,const string& gender,int age,const string& rank)
		:Person(name,gender,age)
		, _rank(rank)
	{}
	virtual void BuyTicket(){
		cout << "���" << endl;
	}
protected:
	string _rank;
};

// ����ͨ�������ָ�������������
// ��̬�����֣��������ʱ������ȷ�����׵����Ǹ�����麯��
//           �ڴ�������ʱ������p��ָ���ʵ�ʶ���ѡ����ö�Ӧ����麯��
// �����̬��ʵ������û����ȫ���㣺1. ��дʧ��(���ຯ�������麯��������ԭ�Ͳ�һ��)
//                            2. û��ͨ�������ָ��������õ����麯�� 
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}
void TestBuyTicket(Student& p)
{
	p.BuyTicket();
}
void TestBuyTicket(Soilder& p)
{
	p.BuyTicket();
}


int main(){
	Person p("С��","Ů",22);
	Student s("С��", "��", 23,2022);
	Soilder so("����", "��", 24,"��ξ");
	TestBuyTicket(p);
	TestBuyTicket(s);
	TestBuyTicket(so);
	return 0;
}

#endif

#if 0
struct A{};
struct B :public A{};
class Base{

public:
	virtual void TestFunc1(){
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2(int){
		cout << "Base::TestFunc2()" << endl;
	}
	 void TestFunc3(){
		cout << "Base::TestFunc3()" << endl;
	}
	virtual void TestFunc4(){
		cout << "Base::TestFunc4()" << endl;
	}
	virtual Base* TestFunc5(){
		cout << "Base::TestFunc5()" << endl;
		return this;
	}
	virtual A& TestFunc6(A& a)
	{
		cout << "Base::TestFunc6()" << endl;
		return a;
	}
};

class Derived :public Base{
public:
	virtual void TestFunc1(){
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc2(){
		cout << "Derived::TestFunc2()" << endl;
	}
	virtual void TestFunc3(){
		cout << "Derived::TestFunc3()" << endl;
	}
	void TestFunc4(){
		cout << "Derived::TestFunc4()" << endl;
	}
	virtual Derived* TestFunc5(){
		cout << "Derived::TestFunc5()" << endl;
		return this;
	}
	virtual B& TestFunc6(A& a)
	{
		cout << "Derived::TestFunc6()" << endl;
		return *(new B);
	}

};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2(10);
	pb->TestFunc3();
	pb->TestFunc4();
	pb->TestFunc5();

	A a;
	pb->TestFunc6(a);
}
int main(){
	Base b;
	Derived d;
	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	return 0;
}
#endif


#if 0
// C++11:
// override: ֻ��������������麯��
//           ���ã��ñ����������û������������ĳ���麯���Ƿ���д�˻�����Ǹ��麯��
class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc()override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	int _d;
};

void TestVirtualFunc(Base* pb)
{
	pb->TestFunc();
}


int main()
{
	Base b;
	Derived d;
	TestVirtualFunc(&b);
	TestVirtualFunc(&d);
	return 0;
}
#endif


#if 0
// final: ������--->��ʾ���಻�ܱ��̳�
//        �����麯������--->


class Base
{
public:
	virtual void TestFunc()const
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

// ������Derived�������У���������������дTestFunc���麯��
// C++98��������
// C++11:�ṩ��final�Ĺؼ��ֿ�������
// final�����麯�����������麯�����������������б���д(һ��final����������麯��)
class Derived : public Base
{
public:
	virtual void TestFunc()const override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	int _d;
};
#endif


# if 0
class WC
{
public:
	void ManRoom(){
		cout << "go to left" << endl;
	}
	void WOManRoom(){
		cout << "go to right" << endl;
	}
};

// ������--�����д��麯������
// ���ԣ�����ʵ�������󣬵����Դ��������ָ��(����)
// ���ã��淶����ӿ�

class Person{
public:
	// ���麯��
	virtual void GoWC(WC& wc) = 0;
	string _name;
	int _age;
};

class Man :public Person{
public:
	void GoWC(WC& wc){
		wc.ManRoom();
	}

};

class WOMan :public Person{
public:
	void GoWC(WC& wc){
		wc.WOManRoom();
	}

};

// Monster��Ҳ�ǳ����࣬��Ϊ����û����д�����еĴ��麯��
class Monster : public Person
{};

#include <windows.h>
#include <time.h>
void TestWC(int n){
	WC wc;
	srand(time(nullptr));
	for (int i = 0; i < n;i++){
		Person* s;
		if (rand() % 2 == 0){
			s = new Man;
		}
		else
		    s = new WOMan;
		s->GoWC(wc);
		delete s;

		Sleep(1000);
	}

}
int main(){
	Person* p;

	//Monster m;
	TestWC(10);
	return 0;
}
#endif


#if 0
//���һ�����а������麯�������С����ĸ��ֽ�
//�����������������һ��Ĭ�ϵĹ��캯��
class Base
{
public:
	// 	Base()
	// 	{}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	int _b;
};


int main()
{
	cout << sizeof(Base) << endl;

	Base b;
	b._b = 1;

	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void TestFunc1(){
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2(){
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3(){
		cout << "Base::TestFunc3()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	int _d;
};



typedef void(*PVFT)();
void PrintTable(Base& b,const string str){
	cout << str << endl;
	//&b;  // ָ�������
	//(int*)&b; // ָ������ǰ4���ֽ�
	//*(int*)&b; // ����ǰ4���ֽ�������--->����������
	// ����������ת���ɱ����׵�ַ--->��Ҫ֪�������Ԫ�ص�����--->ǰ���Ѿ��������д洢�����麯���ĵ�ַ

	PVFT* pVFT = (PVFT*)(*(int*)&b);

	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;

}

int main(){
	cout << sizeof(Base) << endl;

	Base b1, b2;

	Base b;
	b._b = 1;

	cout << sizeof(Derived) << endl;
	Derived d;
	d._b = 1;
	d._d = 2;

	PrintTable(b, "Base VFT:");
	PrintTable(d, "Derived VFT:");

	// ȷ��TestFunc4��TestFunc5����ڵ�ַ
	d.TestFunc4();
	d.TestFunc5();
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	int _d;
};

// �麯���ĵ��ã�ͨ�������ָ��������õ����麯��
void TestVirtual(Base* pb)
{
	pb->TestFunc1(); // call Base::TestFunc1
	pb->TestFunc2(); // call Base::TestFunc2
	pb->TestFunc3(); // call Base::TestFunc3
	pb->TestFunc4(); // call Base::TestFunc4
}

int main()
{
	Base b;
	Derived d;

	TestVirtual(&b);
	TestVirtual(&d);

	// 
	Base* pb = (Base*)&d;
	pb->TestFunc1();
	return 0;
}
#endif


#if 0
// �����麯���Ķ�̳�������Ķ���ģ��

// 8
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2()" << endl;
	}
	int _b1;
};

// 8
class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "B2::TestFunc4()" << endl;
	}
	int _b2;
};

// 20   24
class D : public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}

	int _d;
};


typedef void(*PVFT)();

void PrintVFT1(B1& b, const string& str)
{
	cout << "D��дB1��������" << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

void PrintVFT2(B2& b, const string& str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)(*(int*)&b);
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFT1(d, "D��дB1��������");
	PrintVFT2(d, "D��дB2��������");

	return 0;
}
#endif



#include <iostream>

using namespace std;
#include <string>
#if 0
// ��Ʊ
// ��ͨ��
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		: _name(name)
		, _gender(gender)
		, _age(age)
	{}

	// �麯��
	virtual void BuyTicket()
	{
		cout << "ȫ��Ʊ" << endl;
	}

protected:
	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	Student(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}
protected:
	int _stuId;
};

class Soilder : public Person
{
public:
	Soilder(const string& name, const string& gender, int age, const string& rank)
		: Person(name, gender, age)
		, _rank(rank)
	{}

	void BuyTicket()
	{
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
//   
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}

/*
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
*/

int main()
{
	Person p("Peter", "��", 18);
	Student st("С˧", "Ů", 19, 1000);
	Soilder so("����", "��", 23, "�೤");
	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	return 0;
}
#endif

#if 0
struct A{};
struct B :public A{};

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2(int)
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual Base* TestFunc5()
	{
		cout << "Base::TestFunc5()" << endl;
		return this;
	}

	virtual A& TestFunc6(A& a)
	{
		cout << "Base::TestFunc6()" << endl;
		return a;
	}
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

	void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	virtual Derived* TestFunc5()
	{
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
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base::Base()" << endl;
	}

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	Derived(int b)
		: Base(b)
		, _p(new int[10])
	{
		cout << "Derived::Derived(int)" << endl;
	}

	~Derived()
	{
		delete[] _p;
		cout << "Derived::~Derived()" << endl;
	}

protected:
	int* _p;
};

void TestDestroy()
{
	Base* pb = new Derived(10);
	delete pb;
}

int main()
{
	TestDestroy();
	return 0;
}

#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}

		return *this;
	}

	void SetBase(int b)
	{
		_b = b;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			// �����ಿ�ֳ�Ա��ֵ
			Base::operator=(d);

			// �������������ӳ�Ա��ֵ
			_d = d._d;
		}

		return *this;
	}

	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}

protected:
	int _d;
};


int main()
{
	Base b(10);
	Derived d1(10, 20);
	Derived d2(d1);

	Derived d3(30, 40);
	d2 = d3;
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base::Base(int)" << endl;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{
		cout << "Derived::Derived(int,int)" << endl;
	}

	~Derived()
	{
		cout << "Derived::~Derived()" << endl;
		// call Base::~Base();
	}

protected:
	int _d;
};


// 1. ���н�����ӡ���
/*
Base::Base(int)
Derived::Derived(int,int)
Derived::~Derived()
Base::~Base()
*/
// 2. ����������ĵ��ô���
/*
�������ִ�д����ȵ����๹��--->�����๹��--->����������--->��������

�������
�����๹�캯��()
: ���๹�캯������
{}

��������
��������������()
{
// �ͷ���������Դ

// �������������������������һ����Ч�������һ��������
   ������������;
}
*/
void TestDerived()
{
	Derived d(10, 20);
}

int main()
{
	TestDerived();
	return 0;
}
#endif

#if 0
// C++98
// ���һ���಻�ܱ��̳�
class Base
{
public:
	static Base GetObject(int b)
	{
		return Base(b);
	}

private:
	Base(int b)
		: _b(b)
	{}

protected:
	int _b;
};

#if 0
class Derived : public Base
{
	/*
	public:
	Derived()
	: Base()
	{}

	��Ϊ���๹�캯������Ȩ����private�����������оͲ���
	ֱ�ӱ����ã����������Ĺ��캯���޷�����
	*/
};
#endif


int main()
{
	// Derived d;
	Base b(Base::GetObject(10));
	return 0;
}
#endif

#if 0
// final�������һ���ࣺ��ʾ���಻�ܱ��̳�
class Base final
{
public:
	Base(int b)
		: _b(b)
	{}

protected:
	int _b;
};

class Derived : public Base
{};

int main()
{
	return 0;
}
#endif


#if 0
// ��Ԫ��ϵ�����ܱ��̳�
class Base
{
	friend void Print();
public:
	Base(int b)
		: _b(b)
	{}

	int GetB()
	{
		return _b;
	}
protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

protected:
	int _d;
};

void Print()
{
	Base b(10);
	cout << b.GetB() << endl;
	cout << b._b << endl;

	Derived d(10, 20);
	cout << d._d << endl;
}
#endif

#if 0
// ͳ��һ���ഴ���˶��ٸ�����
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		: _name(name)
		, _gender(gender)
		, _age(age)
	{
		_count++;
	}

	Person(const Person& p)
		: _name(p._name)
		, _gender(p._gender)
		, _age(p._age)
	{
		++_count;
	}

	~Person()
	{
		--_count;
	}

protected:
	string _name;
	string _gender;
	int _age;

public:
	static size_t _count;
};

size_t Person::_count = 0;


class Student : public Person
{
public:
	Student(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	Student(const Student& s)
		: Person(s)
		, _stuId(s._stuId)
	{}


protected:
	int _stuId;
};

class Teacher : public Person
{
public:
	Teacher(const string& name, const string& gender, int age, int stuId)
		: Person(name, gender, age)
		, _stuId(stuId)
	{}

	Teacher(const Teacher& s)
		: Person(s)
		, _stuId(s._stuId)
	{}


protected:
	int _stuId;
};



void TestPerson()
{
	Person p("111", "��", 18);
	Student s("222", "Ů", 18, 20);

	cout << Person::_count << endl;
	cout << Student::_count << endl;

	cout << &Person::_count << endl;
	cout << &Student::_count << endl;
	cout << &Teacher::_count << endl;

	/*
	���ۣ�
	1. �����о�̬��Ա�������Ա�����̳�
	2. �������̳���ϵ�У���̬��Ա����ֻ��һ��//?
	*/
}

int main()
{
	TestPerson();
	return 0;
}
#endif


#if 0
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

// ע�⣺ÿ������ǰ��������̳�Ȩ�ޣ��������Ĭ�ϵļ̳�Ȩ��
class D : public B2, public B1
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif

#if 0
class B
{
public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	//d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
	return 0;
}
#endif

#if 0
// ��������̳�
class B
{
public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

#if 0
	D d;
	d._b = 1;  // ���μ̳�ȱ�ݣ�����ڶ���������

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
#endif

	// ��������̳�

	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	return 0;
}
#endif

#if 0
// ����̳�
class B
{
public:
	int _b;
};

class D : virtual public B
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = 1;
	d._d = 2;

	return 0;
}
#endif

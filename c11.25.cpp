#include<iostream>
using namespace std;

#if 0
class Base{
public:
	void SetBase(int pri,int pro,int pub){
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase(){
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;


};

class Derived :public Base{};
int main(){
	cout << sizeof(Derived) << endl;
	Derived d;
	d.SetBase(1,2,3);
	d.PrintBase();
	return 0;
}
#endif


#if 0
// public�̳з�ʽ��
class Base{
public:
	void SetBase(int pri, int pro, int pub){
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase(){
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;


};

class Derived :public Base{
public:
	void SetDerived(int priD,int proD,int pubD){
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		 //_pri = 20; // ���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	

	// ����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
}

private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;


};

int main()
{
	Derived d;
	cout << sizeof(d) << endl;

	d._pub = 10;
	// d._pro = 10;
	return 0;
}
#endif

#if 0
class Base{
public:
	void SetBase(int pri, int pro, int pub){
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase(){
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

// �̳з�ʽ--protected
// ������public�ĳ�Ա�������з���Ȩ���Ѿ����protected
// ������protected�ĳ�Ա�������з���Ȩ�޲���
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)

class Derived :protected Base{
public:
	void SetDerived(int priD, int proD, int pubD){
		_priD = priD;
		_proD = proD;
		_pubD = pubD;
	
		_pro = 10;
		
	}

private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};

class D :public Derived{
public:
	void Test()
	{
		_pub = 10;
		_pro = 20;
	}
};
int main(){
	Derived d;
	//d._pub = 1;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};


// �̳з�ʽ--private
// ������public�ĳ�Ա�������з���Ȩ���Ѿ����private
// ������protected�ĳ�Ա�������з���Ȩ���Ѿ����private
// ������private�ĳ�Ա�������в��ɼ�(������---�ó�Ա����ȷʵ�Ѿ��̳е�������)
class Derived : private Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;

		_pro = 10;
		// _pri = 20; // ���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}

	// ����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
public:
	int _pubD;
protected:
	int _proD;
private:
	int _priD;
};

class D : public Derived
{
public:
	void Test()
	{
		// _pub = 10;
		//_pro = 20;
	}
};

int main()
{
	Derived d;
	d._pub = 10;
	return 0;
}
#endif

#if 0
class B{
public:
	void SetB(int b){
		_b = b;
	}
protected:
	int _b;
};

class D :public B{
public:
	void SetD(int b,int d){
		_b = b;
		_d = d;
	}

//protected:
	int _d;
};

// ��ֵ���ݹ���ǰ��---->public
// �����public�̳з�ʽ����������������֮����--is-a�Ĺ�ϵ
// is-a: ��һ�������Խ�һ��������󿴳���һ���������
// �����õ���������λ�ö�����ʹ�����������д���

int main(){
	B b;
	b.SetB(10);
	D d;
	d.SetB(1);
	d.SetD(10,11);

	b = d;// ��������������������������и�ֵ


	// һ������ָ�����ָ���������
	// һ�������ָ�벻��ֱ��ָ��һ������Ķ���

	B* pb = &d;
	D* pd =(D*) &b;
	pd->_d = 10;

	B& rb = d;
	//D& rd = b;

	// d = b;
	return 0;
}
#endif



// ͬ�����أ�������������о�����ͬ���Ƶĳ�Ա(��Ա���� || ��Ա����)
// ���ͨ�����������ֱ�ӷ���ͬ����Ա�����ȷ��ʵ������������Լ��ģ������
// ͬ����Ա����ֱ�ӷ��ʵ�(�����ཫ�����е�ͬ����Ա����)

// ��Ա����������������Ƿ���ͬ�޹�
// ��Ա���������Ա����ԭ���Ƿ���ͬ�޹�
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}

	void Test(int a)
	{}

	// protected:
	char _b;
};
class D : public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
	}

	void Test()
	{}

	//protected:
	int _b;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = '1';
	d.B::_b = '2';

	d.Test();
	d.B::Test(10);
	d.SetD(1, 2);
	return 0;
}
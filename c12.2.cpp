#include<iostream>
using namespace std;

#if 0
template<class T>
class Smartptr{
public:
	Smartptr(T* ptr = nullptr)
	:_ptr(ptr){
		cout << "Smartptr" << endl;
	}
	~Smartptr(){
		cout << "~Smartptr()" << endl;
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}
private:
	T* _ptr;
};

struct B
{
	int a ;
	int b ;
	int c;
};

void Test(){
	Smartptr <int> sp(new int );
	*sp = 10;
	Smartptr<B> sp1(new B);
	sp1->a = 10;
}
int main(){
	Test();
	return 0;
}
#endif

#if 0
template<class T>
class Smartptr{
public:
	Smartptr(T* ptr = nullptr)
		:_ptr(ptr){
		cout << "Smartptr" << endl;
	}
	~Smartptr(){
		cout << "~Smartptr()" << endl;
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}
private:
	T* _ptr;
};


void Test(){
	Smartptr <int> sp(new int);
	*sp = 10;
	Smartptr<int> sp1(sp);
}
int main(){
	Test();
	return 0;
}
#endif

#if 0
namespace AUTO_Ptr{
template<class T>
class auto_ptr{
public:
	auto_ptr(T* ptr = nullptr)
			:_ptr(ptr){
			cout << "Smartptr" << endl;
	}
	~auto_ptr(){
			cout << "~Smartptr()" << endl;
			if (_ptr){
				delete _ptr;
				_ptr = nullptr;
			}
	}
	auto_ptr(auto_ptr<T>& sp)
	:_ptr(sp._ptr){
		sp._ptr = nullptr;
	}
	auto_ptr<T>& operator=(auto_ptr<T>& sp)
	{
		if( this!=&sp){
			if (_ptr)
				delete _ptr;
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
	}
	T& operator*(){
			return *_ptr;
	}
	T* operator->(){
			return _ptr;
	}

private:
		T* _ptr;
	};
}
#endif

#if 0
namespace AUTO_Ptr{
template<class T>
class auto_ptr{
public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		,_owner(false){
			if (_ptr)
				_owner = true;
		}
		~auto_ptr(){
			
			if (_ptr&&_owner){
				delete _ptr;
				_ptr = nullptr;
			}
		}
		auto_ptr(auto_ptr<T>& sp)
			:_ptr(sp._ptr)
		,_owner(sp._owner){

			sp._owner = false;
		}
		auto_ptr<T>& operator=(auto_ptr<T>& sp)
		{
			if (this != &sp){
				if (_ptr&&_owner)
					delete _ptr;
				_ptr = sp._ptr;
				_owner = sp._owner;
				sp._owner = false;
			}
			return  *this;
		}
		T& operator*(){
			return *_ptr;
		}
		T* operator->(){
			return _ptr;
		}

private:
		T* _ptr;
		mutable bool _owner;
};
 }

void Test1(){
	int a = 10;
	int* pa = &a;
	int* pb = pa;

	*pa = 100;
	*pb = 200;
	AUTO_Ptr::auto_ptr<int> ptr1(new int);
	AUTO_Ptr::auto_ptr<int> ptr2(ptr1);
	*ptr2 = 200;
	*ptr1 = 100;
	AUTO_Ptr::auto_ptr<int> ptr3(new int);
	ptr3 = ptr2;
}

// ��_owner�汾��auto_ptrȱ�ݣ����ܻ����Ұָ��--�����´������
void Test2(){
	AUTO_Ptr::auto_ptr<int> ap1(new int);

	if (true)
	{
		AUTO_Ptr::auto_ptr<int> ap2(ap1);
		*ap2 = 20;
	}

	// ap1��Ұָ��
	*ap1 = 10;
}
int main(){
	//Test1();
	Test2();
	return 0;
}
#endif


#if 0
// ���ǳ������ʽ����Դ��ռ(ֻ��һ������ʹ�ã����ܹ���)--->ʵ�֣���ֹ���ÿ�������͸�ֵ���������
namespace unique_Ptr
{
	template<class T>
	class unique_ptr
	{
	public:
		// RAII
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr; // �ͷ���Դ�ķ�ʽ�̶���ֻ�ܹ���new����Դ�����ܴ����������͵���Դ
				_ptr = nullptr;
			}
		}

		// ����ָ��������Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// ���ǳ��������ֹ���ÿ������캯���͸�ֵ���������

		// C++98:
		/*
		private:  // ���������Ȩ��һ��Ҫ���ó�private��ԭ��Ϊ�˷�ֹ�û��Լ������ⶨ��
		unique_ptr(const unique_ptr<T>& up);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
		*/

		// C++11 ��ֹ���ÿ�������͸�ֵ���������
		unique_ptr(const unique_ptr<T>&) = delete;  // 1. �ͷ�new�Ŀռ�  2.Ĭ�ϳ�Ա���� = delete �� ���߱�������ɾ����Ĭ�ϳ�Ա����
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		T* _ptr;
	};

	// �û����ⲿʵ��
	// 	template<class T>
	// 	unique_ptr<T>::unique_ptr(const unique_ptr<T>& up)
	// 	{}
}




void TestUniquePtr()
{
	unique_Ptr::unique_ptr<int> up1(new int);
//	unique_Ptr::unique_ptr<int> up2(up1);
	unique_Ptr::unique_ptr<int> up3(new int);
	//up3 = up1;
}
#endif


#if 0
namespace Shared_ptr{
template <class T>
class shared_ptr
	{
public:shared_ptr(T* ptr=nullptr)
	:_ptr(ptr)
	,_pCount(nullptr){
			   if (_ptr)
				   _pCount = new int(1);
	}
		   ~shared_ptr(){
			   if (_ptr&& 0 == --*_pCount){
				   delete _ptr;
				   delete _pCount;
			   }
		   }
		   T& operator*()
		   {
			   return *_ptr;
		   }

		   T* operator->()
		   {
			   return _ptr;
		   }
		   shared_ptr(const shared_ptr<T>& sp)
		   :_ptr(sp._ptr)
		   ,_pCount(sp._pCount){
			   if (_ptr)
				   ++*_pCount;
		   }
		   shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		   {
			   if (this != &sp)
			   {
				   // 1. �����Դ�Ͽ���ϵ
				   // this���ڲ������Լ�����Դ��Ҫ��sp��������Դ
				   if (_ptr && 0 == --*_pCount)
				   {
					   // ��ǰ���������һ��ʹ����Դ�Ķ���
					   delete _ptr;
					   delete _pCount;
				   }

				   // 2. ��sp������Դ������
				   _ptr = sp._ptr;
				   _pCount = sp._pCount;
				   if (_ptr)
					   ++*_pCount;

			   }

			   return *this;
		   }
		   int use_count()
		   {
			   return *_pCount;
		   }

private:
		T* _ptr;
		int* _pCount;
	};
}
void TestShradPtr()
{
	Shared_ptr::shared_ptr<int> sp1(new int);
	cout << sp1.use_count() << endl;
	Shared_ptr::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;


	Shared_ptr::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;

	Shared_ptr::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp3.use_count() << endl;

	sp4 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp4.use_count() << endl;
}


int main()
{
	TestShradPtr();
	return 0;
}
#endif


#if 0
// ����ɾ���������û����Կ�����Դ������ͷŲ���
// �����̰߳�ȫ��

#include <mutex>
template<class T>
class DFDef{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}

};

namespace Shared_ptr1
{
	template<class T, class DF = DFDef<T>>
	class shared_ptr{
	public:shared_ptr(T* ptr = nullptr)
		   : _ptr(ptr)
		   , _pCount(nullptr)
		   , _pMutex(nullptr){
			   if (_ptr)
			   {
				   _pCount = new int(1);
				   _pMutex = new mutex;
			   }
	}
		   ~shared_ptr(){
			   Release();
		}
		   T& operator*()
		   {
			   return *_ptr;
		   }

		   T* operator->()
		   {
			   return _ptr;
		   }
		   shared_ptr(const shared_ptr<T>& sp)
			   : _ptr(sp._ptr)
			   , _pCount(sp._pCount)
			   , _pMutex(sp._pMutex)
		   {
			   AddRef();
		   }
		   shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		   {
			   if (this != &sp)
			   {
				   // 1. �����Դ�Ͽ���ϵ
				   // this���ڲ������Լ�����Դ��Ҫ��sp��������Դ
				   Release();

				   // 2. ��sp������Դ������
				   _ptr = sp._ptr;
				   _pCount = sp._pCount;
				   if (_ptr)
					   AddRef();
			   }

			   return *this;
		   }

		   int use_count()
		   {
			   return *_pCount;
		   }
	private:
		void AddRef()
		{
			if (_pCount)
			{
				_pMutex->lock(); // ����
				++*_pCount;
				_pMutex->unlock();// ����
			}
		}

		int SubRef()
		{
			if (_pCount)
			{
				_pMutex->lock(); // ����
				--*_pCount;
				_pMutex->unlock();// ����
			}

			return *_pCount;
		}

		void Release()
		{
			if (_ptr && 0 == SubRef())
			{
				// ��ǰ���������һ��ʹ����Դ�Ķ���
				DF()(_ptr);
				delete _pCount;
			}
		}

	private:
		T* _ptr;
		int* _pCount;
		mutex* _pMutex;
	};
}


struct Date
{
	Date()
	{
		_year = _month = _day = 0;
	}

	int _year;
	int _month;
	int _day;
};

// 1. shared_ptr�����ü����Ƿ�ȫ---mutex
// 2. shared_ptr��������û������Ƿ����̰߳�ȫ
void SharePtrFunc(Shared_ptr1::shared_ptr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		Shared_ptr1::shared_ptr<Date> copy(sp);

		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

#include <thread>

int main()
{
	Shared_ptr1::shared_ptr<Date> sp(new Date);

	thread t1(SharePtrFunc, sp, 100000);
	thread t2(SharePtrFunc, sp, 100000);

	t1.join();
	t2.join();
	return 0;
}
#endif


#if 0
#include <memory>

// struct ListNode
// {
// 	ListNode* _pPre;
// 	ListNode* _pNext;
// 	int _data;
// };

struct ListNode
{
	ListNode(int data = 0)
	: pre(nullptr)
	, next(nullptr)
	, _data(data)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}

	shared_ptr<ListNode> pre;
	shared_ptr<ListNode> next;
	int _data;
};

void TestListNode()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	TestListNode();
	return 0;
}
#endif




#include <memory>

// struct ListNode
// {
// 	ListNode* _pPre;
// 	ListNode* _pNext;
// 	int _data;
// };

struct ListNode
{
	ListNode(int data = 0)
	// 	: pre(nullptr)
	// 	, next(nullptr)
	: _data(data)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}

	//shared_ptr<ListNode> pre;
	//shared_ptr<ListNode> next;

	weak_ptr<ListNode> pre;
	weak_ptr<ListNode> next;

	int _data;
};

void TestListNode()
{
	shared_ptr<ListNode> sp1(new ListNode(10));
	shared_ptr<ListNode> sp2(new ListNode(20));

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	sp1->next = sp2;
	sp2->pre = sp1;

	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
}

int main()
{
	// weak_ptr<int> sp1;  // ���Ա���ɹ�
	//weak_ptr<int> sp2(new int);   // ����ʧ��--ԭ��weak_ptr���ܶ���������Դ
	TestListNode();
	return 0;
}

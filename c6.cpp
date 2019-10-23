#include<iostream>
using namespace std;
#if 0
// 自定义类型
class Test{
public:Test(){
		   _data = 10;
		   cout << "Test()" << endl;
       }
	   ~Test(){
		   cout << "~Test()" << endl;
	   }

private:
	int _data;
};
int main(){
	Test* s = new Test[10];
	delete[] s;
	return 0;
}
#endif

#if 0
//new能够将申请空间的信息打印
// delete能够将释放空间信息打印
void* operator new(size_t size, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif

#if 0
//跳过一些空间内存内容
// 与类型无关
// Add函数模板
//template<class T1, class T2>       // 模板参数列表
//T1 Add(T1 left, T2 right)  // 参数列表
//{
//	cout << typeid(T1).name() << endl;
//	return left + right;
//}
template <class T>
T Add(T left,T right){
	cout << typeid(T).name() << endl;
	return left + right;
}
int main(){
	// 对函数模板进行实例化
	// 在编译阶段，如果编译器检测到对某个函数模板进行了实例化
	// 对实参的类型进行推演，根据推演的结果，确认模板参数列表中T的实际类型
	// 结合函数模板生成处理具体类型的函数
	// 隐式实例化
	Add(1,2);
	Add(1.0, 2.2);
	Add('1', '2');
	Add(1,(int)2.0);
	Add<int>(1,2.1);
	return 0;

}
#endif

#if 0
int Add(int left,int  right){
	
	return left + right;
}
template <class T1,class T2>//为什莫给class类型
T1 Add(T1 left, T2 right){

	return left + right;
}
int main(){
	Add(1,2);
	Add(1,2.0);
	return 0;
}
#endif

#include <assert.h>

// 顺序表  链表  栈和队列  二叉树  堆  排序
//动态类型顺序表
template<class T>
class Seqlist{
public:Seqlist(size_t capacity = 10)
	   :_array(new T[capacity])
	   , _size(0)
	   , _capacity(capacity)
{}
	   ~Seqlist{
		   if (_array){
		   delete[] _array;
		   _array = nullptr;
		   _capacity = 0;
		   _size = 0; 
       }

       }
void Popback()const{
		   _size--;
	   }
void Capacity(){
	return _capacity;
}
void Size()const{
	return _size;
}
bool Empty()const{
	return 0 == _size;
}
T& operator[](size_t index){
	assert(index < _size);
	return _array[index];
}
const T& operator[](size_t index)const{
	assert(index < _size);
	return _array[index];
}
private:
	void _CheckCapacity(){
		if (_size == _capacity){
			// 开辟新空间
			T* array = new T[2 * _capacity];
			// 拷贝元素
			// memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size;i++){
				array[i] = _array[i];
			}
			// 释放旧空间
			delete[] _array;
			_array = array;
			_capacity *= 2;
		}
	}
private:
	T*  _array;
	size_t _size;
	size_t  _capacity;

};
template<class T>
void SeqList<T>::PushBack(const T& data)
{
	_CheckCapacity();
	_array[_size++] = data;
}

}
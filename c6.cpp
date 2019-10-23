#include<iostream>
using namespace std;
#if 0
// �Զ�������
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
//new�ܹ�������ռ����Ϣ��ӡ
// delete�ܹ����ͷſռ���Ϣ��ӡ
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
//����һЩ�ռ��ڴ�����
// �������޹�
// Add����ģ��
//template<class T1, class T2>       // ģ������б�
//T1 Add(T1 left, T2 right)  // �����б�
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
	// �Ժ���ģ�����ʵ����
	// �ڱ���׶Σ������������⵽��ĳ������ģ�������ʵ����
	// ��ʵ�ε����ͽ������ݣ��������ݵĽ����ȷ��ģ������б���T��ʵ������
	// ��Ϻ���ģ�����ɴ���������͵ĺ���
	// ��ʽʵ����
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
template <class T1,class T2>//ΪʲĪ��class����
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

// ˳���  ����  ջ�Ͷ���  ������  ��  ����
//��̬����˳���
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
			// �����¿ռ�
			T* array = new T[2 * _capacity];
			// ����Ԫ��
			// memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size;i++){
				array[i] = _array[i];
			}
			// �ͷžɿռ�
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
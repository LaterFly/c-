#include<iostream>
using namespace std;
#include<vector>
#if 0
int main(){
	int a[] = {1,2,3,4,5,6};
	vector<int> v(a,a+sizeof(a)/sizeof(int));
	for (size_t i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
	auto pos = find(v.begin(),v.end(),2);
	v.insert(pos,20);
	for (size_t i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
	auto it = v.begin();
	while (it!=v.end())
	{
		cout << *it<<" ";
		it++;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 2);
	v.erase(pos);
	return 0;
}
#endif

#if 0
int main(){
	int a[] = {4,5,6,7,8,9};
	vector<int> v1(a,a+sizeof(a)/sizeof(int));
	auto it = v1.begin();
	/*while (it!=v1.end())
	{
		if (*it%2 == 0){ 
			v1.erase(it);
		}
		it++;
	}*/
	while (it!= v1.end())
	{
		if (*it%2 == 0){
			it = v1.erase(it);
		}
		it++;
	}
	return 0;
}
#endif

namespace test
{
	template<class T>
	class vector{
	public:
		// vector�ĵ�����ʵ�ʾ���ԭ��ָ̬��
		typedef T* iterator;
	public:
		vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
		{}
		vector(int n,const T&data)
			:_start(new T[n])
		{
			for (size_t i = 0; i < n;i++){
				_start[i] = data;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}
		// [first, last)
		template<class Iterator>
		vector(Iterator first ,Iterator last){
			size_t n = 0;
			auto it = first;
			while (it!=last)
			{
				n++;
				it++;
			}
			_start = new T[n];
			for (size_t i = 0; i < n;i++){
				_start[i] = *first++;

				_finish = _start + n;
				_endofstorage = _start + n;
			}
			vector(const vector<T>& v);
			vector<T>& operator=(const vector<T>& v);
		}
		~vector(){
			if (_start){
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}
		/////////////////////////////////////
		// ������
		iterator begin(){
			return _start;
		}
		iterator end(){
			return _finish;
		}
		/////////////////////////////////////
		// ��������
		size_t size()const{
			return _finish - _start;
		}
		size_t capacity()const(){
			return _endofstorage - _start;
		}
		bool empty(){
			return _start == _finish;
		}
		// T():
		// ���T�����������ͣ�T()--->0
		// ���T�����Զ������ͣ�T()---> ���ø�����޲ι��캯��
		void reserve(size_t newcapacity){
			size_t oldcapacity = capacity();
			if (newcapacity>oldcapacity){
				// 1. �����¿ռ�
				T* tem = new T[newcapacity];
				// 2. ����Ԫ��
				//memcpy(temp, _start, size()*sizeof(T));
				// ���_startָ��Ŀռ����
				size_t n = size();
				if (_start){
					for (size_t i = 0; i < n;i++){
						tem[i] = _start[i];
					}
					// 3. �ͷžɿռ�
					delete[] _start;
				}
			}
			_start = tem;
			_finish = _start + n;
			_endofstorage = _start + newCapacity;
		}
		void resize(size_t newsize,const T& Data = T()){
			size_t oldsize = size();
			if (newsize > oldsize){
				size_t capacity = capacity();
				if (newsize>capacity){
					reserve(newsize);
				}
				for (; oldsize < newsize;oldsize++){
					_start[oldsize] = Data;
				}

			}
			_finish = _start + newsize;
		}
		///////////////////////////////////////////////
		// access
		T& operator [](size_t index){
			assert(index < size());
			return _start[index];
		}
		T& front()
		{
			return *_start;
		}
		const T& front()const
		{
			return *_start;
		}

		void push_back(const T& Data){
			if (_finish==_endofstorage){
				reserve(capacity() * 2 + 3);
			}
			*_finish++ = Data;
		}
		void pop_back()
		{
			--_finish;
		}

		// ����ֵ���壺�����²���Ԫ�ص�λ��
		/*iterator insert(iterator pos,const T& Data){
			if (_finish == _endofstorage){
				reserve(capacity() * 2 );
			}
			auto it = _finish;
			while (it>_finish)
			{
				*it = *it();
			}
		}*/
		// ����Ƿ���Ҫ����
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;

	};


}

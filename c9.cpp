#include<iostream>
using namespace std;
#if 0
namespace bite{
	class string{
	public:
		string(const char* str =  ""){
			if (nullptr == str){
				str = "";
			}
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
		}
		string(const string& s)
		:_str(nullptr){
			string temp(s._str);
			swap(_str,temp._str);
		}
		string& operator=(const string& s){
			if (this!=&s){
				string temp(s);
				swap(_str,temp._str);
				return *this;
			}
		
		}
		~string(){
			if (_str){
				delete[] _str;
			}
		}

	private:
		char* _str;
	};

}
#endif

#if 0
namespace bite{
	class string{
	public:
		string(const char* str = ""){
			if (nullptr == str){
				_str = "";
			}
			_str = new char[strlen(str)+1];
			_count = 1;
			strcpy(_str,str);
		}
		string(string& s)
		:_str(s._str)
		,_count(++s._count){
		
		}
		~string(){
			if (_str&& 0 == --_count){
				delete[] _str;
				_str = nullptr;
			}
		
		}
	private:
		char* _str;
		int _count;
	};


}
#endif


#if 0
// 将计数给成静态类型的成员变量---->不行
// 原因：静态类型成员变量是所有对象共享
//      计数应该与资源个数保持一致

namespace bite{
	class string{
	public:
		string(const char* str = ""){
			if (nullptr == str){
				_str = "";
			}
			_str = new char[strlen(str) + 1];
			_count = 1;
			strcpy(_str, str);
		}
		string(string& s)
			:_str(s._str)
	     {
			_count++;
		}
		~string(){
			if (_str && 0 == --_count){
				delete[] _str;
				_str = nullptr;
			}

		}
	private:
		char* _str;
	static	int _count;
	};
	int string::_count = 0;
}
#endif
namespace bite{
	class string{
	public:
		string(const char* str = "")
		:_pcount(new int(1)){
			if (nullptr == str){
				_str = "";
			}
			_str = new char[strlen(str) + 1];
		
			strcpy(_str, str);
		}
		string(string& s)
			:_str(s._str)
			, _pcount(s._pcount)
		{
			++(*_pcount);
		}

		// s2 = s1;
		// 1. s2原来的资源将不再使用--- 应该给原来计数-1
		//                         计数：非0  0
		// 2. s2应该与s1共享同一份资源  计数++
		string& operator=(const string& s){
			if (this != &s){
				// 让当前对象与其管理资源分离开
				if (0 ==--*_pcount){
					delete[]  _str;
					delete _pcount;

					// 与s共享资源
					_str = s._str;
					_pcount = s._pcount;
					++(*_pcount);
				}
			
			}
			return *this;
		}

		~string(){
			if (_str && 0 == --(*_pcount)){
				delete[] _str;
				_str = nullptr;
				delete _pcount;
				_pcount = nullptr;
			}

		}
		char& operator [](size_t index){
			return _str[index];
		}
	private:
		char* _str;
		int* _pcount;
	};
	
}
void Teststring(){
	bite::string s1("hello");
	bite::string s2(s1);
	bite::string s3("dalao");
	bite::string s4(s3);
	// s3不需要释放原来的资源，因为还有s4在用
	s3 = s1;

	// s4是最后使用资源的对象， 赋值期间必须释放原来的资源
	s4 = s1;

	s1[0] = 'H';
}
int main(){
	Teststring();
	return 0;
}
// 解决浅拷贝：浅拷贝 + 引用计数
// 在类中增加int类的成员变量-----不行
// 普通的整形成员变量，每个对象中都有一份，一个对象在修改该计数时候，不会影响其他对象
// 导致：资源没有释放
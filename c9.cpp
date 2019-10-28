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
// ���������ɾ�̬���͵ĳ�Ա����---->����
// ԭ�򣺾�̬���ͳ�Ա���������ж�����
//      ����Ӧ������Դ��������һ��

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
		// 1. s2ԭ������Դ������ʹ��--- Ӧ�ø�ԭ������-1
		//                         ��������0  0
		// 2. s2Ӧ����s1����ͬһ����Դ  ����++
		string& operator=(const string& s){
			if (this != &s){
				// �õ�ǰ�������������Դ���뿪
				if (0 ==--*_pcount){
					delete[]  _str;
					delete _pcount;

					// ��s������Դ
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
	// s3����Ҫ�ͷ�ԭ������Դ����Ϊ����s4����
	s3 = s1;

	// s4�����ʹ����Դ�Ķ��� ��ֵ�ڼ�����ͷ�ԭ������Դ
	s4 = s1;

	s1[0] = 'H';
}
int main(){
	Teststring();
	return 0;
}
// ���ǳ������ǳ���� + ���ü���
// ����������int��ĳ�Ա����-----����
// ��ͨ�����γ�Ա������ÿ�������ж���һ�ݣ�һ���������޸ĸü���ʱ�򣬲���Ӱ����������
// ���£���Դû���ͷ�
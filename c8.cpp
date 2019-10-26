#include<iostream>
using namespace std;
#if 0
// string来解决浅拷贝问题
// string类动态管理字符串
namespace bite{
	class string
	{
	public:
		string(char* str = " "){
			if (nullptr==str){
				str = " ";
			}
			// 申请空间
			_str = new char[strlen(str)+1];
			// 存放str中的字符
			strcpy(_str,str);
		}
		// 将s对象中内容原封不动的拷贝到新对象中
		// 值的拷贝---bite位的拷贝
		string(const string& s)
			:_str(s._str)
		{}
		// 编译器生成的默认拷贝构造函数--浅拷贝 & 资源泄漏
		string& operator=(const string &s){
			_str = s._str;
			return *this;
		}
		~string(){
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
void Teststring(){
	bite::string s1("hello");
	bite::string s2(nullptr);

	bite::string s3(s1);// 默认的拷贝构造是浅拷贝
	// 调用编译器提供的默认赋值运算符重载
	s2 = s1;
}
int main(){
	Teststring();
	return 0;
}
#endif

namespace bite{
	// 深拷贝--传统版
	class string{
       public:
	    string(char* str = ""){
			if (nullptr == str){
				_str = " ";
			   }
			_str = new char[strlen(str)+1];
			strcpy(_str,str);
	        }
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str,s._str);
		}
		string& operator=(const string& s){
			if (this!= &s){
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp,s._str);
				delete[] _str;
				_str = temp;
			}
			return *this;
		}

		~string(){
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
  };
}
void Teststring(){

	bite::string s1("hello");
	bite::string s2(s1);
    bite::string s3;

	s3 = s1;
}

int main(){
	Teststring();
	return 0;
}
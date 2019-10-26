#include<iostream>
using namespace std;
#if 0
// string�����ǳ��������
// string�ද̬�����ַ���
namespace bite{
	class string
	{
	public:
		string(char* str = " "){
			if (nullptr==str){
				str = " ";
			}
			// ����ռ�
			_str = new char[strlen(str)+1];
			// ���str�е��ַ�
			strcpy(_str,str);
		}
		// ��s����������ԭ�ⲻ���Ŀ������¶�����
		// ֵ�Ŀ���---biteλ�Ŀ���
		string(const string& s)
			:_str(s._str)
		{}
		// ���������ɵ�Ĭ�Ͽ������캯��--ǳ���� & ��Դй©
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

	bite::string s3(s1);// Ĭ�ϵĿ���������ǳ����
	// ���ñ������ṩ��Ĭ�ϸ�ֵ���������
	s2 = s1;
}
int main(){
	Teststring();
	return 0;
}
#endif

namespace bite{
	// ���--��ͳ��
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
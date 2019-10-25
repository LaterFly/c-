#include<iostream>
using namespace std;
#include<string>
void Test1(){
	string s1;
	string s2("hai da lao");
	string s3(5,'A');
	string s4(s3);
	cin >> s1;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}
//������������
void Test2(){
	string s1("da da da");
	cout << s1.size() << endl;
	cout << s1.capacity()<< endl;
	cout << s1.length() << endl;
	if (s1.empty()){
		cout << "��" << endl;
	}
	else{
		cout << "��" << endl;
	}
	// ֻ���string������Ч�ַ�����������ı�ײ�ռ���ܴ�С
	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.length() << endl;
	if (s1.empty()){
		cout << "��" << endl;
	}
	else{
		cout << "��" << endl;
	}
}
//resize ����--��string���е���Ч�ַ��ı䵽n��������ַ�����ch�������
// ע�⣺ 1. ����ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�ظ���������ı�ײ�ռ��С
//       2. ����ǽ�string���е���ЧԪ�����࣬������Ҫ����
void Test3(){
	string s("iloveyou");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s.length() << endl;
	s.resize(10,'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s.length() << endl;
	s.resize(30,'A');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s.length() << endl;
	s.resize(4);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s.length() << endl;
}

// reserve ����
// newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity)����ЧԪ�ظ�������
// newcapacity < oldcapacity(string��ɿռ��С)���ռ���С���ú���ֱ�ӷ��� ����newcapacity < 15
// ע�⣺ֻ�ı�������С������ı���ЧԪ�ظ���

void Test4(){
	string s1(15, 'A');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(60);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.reserve(3);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

}
void Test5(){
	string s1;
	s1.push_back('I');
	s1 += "love";//1>f:\c���Գ�����ϰ\c7\c7\c7.cpp(83) : warning C4305 : �������� : �ӡ�int������char���ض�
	string s2;
	s2.push_back('$');
	s1 += s2;
	s1.append(1,'.');
}
// 1. string������ݻ���---vs--PJ  1.5��
//                      linux--SGI 2��
// 2. �����ǰ֪�����Ҫ��string���Ŷ��ٸ�Ԫ�أ�������ǰͨ��reserve���ռ��ṩ��
void Test6(){
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	for (int i = 0; i < 100;++i)//
	{
		s.push_back('c');
		if (sz!=s.capacity()){
			sz = s.capacity();
			cout << sz << endl;
		}
	}
	
}
void Test7(){
	string s("hello po hou");
	size_t pos = s.find(' ');
	if (pos != string::npos){
		cout << "zai" << endl;
	}
	pos = s.find("hou");
	if (pos != string::npos){
		cout << "zai" << endl;
	}
	// ��ȡ�ļ��ĺ�׺ - 20190923.cpp.cpp
	string s1("20190923.cpp.cpp");
	pos = s1.rfind('.') + 1;
	string s2 = s1.substr(pos);
	cout << s2 << endl;
}
void Test8(){
	string s("heloo hello");
	for (auto e:s){
		cout << e;
		cout << endl;
	}
	for (size_t i = 0; i < s.size();++i){
		cout << s[i];
		cout << endl;
	}
	auto it  = s.begin();
	while (it!=s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}
int main(){
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
   //Test6();
	//Test7();
	//Test8();
	return 0;
}
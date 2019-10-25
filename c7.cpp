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
//测试容量操作
void Test2(){
	string s1("da da da");
	cout << s1.size() << endl;
	cout << s1.capacity()<< endl;
	cout << s1.length() << endl;
	if (s1.empty()){
		cout << "是" << endl;
	}
	else{
		cout << "否" << endl;
	}
	// 只清空string类中有效字符个数，不会改变底层空间的总大小
	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.length() << endl;
	if (s1.empty()){
		cout << "是" << endl;
	}
	else{
		cout << "否" << endl;
	}
}
//resize 功能--将string类中的有效字符改变到n个，多的字符采用ch进行填充
// 注意： 1. 如果是将string类中的有效元素缩小，只改变有效元素个数，不会改变底层空间大小
//       2. 如果是将string类中的有效元素增多，可能需要扩容
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

// reserve 扩容
// newcapacity > oldcapacity(string类旧空间大小)：空间增多--->容量改变(最终容量大小 >= newCapacity)，有效元素个数不变
// newcapacity < oldcapacity(string类旧空间大小)：空间缩小，该函数直接返回 除非newcapacity < 15
// 注意：只改变容量大小，不会改变有效元素个数

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
	s1 += "love";//1>f:\c语言初阶练习\c7\c7\c7.cpp(83) : warning C4305 : “参数” : 从“int”到“char”截断
	string s2;
	s2.push_back('$');
	s1 += s2;
	s1.append(1,'.');
}
// 1. string类的扩容机制---vs--PJ  1.5倍
//                      linux--SGI 2倍
// 2. 如果提前知道大概要往string类存放多少个元素，可以提前通过reserve将空间提供好
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
	// 获取文件的后缀 - 20190923.cpp.cpp
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
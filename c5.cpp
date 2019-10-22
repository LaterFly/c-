#include<iostream>
using namespace std;

#if 0
int main(){
	int*p = (int*)malloc(sizeof(int)*10);
	free(p);
	return 0;
}
#endif

#if 0
// new/delete     new[]/delete[]
// malloc/free
// 注意：一定要匹配使用
// 1. new和delete不是函数，C++提供的新的操作符
// 2. new/new[] 只需在其后跟空间类型，不需要传递字节数
// 3. new 后跟的就是空间的类型，因此不需要强转
// 4. new/new[]可以进行初始化
// 5. new的结果不需要判空
// 6. 
int main(){
	// new 申请单个类型元素的空间---默认情况：new出的空间在堆上
	int* ptr1 = new int;
	int* ptr2 = new int(5);
	int* ptr3 = new int[3]{1,2,3};
	delete ptr1;
	delete ptr2;
	delete[] ptr3;
	return 0;
}
#endif

// 如果没有匹配使用，产生后果?
// 如果申请的是内置类型的空间，不会产生任何后果
void Test(){
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	int* p3 = new int;
	int* p4 = new int;
	int* p5 = new int[6];
	int* p6 = new int[2];
	delete p1;
	delete[] p2;
	free(p3);
	delete[] p4;
	free(p5);
	delete(p6);
}

//自定义类型
class Test{
public:
	Test(){
		_data = 10;
		_p = new int;
		cout << "Test()" << this << endl;
	}
	~Test(){
		delete _p;
		cout << "Test()" << this << endl;
	}

private:
	int _data;
	int* _p;
};

// 对于自定义类型，只要涉及到[]，必然会崩溃
// new会调用构造函数
// free不会调用析构函数--对象中的资源不会被销毁
void Test1(){
	//Test* p3 = new Test;//有问题
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;
	
	//Test* p1 = (Test*)malloc(sizeof(Test));
	//free(p1);
	
}
int main(){
	//Test();
	Test1();
	return 0;
}
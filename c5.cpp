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
// ע�⣺һ��Ҫƥ��ʹ��
// 1. new��delete���Ǻ�����C++�ṩ���µĲ�����
// 2. new/new[] ֻ���������ռ����ͣ�����Ҫ�����ֽ���
// 3. new ����ľ��ǿռ�����ͣ���˲���Ҫǿת
// 4. new/new[]���Խ��г�ʼ��
// 5. new�Ľ������Ҫ�п�
// 6. 
int main(){
	// new ���뵥������Ԫ�صĿռ�---Ĭ�������new���Ŀռ��ڶ���
	int* ptr1 = new int;
	int* ptr2 = new int(5);
	int* ptr3 = new int[3]{1,2,3};
	delete ptr1;
	delete ptr2;
	delete[] ptr3;
	return 0;
}
#endif

// ���û��ƥ��ʹ�ã��������?
// �����������������͵Ŀռ䣬��������κκ��
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

//�Զ�������
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

// �����Զ������ͣ�ֻҪ�漰��[]����Ȼ�����
// new����ù��캯��
// free���������������--�����е���Դ���ᱻ����
void Test1(){
	//Test* p3 = new Test;//������
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
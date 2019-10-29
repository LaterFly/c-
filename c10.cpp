#include<iostream>
using namespace std;
#include<vector>
#if 0
void Testvector1(){
	vector<int> v1;
	vector<int> v2(4,2);
	vector<int> v3(v2);
	int array[] = {1,2,3,4,5,6,7};
	vector<int> v4(array,array+sizeof(array)/sizeof(array[0]));
	vector<int> v5{1,2,3,4,5};
	for (size_t i = 0; i < v2.size();i++){
		cout << v2[i]<<" ";
		cout << endl;
	}
	for (auto e:v3){
		cout << e;
		cout << endl;
	}
	cout << endl;
	auto it = v2.begin();
	while (it!=v2.end())
	{
		cout << *it;
		cout << endl;
		it++;
	}
	cout << endl;
	auto it1 = v5.rbegin();
	while (it1!= v5.rend())
	{
		cout << *it1;
		cout << endl;
		it1++;
	}
}
void Testvector2(){
	vector<int> v5{1,2,3,4,5,6,7,8,9};
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;
	v5.push_back(6);
	v5.push_back(6);
	v5.push_back(6);
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;
	v5.erase(v5.begin());
	v5.erase(v5.end()-1);
	auto pos = find(v5.begin(),v5.end(),4);
	if (pos != v5.end())
		v5.erase(pos);
	v5.clear();
}
void Testvector3(){
	vector<vector<int>> v6;
	v6.resize(6);
	for (size_t i = 0; i < 6;i++){
		v6[i].resize(6,6);
	}
}
int main(){
	//Testvector1();
	//Testvector2();
	Testvector3();
	return 0;
}
#endif

#if 0
int main(){
	size_t sz;
 vector<int> v;

	v.reserve(100);
	sz = v.capacity();
	v[1] = 1;//下标访问必须有元素
	cout << "grow";
	for (int i = 0; i < v.size();i++){
		v.push_back(i);
		if (sz!= v.capacity()){

			sz = v.capacity();
			cout << "change"<<sz<<'\n';
		}
	}
	return 0;
}
#endif

#if 0
int main(){
	vector<int> v{1,2,3,4,5,6};
	for (size_t i = 0; i < v.size();i++){
		cout <<v[i]<<" " ;
		cout << endl;
	}
	cout << endl;
	for (auto& e:v){
		cout << e ;
		
	}
	cout << endl;
	// 迭代器：类似是指针的一种类型，可以将迭代器定义的对象当成是指针的方式进行应用
	// 作用：帮助用户透明的(用户可以不用知道该容器的底层数据结构)遍历容器中的元素
	auto it = v.begin();
	v.push_back(2);// 可能会导致迭代器it失效

	// 解决方式：给it迭代器重新赋值
	it = v.begin();
	while (it!=v.end()){
		cout << *it << " ";
		++it;
	}
	return 0;
}
#endif

int main(){
	vector<int> v{ 1, 2, 3, 4, 5, 6 };
	
	auto it = v.begin();
	while (it != v.end()){
		it = v.erase(it);
		++it;
	}
	return 0;
}
//��a b �ͣ�������룬ÿ��������
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int a, b;
	while(cin>>a>>b){
		cout << a + b <<endl;
	}
	return 0;

}
//˼·:�Ƚ���������ݴ���һ���������棬�ٶ�����������������5 2 8 5 1 5֮������Ϊ1 2 5 5 5 8������Ȼ��Ҫʹ���ж����ƽ��ֵ��󣬿�������̰����˼�롣���������ʼ����ǰȡ�δ������
//����8�����ģ�������ǰȡ�Ĵδ�������5��������Сֵ�����ˣ���Ϊ������Ľ���Ӱ�죻����ǰȡ�������ڶ���5Ϊ���������δ���Ϊ����������5������������鶼�㶨�����ý⼴Ϊ���Ž⡣

int main(){
	int n = 0;
	vector<int> v(3*n);
	for (int i = 0; i < 3 * n;i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	long sum = 0;
	for (int i = 3 * n - 2, int count = n; count > 0;i-=2,count--){
		sum += v[i];
	}

	return 0;
}
//�ӵ�һ���ַ�����ɾ���ڶ����ַ����е������ַ� (C++��)
#include <assert.h>
char* deleteChar(char *first,char *second){
	assert((NULL!=first)&&(NULL!=second));
	const int tableSize = 256;
	bool hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));
	while (*second!='/0'){
		if (!hashTable[*second]){
			hashTable[*second] = true;
		}
		second++;
	}
	char *fast = first;
	char *slow = first;
	while (*fast!='/0'){
		if (!hashTable[*first]){
			slow = fast;
			slow++;
		}
		fast++;
	}
	*slow = '/0';
	return  first;
}
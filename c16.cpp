//求a b 和；多组读入，每行两个数
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
//思路:先将输入的数据存在一个数组里面，再对数组排序，例如输入5 2 8 5 1 5之后排序为1 2 5 5 5 8，很显然，要使所有队伍的平均值最大，可以运用贪婪法思想。从最大数开始，向前取次大的数，
//由于8是最大的，所以向前取的次大数就是5，另外最小值不管了，因为对问题的解无影响；再向前取，倒数第二个5为最大的数，次大数为倒数第三个5，至此两组队伍都搞定，所得解即为最优解。

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
//从第一个字符串中删除第二个字符串中的所有字符 (C++版)
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
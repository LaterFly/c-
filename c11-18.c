#include<stdio.h>
//int main(){
//	/*int num = 0;
//	scanf("%d",&num);
//	int* ptr = NULL;
//	int arr[num] = {0};
//    ptr = malloc(num*sizeof(int));*/
//	int* ptr = NULL;
//	int num = 0;
//	scanf("%d", &num);
//	ptr = malloc(num*sizeof(int));
//	if (ptr!=NULL){
//		int i = 0;
//		for (i = 0; i < num;i++){
//			*(ptr + i) = 1;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//有必要赋为空指针
//	return 0;
//}

//calloc
//#include<stdlib.h>
//int main(){
//	int *p = calloc(5,sizeof(int));
//	if (NULL != p){
//	
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//realloc 调整动态开辟内存的大小
//如果原有空间没有足够多，需在堆上找连续空间，并释放原有内存空间
//int main(){
//
//	int* ptr = malloc(10);
//	if (ptr!=NULL){
//	}
//	int* p = realloc(ptr,1000);
//	if (p != NULL){
//		ptr = p;
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

//对NULL指针的解引用操作
//int main(){
//	int* p = (int*)malloc(10*sizeof(int));
//	*p = 20;//如果p的值是NULL，就会有问题
//	return 0;
//}

//动态开辟空间的越界访问
//int main(){
//	int*p = (int*)malloc(10 * sizeof(int));
//	int i = 0;
//	if (NULL != p){
//		for (i = 0; i <= 10;i++){
//			*(p + i) = i;
//		}
//	
//	}
//	free(p);
//	return 0;
//}

//对非动态开辟内存使用free释放
//int main(){
//	int a = 5;
//	int*p = &a;
//	free(p);//栈上空间不需释放
//	return 0;
//}


//使用free释放动态开辟内存的一部分
//int main(){
//	
//	int*p = (int*)malloc(10);
//	p++;//
//	free(p);//p不在指向动态内存起始位置
//	return 0;
//}

//多次释放
//int main(){
//	int* p = (int*)malloc(10);
//	free(p);
//	free(p);//重复释放
//	return 0;
//}


//void GetMemory(char* p){
//	p = (char*)malloc(10);//调用后变量消失
//	//没判断，没释放
//}
//void Test(void){
//	char* str = NULL;
//	GetMemory(str);//传参为复制，不会改变str的值
//	strcpy(str,"hello");
//	printf(str);
//}

//char* GetMemory(void){
//	char p[] = "hello";//局部临时变量会释放；打印时。printf函数只覆盖数据栈针，故为乱码
//	return p;
//}
//void Test(void){
//	char* str = NULL;
//	str = GetMemory(str);//得到已经释放的内存
//	printf(str);
//}

//void Test(void){
//	char* str = (char*)malloc(100);
//	strcpy(str,"hello");
//	free(str);
//	if (str != NULL){//释放内存后的地址需设置为空
//		strcpy(str,"world");
//		printf(str);
//	}
//}

//void GetMemory(char** p,int num){
//	*p = (char*)malloc(num);//内存判断，释放
//	return p;
//}
//void Test(void){
//	char* str = NULL;
//	GetMemory(&str, 100);
//    strcpy(str,"world");
//	printf(str);
//		
//	}
int main(){
	Test();
	return 0;
}
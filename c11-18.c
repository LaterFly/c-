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
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�б�Ҫ��Ϊ��ָ��
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

//realloc ������̬�����ڴ�Ĵ�С
//���ԭ�пռ�û���㹻�࣬���ڶ����������ռ䣬���ͷ�ԭ���ڴ�ռ�
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

//��NULLָ��Ľ����ò���
//int main(){
//	int* p = (int*)malloc(10*sizeof(int));
//	*p = 20;//���p��ֵ��NULL���ͻ�������
//	return 0;
//}

//��̬���ٿռ��Խ�����
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

//�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//int main(){
//	int a = 5;
//	int*p = &a;
//	free(p);//ջ�Ͽռ䲻���ͷ�
//	return 0;
//}


//ʹ��free�ͷŶ�̬�����ڴ��һ����
//int main(){
//	
//	int*p = (int*)malloc(10);
//	p++;//
//	free(p);//p����ָ��̬�ڴ���ʼλ��
//	return 0;
//}

//����ͷ�
//int main(){
//	int* p = (int*)malloc(10);
//	free(p);
//	free(p);//�ظ��ͷ�
//	return 0;
//}


//void GetMemory(char* p){
//	p = (char*)malloc(10);//���ú������ʧ
//	//û�жϣ�û�ͷ�
//}
//void Test(void){
//	char* str = NULL;
//	GetMemory(str);//����Ϊ���ƣ�����ı�str��ֵ
//	strcpy(str,"hello");
//	printf(str);
//}

//char* GetMemory(void){
//	char p[] = "hello";//�ֲ���ʱ�������ͷţ���ӡʱ��printf����ֻ��������ջ�룬��Ϊ����
//	return p;
//}
//void Test(void){
//	char* str = NULL;
//	str = GetMemory(str);//�õ��Ѿ��ͷŵ��ڴ�
//	printf(str);
//}

//void Test(void){
//	char* str = (char*)malloc(100);
//	strcpy(str,"hello");
//	free(str);
//	if (str != NULL){//�ͷ��ڴ��ĵ�ַ������Ϊ��
//		strcpy(str,"world");
//		printf(str);
//	}
//}

//void GetMemory(char** p,int num){
//	*p = (char*)malloc(num);//�ڴ��жϣ��ͷ�
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
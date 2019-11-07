//字符串函数
//strlen
#include<stdio.h>
#include<string.h>
/*int main(){
	const char* pstr1 = "ascd";
	const char* pstr2 = "asd";
	if (strlen(pstr1)>strlen(pstr2)){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}*/
//int  mystrlen(const char* pstr);
//int  mystrlen( char* pstr);
//int main(){
//	const char* pstr1 = "ascd";
//	const char* pstr2 = "asd";
//	if (mystrlen(pstr1)>mystrlen(pstr2)){
//		printf("1");
//	}
//	else{
//		printf("0");
//	}
//	return 0;
//}
//模拟
/* int  mystrlen(const char* pstr){
	 int count = 0;
	// char* str = pstr;//const char不能初始化char*类型
	 while (*pstr){
		 count++;
		 pstr++;
	 }
	 return count;
 }*/
/*int mystrlen(const char* str){
	if (*str == '/0')
		return 0;
	else
		return 1 + mystrlen(str + 1);

}*/
/*int  mystrlen(char* str){

	char* pstr = str;//const char不能初始化char*类型
	while (*pstr != '\0'){

		pstr++;
	}
	return pstr - str;
}*/


//strcpy
//char* mystrcpy(char* dis, const char* src);
//int main(){
//	char s1[10]="hello";
//	char s2[20]="dawang";
//	mystrcpy(s2,s1);
//	return 0;
//}
//char* mystrcpy(char* dis,const char* src){
//	char* ret = dis;
//	while (*ret!='\0'){
//		*ret = *src;
//		src++;
//		ret++;
//	}
//	return ret;
//
//}

//strcat
/*char* mystrcat(char* dis, const char* src);
int main(){
	char s1[10]="hello";
    char s2[20]="dawang";
    mystrcat(s2,s1);
    return 0;
	}

char* mystrcat(char* dis,const char* src){
	char* ret = dis;
	while (*dis){
		dis++;
	}
	while (*src)
	{
		*dis = *src;
		*src++;
		dis++;
	}
	return ret;

}*/


//strcmp
//int my_strcmp(const char* str1, const char* str2);
//int my_strcmp(const char* str1,const char* str2){
//	while ((*str1!='\0')&&(*str2!='\0'))
//	{
//		if (*str1<*str2){
//		
//			return -1;
//		}
//		else if (*str1 < *str2){
//			return  1;
//		}
//		else{
//			str1++;
//			str2++;
//		}
//	}
//	if (*str1<*str2){
//		return -1;
//	}
//	else if (*str1 > *str2){
//		return  1;
//	}
//	else
//		return 0;
//}
//int main(){
//	char s1[] = "abcd";
//	char s2[] = "acs";
//	int ret = my_strcmp(s1, s2);
//	printf("%d",ret);
//	return 0;
//}


//memcpy

//void *my_memcpy(void *dst, const void *src, unsigned int count){
//	char* pstr = dst;
//	if((dst == NULL) || (src == NULL))
//		return;
//	while (count--){
//		*dst = *src;
//		dst++;
//		src++;
//	}
//	return pstr;
//}

//void *my_memcpy(void *dst, const void *src, size_t count){
//
//	char* pstr = dst;
//	const* pstr1 = src;
//	if ((pstr == NULL) || (pstr1 == NULL))
//		return;
//	while (count--){
//		*pstr++ = *pstr1++;
//	}
//	return dst;
//}
void *my_memcpy(void *dst, const void *src, size_t count){
	void* ret = dst;
	assert(dst);
	assert(src);
		while (count--){
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
		return ret;
	}
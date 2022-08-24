#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

        指 针 运 算

   指针 + - 整数

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
		printf("%d\n", *p);
		printf("%p\n", p);
		p+=1;
	}

	return 0;
}

#define N_VALUES 5
int main()
{
	float values[N_VALUES];
	float* vp;
	for (vp = &values[0]; vp < &values[N_VALUES];)
	{
		*vp++ = 0;
		printf("%d ", vp);
	}
	return 0;
}

     指针 - 指针
int main()
{
	char ch[5] = { 0 };
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d ", &arr[9] - &arr[0]);//   指针 - 指针 = 中间元素的个数 9
	     当指针 - 指针 ，必须指向同一块空间
 	printf("%d ", &arr[9] - &ch[0]);//   error
	return 0;
}

int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;//   指针 - 指针，中间元素个数
}
int main()
{
	  求字符串长度
	  递归  、  计数器
	char arr[] = "hello world";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
  标准：允许指向数组元素的指针与指向数组 最后 一个元素后面的哪个内存位置的指针比较，
        不允许与指向数组 第一个 元素前面的内存位置的指针比较

			指 针 和 数 组
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);//  地址 - 首元素的地址
	printf("%p\n", arr+1);

	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0]+1);

	printf("%p\n", &arr);
	printf("%p\n", &arr[9]);
	printf("%p\n", &arr+1);
	 绝大多数情况下都是首元素地址，除以下两种情况
	 1. &arr - &数组名 - 数组名不是首元素的地址，数组名表示 整个 数组，
	    &数组名表示取出整个数组的 地址
	 2. sizeof(arr) - sizeof(数组名) - 数组名表示 整个 数组
	    sizeof(数组名)计算的是整个数组的 大小
	return 0;
}

int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	/*for (i = 0; i < 10; i++)
	{
		printf("%p ========= %p\n", p + i, &arr[i]);
	}*/
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
		printf("%d ", arr[i]);
		printf("%d ", *(p + i));
	}
	return 0;
}

					二 级 指 针

int main()
{
	int a = 10;
	int * pa = &a;   //  一级指针
	int* * ppa = &pa; //  二级指针 * 代表pc是指针，指向int*
	int** * pppa = &ppa;//  三级指针 * 代表pd是指针，指向int**
	***pppa = 666;
	  ........
	printf("%d ", * * *pppa);
				等价于
	printf("%d ", (*(*(*pppa))));
	  *pppa 找到 ppa,**pppa = *ppa,***pppa = **ppa = *pa = 10
	printf("%d ", a);
	   因为上面解引用取到a的值并改变
	return 0;
}

			指	针	数	组 - 存放指针
  整型数组 - 存放整型
  字符数组 - 存放字符
int main()
{
	int a = 10, b = 20, c = 30;
	int arr1[10];
	int* pa = &a;
	int* pb = &b;
	int* pc = &c; 
	int* arr2[3]={&a,&b,&c};	//  指针数组
	printf("%p ", &arr2[0]);
	printf("%p ", pa);
	int i = 0;
	for (i - 0; i < 3; i++)
	{
		printf("%d ", *arr2[i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

        ָ �� �� ��

   ָ�� + - ����

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

     ָ�� - ָ��
int main()
{
	char ch[5] = { 0 };
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d ", &arr[9] - &arr[0]);//   ָ�� - ָ�� = �м�Ԫ�صĸ��� 9
	     ��ָ�� - ָ�� ������ָ��ͬһ��ռ�
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
	return end - start;//   ָ�� - ָ�룬�м�Ԫ�ظ���
}
int main()
{
	  ���ַ�������
	  �ݹ�  ��  ������
	char arr[] = "hello world";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
  ��׼������ָ������Ԫ�ص�ָ����ָ������ ��� һ��Ԫ�غ�����ĸ��ڴ�λ�õ�ָ��Ƚϣ�
        ��������ָ������ ��һ�� Ԫ��ǰ����ڴ�λ�õ�ָ��Ƚ�

			ָ �� �� �� ��
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);//  ��ַ - ��Ԫ�صĵ�ַ
	printf("%p\n", arr+1);

	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0]+1);

	printf("%p\n", &arr);
	printf("%p\n", &arr[9]);
	printf("%p\n", &arr+1);
	 �����������¶�����Ԫ�ص�ַ���������������
	 1. &arr - &������ - ������������Ԫ�صĵ�ַ����������ʾ ���� ���飬
	    &��������ʾȡ����������� ��ַ
	 2. sizeof(arr) - sizeof(������) - ��������ʾ ���� ����
	    sizeof(������)���������������� ��С
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

					�� �� ָ ��

int main()
{
	int a = 10;
	int * pa = &a;   //  һ��ָ��
	int* * ppa = &pa; //  ����ָ�� * ����pc��ָ�룬ָ��int*
	int** * pppa = &ppa;//  ����ָ�� * ����pd��ָ�룬ָ��int**
	***pppa = 666;
	  ........
	printf("%d ", * * *pppa);
				�ȼ���
	printf("%d ", (*(*(*pppa))));
	  *pppa �ҵ� ppa,**pppa = *ppa,***pppa = **ppa = *pa = 10
	printf("%d ", a);
	   ��Ϊ���������ȡ��a��ֵ���ı�
	return 0;
}

			ָ	��	��	�� - ���ָ��
  �������� - �������
  �ַ����� - ����ַ�
int main()
{
	int a = 10, b = 20, c = 30;
	int arr1[10];
	int* pa = &a;
	int* pb = &b;
	int* pc = &c; 
	int* arr2[3]={&a,&b,&c};	//  ָ������
	printf("%p ", &arr2[0]);
	printf("%p ", pa);
	int i = 0;
	for (i - 0; i < 3; i++)
	{
		printf("%d ", *arr2[i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	empty = money;
//	total = empty;
//	while (empty>=2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}


#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	scanf("%d", &money);
	if (money > 0)
		total = money * 2 - 1;//题目中相当于喝一瓶汽水5毛钱，但
	printf("%d\n", total);    //两个空瓶才能换一瓶汽水，所以会剩下一个空瓶，要减一
	return 0;
}
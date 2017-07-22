/*******欧拉函数值*******/
/**
* 欧拉函数是小于n的正整数中与n互质的数的数目
*
*/

#include <iostream>
#include <cmath>
using namespace std;
#define N 100000001

int euler(int n)
{
	int ans = 1;
	int i;
	for (i = 2;i*i <= n;i++)
	{
		if (n%i == 0)
		{
			n /= i;
			ans *= i - 1;
			while (n%i == 0)
			{
				n /= i;
				ans *= i;
			}
		}
	}
	if (n>1)
		ans *= n - 1;
	return ans;
}
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		printf("%d\n", n - 1 - euler(n));
	}
	return 0;
}
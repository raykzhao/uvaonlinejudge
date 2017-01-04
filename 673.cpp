#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

char str[200];
int n;

int main(int argc, char **argv)
{
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{

		gets(str);

		int flag = 0;

		stack<char> matching;

		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == '(' || str[j] == '[')
			{
				matching.push(str[j]);
			}
			else if (str[j] == ')')
			{
				if (matching.size() && matching.top() == '(')
				{
					matching.pop();
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else if (str[j] == ']')
			{
				if (matching.size() && matching.top() == '[')
				{
					matching.pop();
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}

		if (matching.size())
		{
			flag = 1;
		}

		if (flag)
		{
			puts("No");
		}
		else
		{
			puts("Yes");
		}
	}

	return 0;
}

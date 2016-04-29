#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

queue <int> pile;

int main(int argc, char **argv)
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		for (int i = 1; i <= n; i++)
		{
			pile.push(i);
		}

		printf("Discarded cards:");
		if (pile.size() >= 2)
		{
			printf(" %d", pile.front());
			pile.pop();
			int x = pile.front();
			pile.push(x);
			pile.pop();

			while (pile.size() >= 2)
			{
				printf(", %d", pile.front());
				pile.pop();
				int x = pile.front();
				pile.push(x);
				pile.pop();
			}
		}
		printf("\n");

		printf("Remaining card:");
		if (!pile.empty())
		{
			printf(" %d", pile.front());
			pile.pop();
		}
		printf("\n");
	}

	return 0;
}

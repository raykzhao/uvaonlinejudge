#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;
vector <int> output;

int main(int argc, char **argv)
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}

		output.clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);

			if (x)
			{
				output.push_back(x);
			}
		}

		if (!output.size())
		{
			printf("0\n");
		}
		else
		{
			printf("%d", output[0]);
			for (int i = 1; i < output.size(); i++)
			{
				printf(" %d", output[i]);
			}
			printf("\n");
		}
	}

	return 0;
}

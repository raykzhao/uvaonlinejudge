#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> num;

int main(int argc, char **argv)
{
	int n;
	vector<int>::iterator it;

	while (scanf("%d", &n) == 1)
	{
		for (it = num.begin(); (it != num.end()) && ((*it) < n); it++);
		
		num.insert(it, n);
		
		if (num.size() % 2)
		{
			printf("%d\n", num[num.size() / 2]);
		}
		else
		{
			printf("%d\n", (num[num.size() / 2 - 1] + 
						num[num.size() / 2]) / 2);
		}
	}
	return 0;
}

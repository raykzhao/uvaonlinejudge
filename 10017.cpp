#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

vector <int> La;
vector <int> Lb;
vector <int> Lc;

int n, m;

void a_and_b()
{
	if (!(La.size()))
	{
		La.push_back(Lb[Lb.size() - 1]);
		Lb.pop_back();
	}
	else if (!(Lb.size()))
	{
		Lb.push_back(La[La.size() - 1]);
		La.pop_back();
	}
	else
	{
		if (La[La.size() - 1] < Lb[Lb.size() - 1])
		{
			Lb.push_back(La[La.size() - 1]);
			La.pop_back();
		}
		else
		{
			La.push_back(Lb[Lb.size() - 1]);
			Lb.pop_back();
		}
	}
}

void a_and_c()
{
	if (!(La.size()))
	{
		La.push_back(Lc[Lc.size() - 1]);
		Lc.pop_back();
	}
	else if (!(Lc.size()))
	{
		Lc.push_back(La[La.size() - 1]);
		La.pop_back();
	}
	else
	{
		if (La[La.size() - 1] < Lc[Lc.size() - 1])
		{
			Lc.push_back(La[La.size() - 1]);
			La.pop_back();
		}
		else
		{
			La.push_back(Lc[Lc.size() - 1]);
			Lc.pop_back();
		}
	}
}

void b_and_c()
{
	if (!(Lb.size()))
	{
		Lb.push_back(Lc[Lc.size() - 1]);
		Lc.pop_back();
	}
	else if (!(Lc.size()))
	{
		Lc.push_back(Lb[Lb.size() - 1]);
		Lb.pop_back();
	}
	else
	{
		if (Lb[Lb.size() - 1] < Lc[Lc.size() - 1])
		{
			Lc.push_back(Lb[Lb.size() - 1]);
			Lb.pop_back();
		}
		else
		{
			Lb.push_back(Lc[Lc.size() - 1]);
			Lc.pop_back();
		}
	}
}

void print()
{
	int i;

	printf("A=>");

	if (La.size())
	{
		printf("   ");
	}

	for (i = 0; i < La.size(); i++)
	{
		printf("%d", La[i]);

		if (i < (La.size() - 1))
		{
			printf(" ");
		}
	}

	printf("\n");

	printf("B=>");

	if (Lb.size())
	{
		printf("   ");
	}

	for (i = 0; i < Lb.size(); i++)
	{
		printf("%d", Lb[i]);

		if (i < (Lb.size() - 1))
		{
			printf(" ");
		}
	}

	printf("\n");

	printf("C=>");

	if (Lc.size())
	{
		printf("   ");
	}

	for (i = 0; i < Lc.size(); i++)
	{
		printf("%d", Lc[i]);

		if (i < (Lc.size() - 1))
		{
			printf(" ");
		}
	}

	printf("\n");

	printf("\n");
}

int main(int argc, char **argv)
{
	int i;
	int cas = 0;

	while (++cas)
	{
		scanf("%d %d", &n, &m);

		if ((!n) && (!m))
		{
			break;
		}

		printf("Problem #%d\n\n", cas);

		La.clear();
		Lb.clear();
		Lc.clear();

		for (i = n; i >= 1; i--)
		{
			La.push_back(i);
		}

		print();

		for (i = 0; i < m; i++)
		{
			if (n % 2)
			{
				if (!(i % 3))
				{
					a_and_c();
				}

				if ((i % 3) == 1)
				{
					a_and_b();
				}

				if ((i % 3) == 2)
				{
					b_and_c();
				}
			}
			else
			{
				if (!(i % 3))
				{
					a_and_b();
				}

				if ((i % 3) == 1)
				{
					a_and_c();
				}

				if ((i % 3) == 2)
				{
					b_and_c();
				}
			}

			print();
		}
	}

	return 0;
}

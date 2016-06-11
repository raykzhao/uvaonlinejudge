#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>

using namespace std;

int n;
int sudoku[30][30];
set <int> appear;

int main(int argc, char **argv)
{
	int numCase;
	scanf("%d", &numCase);

	for (int cas = 0; cas < numCase; cas++)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &(sudoku[i][j]));
			}
		}

		int flag = 1;

		for (int i = 0; i < n; i++)
		{
			appear.clear();
			for (int j = 0; j < n; j++)
			{
				if (appear.find(sudoku[i][j]) != appear.end())
				{
					flag = 0;
					break;
				}
				else
				{
					appear.insert(sudoku[i][j]);
				}
			}

			if (!flag)
			{
				break;
			}
		}

		if (flag)
		{
			for (int i = 0; i < n; i++)
			{
				appear.clear();
				for (int j = 0; j < n; j++)
				{
					if (appear.find(sudoku[j][i]) != appear.end())
					{
						flag = 0;
						break;
					}
					else
					{
						appear.insert(sudoku[j][i]);
					}
				}

				if (!flag)
				{
					break;
				}
			}
		}

		if (flag)
		{
			int sn = sqrt(n);

			for (int x = 0; x < sn; x++)
			{
				for (int y = 0; y < sn; y++)
				{
					appear.clear();
					for (int i = x * sn; i < x * sn + sn; i++)
					{
						for (int j = y * sn; j < y * sn + sn; j++)
						{
							if (appear.find(sudoku[i][j]) != appear.end())
							{
								flag = 0;
								break;
							}
							else
							{
								appear.insert(sudoku[i][j]);
							}
						}

						if (!flag)
						{
							break;
						}
					}

					if (!flag)
					{
						break;
					}
				}

				if (!flag)
				{
					break;
				}
			}
		}

		if (flag)
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mem[1010];
int reg[15];

int pc;
int count;

int num_case;

char str[10];

void do_exe()
{
	int inst;
	int x, y;

	pc = 0;
	count = 0;

	while (++count)
	{
		inst = mem[pc++];

		x = ((inst / 10) % 10);
		y = (inst % 10);
		
		switch (inst / 100)
		{
			case 1:
				return;
			case 2:
				reg[x] = y;
				break;
			case 3:
				reg[x] = ((reg[x] + y) % 1000);
				break;
			case 4:
				reg[x] = ((reg[x] * y) % 1000);
				break;
			case 5:
				reg[x] = reg[y];
				break;
			case 6:
				reg[x] = ((reg[x] + reg[y]) % 1000);
				break;
			case 7:
				reg[x] = ((reg[x] * reg[y]) % 1000);
				break;
			case 8:
				reg[x] = mem[reg[y]];
				break;
			case 9:
				mem[reg[y]] = reg[x];
				break;
			case 0:
				if (reg[y])
				{
					pc = reg[x];
				}
				break;
		}
	}
}

int main(int argc, char **argv)
{
	int cas;
	int cur;

	scanf("%d", &num_case);
	getchar();
	gets(str);

	for (cas = 0; cas < num_case; cas++)
	{
		memset(mem, 0, sizeof(mem));
		memset(reg, 0, sizeof(reg));

		cur = 0;

		while (gets(str))
		{
			if (!(strlen(str)))
			{
				break;
			}

			mem[cur++] = atoi(str);
		}

		do_exe();

		printf("%d\n", count);

		if (cas < num_case - 1)
		{
			printf("\n");
		}
	}

	return 0;
}

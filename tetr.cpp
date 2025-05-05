#include <stdio.h>
#include <conio.h>
#include <vector>
#include <windows.h>
struct edge
{
	char piece;
	int next;
};
std::vector<edge> g[28];
bool dfs(int, char, char, char, char, char, char, char, int&);
void init(void);
int main()
{
	system("");
	printf("\033[36mTetr.io\033[0m\n");
	init();
	char buffer[128] = "";
	// while (true)
	// 	printf("%d\n", getch());
	// return 0;
	while (true)
	{
		int board, res = -2, len = 0;
		char hode[3], now[2], next[6];
		puts("\033[36mInput with \033[38;2;128;128;128m[board id] [hold piece] [current piece] [next 5 pieces]\033[0m");
		while (buffer[len])
			++len;
		printf("%s", buffer);
		while (true)
		{
			int c = getch();
			if (c == 8)
			{
				if (len > 0)
				{
					buffer[--len] = 0;
					printf("\033[D\033[K");
				}
			}
			else if (c == 13)
			{
				putchar('\n');
				break;
			}
			else if (c == 3)
			{
				buffer[0] = 'e';
				buffer[1] = 'x';
				buffer[2] = 'i';
				buffer[3] = 't';
				buffer[4] = 0;
				len = 5;
				break;
			}
			else
			{
				buffer[len++] = c;
				buffer[len] = 0;
				putchar(c);
			}
		}
		if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i' && buffer[3] == 't' && buffer[4] == 0)
			break;
		sscanf(buffer, "%d%s%s%s", &board, hode, now, next);
		if (hode[0] == '-')
			hode[0] = -hode[1];
		dfs(board, hode[0], now[0], next[0], next[1], next[2], next[3], next[4], res);
		if (res == -2)
		{
			puts("\033[38;2;0;128;0mNo solution.\033[0m");
			buffer[0] = 0;
		}
		else if (res == -1)
		{
			puts("\033[38;2;0;128;0mHolding piece.\033[0m");
			sprintf(buffer, "%d -%c %c %s", board, now[0], hode[0], next);
		}
		else
		{
			printf("\033[38;2;0;128;0mMove to %d.\n\033[0m", res);
			sprintf(buffer, "%d %c %c %s", res, abs(hode[0]), next[0], next + 1);
		}
	}
}
inline char abs(char x) { return x < 0 ? -x : x; }
bool dfs(int board, char hold, char now, char next1, char next2, char next3, char next4, char next5, int& res)
{
	if (now == 0)
		return true;
	for (auto [piece, to] : g[board])
		if (piece == now && dfs(to, abs(hold), next1, next2, next3, next4, next5, 0, res))
		{
			res = to;
			return true;
		}
	if (hold > 0 && dfs(board, -now, hold, next1, next2, next3, next4, next5, res))
	{
		res = -1;
		return true;
	}
	return false;
}
void init(void)
{
	g[0].push_back({ 'S', 4 });
	g[0].push_back({ 'T', 5 });
	g[0].push_back({ 'L', 6 });
	g[0].push_back({ 'I', 12 });
	g[0].push_back({ 'I', 0 });
	g[0].push_back({ 'I', 0 });

	g[1].push_back({ 'Z', 5 });
	g[1].push_back({ 'T', 3 });
	g[1].push_back({ 'T', 4 });
	g[1].push_back({ 'J', 0 });
	g[1].push_back({ 'J', 7 });
	g[1].push_back({ 'I', 1 });

	g[2].push_back({ 'Z', 9 });
	g[2].push_back({ 'T', 0 });
	g[2].push_back({ 'T', 8 });
	g[2].push_back({ 'L', 3 });
	g[2].push_back({ 'L', 11 });
	g[2].push_back({ 'I', 2 });

	g[3].push_back({ 'Z', 8 });
	g[3].push_back({ 'T', 9 });
	g[3].push_back({ 'L', 0 });
	g[3].push_back({ 'J', 10 });
	g[3].push_back({ 'I', 3 });
	g[3].push_back({ 'I', 13 });

	g[4].push_back({ 'L', 14 });
	g[4].push_back({ 'I', 4 });
	g[4].push_back({ 'O', 0 });

	g[5].push_back({ 'S', 3 });
	g[5].push_back({ 'T', 3 });
	g[5].push_back({ 'L', 2 });
	g[5].push_back({ 'L', 4 });
	g[5].push_back({ 'L', 15 });
	g[5].push_back({ 'J', 18 });
	g[5].push_back({ 'I', 5 });
	g[5].push_back({ 'O', 1 });

	g[6].push_back({ 'S', 20 });
	g[6].push_back({ 'S', 24 });
	g[6].push_back({ 'Z', 3 });
	g[6].push_back({ 'Z', 22 });
	g[6].push_back({ 'T', 3 });
	g[6].push_back({ 'T', 15 });
	g[6].push_back({ 'J', 2 });

	g[7].push_back({ 'S', 8 });
	g[7].push_back({ 'T', 14 });
	g[7].push_back({ 'I', 7 });
	g[7].push_back({ 'O', 0 });

	g[8].push_back({ 'J', 16 });
	g[8].push_back({ 'I', 8 });
	g[8].push_back({ 'O', 3 });

	g[9].push_back({ 'Z', 0 });
	g[9].push_back({ 'T', 0 });
	g[9].push_back({ 'L', 19 });
	g[9].push_back({ 'J', 1 });
	g[9].push_back({ 'J', 8 });
	g[9].push_back({ 'J', 17 });
	g[9].push_back({ 'I', 9 });
	g[9].push_back({ 'O', 2 });

	g[10].push_back({ 'S', 0 });
	g[10].push_back({ 'S', 23 });
	g[10].push_back({ 'Z', 21 });
	g[10].push_back({ 'Z', 25 });
	g[10].push_back({ 'T', 0 });
	g[10].push_back({ 'T', 17 });
	g[10].push_back({ 'L', 1 });
	g[10].push_back({ 'I', 10 });
	g[10].push_back({ 'O', 2 });

	g[11].push_back({ 'Z', 27 });
	g[11].push_back({ 'T', 16 });
	g[11].push_back({ 'I', 11 });
	g[11].push_back({ 'O', 3 });

	g[12].push_back({ 'T', 16 });
	g[12].push_back({ 'L', 5 });
	g[12].push_back({ 'L', 17 });
	g[12].push_back({ 'J', 5 });
	g[12].push_back({ 'I', 12 });


	g[13].push_back({ 'T', 14 });
	g[13].push_back({ 'L', 15 });
	g[13].push_back({ 'L', 9 });
	g[13].push_back({ 'J', 15 });
	g[13].push_back({ 'J', 9 });
	g[13].push_back({ 'I', 13 });

	g[14].push_back({ 'L', 0 });
	g[14].push_back({ 'L', 21 });
	g[14].push_back({ 'J', 2 });
	g[14].push_back({ 'I', 14 });

	g[15].push_back({ 'S', 2 });
	g[15].push_back({ 'T', 2 });
	g[15].push_back({ 'T', 23 });
	g[15].push_back({ 'L', 1 });
	g[15].push_back({ 'L', 8 });
	g[15].push_back({ 'L', 17 });
	g[15].push_back({ 'J', 22 });
	g[15].push_back({ 'I', 15 });
	g[15].push_back({ 'S', 0 });

	g[16].push_back({ 'L', 1 });
	g[16].push_back({ 'J', 3 });
	g[16].push_back({ 'J', 20 });
	g[16].push_back({ 'I', 16 });

	g[17].push_back({ 'S', 1 });
	g[17].push_back({ 'T', 1 });
	g[17].push_back({ 'T', 22 });
	g[17].push_back({ 'L', 23 });
	g[17].push_back({ 'J', 2 });
	g[17].push_back({ 'J', 4 });
	g[17].push_back({ 'J', 15 });
	g[17].push_back({ 'I', 17 });
	g[17].push_back({ 'O', 3 });

	g[18].push_back({ 'S', 0 });
	g[18].push_back({ 'T', 4 });
	g[18].push_back({ 'L', 3 });
	g[18].push_back({ 'L', 5 });
	g[18].push_back({ 'J', 8 });
	g[18].push_back({ 'I', 18 });

	g[19].push_back({ 'Z', 3 });
	g[19].push_back({ 'T', 8 });
	g[19].push_back({ 'L', 4 });
	g[19].push_back({ 'J', 0 });
	g[19].push_back({ 'J', 9 });
	g[19].push_back({ 'I', 19 });

	g[20].push_back({ 'T', 3 });
	g[20].push_back({ 'L', 16 });
	g[20].push_back({ 'I', 20 });

	g[21].push_back({ 'T', 0 });
	g[21].push_back({ 'J', 14 });
	g[21].push_back({ 'I', 21 });

	g[23].push_back({ 'S', 0 });
	g[23].push_back({ 'I', 23 });

	g[24].push_back({ 'J', 0 });
	g[24].push_back({ 'I', 24 });

	g[25].push_back({ 'L', 3 });
	g[25].push_back({ 'I', 25 });

	g[26].push_back({ 'L', 27 });
	g[26].push_back({ 'J', 3 });
	g[26].push_back({ 'I', 26 });

	g[27].push_back({ 'L', 0 });
	g[27].push_back({ 'J', 26 });
	g[27].push_back({ 'I', 27 });
}
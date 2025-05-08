#include <stdio.h>
#include <conio.h>
#include <vector>
#include <stdlib.h>
struct edge
{
	char piece;
	int next;
};
std::vector<edge> g[28];
const char pieces[7] = { 'J', 'I', 'T', 'Z', 'L', 'O', 'S' };
bool dfs(int, char, char, char*);
void init(void);
int main()
{
	system("");
	printf("\033[91mTetr.io\033[0m\n");
	init();
	char buffer[128] = "";
	while (true)
	{
		int board, len = 0;
		char hode[3], now[2], next[32];
		puts("\033[36mInput with \033[90m[board id] [hold piece] [current piece] [next pieces]\033[0m");
		while (buffer[len])
		{
			if (buffer[len] == 'J')
				printf("\033[94m");
			else if (buffer[len] == 'I')
				printf("\033[96m");
			else if (buffer[len] == 'T')
				printf("\033[95m");
			else if (buffer[len] == 'Z')
				printf("\033[91m");
			else if (buffer[len] == 'L')
				printf("\033[31m");
			else if (buffer[len] == 'O')
				printf("\033[33m");
			else if (buffer[len] == 'S')
				printf("\033[92m");
			putchar(buffer[len]);
			printf("\033[0m");
			++len;
		}
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
				putchar('\n');
				break;
			}
			else
			{
				buffer[len++] = c;
				buffer[len] = 0;
				if (c == 'J')
					printf("\033[94m");
				else if (c == 'I')
					printf("\033[96m");
				else if (c == 'T')
					printf("\033[95m");
				else if (c == 'Z')
					printf("\033[91m");
				else if (c == 'L')
					printf("\033[31m");
				else if (c == 'O')
					printf("\033[33m");
				else if (c == 'S')
					printf("\033[92m");
				putchar(c);
				printf("\033[0m");
			}
		}
		if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i' && buffer[3] == 't' && buffer[4] == 0)
			break;
		sscanf(buffer, "%d%s%s%s", &board, hode, now, next);
		if (hode[0] == '-')
			hode[0] = -hode[1];
		int res = -2, point = 0, lengthOfNext = 0;
		while (next[lengthOfNext])
			++lengthOfNext;

		for (auto [piece, to] : g[board])
			if (piece == now[0])
			{
				int nowPoint = 0;
				for (char lastPiece : pieces)
				{
					next[lengthOfNext] = lastPiece;
					next[lengthOfNext + 1] = 0;
					if (dfs(to, abs(hode[0]), next[0], next + 1))
						++nowPoint;
					next[lengthOfNext] = 0;
				}
				if (nowPoint > point)
				{
					point = nowPoint;
					res = to;
				}
			}

		{
			int nowPoint = 0;
			for (char lastPiece : pieces)
			{
				next[lengthOfNext] = lastPiece;
				next[lengthOfNext + 1] = 0;
				if (dfs(board, -now[0], abs(hode[0]), next))
					++nowPoint;
				next[lengthOfNext] = 0;
			}
			if (nowPoint > point)
			{
				point = nowPoint;
				res = -1;
			}
		}

		if (res == -2)
		{
			puts("\033[91mNo solution.\n\033[0m");
			buffer[0] = 0;
		}
		else if (res == -1)
		{
			puts("\033[90mHolding piece.\n\033[0m");
			sprintf(buffer, "%d -%c %c %s", board, now[0], hode[0], next);
		}
		else
		{
			printf("\033[38;2;0;128;0mMove to %d.\n\n\033[0m", res);
			sprintf(buffer, "%d %c %c %s", res, abs(hode[0]), next[0], next + 1);
		}
	}
	printf("\033[32mThanks for your using.\033[0m");
	return 0;
}
inline char abs(char x) { return x < 0 ? -x : x; }
bool dfs(int board, char hold, char now, char* next)
{
	if (now == 0)
		return true;
	for (auto [piece, to] : g[board])
		if (piece == now && dfs(to, abs(hold), *next, next + 1))
			return true;
	if (hold > 0 && dfs(board, -now, hold, next))
		return true;
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

	g[2].push_back({ 'S', 9 });
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

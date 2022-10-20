#include<iostream>
using namespace std;

const int MAX = 1e3 + 5;

int N,M;
int Answer;
int Map[MAX][MAX];

bool Visit[MAX][MAX];
bool IsHill;

int drow[8] = {-1,-1,-1, 0,0, 1,1,1};
int dcol[8] = {-1, 0, 1,-1,1,-1,0,1};

void DFS(int row, int col)
{
	Visit[row][col] = true;

	for(int i = 0; i < 8; i++)
	{
		int r = row + drow[i];
		int c = col + dcol[i];

		if(r >= 0 && r < N && c >= 0 && c < M)
		{
			if(IsHill && Map[r][c] > Map[row][col]) IsHill = false;
			if(Map[r][c] == Map[row][col] && !Visit[r][c]) DFS(r, c);
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
	freopen("BAI2.INP","r",stdin);
	freopen("BAI2.OUT","w",stdout);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			Visit[i][j] = false;
		}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(!Visit[i][j])
			{
				IsHill = true;
				DFS(i, j);
				Answer += (IsHill);
			}

	cout << Answer << endl;

	return 0;
}

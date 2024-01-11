#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int solution(vector<vector<int>> maps)
{
	int answer = -1;

	int deltaY[4] = { -1, 0, 1, 0 };
	int deltaX[4] = { 0, 1, 0, -1 };

	const int n = maps.size();
	const int m = maps[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// 튜플로 pos 만든다. (y, x, distance)
	queue<tuple<int, int, int>> mapQueue;

	mapQueue.push(make_tuple(0, 0, 1));
	visited[0][0] = true;

	while (!mapQueue.empty())
	{
		tuple<int, int, int> pos = mapQueue.front();
		mapQueue.pop();

		int nowY = get<0>(pos);
		int nowX = get<1>(pos);
		int nowDistance = get<2>(pos);

		if (nowY == n - 1 && nowX == m - 1)
			answer = nowDistance;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + deltaY[i];
			int nextX = nowX + deltaX[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
				continue;
			if (maps[nextY][nextX] == 0)
				continue;
			if (visited[nextY][nextX])
				continue;

			mapQueue.push(tuple<int, int, int>(nextY, nextX, nowDistance + 1)); // 거리 저장
			visited[nextY][nextX] = true;
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> maps;
	maps.push_back({ 1, 0, 1, 1, 1 });
	maps.push_back({ 1, 0, 1, 0, 1 });
	maps.push_back({ 1, 0, 1, 1, 1 });
	maps.push_back({ 1, 1, 1, 0, 1 });
	maps.push_back({ 0, 0, 0, 0, 1 });

	cout << solution(maps);

	return 0;
}
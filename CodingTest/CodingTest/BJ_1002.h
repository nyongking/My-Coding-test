#pragma once

#include <iostream>
using namespace std;

/*
  https://www.acmicpc.net/problem/1002

  정답의 종류는 총 4개 : 2, 1, 0, -1(무한대)
  1) -1이 나오는 경우
  조건 : (x1, y1, r1) = (x2, y2, r2)
  2) 0이 나오는 경우
  조건1 : (x1, y1) = (x2, y2) && (r1 != r2)
  조건2 : 1과 2사이의 거리가 r1 + r2보다 멀 경우,
  조건3 : 1과 2사이의 거리가 r1 or r2 - r2 or r1보다 작을 경우 (한 원이 다른 원의 내부에 있는 경우)
  3) 1이 나오는 경우
  조건1 : 1과 2사이의 거리 = r1 + r2
  조건2 : 1과 2사이의 거리 = r1 or r2 - r2 or r1 (내접하는 경우)
  4) 2가 나오는 경우
  나머지

*/

void Solve()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2)
		{
			// 1) -1이 나오는 경우
			if (r1 == r2)
				cout << -1;
			// 2) 0이 나오는 경우
			else
				cout << 0;
		}

		else
		{
			int lenSquare = (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
			int rSquare = (r1 + r2) * (r1 + r2);

			if (lenSquare == rSquare) // 1이 나오는 경우
				cout << 1;
			else if (lenSquare > rSquare) // 0이 나오는 경우
				cout << 0;
			else // 둘 사이의 거리가 r1 + r2보다 작을 경우
			{
				int rDiffSquare = (r1 - r2) * (r1 - r2);

				if (rDiffSquare == lenSquare)
					cout << 1;
				else if (rDiffSquare > lenSquare)
					cout << 0;
				else
					cout << 2;
			}
		}

		cout << '\n';
	}
}
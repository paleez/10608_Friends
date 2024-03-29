// 10608_Friends_DennisNilsson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstring>

int visited[30001];
int count;
std::vector<int> nodes[30001];

void dfs(int u);

void dfs(int u)
{
	int v;
	visited[u] = 1;
	for (auto i = 0; i < nodes[u].size(); i++)
	{
		v = nodes[u][i];
		if (visited[v] == 0)
		{
			dfs(v);
			count++;
		}
	}
}

int main()
{
	int tc;
	int citizens; // nodes
	int pairs; // edges
	int a;
	int b;
	int lgf;

	std::cin >> tc;

	
	
	for (auto i = 0; i < tc; i++)
	{
		std::cin >> citizens >> pairs;

		memset(nodes, 0, sizeof(nodes));
		memset(visited, 0, sizeof(visited));

		for (auto j = 0; j < pairs; j++)
		{
			std::cin >> a >> b;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		lgf = 0;

		for (auto k = 0; k < citizens; k++)
		{
			count = 1;
			if (visited[k] == 0)
			{
				dfs(k);
			}
			if (count > lgf)
			{
				lgf = count;
			}
		}

		std::cout << lgf << std::endl;
	}
    return 0;
}


/*
이분 매칭을 구현하되
각 상어들의 크기,지능,속도를
비교해서 그래프를 구현하자

그런다음 이분 매칭을 한 후
전체 상어수에서 총 매칭수를 빼자
*/
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
#define MAX 51
typedef tuple<long, long, long>edge;

int N;
long ssize, speed, intelligence;
vector<long>graph[MAX];
vector<edge>input;
long node[MAX];
bool visit[MAX];
bool dfs(int shark);
int findMax(edge node1, edge node2);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ssize >> speed >> intelligence;
		input.push_back(edge(ssize, speed, intelligence));
	}

	long samecount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			edge tmp = input[i];
			edge tmp2 = input[j];
			int check = findMax(tmp, tmp2);
			if (check == 1)
				graph[i+1].push_back(j+1);
			else if (check == -1)
				graph[j+1].push_back(i+1);
			else if (check == 100) {
				samecount++;
				graph[i+1].push_back(j+1);
			}
		}
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			fill(visit, visit + MAX, false);
			if (dfs(i))
				count++;
		}
	}
	
	long res = N * (N - 1) / 2;
	if (samecount == res)
		cout << 1;
	else
		cout << N - count;
}

bool dfs(int shark)
{
	for (int i = 0; i < graph[shark].size(); i++) {
		int shark2 = graph[shark][i];
		if (visit[shark2])
			continue;
		visit[shark2] = true;
		if (node[shark2] == 0 || dfs(node[shark2])) {
			node[shark2] = shark;
			return true;
		}
	}
	return false;
}

int findMax(edge node1, edge node2) // node1이 더 크면 true를, node2가 더 크면 false를 반환
{
	long size1 = get<0>(node1);
	long speed1 = get<1>(node1);
	long intelligence1 = get<2>(node1);
	long size2 = get<0>(node2);
	long speed2 = get<1>(node2);
	long intelligence2 = get<2>(node2);

	if (size1 == size2 && speed1 == speed2 && intelligence1 == intelligence2)
		return 100;
	if (size1 >= size2 && speed1 >= speed2 && intelligence1 >= intelligence2)
		return 1;
	else if (size1 <= size2 && speed1 <= speed2 && intelligence1 <= intelligence2)
		return -1;
	return 0;
}

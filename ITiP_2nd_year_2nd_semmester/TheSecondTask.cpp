#include "Header_ITiP_2nd_year_2nd_semmester.h"

using namespace std;

const int INF = 1e9;

class Graph //Граф, представленный в виде матрицы смежности
{ 
public:
	int n;
	vector<vector<int>> matrix;

	Graph(int n) : n(n) {
		matrix.resize(n, vector<int>(n, INF));
		for (int i = 0; i < n; i++)
			matrix[i][i] = 0;
	}

	void addEdge(int u, int v, int w) {
		matrix[u][v] = w;
		matrix[v][u] = w;
	}

	void removeNode(int t) {
		for (int i = 0; i < n; i++) {
			matrix[t][i] = INF;
			matrix[i][t] = INF;
		}
	}
};

vector<int> dijkstra(Graph& g, int start) //Дейкстра для поиска кратчайших расстояний от узла start до всех остальных узлов в графе g 
{
	vector<int> dist(g.n, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		for (int v = 0; v < g.n; v++) {
			if (g.matrix[u][v] != INF) {
				if (dist[v] > d + g.matrix[u][v]) {
					dist[v] = d + g.matrix[u][v];
					pq.push({ dist[v], v });
				}
			}
		}
	}

	return dist;
}


vector<vector<int>> floyd(Graph g) //Флойд для поиска кратчайших расстояний между всеми парами узлов в графе g
{
	auto dist = g.matrix;

	for (int k = 0; k < g.n; k++)
		for (int i = 0; i < g.n; i++)
			for (int j = 0; j < g.n; j++)
				if (dist[i][k] < INF && dist[k][j] < INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	return dist;
}

int TheSecondTask_int()
{
	std::cout << "Пакеты передаются между узлами по кратчайшим расстояниям." << std::endl;
	std::cout << "В момент передачи пакета из узла K в узел M произошел сбой (из строя вышел узел T)." << std::endl;
	std::cout << "Написать программу, используя методологию ООП, применяя алгоритмы Флойда и  Дейкстры," << std::endl;
	std::cout << "которая вычисляла кратчайшие расстояния до и после сбоя передачи пакета из узла K в узел M." << std::endl;
	std::cout << "К, M, T – случайные числа." << std::endl << std::endl;
	std::cout << "В варианте 14 дана схема из 8 узлов." << std::endl;
	std::cout << "Нужно найти рандомно, между какими узлами передаются пакеты." << std::endl;
	std::cout << "По условию, у нас идет пакет через 1 узел, то есть, напрямую данные не передаются." << std::endl;
	std::cout << "Это значит, что у нас не должно быть того, что пакеты передаются из узла 5 в узел 6" << std::endl;
	std::cout << "Значит, нам нужно сгенерировать не только 2 узла, между которыми данные передаются, а так же" << std::endl;
	std::cout << "сделать правило, что между этими узлами должно быть 1 и более других узлов." << std::endl;
	
	srand(time(0));

	Graph g(8);

	// Инициализация графа с 8 узлами и весами ребер
	g.addEdge(0, 1, 2);
	g.addEdge(1, 2, 3);
	g.addEdge(2, 3, 4);
	g.addEdge(3, 4, 2);
	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 5);
	g.addEdge(6, 7, 3);
	g.addEdge(7, 0, 6);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 4, 5);

	//Случайные узлы K, M, T
	int K = rand() % 8;
	int M = rand() % 8;
	while (M == K) M = rand() % 8;

	int T = rand() % 8;
	while (T == K || T == M) T = rand() % 8;

	cout << "Старт (K): " << K + 1 << endl;
	cout << "Финиш (M): " << M + 1 << endl;
	cout << "Сбойный узел (T): " << T + 1 << endl;

	// Работа до сбоя
	auto distBefore = dijkstra(g, K);
	cout << "\nДо сбоя (Дейкстра): ";

	if (distBefore[M] == INF)
		cout << "нет пути\n";
	else
		cout << distBefore[M] << endl;

	auto floydBefore = floyd(g);
	cout << "До сбоя (Флойд): ";

	if (floydBefore[K][M] == INF)
		cout << "нет пути\n";
	else
		cout << floydBefore[K][M] << endl;

	// сам сбой - удаление узла T
	g.removeNode(T);

	//работа после сбоя
	auto distAfter = dijkstra(g, K);
	cout << "\nПосле сбоя (Дейкстра): ";

	if (distAfter[M] == INF)
		cout << "нет пути\n";
	else
		cout << distAfter[M] << endl;

	auto floydAfter = floyd(g);
	cout << "После сбоя (Флойд): ";

	if (floydAfter[K][M] == INF)
		cout << "нет пути\n";
	else
		cout << floydAfter[K][M] << endl;

	return 0;
}
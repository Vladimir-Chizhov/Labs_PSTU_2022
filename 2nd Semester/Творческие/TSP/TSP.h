#ifndef TSP_H
#define TSP_H

#endif // TSP_H

#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "Graph.h"


using namespace std;


class TSPSolver {
private:
    const int INF = numeric_limits<int>::max();  // Бесконечность

    vector<int> bestPath;       // Наилучший путь
    int bestCost = INF;         // Наилучшая стоимость
    int startVertex;            // Начальная вершина
    int numVertices;            // Кол-во вершин
    vector<bool> visited;       // Пройденные вершины

public:
    TSPSolver(const Graph& graph, int startVertex)
        : startVertex(startVertex), numVertices(graph.Smatr.size())
    {
        visited.resize(numVertices, false);
        bestPath.resize(numVertices + 1);
    }

    void solve(const Graph& graph) {
        vector<int> path(numVertices + 1);
        path[0] = startVertex;
        visited[startVertex] = true;

        tsp(graph, path, 0, 1, 0);

        visited[startVertex] = false;
    }

    void tsp(const Graph& graph, vector<int>& path, int currCost, int level, int pos) {
        if (level == numVertices) {
            if (graph.Smatr[path[level - 1]][startVertex] != 0) {
                int currPathCost = currCost + graph.Smatr[path[level - 1]][startVertex];

                if (currPathCost < bestCost) {
                    for (int i = 0; i < numVertices; i++) {
                        bestPath[i] = path[i];
                    }
                    bestPath[numVertices] = startVertex;
                    bestCost = currPathCost;
                }
            }
            return;
        }

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && graph.Smatr[path[level - 1]][i] != 0) {  // Проверка наличия ребра между вершинами
                visited[i] = true;
                path[level] = i;
                tsp(graph, path, currCost + graph.Smatr[path[level - 1]][i], level + 1, i);
                visited[i] = false;
            }
        }
    }

    string getBestPath(const vector<string>& vertexNames) {

        if (bestCost == INF) {
                return "Нет решения";
            }

        string result;
        for (int i = 0; i <= numVertices; i++) {
            result += vertexNames[bestPath[i]];
            if (i != numVertices)
                result += " -> ";
        }
        return result;
    }

    int getBestCost() const {
        return bestCost;
    }

    vector<int> bestpath_vec()
    {
        return bestPath;
    }
};



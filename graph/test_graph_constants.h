#ifndef TEST_GRAPH_CONSTANTS_H
#define TEST_GRAPH_CONSTANTS_H

#include <iostream>

#define INF 999
#define N 7

#define GRAPH                                                     \
  {                                                               \
    {0, 3, INF, INF, INF, INF, 2}, {3, 0, 2, INF, INF, INF, 5},   \
        {INF, 2, 0, 7, 1, 1, 3}, {INF, INF, 7, 0, 6, 7, INF},     \
        {INF, INF, 1, 6, 0, 4, INF}, {INF, INF, 1, 7, 4, 0, 8}, { \
      2, 5, 3, INF, INF, 8, 0                                     \
    }                                                             \
  }

void print(int graph[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      if (graph[i][j] != INF)
        std::cout << graph[i][j] << "  ";
      else
        std::cout << "~  ";
    std::cout << "\n";
  }
}

#endif

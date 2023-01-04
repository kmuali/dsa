#include <iostream>

#include "test_graph_constants.h"

void shortest_path(int graph[N][N], int src, int dst) {
  int r, min_w, min_r;

  struct GraphNode {
    int dst, w;
    bool connected;
  } nodes[N];

  for (r = 0; r < N; r++) nodes[r] = {src, INF, false};
  nodes[src] = {src, 0, true};
  min_r = src;
  min_w = 0;

  do {
    for (r = 0; r < N; r++)
      if (!nodes[r].connected && nodes[r].w > graph[r][min_r] + min_w) {
        nodes[r].w = graph[r][min_r] + min_w;
        nodes[r].dst = min_r;
      }

    min_w = INF;
    for (r = 0; r < N; r++)
      if (!nodes[r].connected && min_w > nodes[r].w) {
        min_w = nodes[r].w;
        min_r = r;
      }

    nodes[min_r].connected = true;

    std::cout << "shortest_path  min_w=" << min_w << "  min_r=" << min_r
              << "\n";
    std::cout << "shortest_path  nodes[]=";
    for (r = 0; r < N; r++) {
      std::cout << nodes[r].dst << ":";
      if (nodes[r].w == INF)
        std::cout << "~";
      else
        std::cout << nodes[r].w;
      std::cout << ":" << nodes[r].connected << " ";
    }
    std::cout << "\n";

  } while (min_r != dst);

  std::cout << "shortest_path  " << dst;
  r = dst;
  while (r != src) {
    r = nodes[r].dst;
    std::cout << "--" << r;
  }
  std::cout << "\n";
}

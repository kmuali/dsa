#include <iostream>

#include "test_graph_constants.h"

void prims_minspan(int src_graph[N][N], int dst_graph[N][N]) {
  int r, c, total_w, min_w, min_r, nxt_min_r;

  for (r = 0; r < N; r++) {
    dst_graph[r][r] = 0;
    for (c = r + 1; c < N; c++) {
      dst_graph[r][c] = INF;
      dst_graph[c][r] = INF;
    }
  }

  struct GraphNode {
    int dst, w;
    bool connected;
  } nodes[N];

  nodes[0] = {0, 0, true};
  for (r = 1; r < N; r++) nodes[r] = {0, INF, false};
  min_r = 0;

  total_w = 0;

  while (1) {
    for (r = 1; r < N; r++)
      if (!nodes[r].connected && src_graph[r][min_r] < nodes[r].w) {
        nodes[r].w = src_graph[r][min_r];
        nodes[r].dst = min_r;
      }

    min_w = INF;
    for (r = 1; r < N; r++)
      if (!nodes[r].connected && nodes[r].w < min_w) {
        min_w = nodes[r].w;
        min_r = nodes[r].dst;
        nxt_min_r = r;
      }

    if (min_w == INF) {
      print(dst_graph);
      std::cout << "prims_minspan  total_w=" << total_w << "\n";
      return;
    }
    total_w += min_w;
    dst_graph[min_r][nxt_min_r] = min_w;
    dst_graph[nxt_min_r][min_r] = min_w;

    std::cout << "prims_minspan  min_w=" << min_w << "  min_r=" << min_r
              << "  nxt_min_r=" << nxt_min_r << "\n";

    min_r = nxt_min_r;
    nodes[min_r].connected = true;

    std::cout << "prims_minspan  nodes[]=";
    for (r = 0; r < N; r++) {
      std::cout << nodes[r].dst << ":";
      if (nodes[r].w == INF)
        std::cout << "~";
      else
        std::cout << nodes[r].w;
      std::cout << ":" << nodes[r].connected << " ";
    }
    std::cout << "\n";
  }
}

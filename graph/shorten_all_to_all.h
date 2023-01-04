#include <iostream>

#include "test_graph_constants.h"

void shorten_all_to_all(int graph[N][N]) {
  int r, c, src, via, dst, flag;

  do {
    flag = 0;
    for (src = 0; src < N; src++)
      for (via = 0; via < N; via++)
        for (dst = 0; dst < N; dst++)
          if (graph[src][dst] > graph[src][via] + graph[via][dst]) {
            std::cout << "shorten_all_to_all  src=" << src << "  via=" << via
                      << "  dst=" << dst << "\n";
            graph[src][dst] = graph[src][via] + graph[via][dst];
            flag++;
          }
    std::cout << "shorten_all_to_all  flag=" << flag << "\n";
    print(graph);
  } while (flag);
}

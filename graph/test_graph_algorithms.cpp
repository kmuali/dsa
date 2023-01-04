#include <iostream>

#include "kruskals_minspan.h"
#include "prims_minspan.h"
#include "shorten_all_to_all.h"
#include "shortest_path.h"
#include "test_graph_constants.h"

#define PRINTSEP std::cout << "\n============\n";

int main() {
  int graph1[N][N] = GRAPH;
  int graph2[N][N];

  std::cout << "Example graph:\n";
  print(graph1);

  PRINTSEP
  kruskals_minspan(graph1, graph2);

  int graph3[N][N] = GRAPH;
  int graph4[N][N];
  PRINTSEP
  prims_minspan(graph3, graph4);

  int graph5[N][N] = GRAPH;
  PRINTSEP
  shorten_all_to_all(graph5);

  int graph6[N][N] = GRAPH;
  PRINTSEP
  shortest_path(graph6, 0, 3);
  PRINTSEP
  shortest_path(graph6, 1, 5);

  return 0;
}

#include <iostream>

#include "test_graph_constants.h"

void kruskals_minspan(int src_graph[N][N], int dst_graph[N][N]) {
  int r, c, total_w, min_w, min_r, min_c, gps[N], gps_n, tmp_gp;

  for (r = 0; r < N; r++) {
    dst_graph[r][r] = 0;
    for (c = r + 1; c < N; c++) {
      dst_graph[r][c] = INF;
      dst_graph[c][r] = INF;
    }
  }

  for (r = 0; r < N; r++) gps[r] = 0;
  gps_n = 0;
  total_w = 0;

  while (1) {
    min_w = INF;
    for (r = 0; r < N; r++)
      for (c = r + 1; c < N; c++)
        if (src_graph[r][c] < min_w) {
          min_w = src_graph[r][c];
          min_r = r;
          min_c = c;
        }
    if (min_w == INF) {
      print(dst_graph);
      std::cout << "kruskals_minspan  total_w=" << total_w << "\n";
      return;
    }
    src_graph[min_r][min_c] = INF;
    std::cout << "kruskals_minspan  min_w=" << min_w << "  min_r=" << min_r
              << "  min_c=" << min_c << "\n";

    if (!gps[min_r] || !gps[min_c] || gps[min_c] != gps[min_r]) {
      dst_graph[min_r][min_c] = min_w;
      dst_graph[min_c][min_r] = min_w;
      total_w += min_w;
      if (!gps[min_r] && !gps[min_c]) {
        gps[min_r] = ++gps_n;
        gps[min_c] = gps_n;
      } else if (!gps[min_r]) {
        gps[min_r] = gps[min_c];
      } else if (!gps[min_c]) {
        gps[min_c] = gps[min_r];
      } else {
        tmp_gp = gps[min_r];
        for (r = 0; r < N; r++)
          if (gps[r] == tmp_gp) gps[r] = gps[min_c];
        gps_n--;
      }
    }

    std::cout << "kruskals_minspan  gps[]=";
    for (r = 0; r < N; r++) std::cout << gps[r] << " ";
    std::cout << "\n";
  }
}

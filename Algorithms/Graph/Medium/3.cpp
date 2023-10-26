#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<vector<int>> GRAPH;

bool valid(int nr, int nc, int row, int col) {
    if (nr < 0 || nr >= row || nc < 0 || nc >= col)
        return false;
    return true;
}

void add_edges(GRAPH& graph, int from, int to) {
    graph[from].push_back(to);
}

void add_image(GRAPH& graph, int row, int col) {
    const int dr[]{ 0, 0, 1, -1 };
    const int dc[]{ -1, 1, 0, 0 };
    int from, to;

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            from = r * col + c;
            for (int dir = 0; dir < 4; ++dir) {
                int nc = dc[dir] + c;
                int nr = dr[dir] + r;

                if (valid(nr, nc, row, col)) {
                    to = nr * col + nc;
                    add_edges(graph, from, to);
                }
            }
        }
    }
}

void print(GRAPH& graph) {
    int nodes = graph.size();
    for (int i = 0; i < nodes; i++) {
        cout << "Node " << i << " has neighbors: ";
        for (int to = 0; to < (int)graph[i].size(); ++to) {
            cout << graph[i][to] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cout << "Enter number of ROWS and COLUMNS: ";
    int col, row;
    cin >> row >> col;
    GRAPH  graph(row * col);

    add_image(graph, row, col);
    print(graph);
}

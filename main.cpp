#include <iostream>
#include "Graph.h"
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
    string filename = "datasets/soc-epinions.txt";
    Graph *g = new Graph(filename);

    if(g->getNumberNodes() > 0)
    {
        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        cout << "Number of Nodes: " << g->getNumberNodes() << endl;
        g->computeCentrality();
        cout << "Centrality: " << endl;

        auto end = chrono::high_resolution_clock::now();
        g->printCentrality();
        // Calculating total time taken by the program.
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        time_taken *= 1e-9;

        cout << "Time taken by program is : " << fixed
             << time_taken << setprecision(9);
        cout << " sec" << endl;

    }
    else
        cout << "Data null in the dataset";

    delete g;
}

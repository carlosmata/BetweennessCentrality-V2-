#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Graph
{
    public:
        Graph(string filename);
        Graph(int numberNodes);
        virtual ~Graph();

        //Graph
        //void addEdge(int nodeI, int nodeJ, int cost);
        bool addEdges(string filename);
        int getNumberNodes();
        void computeCentrality();
        void printCentrality();

        //Node
        void addEdge(int source, int endpoint, int cost);
        void resetValues(int source);
        vector<float> getEdgesCost(int source);
        vector<int> getEdgesEdpoints(int source);
        int getNextIndex(int source);
        void resetCentrality(int source);
        void incrementCentrality(int source, float increment);
        float getCentrality(int source);
        void setVisited(int source, bool visited);
        bool isVisited(int source);
        void setDistance(int source, int distance);
        int getDistance(int source);
        void setParent(int source, int parent);
        void addParent(int source, int parent);
        vector<int> getParents(int source);

        //Edge
        int getEndpoint(int source, int offset);
        float getCost(int source, int offset);

    protected:

    private:
        int numberNodes;

        vector<float> edges_cost;
        vector<int> edges_tail;
        vector<int> indexs;

        //To centrality
        vector<float> centrality;
        vector<bool> visited;
        vector<int> distance;
        vector<vector<int>> parents;

        void dijkstra(int source);
        int readNumberOfNodes(string filename);
        int getSmallDistance();
        void computeCentralityPath(int source, int tail, int n_shortest_path);

};

#endif // GRAPH_H

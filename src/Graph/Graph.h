#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include "Node.h"
#include "MutablePriorityQueue.h"

using namespace std;



class Graph
{
private:
    unordered_map<long,Node*> nodes;
    vector<Node*> nodesVector;
    unordered_map<long,Edge*> edges;
    vector<unordered_set<int>> graphs;
    vector<vector<int>> graphsVector;
    unordered_map<int,int> edgeDiff;
    vector<vector<int>> floydMatrix;
    bool hasFloyd = false;
    bool grid = false;
public:
    bool isGrid() const;

    void setGrid(bool grid);

private:

    //FLoyd Warshall matrices
    double ** W;   // dist
    double **P;   // path


    void initNodes(Node *origin,Node *target,vector<Node> *nodesVisited = nullptr);
    bool relax(Node *v,Node *w, double weight,long int targetDistance, int edge_difficulty, int difficulty,bool withPoi = true);
    void DFSVisit(Node *v);

    vector<int> selected_difficulties;
    int numOfConfluencePoints;
    float calculateDistance(int n1,int n2);
    void defineHours(vector<int> finalVect,vector<int> confluencePoints,vector<int> &hours);
public:
    vector<int> mandatoryPOIS(vector<int> confluencePoints,vector<int> mandatoryPOIS,vector<int> hours, vector<int> difficulties);
    int getNumOfConfluencePoints() const;
    void setNumOfConfluencePoints(int numOfConfluencePoints);
    unordered_map<int,int> getEdgeDiff();
    void setEdgeDiff(const unordered_map<int,int> edgeDiff);
    void setGraphs(const vector<unordered_set<int>> &graphs);
    const vector<vector<int>> &getGraphsVector() const;
    void setGraphsVector(const vector<vector<int>> &graphsVector);
    const vector<vector<int>> &getFloydMatrix() const;
    void setFloydMatrix(const vector<vector<int>> &floydMatrix);
    string path;
    bool isHasFloyd() const;
    void setHasFloyd(bool hasFloyd);

    vector<vector<Node>> pointsToDraw;
    double min_x=8000000000000.0;
    double max_x=-800000000000.0;
    double min_y=8000000000000.0;
    double max_y=-800000000000.0;

    const unordered_map<long,Edge*> getEdges();
    void setEdges(const unordered_map<long, Edge*> edges);
    unordered_map<long,Node*> getNodes();
    vector<unordered_set<int>> getGraphs();
    vector<Node> getPath(long int origin,long int dest);
    Node *findNode(const int &id) const;
    bool addNode(const int &id, int x, int y,int position);
    bool addEdgeDiff(const int &id, int diff);
    bool addEdge(int edgeId,int origId, int destId);
    Edge *findEdge(Node orig, Node dest);
    Edge *findEdge(const int &id) const;
    void printMatrix(double** matrix, ostream& ostream);
    void resetVisited();
    bool difficultyRange(int difficulty, int edge_difficulty);
    int getNodeDistance(int origid, int destid);

    //Algorithms
    void DFSConnectivity(int id);
    void FloydWarshall(string directory);
    double AStar(long int origin,long int  target,long int targetDistance, int difficulty,vector<Node> *nodesVisited = nullptr,string AStarType = "");


    void removeUnvisited(Graph *graph);
    void removeSymetricEdges(int id);
    Edge *getSymetricEdge(Edge *edge);

    int getMostConnected();

    bool calculateInterestingPath(vector<int> confluencePoints, vector<int> hours, vector<int> difficulties, int TMax);

    int getNodeConnectedGraph(int node);

    bool isInConnectedGraph(int index, int node);

    void dijkstraShortestPath(const int &source, const int &dest);

    bool relaxDijkstra(Node *node, Edge *edge);

    void setSelectedDiff(vector<int> selected_difficulties){this->selected_difficulties = selected_difficulties;}
    vector<int> getSelectedDiff() {return selected_difficulties;}

    bool getRelaxFunction(Node *v, Node *w, double tam_edge, long targetDistance, int edge_difficulty, int difficulty,string type);

    bool relaxDistance(Node *v, Node *w, double tam_edge, long targetDistance,int edge_difficulty);
};


#endif // GRAPH_H

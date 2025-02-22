#include "Graph.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Graph::PrimsAlgorithm(int startVertex)
{
    int visited[8];
    for (int i = 0; i < 8; i++)
    {
        visited[i] = false;
    }

    visited[startVertex] = true; 
    int currentEdge = 0;
    int x;
    int y;
    while (currentEdge < 7)
    {
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < 8; i++)
        {
            if (visited[i]) {
                for (int j = 0; j < 8; j++)
                {
                    if (!visited[j])
                    {
                        if (min > graphMatrix[i][j])
                        {
                            min = graphMatrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x + 1 << " - "  << y + 1 << " : " << graphMatrix[x][y] << endl;
        visited[y] = true;
        currentEdge++;
    }
}

void Graph::KruskalsAlgoritm()
{
    int n = 8;
    int connectedVert[8];

    for (int i = 0; i < n; i++)
    {
        connectedVert[i] = i;
    }

    std::sort(edgeList.begin(), edgeList.end(), [](Edge& a, Edge& b) { return a.weight < b.weight; });

    for (Edge& e : edgeList)
    {
        if (connectedVert[e.start] != connectedVert[e.end])
        {
            cout << e.start << " - "  << e.end << " : " << e.weight << endl;

            int oldVert = connectedVert[e.start], newVert = connectedVert[e.end];

            for (int i = 0; i < n; i++)
            {
                if (connectedVert[i] == oldVert)
                {
                    connectedVert[i] = newVert;
                }
            }
        }
    }
}

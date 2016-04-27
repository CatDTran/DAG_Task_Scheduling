/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*dag_task_scheduling.cpp*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string>
#include "dag.h"

#define MAX 1000

using namespace std;
int numCrews = 0;
int numNodes = 0;
int numArcs = 0;
DAG directedAcylicGraph(MAX);
string line;
int main()
{
	int maxNodes = MAX;
	cin >> numCrews;
	cout << "Number of crews: " << numCrews << endl;
	while(getline(cin, line))
	{
		if(line[0] == 'c')
		{
			++numNodes;
			directedAcylicGraph.graph[numNodes].nodeName = numNodes;
			cout << directedAcylicGraph.graph[numNodes].nodeName << endl;
		}
		else if(line[0] == 'a')
		{
			++numArcs;
		}
	}
	cout << "numNodes: " << numNodes << " | numArcs: " << numArcs << endl;

}
/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*dag_task_scheduling.cpp*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include "dag.h"

#define MAX 1000

using namespace std;
int numCrews = 0;
int numNodes = 0;
int numArcs = 0;
DAG directedAcylicGraph(MAX);
DataReadySet myDataReadySet (MAX);
string line;
int main()
{
	int maxNodes = MAX;
	cin >> numCrews;
	cout << "Number of crews: " << numCrews << endl;
	directedAcylicGraph.distance;
	while(getline(cin, line))
	{
		string command;
		int tail, head, distance;
		istringstream iss(line);
		iss >> command;
		if(line[0] == 'c')
		{
			++numNodes;
			//initialize each node
			DAGNode node;
			node.nodeName = numNodes;
			node.taskScheduled = false;
			directedAcylicGraph.graph[numNodes] = node;
			//
			cout << directedAcylicGraph.graph[numNodes].nodeName;
			if(!node.taskScheduled)
				cout << "False" << endl;
			else
				cout << "True" << endl;
		}
		else if(line[0] == 'a')
		{
			++numArcs;
			iss >> tail;
			iss >> head;
			iss >> distance;
			cout << command << " " << tail << " " << head << " ";

			directedAcylicGraph.distance[tail][head] = distance;
			cout  << directedAcylicGraph.distance[tail][head] << endl;
		}
	}
	for(int i = 1;i <= numNodes; i++)
	{
		for (int j = 1; j <= numNodes; j++)
			if(i == j)
				directedAcylicGraph.distance[i][j] = 0;
			else if(i != j && directedAcylicGraph.distance[i][j] == 0)
			{
				directedAcylicGraph.distance[i][j] = -1;
			}
	}

	for(int i= 1; i <= numNodes; i++)
	{
		for(int j = 1; j <= numNodes; j++)
		{

			cout << directedAcylicGraph.distance[i][j] << " ";
		}
		cout << endl;
	}
	cout << "numNodes: " << numNodes << " | numArcs: " << numArcs << endl;
}
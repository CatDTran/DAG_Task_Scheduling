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
	cin >> numCrews;//read the first line which contains number of crews
	cout << "Number of crews: " << numCrews << endl;//print out the number of crews

	while(getline(cin, line))
	{
		string command;
		int nodeName;
		int tail, head, distance;
		istringstream iss(line);//store read in line into in-string-stream
		iss >> command;//first portion of in-string stream will be the 'command'
		//if command is 'c': create new node object
		if(line[0] == 'c')
		{
			++numNodes;
			iss >> nodeName;
			//initialize the node object
			DAGNode node(MAX);
			node.nodeName = nodeName;
			node.taskScheduled = false;
			node.numPredecessors = 0;
			node.numSuccessors = 0;
			directedAcylicGraph.graph[node.nodeName] = node;
			//
			cout << directedAcylicGraph.graph[node.nodeName].nodeName;
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

			int successorsIndex = ++directedAcylicGraph.graph[tail].numSuccessors;
			int predecessorsIndex = ++directedAcylicGraph.graph[head].numPredecessors;
			//store successor for each node
			directedAcylicGraph.graph[tail].successors[successorsIndex] = directedAcylicGraph.graph[head].nodeName;
			//store predecessors for each node
			directedAcylicGraph.graph[head].predecessors[predecessorsIndex] = directedAcylicGraph.graph[tail].nodeName;
			directedAcylicGraph.distance[tail][head] = distance;
			
			cout  << directedAcylicGraph.distance[tail][head] << endl;
		}
	}

	//print out successors for each node
	for(int i = 1; i <= numNodes;i++)
	{
		//print out node's successors
		cout << "Node " << directedAcylicGraph.graph[i].nodeName << " Successor: ";
		for(int j = 0; j <= directedAcylicGraph.graph[i].numSuccessors; j++)
		{
			if(directedAcylicGraph.graph[i].successors[j] != -1)
				cout << directedAcylicGraph.graph[i].successors[j];
		}
		cout << endl;

		//print out node's predecessors
		cout << "Node " << directedAcylicGraph.graph[i].nodeName << " Predecessors: ";
		for(int j = 0; j <= directedAcylicGraph.graph[i].numPredecessors; j++)
		{
			if(directedAcylicGraph.graph[i].predecessors[j] != -1)
				cout << directedAcylicGraph.graph[i].predecessors[j];
		}
		cout << endl;
	}
	// for(int i = 1;i <= numNodes; i++)
	// {
	// 	for (int j = 1; j <= numNodes; j++)
	// 		if(i == j)
	// 			directedAcylicGraph.distance[i][j] = 0;
	// 		else if(i != j && directedAcylicGraph.distance[i][j] == 0)
	// 		{
	// 			directedAcylicGraph.distance[i][j] = -1;
	// 		}
	// }

	// for(int i= 1; i <= numNodes; i++)
	// {
	// 	for(int j = 1; j <= numNodes; j++)
	// 	{

	// 		cout << directedAcylicGraph.distance[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << "numNodes: " << numNodes << " | numArcs: " << numArcs << endl;
}
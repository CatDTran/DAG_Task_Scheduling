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
void appendNode(DAGNode *start,DAGNode *endNode, int tail, int head);
void addSuccessors(DAGNode *tail, DAGNode *successors);
void printSuccessors(DAGNode *start);

int main()
{
	int maxNodes = MAX;
	DAGNode *current = new DAGNode();
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
			node.next = NULL;
			directedAcylicGraph.graph[node.nodeName] = node;
			//
			cout << "Node created: " << directedAcylicGraph.graph[node.nodeName].nodeName << endl;
			// if(!node.taskScheduled)
			// 	cout << "False" << endl;
			// else
			// 	cout << "True" << endl;
		}
		else if(line[0] == 'a')
		{
			++numArcs;
			iss >> tail;
			iss >> head;
			iss >> distance;
			cout << "Arc added: " << " " << tail << " --> " << head << " " << " | weight: " << distance << endl;
			//int successorsIndex = ++directedAcylicGraph.graph[tail].numSuccessors;
			//int predecessorsIndex = ++directedAcylicGraph.graph[head].numPredecessors;
			//store successor for each node
			addSuccessors(&directedAcylicGraph.graph[tail], &directedAcylicGraph.graph[head]);
			//appendNode(&directedAcylicGraph.graph[tail], &directedAcylicGraph.graph[head], tail, head);
			//store predecessors for each node
			//directedAcylicGraph.graph[head].predecessors[predecessorsIndex] = directedAcylicGraph.graph[tail].nodeName;
			//directedAcylicGraph.distance[tail][head] = distance;			
			//cout  << directedAcylicGraph.distance[tail][head] << endl;
		}
	}
	for(int i = 1; i <= numNodes; i++)
	{
		printSuccessors(&directedAcylicGraph.graph[i]);
	}

	//print out successors and predecessors for each node
	// for(int i = 1; i <= numNodes; i++)
	// {
	// 	cout << "Node " << directedAcylicGraph.graph[i].nodeName << " Successor: ";
	// 	DAGNode *temp = new DAGNode();
	// 	temp = directedAcylicGraph.graph[i].next;
	// 	while(temp != NULL)
	// 	{
	// 		cout << temp->nodeName;
	// 		temp = temp->next;
	// 		//break;			
	// 	}
	// 	cout << endl;
	// }
	// for(int i = 1; i <= numNodes;i++)
	// {
	// 	//print out node's successors
	// 	cout << "Node " << directedAcylicGraph.graph[i].nodeName << " Successor: ";
	// 	for(int j = 0; j <= directedAcylicGraph.graph[i].numSuccessors; j++)
	// 	{
	// 		if(directedAcylicGraph.graph[i].successors[j] != -1)
	// 			cout << directedAcylicGraph.graph[i].successors[j];
	// 	}
	// 	cout << endl;

	// 	//print out node's predecessors
	// 	cout << "Node " << directedAcylicGraph.graph[i].nodeName << " Predecessors: ";
	// 	for(int j = 0; j <= directedAcylicGraph.graph[i].numPredecessors; j++)
	// 	{
	// 		if(directedAcylicGraph.graph[i].predecessors[j] != -1)
	// 			cout << directedAcylicGraph.graph[i].predecessors[j];
	// 	}
	// 	cout << endl;
	//}
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

void appendNode(DAGNode *start,DAGNode *endNode, int tail, int head)
{
	DAGNode *current = new DAGNode();
	DAGNode *last = new DAGNode();
	*last = *endNode;
	current = start;
	while(current->next)
	{
		current = current->next;
	}
	current->next = new DAGNode();
	current->next = endNode;
	current->next->next = NULL;
}
void addSuccessors(DAGNode *tail, DAGNode *successors)
{
	int i = ++(tail->numSuccessors);
	tail->successors[i] = successors->nodeName;
}
void printSuccessors(DAGNode *start)
{
	DAGNode *current = start;
	// while(current->next)
	// {
	// 	cout << "Successor of node " << start->nodeName << ": " << current->nodeName << endl;
	// 	current = current->next;
	// }
	cout << "Node " << start->nodeName << " has successor(s): ";
	for(int i = 1; i <= start->numSuccessors;i++)
	{
		cout << start->successors[i] << " ";
	}

	cout << endl;
}
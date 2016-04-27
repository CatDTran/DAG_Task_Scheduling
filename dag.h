/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*dag.h*/
#include "node.h"
#include "data_ready_set.h"
#define MAX2 1000
class DAG
{
public:
	DAGNode graph[];
	int distance[MAX2][MAX2];
	DAG(int max);
};

DAG::DAG(int max)
{
	graph[max];
}
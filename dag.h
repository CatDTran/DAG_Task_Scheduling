/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*dag.h*/
#include "node.h"

class DAG
{
public:
	DAGNode graph[];
	DAG(int max);
};

DAG::DAG(int max)
{
	graph[max];
}
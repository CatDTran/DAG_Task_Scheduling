/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*node.h*/
#ifndef DAGNODE
#define DAGNODE
class DAGNode
{
	public:
	int nodeName;
	bool taskScheduled;
	int distance;
	int numPredecessors;
	int numSuccessors;
	int predecessors[];
	int successors[];
	DAGNode *next;

	DAGNode(int max);
};
DAGNode::DAGNode(int max)
{
	predecessors[max];
	successors[max];
}
#endif
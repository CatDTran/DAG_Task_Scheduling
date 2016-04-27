/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*node.h*/
#ifndef DAGNODE
#define DAGNODE
class DAGNode
{
	private:
		int maxNodes;
	public:
	int nodeName;
	bool taskScheduled;
	int distance;
	int numPredecessors;
	int numSuccessors;
	int predecessors[1000];
	int successors[1000];
	DAGNode *next;

	DAGNode(int max);
	void initializeSuccessors();
	void initializePredecessors();
};
DAGNode::DAGNode(int max)
{
	maxNodes = max;
	initializeSuccessors();
	initializePredecessors();
}
void DAGNode::initializeSuccessors()
{
	for (int i = 0; i < maxNodes; i++)
	{
		successors[i] = -1;
	}
}
void DAGNode::initializePredecessors()
{
	for (int i = 0; i < maxNodes; i++)
	{
		predecessors[i] = -1;
	}
}
#endif
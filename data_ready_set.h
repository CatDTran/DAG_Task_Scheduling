/*Author: Cat Tran
*Program: Task Scheduling using Directed Acylic Graph
*Spring 2016 CSCE 2110-Program 3
*University of North Texas
*data_ready_set.h*/

class DataReadySet
{
public:
	DAGNode readyNodes[];
	DataReadySet(int max);
};
DataReadySet::DataReadySet(int max)
{
	readyNodes[max];
}
This questino is not that hard. We have to analyze it first.

The problem can have 2 cases:
    1. each node has only one parent, and there is a circle.
    2. one node has 2 parents.

So the steps are:
1. determine if there is a node who has 2 parents.
	if so, store the 2 vectors, and ignore one in the following union-find.
2. Do the union find operation to find if there is a cycle.
	if every node has one parent, just return the px==py edge.
	else, return one of the stored edges.

Runtime: 8ms

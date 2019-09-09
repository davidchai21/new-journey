This question is not hard. We can use Union-Find to find the minimum path.

Sort the vector first by cost in ascending order. Then if 2 nodes' parents are the same, continue; otherwise union and add cost.

Runtime: 136ms

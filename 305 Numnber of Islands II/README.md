This question is not hard. We can use union-and-find to solve it.

Every time we add a new point, we mark it as a new island initially. Then for its 4 directions, if there is any territory adjacent, we union it together if the 2 parts doesn't belong to the same parent.

We maintain an integer count to count the current island number. 

Runtime: 140ms

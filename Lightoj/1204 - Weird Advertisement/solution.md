# explanation of solution

First we will to create two Segment Tree, one is a counter (have the amount of a segment) and sum has the answer for the queries. The most complex part is build the answer in the Segment Tree sum, then we are going to implement a sweep line, and each update we are going to go down to the leaf nodes or go down to where it's necessary, obiously, only for the path necessary. It is important that when you go dow, you have an acomulated.
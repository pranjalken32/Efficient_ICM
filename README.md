# Efficient_ICM

## Algorithm/flowchart

### START

1. Initialize the network
   - Set the status of each node in the network as either "inactive" or "active”.
   - Set the randomness of the edges between the nodes

2. Choose the initial set of active nodes
   - Select a set of nodes to be initially active

3. Divide the nodes into groups and assign each group to a processor
   - Divide the nodes in the network into groups
   - Assign each group to a processor

4. Iterate through the network until no new nodes are activated
   - For each active node in the group assigned to the processor:
     a. Attempt to activate its inactive neighbours based on the weights of the edges between them.
     b. For each newly activated node, add it to the set of active nodes.
     c. Repeat steps (a) and (b) until no new nodes are activated in the iteration.
   - Synchronize the active node list across all processors after each iteration

5. Output the final set of active nodes

### END

<br>

## The parallel ICM algorithm can be summarized as follows:

Initialize the network: Set the status of each node in the network as either "inactive" or "active". Also, set the randomness of the edges between the nodes.

Choose the initial set of active nodes: Select a set of nodes to be initially active.

Divide the nodes into groups and assign each group to a processor: Divide the nodes in the network into groups and assign each group to a processor. Each processor will execute the ICM algorithm on its assigned group of nodes.

Iterate through the network until no new nodes are activated:

a. For each active node in the group assigned to the processor, attempt to activate its inactive neighbours based on the weights of the edges between them.

b. For each newly activated node, add it to the set of active nodes.

c. Repeat steps (a) and (b) until no new nodes are activated in the iteration.

d. Synchronize the active node list: After each iteration, the active node list needs to be synchronized across all processors.

Output the final set of active nodes.

The parallel implementation of the ICM algorithm can significantly reduce the execution time of the ICM algorithm by utilizing multiple processors to work on different parts of the network simultaneously. However, the parallel implementation also introduces additional overhead due to the synchronization and communication required between processors. The optimal number of processors and the best partitioning strategy for the nodes depend on the specific characteristics of the network and the hardware used for the computation.

##Time comparison

In general, parallel code can be faster than serial code when dealing with large data sets and complex calculations. However, the exact speedup achieved will depend on a number of factors such as the nature of the problem, the algorithm used, the hardware configuration, and the efficiency of the parallelization.

When comparing the execution time of parallel and serial code, it is important to consider both the computation time and the communication time. Computation time is the time taken to perform actual calculations, whereas communication time refers to the time taken to move data between different processors or threads.

Hardware Configuration for the experiment:	
Processor	AMD Ryzen 9 5900HX with Radeon Graphics 3.30 GHz
Installed RAM	16.0 GB (15.4 GB usable)



### Observations: -

#### 2000 nodes 4000 edges
Serial time taken: 4.787000 seconds.
Parallel time taken: 1.069000 seconds.

#### 3000 nodes 6000 edges
Serial time taken: 16.148000 seconds.
Parallel time taken: 2.816000 seconds.

#### 4000 nodes 8000 edges
Serial time taken: 38.923000 seconds.
Parallel time taken: 6.666000 seconds.

#### 5000 nodes 12000 edges
Serial time taken: 83.736000 seconds.
Parallel time taken: 12.942000 seconds.

#### 10k nodes 22k edges
Serial time taken: 633.550000 seconds.
Parallel time taken: 97.225000 seconds.

![image](https://github.com/pranjalken32/Efficient_ICM/assets/76617914/72fb22ab-753e-47b7-8075-fc9bfbb28843)

<br>

![image](https://github.com/pranjalken32/Efficient_ICM/assets/76617914/e95db961-7058-453e-96e0-b10d0cb2b772)





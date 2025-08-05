import math
from queue import PriorityQueue
G={
    's':{'t': 10 ,'y':5 },
    't':{'x': 10 ,'y':5 },
    'x':{'z': 4 },
    'y':{'t': 3 ,'x':9,'z':2 },
     'z':{'t': 10 ,'y':5 },
}

def DJ(G,source):
    cost = {}  # initialize a dictionary to store cost
    prev={} # initiaixe a dictionary to store previous
    for vertex in G.keys():
        cost[vertex]=math.inf
        prev[vertex]= ""
    cost[source]=0
    visited = list()# to keep track of visited vertices.
    PQ = PriorityQueue()
    for vertex in G.keys():
        PQ.put((cost[vertex],vertex))
    while(len(visited)!=len(G.keys())):
        _, currentvertex = PQ.get()
        visited.append(currentvertex)
        for chimiki in G[currentvertex].keys():
            if chimiki not in visited:
                if cost[chimiki]>cost[currentvertex]+ G[currentvertex][chimiki]:
                    cost[chimiki]= cost[currentvertex]+ G[currentvertex][chimiki]

                    prev[chimiki]=currentvertex
                    PQ.put((cost[chimiki],chimiki))
    return cost,prev

def reconstruct_path(prev,vertex):
    path = vertex
    while prev[vertex]!="":
        path = prev[vertex]+ '->'+path
        vertex = prev[vertex]
    return path

source = 's'
cost, prev = DJ(G,source)
# print(cost)
# print(prev)
for vertex in G.keys():
    print(f"from {source} to {vertex}, path is{reconstruct_path(prev,vertex)}")
    print(f"cost is {cost[vertex]}")


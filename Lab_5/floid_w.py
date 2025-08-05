import math
G=[
    [0,10,math.inf,5,math.inf],
    [math.inf,0,1,2,math.inf],
    [math.inf,math.inf,0,math.inf,math.inf,4],
    [math.inf,3,9,9,2],
    [7,math.inf,6,math.inf,math.inf,0]
]
def  floydwarshall(w):
    n = len(w)
    prev ={}
    D = {}
    D[-1]= w
    for k in range(n):
        D[k]= D[k-1]
        for i in range(n):
            for j in range(n):

                if D[k-1][i][j]>D[k-i][i][j]+ D[k-1][k][j]:
                    D[k][i][j]=D[k-i][i][j]+ D[k-1][k][j]
    return D

ans = floydwarshall(G )
print(ans)


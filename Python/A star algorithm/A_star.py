import math
import random

def init_block(i, j, m, n):
    if (i == 0 and j == 0) or (i == m-1 and j == n-1):
        return 0
    else:
        if random.random() < 0.3:
            return -1

    return 0

def init_score(rows, cols):
    Score = {}
    for i in range(rows):
        for j in range(cols):
            Score[(i,j)] = float("inf")

    return Score

def heuristics(node, end): # Euclidean Distance
    return math.sqrt((node[0] - end[0])**2 + (node[1] - end[1])**2)

def get_lowest_f(Set, fScore):
    lowest = float("inf")
    lowestEle = None
    for ele in Set:
        if fScore[ele] < lowest:
            lowestEle = ele

    return lowestEle

def reconstruct_path(cameFrom, current):
    total_path = [current]
    while current in cameFrom:
        current = cameFrom[current]
        total_path = [current] + total_path

    return total_path

def get_neighbours(node, m, n):
    neighbours = []
    i = node[0]
    j = node[1]
    if i-1 > -1:
        neighbours.append((i-1, j)) 
    if i+1 < m:
        neighbours.append((i+1, j)) 
    if j-1 > -1:
        neighbours.append((i, j-1)) 
    if j+1 < n:
        neighbours.append((i, j+1)) 

    return neighbours

def A_star(grid, start, end, m, n):
    if grid[end[0]][end[1]] == -1 or grid[start[0]][start[1]] == -1: # If end itself is a wall
        return -1

    openSet = [start] # initialise openSet with a list with start node in it
    cameFrom = {} # cameFrom is a map that keeps track of parent node of each vertex while computing the route
    gScore = init_score(m, n)
    gScore[start] = 0 # set gScore of start node to 0
    fScore = init_score(m, n)
    fScore[start] = heuristics(start, end) # set fScore of start node to the estimated(heuristic) value
    reached = False

    while len(openSet) > 0:
        current = get_lowest_f(openSet, fScore) # select the node which is in openSet and has least fScore
        if current == end: # if the selected node is the destination terminate iteration
            reached = True
            break

        openSet.remove(current)
        for neighbour in get_neighbours(current, m, n): # for every neighbour of selected node, calculate tentative gScore
            tempG = gScore[current] + 1 # gScore of current + distance of neighbour from current
            if grid[neighbour[0]][neighbour[1]] != -1 and tempG < gScore[neighbour]: # if the tentative gScore is lower than alloted gScore, update the gScore map
                cameFrom[neighbour] = current # update cameFrom to current 
                gScore[neighbour] = tempG
                fScore[neighbour] = gScore[neighbour] + heuristics(neighbour, end)

                if neighbour not in openSet:
                    openSet.append(neighbour)

    if not reached:
        return -1
    
    return cameFrom

def display(grid):
    for arr in grid:
        for ele in arr:
            print(ele, end = "\t")
        print()

if __name__ == "__main__":
    m = 4
    n = 4
    grid = [[ init_block(i, j, m, n) for j in range(n)] for i in range(m)]
    display(grid)

    start = (0,0)
    end = (m-1, n-1)

    cameFrom = A_star(grid, start, end, m, n)
    node = end
    if cameFrom == -1:
        print("No path available.")
    else:
        while node in cameFrom:
            print(node)
            node = cameFrom[node]
        print(start)

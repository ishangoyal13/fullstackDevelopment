from os import path


class Graph :

    def __init__(self, edges, directed=False): 
        self.directed = directed
        self.neighbors = {}
        self.add_edges(edges)

    def add_edges(self, edges):
        for x, y, in edges:
            self.neighbors.setdefault(x, []).append(y)
            if self.directed:
                self.neighbors.setdefault(y, [])
            else:
                self.neighbors.setdefault(y, []).append(x)

    def get_edges(self):
        edges = []
        for key in self.neighbors.keys():
            for value in self.neighbors[key]:
                edges.append((key, value))
        return edges

    def get_vertices(self): 
        return list(self.neighbors.keys())

    def egde_exists(self, edge:tuple):
        return edge[0] in self.neighbors and edge[1] in self.neighbors[edge[0]]

def get_dependents(graph, vertex):
    visited = {key:False for key in graph.get_vertices()}
    initial_vertex = vertex
    relations = []
    direct_depentens = []
    indirect_depentens = []

    def rec_dfs(graph, vertex):
        visited[vertex] = True

        for neighbor in graph.neighbors[vertex]:

            if not visited[neighbor]:
                if vertex == initial_vertex:
                    direct_depentens.append(neighbor)
                else:
                    indirect_depentens.append(neighbor)
                relations.append((vertex, neighbor))
                rec_dfs(graph, neighbor)

    rec_dfs(graph, vertex)

    return [direct_depentens, indirect_depentens, relations]

def get_dependencies(graph, vertex):
    visited = {key:False for key in graph.get_vertices()}
    target_vertex = vertex
    dependencies = []
    dependencies_paths = []

    def rec_dfs(graph, vertex):
        visited[vertex] = True
        dependencies.append(vertex)

        if vertex == target_vertex:
            dependencies_paths.append(dependencies.copy())
        else:
            for neighbor in graph.neighbors[vertex]:
                if not visited[neighbor]:
                    rec_dfs(graph, neighbor)
        dependencies.pop()
        visited[vertex] = False


    for vertex in graph.get_vertices():
        if not visited[vertex]:
            rec_dfs(graph, vertex)

    result = []

    for paths in dependencies_paths:
        temp = (set(paths) - set(result))
        result = result + list(temp)

    result.remove(target_vertex)
    result.sort()
    return result

class Router:
    def __init__(self, id, neighbors):
        self.id = id
        self.neighbors = neighbors
        self.routing_table = {}

    def initialize_routing_table(self, nodes):
        for node in nodes:
            if node == self.id:
                self.routing_table[node] = (self.id, 0)
            elif node in self.neighbors:
                self.routing_table[node] = (node, self.neighbors[node])
            else:
                self.routing_table[node] = (None, float('inf'))

    def update_routing_table(self, network):
        updated = False
        for neighbor in self.neighbors:
            neighbor_table = network[neighbor].routing_table
            for dest, (via, cost) in neighbor_table.items():
                if dest != self.id:
                    new_cost = self.neighbors[neighbor] + cost
                    if new_cost < self.routing_table[dest][1]:
                        self.routing_table[dest] = (neighbor, new_cost)
                        updated = True
        return updated

    def display_routing_table(self):
        print(f"Router {self.id} Routing Table:")
        for dest, (next_hop, cost) in sorted(self.routing_table.items()):
            if cost == float('inf'):
                print(f"{dest} -> None : infinity")
            else:
                print(f"{dest} -> {next_hop} : {cost}")
        print()


def distance_vector_routing(network):
    nodes = list(network.keys())
    for router in network.values():
        router.initialize_routing_table(nodes)
    while True:
        changes = [router.update_routing_table(network) for router in network.values()]
        if not any(changes):
            break
    for router in network.values():
        router.display_routing_table()

network = {
    'A': Router('A', {'B': 1, 'C': 4}),
    'B': Router('B', {'A': 1, 'C': 2, 'D': 5}),
    'C': Router('C', {'A': 4, 'B': 2, 'D': 1}),
    'D': Router('D', {'B': 5, 'C': 1})
}

distance_vector_routing(network)


from .population import Population
from .cell import Cell

class _PopulationFactory:
    def __init__(self, timepoint:float, node_locations, boundary_nodes, location_indices):
        self.node_locations = node_locations
        self.boundary_nodes = boundary_nodes
        self.location_indices = location_indices
        self.timepoint = timepoint

        self.n_nodes = len(node_locations)
        assert self.n_nodes == len(self.boundary_nodes)
        self.n_real_cells = len(self.location_indices)

        self.cell_ages = None
        self.cell_ancestors = None
        self.cell_areas = None
        self.cell_types = None
        self.cell_proliferative_types = None


    def create_population(self):
        population = Population()
        population.cells = [Cell() for _ in range(self.n_real_cells)]

        for i, location_index in enumerate(self.location_indices):
            population.cells[i].location = self.node_locations[location_index]
            population.cells[i].location_index = location_index
            assert self.boundary_nodes[location_index] == 0

        if self.cell_ages is not None:
            for i, age in enumerate(self.cell_ages):
                population.cells[i].age = age
        
        if self.cell_ancestors is not None:
            for i, ancestor in enumerate(self.cell_ancestors):
                population.cells[i].ancestor = ancestor
        
        if self.cell_areas is not None:
            for i, area in enumerate(self.cell_areas):
                population.cells[i].area = area

        if self.cell_types is not None:
            for i, cell_type in enumerate(self.cell_types):
                population.cells[i].cell_type = cell_type
        
        if self.cell_proliferative_types is not None:
            for i, proliferative_cell_type in enumerate(self.cell_proliferative_types):
                population.cells[i].proliferative_cell_type = proliferative_cell_type
        
        return population

    
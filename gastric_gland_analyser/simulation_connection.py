
from .data_readers import *
from ._population_factory import _PopulationFactory

class SimulationConnection:
    def __init__(self, output_folder):
        self.output_folder = output_folder
        self.node_locations = NodeLocations(output_folder)
        assert self.node_locations is not None
        self.boundary_nodes = BoundaryNodes(output_folder)
        assert self.boundary_nodes is not None

    
    def recreate_timepoint(self, timepoint:float):
        self.factory = _PopulationFactory(
            self.node_locations.data_at_time(timepoint),
            self.boundary_nodes.data_at_time(timepoint),
            timepoint)
        


    def enable_cell_ages(self):
        self.cell_ages = CellAges(self.output_folder)
        assert self.cell_ages is not None

    def enable_cell_ancestors(self):
        self.cell_ancestors = CellAncestors(self.output_folder)
        assert self.cell_ancestors is not None

    def enable_cell_areas(self):
        self.cell_areas = CellAreas(self.output_folder)
        assert self.cell_areas is not None

    def enable_cell_proliferative_types(self):
        self.cell_proliferative_types = CellProliferativeTypes(self.output_folder)
        assert self.cell_proliferative_types is not None

    def enable_cell_types(self):
        self.cell_types = CellTypes(self.output_folder)
        assert self.cell_types is not None


    def timepoints(self):
        return self.node_locations.timepoints()
    



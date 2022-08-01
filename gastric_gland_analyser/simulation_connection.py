
from .data_readers import *
from ._population_factory import _PopulationFactory

class SimulationConnection:
    def __init__(self, output_folder):
        self.output_folder = output_folder
        self.node_locations = NodeLocations(output_folder)
        assert self.node_locations is not None
        self.boundary_nodes = BoundaryNodes(output_folder)
        assert self.boundary_nodes is not None
        self.location_indices = CellLocationIndices(output_folder)
        assert self.location_indices is not None

        self.cell_ages = None
        self.cell_ancestors = None
        self.cell_areas = None
        self.cell_proliferative_types = None
        self.cell_types = None

    
    def recreate_timepoint(self, timepoint:float):
        self.factory = _PopulationFactory(
            timepoint,
            self.node_locations.data_at_time(timepoint),
            self.boundary_nodes.data_at_time(timepoint),
            self.location_indices.data_at_time(timepoint))
        if self.cell_ages is not None:
            self.factory.cell_ages = CellAges(self.output_folder).data_at_time(timepoint)
        if self.cell_ancestors is not None:
            self.factory.cell_ancestors = CellAncestors(self.output_folder).data_at_time(timepoint)
        if self.cell_areas is not None:
            self.factory.cell_areas = CellAreas(self.output_folder).data_at_time(timepoint)
        if self.cell_proliferative_types is not None:
            self.factory.cell_proliferative_types = CellProliferativeTypes(self.output_folder).data_at_time(timepoint)
        if self.cell_types is not None:
            self.factory.cell_types = CellTypes(self.output_folder).data_at_time(timepoint)
        return self.factory.create_population()
        


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
    



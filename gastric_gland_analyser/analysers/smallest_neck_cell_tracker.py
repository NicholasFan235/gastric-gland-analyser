from ._abstract_analyser import AbstractAnalyser
from ..population import Population
from .helpers._find_smallest_cell import _find_smallest_cell

class SmallestNeckCellTracker(AbstractAnalyser):
    def __init__(self):
        super().__init__()

    def analyse_timepoint(self, population: Population, timepoint: float):
        smallest_cell = _find_smallest_cell(population,
            lambda c: c.proliferative_cell_type=='neck')
        assert smallest_cell is not None
        self.result[timepoint] = smallest_cell.area


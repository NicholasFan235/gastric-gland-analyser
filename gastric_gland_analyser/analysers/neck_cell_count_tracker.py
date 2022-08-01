
from ._abstract_analyser import AbstractAnalyser
from .helpers._count_cells import _count_neck_cells
from ..population import Population

class NeckCellCountTracker(AbstractAnalyser):
    def __init__(self):
        super().__init__()

    def analyse_timepoint(self, population:Population, timepoint:float):
        height = _count_neck_cells(population)
        self.result[timepoint] = height


from ._abstract_analyser import AbstractAnalyser
from ..population import Population
from ..cell import Cell


class LabelTracker(AbstractAnalyser):
    def __init__(self):
        super().__init__()

    def analyse_timepoint(self, population: Population, timepoint: float):
        for cell in population.cells:
            pass
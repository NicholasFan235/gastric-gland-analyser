
from ._abstract_analyser import AbstractAnalyser
from ..population import Population
from .helpers._calculate_foveolar_height import _calculate_foveolar_height


class FoveolarHeightTracker(AbstractAnalyser):
    def __init__(self):
        super().__init__()

    def analyse_timepoint(self, population:Population, timepoint:float):
        height = _calculate_foveolar_height(population)
        self.result[timepoint] = height


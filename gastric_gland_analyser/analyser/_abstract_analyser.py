
from ..population import Population

class AbstractAnalyser:
    def __init__(self):
        self.result = {}

    def analyse_timepoint(self, population:Population, timepoint:float):
        raise NotImplementedError

    def results(self):
        return self.result


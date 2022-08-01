
from .analysers._abstract_analyser import AbstractAnalyser
from .simulation_connection import SimulationConnection
import bisect
import numpy as np


class Analyser:
    def __init__(self, simulation_connection:SimulationConnection):
        self.simulation_connection = simulation_connection
        self.analysers = []

    def add_analyser(self, analyser:AbstractAnalyser):
        assert isinstance(analyser, AbstractAnalyser), "Anasyler must be an instance of AbstractAnalyser"
        self.analysers.append(analyser)

    def analyse(self, start:float=0, stop:float=np.inf, stride=1):
        timepoints = list(self.simulation_connection.timepoints())
        timepoints.sort()
        start_index = bisect.bisect_left(timepoints, start)
        stop_index = bisect.bisect_right(timepoints, stop)
        assert stride > 1
        for i in range(start_index, stop_index, stride):
            print(f'\r{i/(stop_index-start_index)*100}%', end=None)
            self.analyse_timepoint(timepoints[i])

    def analyse_timepoint(self, timepoint):
        population = self.simulation_connection.recreate_timepoint(timepoint)
        for analyser in self.analysers:
            analyser.analyse_timepoint(population, timepoint)

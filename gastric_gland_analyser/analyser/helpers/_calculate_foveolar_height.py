from ...population import Population
import numpy as np

def _calculate_foveolar_height(population:Population):
    lowest = np.inf
    highest = -np.inf
    for cell in population.cells:
        assert cell.proliferative_type is not None
        if cell.proliferative_type != 4: continue
        loc = cell.location
        if loc[1] < lowest: lowest = loc[1]
        if loc[1] > highest: highest = loc[1]
    return max(0, highest-lowest)
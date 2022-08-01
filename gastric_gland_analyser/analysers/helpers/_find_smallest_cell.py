from ...population import Population
import numpy as np

def _find_smallest_cell(population:Population, filter=None):
    smallest_area = np.inf
    smallest = None
    for cell in population.cells:
        if filter is not None:
            if not filter(cell):
                continue
        if cell.area < smallest_area:
            smallest = cell
    return cell
    
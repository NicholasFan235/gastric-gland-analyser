from ...population import Population
import numpy as np
import functools

def _count_cells(population:Population, filter=None):
    return len(population.cells) if filter is None\
        else sum(1 if filter(cell) else 0 for cell in population.cells)

def _count_neck_cells(population:Population):
    return _count_cells(population, lambda c: c.proliferative_cell_type=='neck')

def _count_foveolar_cells(population:Population):
    return _count_cells(population, lambda c: c.proliferative_cell_type=='foveolar')


from ._abstract_cell_data_reader import AbstractCellDataReader
from pathlib import Path
import os

class CellAncestors(AbstractCellDataReader):
    def __init__(self, output_folder):
        super().__init__(output_folder)
        self.input_file = os.path.join(output_folder, 'results.vizancestors')
        self.load_data(dtype=int)
    
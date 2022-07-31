from ._abstract_cell_data_reader import AbstractCellDataReader
from pathlib import Path
import os

class NodeLocations(AbstractCellDataReader):
    def __init__(self, output_folder:str):
        super().__init__(output_folder)
        self.input_file = os.path.join(output_folder, 'results.viznodes')
        self.load_data(group_size=2)

    
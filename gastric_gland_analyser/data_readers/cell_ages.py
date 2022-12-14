from ._abstract_cell_data_reader import AbstractCellDataReader
from pathlib import Path
import os

class CellAges(AbstractCellDataReader):
    def __init__(self, output_folder):
        super().__init__(output_folder)
        self.input_file = os.path.join(output_folder, 'cellages.dat')
        self.load_data(group_size=4)
    
    def format_data(self, data):
        assert type(data)==list
        assert len(data)==4, f'{data}'
        return data[-1]

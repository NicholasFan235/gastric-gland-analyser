from ._abstract_cell_data_reader import AbstractCellDataReader
from pathlib import Path
import os

_cell_type_map = {
    0:'stem',
    1:'transit',
    2:'differentiated',
    3:'base',
    4:'foveolar',
    5:'neck',
    6:'isthmus',
}
def _cell_proliferative_type(data):
    key = int(data)
    if key in _cell_type_map:
        return _cell_type_map[key]
    else:
        return key

class CellProliferativeTypes(AbstractCellDataReader):
    def __init__(self, output_folder):
        super().__init__(output_folder)
        self.input_file = os.path.join(output_folder, 'results.vizprolifcelltypes')
        self.load_data(dtype=_cell_proliferative_type)
        
import os


class AbstractCellDataReader:
    def __init__(self, output_folder):
        self.output_folder = output_folder
        assert os.path.exists(output_folder),\
            f'Cannot find output_folder "{output_folder}"'
        self.data = {}
    
    def load_data(self, group_size:int=1, dtype=float):
        assert os.path.exists(self.input_file),\
            f'Cannot find file "{self.input_file}"'
        with open(self.input_file, 'r') as f:
            for line in f.readlines():
                line = line.strip().split('\t')
                assert len(line)==2
                line[0] = float(line[0].strip())
                line[1] = [dtype(i) for i in line[1].strip().split(' ')]
                assert group_size > 0
                if group_size == 1:
                    self.data[line[0]] = [self.format_data(v) for v in line[1]]
                else:
                    assert len(line[1])%group_size == 0
                    self.data[line[0]] = []
                    for i in range(0, len(line[1]), group_size):
                        self.data[line[0]].append(self.format_data(line[1][i:i+group_size]))

    def data_at_time(self, time:float):
        return self.data[time]
    
    def n_cells_at_time(self, time:float):
        return len(self.data[time])
    
    def timepoints(self):
        return self.data.keys()

    def format_data(self,data):
        return data


import os
import csv
from pathlib import Path
import re
from chaste_database_connector import Connection, xml_to_dict
import tqdm
import math


def store_cpp_analysis(experiment_folder:str, db_file='gastric_gland.db'):
    helper = _StoreCppAnalysis(Connection(db_file))
    folder = Path(experiment_folder)
    m = re.match('^sim_(?P<simulation_id>\d+)', folder.name)
    if m is not None:
        helper.retrieve_simulation(experiment_folder, folder.parent.name, m['simulation_id'])
    else:
        helper.retrieve_experiment(experiment_folder)


class _StoreCppAnalysis:
    def __init__(self, connection:Connection):
        self.conn = connection

    def retrieve_experiment(self, experiment_folder:str):
        assert os.path.exists(experiment_folder)
        assert os.path.isdir(experiment_folder)
        experiment_folder = Path(os.path.abspath(experiment_folder))
        sims = os.listdir(experiment_folder)
        for simulation in tqdm.tqdm(sims):
            m = re.match('^sim_(?P<simulation_id>\d+)', simulation)
            if m is None: continue
            self.retrieve_simulation(os.path.join(experiment_folder, simulation),
                experiment_folder.name, int(m['simulation_id']))


    def retrieve_simulation(self, simulation_folder:str, experiment_name:str, simulation_id:int):
        assert os.path.exists(simulation_folder), \
            f'Could not find simulation folder "{simulation_folder}"'
        potential_folders = os.listdir(simulation_folder)
        for folder in potential_folders:
            m = re.match('^analysis_results_from_time_(?P<results_from_time>\d+)', folder)
            if not m: continue
            output_folder = os.path.join(simulation_folder, folder)
            version_id = self.load_version(
                os.path.join(simulation_folder,
                    f'results_from_time_{m["results_from_time"]}', 'build.info'))
            experiment_id = self.conn.get_experiment_id(
                experiment_name, simulation_id,
                version_id=version_id,
                results_from_time=m['results_from_time'])
            
            self.load_analysis(experiment_id,
                os.path.join(simulation_folder, folder))
            
    def load_version(self, info_file:str):
        assert os.path.exists(info_file), f'Cannot find build info file "{info_file}"'
        build_info = xml_to_dict(open(info_file, 'r').read())
        return self.conn.get_version_id(
            build_info['ChasteBuildInfo']['ProvenanceInfo']['VersionString'],
            build_info['ChasteBuildInfo']['ProvenanceInfo']['Projects']['Project']['Name'],
            build_info['ChasteBuildInfo']['ProvenanceInfo']['Projects']['Project']['Version'],
            build_info['ChasteBuildInfo']['ProvenanceInfo']['BuildTime'])


    def load_analysis(self, experiment_id:int, analysis_folder:str):
        self.load_neck_cell_area(experiment_id, analysis_folder)
        self.load_foveolar_cell_area(experiment_id, analysis_folder)
        self.load_neck_height(experiment_id, analysis_folder)
        self.load_foveolar_height(experiment_id, analysis_folder)
        self.load_cell_count(experiment_id, analysis_folder)
        self.load_neck_cell_count(experiment_id, analysis_folder)
        self.load_foveolar_cell_count(experiment_id, analysis_folder)


    def load_neck_cell_area(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'neck_cell_area.csv')
        if os.path.exists(data_folder):
            desired_radius = math.tan(math.pi/6)
            desired_area = 3*math.sqrt(3)/2 * desired_radius * desired_radius
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'neck_compression_ratio', desired_area/float(data['mean']), t)
            self.conn.load_analysis_result(experiment_id,
                'neck_cell_area_iqr_lower', data['iqr_lower'], t)
            self.conn.load_analysis_result(experiment_id,
                'neck_cell_area_median', data['median'], t)
            self.conn.load_analysis_result(experiment_id,
                'neck_cell_area_iqr_upper', data['iqr_upper'], t)
            self.conn.load_analysis_result(experiment_id,
                'neck_cell_area_std', data['std'], t)

    def load_foveolar_cell_area(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'foveolar_cell_area.csv')
        if os.path.exists(data_folder):
            desired_radius = math.tan(math.pi/6) * \
                float(self.conn.get_parameter_value(experiment_id, 'foveolar_size_multiplier'))
            desired_area = 3*math.sqrt(3)/2 * desired_radius * desired_radius
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'foveolar_compression_ratio', desired_area/float(data['mean']), t)
            self.conn.load_analysis_result(experiment_id,
                'foveolar_cell_area_iqr_lower', data['iqr_lower'], t)
            self.conn.load_analysis_result(experiment_id,
                'foveolar_cell_area_median', data['median'], t)
            self.conn.load_analysis_result(experiment_id,
                'foveolar_cell_area_iqr_upper', data['iqr_upper'], t)
            self.conn.load_analysis_result(experiment_id,
                'foveolar_cell_area_std', data['std'], t)
    
    def load_foveolar_height(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'foveolar_height.csv')
        if os.path.exists(data_folder):
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'foveolar_height', data['foveolar_height'], t)

    def load_neck_height(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'neck_height.csv')
        if os.path.exists(data_folder):
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'neck_height', data['neck_height'], t)

    def load_cell_count(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'cell_counts.csv')
        if os.path.exists(data_folder):
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'num_cells', data['n_cells'], t)

    def load_neck_cell_count(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'neck_cell_counts.csv')
        if os.path.exists(data_folder):
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'num_neck_cells', data['n_neck_cells'], t)

    def load_foveolar_cell_count(self, experiment_id:int, analysis_folder:str):
        data_folder = os.path.join(analysis_folder, 'foveolar_cell_counts.csv')
        if os.path.exists(data_folder):
            t, data = self.get_last_reading(data_folder)
            self.conn.load_analysis_result(experiment_id,
                'num_foveolar_cells', data['n_foveolar_cells'], t)


    def get_last_reading(self, folder:str):
        last_row = None
        with open(folder, 'r') as f:
            reader = csv.DictReader(f)
            for row in reader:
                if row: last_row = row
        return last_row['t'], last_row

def main():
    import sys
    assert len(sys.argv) in (2,3), f'Usage: {sys.argv[0]} [EXPERIMENT_FOLDER] optional[DB_FILE]'
    store_cpp_analysis(sys.argv[1], 'gastric_gland.db' if len(sys.argv)==2 else sys.argv[2])

if __name__ == '__main__':
    main()
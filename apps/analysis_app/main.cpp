
#include "analyser.hpp"
#include "simulation_connection.hpp"
#include "trackers/cell_count_tracker.hpp"
#include "trackers/foveolar_height_tracker.hpp"
#include "trackers/neck_cell_count_tracker.hpp"
#include "trackers/foveolar_cell_count_tracker.hpp"
#include "trackers/neck_height_tracker.hpp"
#include "trackers/cell_area_tracker.hpp"
#include "trackers/neck_cell_area_tracker.hpp"
#include "trackers/foveolar_cell_area_tracker.hpp"

#include <exception>
#include <string>
#include <filesystem>
#include <assert.h>

using namespace gga;

void analyse_experiment(std::filesystem::path simulationFolder)
{
    if (!std::filesystem::exists(simulationFolder))
        throw std::runtime_error("Cannot find simulation folder \"" + simulationFolder.string() + "\"");
    if (!std::filesystem::is_directory(simulationFolder))
        throw std::runtime_error("\"" + simulationFolder.string() + "\" is not a directory");

    std::filesystem::path outputFolder = 
        simulationFolder.parent_path() / ("analysis_" + simulationFolder.stem().string());
    std::cout << "Analysing " << simulationFolder << ", writing outputs to " << outputFolder << std::endl;
    std::filesystem::create_directory(outputFolder);

    SimulationConnectionPtr simulationConnection =
        std::make_shared<SimulationConnection>(simulationFolder);
    simulationConnection->useAges();
    simulationConnection->useAncestors();
    simulationConnection->useAreas();
    simulationConnection->useProliferativeCellTypes();
    simulationConnection->useCellTypes();

    AnalyserPtr analyser = std::make_shared<Analyser>(simulationConnection);

    analyser->addTracker(std::make_shared<CellCountTracker>(outputFolder));
    analyser->addTracker(std::make_shared<FoveolarHeightTracker>(outputFolder));
    analyser->addTracker(std::make_shared<NeckCellCountTracker>(outputFolder));
    analyser->addTracker(std::make_shared<FoveolarCellCountTracker>(outputFolder));
    analyser->addTracker(std::make_shared<NeckHeightTracker>(outputFolder));
    analyser->addTracker(std::make_shared<CellAreaTracker>(outputFolder));
    analyser->addTracker(std::make_shared<NeckCellAreaTracker>(outputFolder));
    analyser->addTracker(std::make_shared<FoveolarCellAreaTracker>(outputFolder));

    analyser->analyse();
}


int main(int argc, char* argv[])
{
    try
    {
        for (int i = 1; i < argc; i++)
        {
            std::string simulationFolder(argv[i]);
            if (simulationFolder.back() == '/') simulationFolder.pop_back();
            analyse_experiment(std::filesystem::path(simulationFolder));
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

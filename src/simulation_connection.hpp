#ifndef GASTRIC_GLAND_ANALYSIS_SIMULATION_CONNECTION_HPP
#define GASTRIC_GLAND_ANALYSIS_SIMULATION_CONNECTION_HPP

#include "dataclasses/population.hpp"

#include "data_readers/abstract_data_reader.hpp"
#include "data_readers/node_locations_reader.hpp"
#include "data_readers/boundary_nodes_reader.hpp"
#include "data_readers/cell_location_indices_reader.hpp"
#include "data_readers/cell_ages_reader.hpp"
#include "data_readers/cell_ancestors_reader.hpp"
#include "data_readers/cell_areas_reader.hpp"
#include "data_readers/proliferative_cell_types_reader.hpp"
#include "data_readers/cell_types_reader.hpp"


#include <filesystem>
#include <memory>
#include <optional>


namespace gga
{

    class SimulationConnection
    {
    private:
        std::filesystem::path m_simulationFolder;
        NodeLocationsReaderPtr m_locationsReader;
        BoundaryNodesReaderPtr m_boundaryNodesReader;
        CellLocationIndicesReaderPtr m_locationIndicesReader;

        CellAgesReaderPtr m_agesReader;
        CellAncestorsReaderPtr m_ancestorsReader;
        CellAreasReaderPtr m_areasReader;
        ProliferativeCellTypesReaderPtr m_proliferativeCellTypesReader;
        CellTypesReaderPtr m_cellTypesReader;

    public:
        SimulationConnection(std::filesystem::path simulationFolder);

        void useAges(bool use=true);
        void useAncestors(bool use=true);
        void useAreas(bool use=true);
        void useProliferativeCellTypes(bool use=true);
        void useCellTypes(bool use=true);

        std::optional<std::pair<double, PopulationPtr>> nextTimepoint();

        void skipTimepoint();

        void restart();

    };

    typedef std::shared_ptr<SimulationConnection> SimulationConnectionPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSIS_SIMULATION_CONNECTION_HPP
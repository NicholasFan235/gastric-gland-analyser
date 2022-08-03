
#include "simulation_connection.hpp"

#include "population_factory.hpp"


namespace gga
{

    SimulationConnection::SimulationConnection(std::filesystem::path simulationFolder) :
        m_simulationFolder(simulationFolder),
        m_locationsReader(std::make_shared<NodeLocationsReader>(simulationFolder)),
        m_boundaryNodesReader(std::make_shared<BoundaryNodesReader>(simulationFolder)),
        m_locationIndicesReader(std::make_shared<CellLocationIndicesReader>(simulationFolder))
    {}

    std::optional<std::pair<double, PopulationPtr>> SimulationConnection::nextTimepoint()
    {
        auto nodeLocationsData = m_locationsReader->readline();
        if (!nodeLocationsData.has_value()) return std::optional<std::pair<double, PopulationPtr>>();
        double timepoint = nodeLocationsData.value().first;

        auto boundaryNodesData = m_boundaryNodesReader->readline(timepoint);        
        auto locationIndicesData = m_locationIndicesReader->readline(timepoint);

        PopulationFactory factory(
            nodeLocationsData.value().second,
            boundaryNodesData.value().second,
            locationIndicesData.value().second);
        
        if (m_agesReader) factory.addAges(m_agesReader->readline(timepoint).value().second);
        if (m_ancestorsReader) factory.addAncestors(m_ancestorsReader->readline().value().second);
        if (m_areasReader) factory.addAreas(m_areasReader->readline(timepoint).value().second);
        if (m_proliferativeCellTypesReader)
            factory.addProliferativeTypes(m_proliferativeCellTypesReader->readline().value().second);
        if (m_cellTypesReader) factory.addCellTypes(m_cellTypesReader->readline().value().second);

        return std::make_pair(timepoint, factory.population());
    }

    void SimulationConnection::skipTimepoint()
    {
        m_locationsReader->skip();
        m_boundaryNodesReader->skip();
        m_locationIndicesReader->skip();
        if (m_agesReader) m_agesReader->skip();
        if (m_ancestorsReader) m_ancestorsReader->skip();
        if (m_areasReader) m_areasReader->skip();
        if (m_proliferativeCellTypesReader) m_proliferativeCellTypesReader->skip();
        if (m_cellTypesReader) m_cellTypesReader->skip();
    }

    void SimulationConnection::restart()
    {
        m_locationsReader->reset();
        m_boundaryNodesReader->reset();
        m_locationIndicesReader->reset();
        if (m_agesReader) m_agesReader->reset();
        if (m_ancestorsReader) m_ancestorsReader->reset();
        if (m_areasReader) m_areasReader->reset();
        if (m_proliferativeCellTypesReader) m_proliferativeCellTypesReader->reset();
        if (m_cellTypesReader) m_cellTypesReader->reset();
    }


} // namespace gga

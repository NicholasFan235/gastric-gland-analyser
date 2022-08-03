
#include "population_factory.hpp"

#include <assert.h>

namespace gga
{

    PopulationFactory::PopulationFactory(
        std::vector<std::pair<double, double>> locations,
        std::vector<int>,
        std::vector<int> locationIndices) :
            m_numNodes(locations.size()),
            m_numCells(locationIndices.size()),
            m_population(std::make_shared<Population>(m_numCells))
    {
        for (size_t i = 0; i < m_numCells; i++)
        {
            size_t locationIndex = static_cast<size_t>(locationIndices[i]);
            m_population->cells()[i].location = locations[locationIndex];
        }
    }

    void PopulationFactory::addAges(std::vector<double> ages)
    {
        assert(ages.size() == m_population->cells().size());
        for (size_t i = 0; i < ages.size(); i++)
        {
            m_population->cells()[i].age = ages[i];
        }
    }

    void PopulationFactory::addAncestors(std::vector<int> ancestors)
    {
        assert(ancestors.size() == m_population->cells().size());
        for (size_t i = 0; i < ancestors.size(); i++)
        {
            m_population->cells()[i].ancestor = ancestors[i];
        }
    }

    void PopulationFactory::addAreas(std::vector<double> areas)
    {
        assert(areas.size() == m_population->cells().size());
        for (size_t i = 0; i < areas.size(); i++)
        {
            m_population->cells()[i].area = areas[i];
        }
    }

    void PopulationFactory::addProliferativeTypes(std::vector<ProliferativeCellType> proliferativeTypes)
    {
        assert(proliferativeTypes.size() == m_population->cells().size());
        for (size_t i = 0; i < proliferativeTypes.size(); i++)
        {
            m_population->cells()[i].proliferativeCelltype = proliferativeTypes[i];
        }
    }

    void PopulationFactory::addCellTypes(std::vector<int> cellTypes)
    {
        assert(cellTypes.size() == m_population->cells().size());
        for (size_t i = 0; i < cellTypes.size(); i++)
        {
            m_population->cells()[i].cellType = cellTypes[i];
        }
    }

    PopulationPtr PopulationFactory::population()
    {
        return m_population;
    }


} // namespace gga

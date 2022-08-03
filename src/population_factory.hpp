#ifndef GASTRIC_GLAND_ANALYSIS_POPULATION_FACTORY_HPP
#define GASTRIC_GLAND_ANALYSIS_POPULATION_FACTORY_HPP

#include "dataclasses/population.hpp"

#include <vector>
#include <tuple>


namespace gga
{


    class PopulationFactory
    {
    private:
        size_t m_numNodes;
        size_t m_numCells;
        PopulationPtr m_population;

    public:
        PopulationFactory(
            std::vector<std::pair<double, double>> locations,
            std::vector<int> boundaryNodes,
            std::vector<int> locationIndices);

        void addAges(std::vector<double> cellAges);
        void addAncestors(std::vector<int> cellAncestors);
        void addAreas(std::vector<double> cellAreas);
        void addCellTypes(std::vector<int> cellTypes);
        void addProliferativeTypes(std::vector<ProliferativeCellType> cellProliferativeTypes);

        PopulationPtr population();

    };


} // namespace gga


#endif // GASTRIC_GLAND_ANALYSIS_POPULATION_FACTORY_HPP
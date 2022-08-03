#ifndef GASTRIC_GLAND_ANALYSER_DATACLASSES_POPULATION_HPP
#define GASTRIC_GLAND_ANALYSER_DATACLASSES_POPULATION_HPP

#include "cell.hpp"

#include <vector>
#include <memory>

namespace gga
{

    class Population
    {
        private:
            std::vector<Cell> m_cells;

        public:
            Population();
            Population(size_t nCells);

            std::vector<Cell>& cells();

    };

    typedef std::shared_ptr<Population> PopulationPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATACLASSES_POPULATION_HPP
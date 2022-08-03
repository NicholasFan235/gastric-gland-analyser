
#include "population.hpp"


namespace gga
{
    Population::Population() :
        m_cells()
    {}

    Population::Population(size_t nCells) :
        m_cells(nCells)
    {}

    
    std::vector<Cell>& Population::cells()
    {
        return m_cells;
    }

} // namespace gga

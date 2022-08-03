
#include "smallest_cell_area_tracker.hpp"

#include <limits.h>

namespace gga
{


    SmallestCellAreaTracker::SmallestCellAreaTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "smallest_cell_area.csv")
    {
        writeHeader();
    }

    void SmallestCellAreaTracker::writeHeader()
    {
        m_ofs << "t,smallest_cell_area" << std::endl;
    }

    void SmallestCellAreaTracker::analyseTimepoint(Population& population, double timepoint)
    {
        double smallest_area = std::numeric_limits<double>::max();
        for (const Cell& cell : population.cells())
        {
            smallest_area = std::min(smallest_area, cell.area);
        }
        m_ofs << timepoint << "," << smallest_area << std::endl;
    }

} // namespace gga

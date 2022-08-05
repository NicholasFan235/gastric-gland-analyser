
#include "cell_area_tracker.hpp"

#include <limits.h>
#include <algorithm>
#include <numeric>
#include <math.h>

namespace gga
{


    CellAreaTracker::CellAreaTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "cell_area.csv")
    {
        writeHeader();
    }

    void CellAreaTracker::writeHeader()
    {
        m_ofs << "t," << distributionHeader() << std::endl;
    }

    void CellAreaTracker::analyseTimepoint(Population& population, double timepoint)
    {
        std::vector<double> areas = std::vector<double>(population.cells().size());
        for (size_t i = 0; i < areas.size(); i++) areas[i] = population.cells()[i].area;
        
        m_ofs << timepoint << "," << analyseDistribution(areas) << std::endl;
    }

} // namespace gga


#include "neck_height_tracker.hpp"

#include <limits>

namespace gga
{

    NeckHeightTracker::NeckHeightTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "neck_height.csv")
    {
        writeHeader();
    }

    void NeckHeightTracker::writeHeader()
    {
        m_ofs << "t,neck_height" << std::endl;
    }

    void NeckHeightTracker::analyseTimepoint(Population& population, double timepoint)
    {
        double lowest = std::numeric_limits<double>::max()/2.0;
        double highest = std::numeric_limits<double>::min()/2.0;
        for (const Cell& cell : population.cells())
        {
            if (cell.proliferativeCelltype != ProliferativeCellType::Neck) continue;
            lowest = std::min(lowest, cell.location.second);
            highest = std::max(highest, cell.location.second);
        }
        m_ofs << timepoint << "," << std::max(0.0, highest-lowest) << std::endl;
    }


} // namespace gga

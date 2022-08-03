
#include "smallest_neck_cell_area_tracker.hpp"


namespace gga
{


    SmallestNeckCellAreaTracker::SmallestNeckCellAreaTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "smallest_neck_cell_area.csv")
    {
        writeHeader();
    }

    void SmallestNeckCellAreaTracker::writeHeader()
    {
        m_ofs << "t,smallest_neck_cell_area" << std::endl;
    }

    void SmallestNeckCellAreaTracker::analyseTimepoint(Population& population, double timepoint)
    {
        double smallest_area = std::numeric_limits<double>::max();
        for (const Cell& cell : population.cells())
        {
            if (cell.proliferativeCelltype != ProliferativeCellType::Neck) continue;
            smallest_area = std::min(smallest_area, cell.area);
        }
        m_ofs << timepoint << "," << smallest_area << std::endl;
    }

} // namespace gga

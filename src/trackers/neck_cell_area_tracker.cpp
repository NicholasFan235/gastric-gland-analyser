
#include "neck_cell_area_tracker.hpp"


namespace gga
{


    NeckCellAreaTracker::NeckCellAreaTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "neck_cell_area.csv")
    {
        writeHeader();
    }

    void NeckCellAreaTracker::writeHeader()
    {
        m_ofs << "t," << distributionHeader() << std::endl;
    }

    void NeckCellAreaTracker::analyseTimepoint(Population& population, double timepoint)
    {
        std::vector<double> areas;
        for (const auto& cell : population.cells())
            if (cell.proliferativeCelltype == ProliferativeCellType::Neck)
                areas.push_back(cell.area);

        m_ofs << timepoint << "," << analyseDistribution(areas) << std::endl;
    }

} // namespace gga

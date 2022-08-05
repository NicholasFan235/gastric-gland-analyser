
#include "foveolar_cell_area_tracker.hpp"


namespace gga
{


    FoveolarCellAreaTracker::FoveolarCellAreaTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "foveolar_cell_area.csv")
    {
        writeHeader();
    }

    void FoveolarCellAreaTracker::writeHeader()
    {
        m_ofs << "t," << distributionHeader() << std::endl;
    }

    void FoveolarCellAreaTracker::analyseTimepoint(Population& population, double timepoint)
    {
        std::vector<double> areas;
        for (const auto& cell : population.cells())
            if (cell.proliferativeCelltype == ProliferativeCellType::Foveolar)
                areas.push_back(cell.area);

        m_ofs << timepoint << "," << analyseDistribution(areas) << std::endl;
    }

} // namespace gga

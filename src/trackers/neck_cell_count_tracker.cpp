
#include "neck_cell_count_tracker.hpp"

#include <algorithm>

namespace gga
{

    NeckCellCountTracker::NeckCellCountTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "neck_cell_counts.csv")
    {
        writeHeader();
    }

    void NeckCellCountTracker::writeHeader()
    {
        m_ofs << "t,n_neck_cells" << std::endl;
    }


    void NeckCellCountTracker::analyseTimepoint(Population& population, double timepoint)
    {
        unsigned n_cells = std::count_if(population.cells().cbegin(), population.cells().cend(),
            [](const Cell& cell)
            { return cell.proliferativeCelltype == ProliferativeCellType::Neck; });
        m_ofs << timepoint << "," << n_cells << std::endl;
    }


} // namespace gga

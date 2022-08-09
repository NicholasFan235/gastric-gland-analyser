
#include "foveolar_cell_count_tracker.hpp"

#include <algorithm>

namespace gga
{

    FoveolarCellCountTracker::FoveolarCellCountTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "foveolar_cell_counts.csv")
    {
        writeHeader();
    }

    void FoveolarCellCountTracker::writeHeader()
    {
        m_ofs << "t,n_foveolar_cells" << std::endl;
    }


    void FoveolarCellCountTracker::analyseTimepoint(Population& population, double timepoint)
    {
        unsigned n_cells = std::count_if(population.cells().cbegin(), population.cells().cend(),
            [](const Cell& cell)
            { return cell.proliferativeCelltype == ProliferativeCellType::Foveolar; });
        m_ofs << timepoint << "," << n_cells << std::endl;
    }


} // namespace gga

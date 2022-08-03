
#include "cell_count_tracker.hpp"

namespace gga
{

    CellCountTracker::CellCountTracker(std::filesystem::path outputFolder) :
        AbstractTracker(outputFolder / "cell_counts.csv")
    {
        writeHeader();
    }

    void CellCountTracker::writeHeader()
    {
        m_ofs << "t,n_cells" << std::endl;
    }


    void CellCountTracker::analyseTimepoint(Population& population, double timepoint)
    {
        size_t n_cells = population.cells().size();
        m_ofs << timepoint << "," << n_cells << std::endl;
    }


} // namespace gga

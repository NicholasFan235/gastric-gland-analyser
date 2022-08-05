#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_FOVEOLAR_CELL_COUNT_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_FOVEOLAR_CELL_COUNT_TRACKER_HPP

#include "abstract_tracker.hpp"

#include <filesystem>


namespace gga
{


    class FoveolarCellCountTracker : public AbstractTracker
    {
    public:
        FoveolarCellCountTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    }; // class CellCountTracker

    typedef std::shared_ptr<FoveolarCellCountTracker> FoveolarCellCountTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_FOVEOLAR_CELL_COUNT_TRACKER_HPP
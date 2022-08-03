#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_CELL_COUNT_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_CELL_COUNT_TRACKER_HPP

#include "abstract_tracker.hpp"

#include <filesystem>


namespace gga
{


    class CellCountTracker : public AbstractTracker
    {
    public:
        CellCountTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    }; // class CellCountTracker

    typedef std::shared_ptr<CellCountTracker> CellCountTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_CELL_COUNT_TRACKER_HPP
#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_NECK_CELL_COUNT_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_NECK_CELL_COUNT_TRACKER_HPP

#include "abstract_tracker.hpp"

#include <filesystem>


namespace gga
{


    class NeckCellCountTracker : public AbstractTracker
    {
    public:
        NeckCellCountTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    }; // class CellCountTracker

    typedef std::shared_ptr<NeckCellCountTracker> NeckCellCountTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_NECK_CELL_COUNT_TRACKER_HPP
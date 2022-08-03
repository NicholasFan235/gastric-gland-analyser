#ifndef GASTRIC_GLAND_ANALYSIS_TRACKERS_SMALLEST_NECK_CELL_AREA_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSIS_TRACKERS_SMALLEST_NECK_CELL_AREA_TRACKER_HPP

#include "abstract_tracker.hpp"


namespace gga
{


    class SmallestNeckCellAreaTracker : public AbstractTracker
    {
    public:
        SmallestNeckCellAreaTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    };

    typedef std::shared_ptr<SmallestNeckCellAreaTracker> SmallestNeckCellAreaTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSIS_TRACKERS_SMALLEST_NECK_CELL_TRACKER_HPP
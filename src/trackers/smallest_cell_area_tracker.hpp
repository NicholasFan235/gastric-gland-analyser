#ifndef GASTRIC_GLAND_ANALYSIS_TRACKERS_SMALLEST_CELL_AREA_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSIS_TRACKERS_SMALLEST_CELL_AREA_TRACKER_HPP

#include "abstract_tracker.hpp"


namespace gga
{


    class SmallestCellAreaTracker : public AbstractTracker
    {
    public:
        SmallestCellAreaTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    };

    typedef std::shared_ptr<SmallestCellAreaTracker> SmallestCellAreaTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSIS_TRACKERS_SMALLEST_CELL_TRACKER_HPP
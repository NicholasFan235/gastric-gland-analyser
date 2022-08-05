#ifndef GASTRIC_GLAND_ANALYSIS_TRACKERS_NECK_CELL_AREA_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSIS_TRACKERS_NECK_CELL_AREA_TRACKER_HPP

#include "abstract_tracker.hpp"
#include "distribution_helper.hpp"


namespace gga
{


    class NeckCellAreaTracker : public AbstractTracker, DistributionHelper<double>
    {
    public:
        NeckCellAreaTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    };

    typedef std::shared_ptr<NeckCellAreaTracker> NeckCellAreaTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSIS_TRACKERS_NECK_CELL_TRACKER_HPP
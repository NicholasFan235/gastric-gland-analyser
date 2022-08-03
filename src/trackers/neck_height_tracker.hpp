#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_NECK_HEIGHT_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_NECK_HEIGHT_TRACKER_HPP

#include "abstract_tracker.hpp"


namespace gga
{


    class NeckHeightTracker : public AbstractTracker
    {
    public:
        NeckHeightTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    };

    typedef std::shared_ptr<NeckHeightTracker> NeckHeightTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_NECK_HEIGHT_TRACKER_HPP
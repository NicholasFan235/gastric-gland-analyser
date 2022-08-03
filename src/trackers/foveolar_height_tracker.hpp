#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_FOVEOLAR_HEIGHT_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_FOVEOLAR_HEIGHT_TRACKER_HPP

#include "abstract_tracker.hpp"


namespace gga
{


    class FoveolarHeightTracker : public AbstractTracker
    {
    public:
        FoveolarHeightTracker(std::filesystem::path outputFolder);

        void analyseTimepoint(Population& population, double timepoint) override;

    private:
        void writeHeader() override;

    };

    typedef std::shared_ptr<FoveolarHeightTracker> FoveolarHeightTrackerPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_FOVEOLAR_HEIGHT_TRACKER_HPP
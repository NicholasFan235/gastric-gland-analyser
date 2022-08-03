#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_ABSTRACT_TRACKER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_ABSTRACT_TRACKER_HPP


#include "../dataclasses/population.hpp"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <memory>

namespace gga
{


    class AbstractTracker
    {
    private:
        std::filesystem::path m_outputFile;
    
    protected:
        std::ofstream m_ofs;

    public:
        AbstractTracker(std::filesystem::path outputFile);
        virtual ~AbstractTracker();

        virtual void analyseTimepoint(Population& population, double timepoint)=0;

    protected:
        virtual void writeHeader()=0;

    };

    typedef std::shared_ptr<AbstractTracker> AbstractTrackerPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_ABSTRACT_TRACKER_HPP
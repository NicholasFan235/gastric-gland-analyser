#ifndef GASTRIC_GLAND_ANALYSER_ANALYSER_HPP
#define GASTRIC_GLAND_ANALYSER_ANALYSER_HPP

#include "simulation_connection.hpp"
#include "trackers/abstract_tracker.hpp"

#include <vector>
#include <limits>
#include <memory>

namespace gga
{


    class Analyser
    {
    private:
        SimulationConnectionPtr m_simulationConnection;
        std::vector<AbstractTrackerPtr> m_trackers;

    public:
        Analyser(SimulationConnectionPtr simulationConnection);

        void addTracker(AbstractTrackerPtr tracker);

        void analyse(
            size_t start=0,
            size_t stop=std::numeric_limits<size_t>::max(),
            size_t stride=1);

        bool analyseTimepoint();

    };

    typedef std::shared_ptr<Analyser> AnalyserPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_ANALYSER_HPP
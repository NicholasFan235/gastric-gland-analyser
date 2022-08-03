
#include "analyser.hpp"

#include <limits.h>

namespace gga
{


    Analyser::Analyser(SimulationConnectionPtr simulationConnection) :
        m_simulationConnection(simulationConnection),
        m_trackers()
    {}

    void Analyser::addTracker(AbstractTrackerPtr tracker)
    {
        m_trackers.push_back(tracker);
    }

    void Analyser::analyse(size_t start, size_t stop, size_t stride)
    {
        m_simulationConnection->restart();
        size_t i = 0;
        for (i = 0; i < start; i++) m_simulationConnection->skipTimepoint();
        while (i++ < stop)
        {
            if (!analyseTimepoint()) break;
            for (size_t j = 1; j < stride; j++)
            {
                m_simulationConnection->skipTimepoint();
                i++;
            }
        }
    }

    bool Analyser::analyseTimepoint()
    {
        auto state = m_simulationConnection->nextTimepoint();
        if (!state.has_value()) return false;
        double time = state.value().first;
        PopulationPtr population = state.value().second;
        for (auto tracker : m_trackers)
        {
            tracker->analyseTimepoint(*population, time);
        }
        return true;
    }


} // namespace gga

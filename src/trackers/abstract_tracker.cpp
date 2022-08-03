
#include "abstract_tracker.hpp"

namespace gga
{


    AbstractTracker::AbstractTracker(std::filesystem::path outputFile) :
        m_outputFile(outputFile),
        m_ofs(outputFile, std::ofstream::out | std::ofstream::trunc)
    {}

    AbstractTracker::~AbstractTracker()=default;


} // namespace gga

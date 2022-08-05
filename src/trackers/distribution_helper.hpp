#ifndef GASTRIC_GLAND_ANALYSER_TRACKERS_DISTRIBUTION_HELPER_HPP
#define GASTRIC_GLAND_ANALYSER_TRACKERS_DISTRIBUTION_HELPER_HPP

#include <string>
#include <vector>


namespace gga
{

    template <typename T>
    class DistributionHelper
    {
    public:
        DistributionHelper();
        ~DistributionHelper();

        std::string distributionHeader();

    protected:
        std::string analyseDistribution(std::vector<T>& data);

    }; // class DistributionHelper


} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_TRACKERS_DISTRIBUTION_HELPER_HPP

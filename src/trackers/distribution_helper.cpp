
#include "distribution_helper.hpp"

#include <numeric>
#include <math.h>
#include <sstream>
#include <algorithm>


namespace gga
{

    template <typename T>
    DistributionHelper<T>::DistributionHelper()
    {}

    template <typename T>
    DistributionHelper<T>::~DistributionHelper()=default;

    template <typename T>
    std::string DistributionHelper<T>::analyseDistribution(std::vector<T>& data)
    {
        if (data.empty()) return ",,,,,,";
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        double mean = sum/static_cast<double>(data.size());
        std::vector<double> diffs = std::vector<double>(data.size());
        std::transform(data.begin(), data.end(), diffs.begin(), [mean](T x)
            { return x-mean; });
        double sq_sum = std::inner_product(diffs.begin(), diffs.end(), diffs.begin(), 0.0);
        double stdev = std::sqrt(sq_sum);

        std::sort(data.begin(), data.end());
        T median = data[data.size()/2];
        T iqr_lower = data[data.size()/4];
        T iqr_upper = data[data.size()*3/4];

        std::stringstream ss;
        ss << mean << "," << stdev << ","
            << data[0] << "," << iqr_lower << "," << median << "," << iqr_upper << "," << *data.end();
        return ss.str();
    }

    template <typename T>
    std::string DistributionHelper<T>::distributionHeader()
    {
        return "mean,std,min,iqr_lower,median,iqr_upper,max";
    }

    template class DistributionHelper<int>;
    template class DistributionHelper<double>;

} // namespace gga

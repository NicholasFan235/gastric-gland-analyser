
#include "node_locations_reader.hpp"


namespace gga
{


    NodeLocationsReader::NodeLocationsReader(std::filesystem::path outputFolder) :
        AbstractDataReader<std::pair<double, double>>(outputFolder / "results.viznodes")
    {}

    NodeLocationsReader::~NodeLocationsReader()=default;

    std::vector<std::pair<double, double>> NodeLocationsReader::interpretTimepoint(std::stringstream& ss)
    {
        std::vector<std::pair<double, double>> r = std::vector<std::pair<double, double>>();
        double x, y;
        while (ss)
        {
            ss >> x >> y;
            r.push_back(std::make_pair(x, y));
        }
        return r;
    }


} // namespace gga

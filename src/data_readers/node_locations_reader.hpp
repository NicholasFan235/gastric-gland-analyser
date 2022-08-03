#ifndef GASTRIC_GLAND_ANALYSER_DATA_REDAERS_NODE_LOCATIONS_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_REDAERS_NODE_LOCATIONS_READER_HPP

#include "abstract_data_reader.hpp"

#include <tuple>

namespace gga
{


    class NodeLocationsReader : public AbstractDataReader<std::pair<double, double>>
    {
    public:
        NodeLocationsReader(std::filesystem::path outputFolder);
        virtual ~NodeLocationsReader();

    protected:
        std::vector<std::pair<double, double>> interpretTimepoint(std::stringstream& ss) override;

    };

    typedef std::shared_ptr<NodeLocationsReader> NodeLocationsReaderPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATA_REDAERS_NODE_LOCATIONS_READER_HPP
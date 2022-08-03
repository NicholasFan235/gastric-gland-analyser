#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_BOUNDARY_NODES_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_BOUNDARY_NODES_READER_HPP

#include "abstract_data_reader.hpp"


namespace gga
{


    class BoundaryNodesReader : public AbstractDataReader<int>
    {
    public:
        BoundaryNodesReader(std::filesystem::path outputFolder);
        virtual ~BoundaryNodesReader();
        
    };

    typedef std::shared_ptr<BoundaryNodesReader> BoundaryNodesReaderPtr;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_BOUNDARY_NODES_READER_HPP

#include "boundary_nodes_reader.hpp"


namespace gga
{

    BoundaryNodesReader::BoundaryNodesReader(std::filesystem::path outputFolder) :
        AbstractDataReader<int>(outputFolder / "results.vizboundarynodes")
    {}

    BoundaryNodesReader::~BoundaryNodesReader()=default;

} // namespace gga
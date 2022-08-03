
#include "cell_location_indices_reader.hpp"


namespace gga
{

    CellLocationIndicesReader::CellLocationIndicesReader(std::filesystem::path outputFolder) :
        AbstractDataReader<int>(outputFolder / "results.vizlocationindices")
    {}

    CellLocationIndicesReader::~CellLocationIndicesReader()=default;

} // namespace gga

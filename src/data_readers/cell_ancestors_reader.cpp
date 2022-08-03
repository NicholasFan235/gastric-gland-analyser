
#include "cell_ancestors_reader.hpp"


namespace gga
{


    CellAncestorsReader::CellAncestorsReader(std::filesystem::path outputFile) :
        AbstractDataReader<int>(outputFile / "results.vizancestors")
    {}

    CellAncestorsReader::~CellAncestorsReader()=default;


} // namespace gga

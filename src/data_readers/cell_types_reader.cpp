
#include "cell_types_reader.hpp"


namespace gga
{


    CellTypesReader::CellTypesReader(std::filesystem::path outputFolder) :
        AbstractDataReader<int>(outputFolder / "results.vizcelltypes")
    {}

    CellTypesReader::~CellTypesReader()=default;

} // namespace gga


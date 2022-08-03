
#include "proliferative_cell_types_reader.hpp"


namespace gga
{


    ProliferativeCellTypesReader::ProliferativeCellTypesReader(std::filesystem::path outputFolder):
        AbstractDataReader<ProliferativeCellType>(outputFolder / "results.vizprolifcelltypes")
    {}

    ProliferativeCellTypesReader::~ProliferativeCellTypesReader()=default;

} // namespace gga


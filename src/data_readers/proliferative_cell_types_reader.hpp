#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_PROLIFERATIVE_CELL_TYPES_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_PROLIFERATIVE_CELL_TYPES_READER_HPP

#include "abstract_data_reader.hpp"
#include "../dataclasses/proliferative_cell_types.hpp"

namespace gga
{


    class ProliferativeCellTypesReader : public AbstractDataReader<ProliferativeCellType>
    {
    public:
        ProliferativeCellTypesReader(std::filesystem::path outputFolder);
        virtual ~ProliferativeCellTypesReader();

    };

    typedef std::shared_ptr<ProliferativeCellTypesReader> ProliferativeCellTypesReaderPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_PROLIFERATIVE_CELL_TYPES_READER_HPP
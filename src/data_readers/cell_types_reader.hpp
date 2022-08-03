#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_TYPES_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_TYPES_READER_HPP

#include "abstract_data_reader.hpp"


namespace gga
{


    class CellTypesReader : public AbstractDataReader<int>
    {
    public:
        CellTypesReader(std::filesystem::path outputFolder);
        virtual ~CellTypesReader();

    };

    typedef std::shared_ptr<CellTypesReader> CellTypesReaderPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_TYPES_READER_HPP
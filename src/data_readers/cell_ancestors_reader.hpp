#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_ANCESTORS_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_ANCESTORS_READER_HPP


#include "abstract_data_reader.hpp"


namespace gga
{


    class CellAncestorsReader : public AbstractDataReader<int>
    {
    public:
        CellAncestorsReader(std::filesystem::path outputFolder);
        virtual ~CellAncestorsReader();
        
    };

    typedef std::shared_ptr<CellAncestorsReader> CellAncestorsReaderPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_ANCESTORS_READER_HPP
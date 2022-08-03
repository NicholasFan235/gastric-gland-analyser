#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_LOCATION_INDICES_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_LOCATION_INDICES_READER_HPP

#include "abstract_data_reader.hpp"


namespace gga
{


    class CellLocationIndicesReader : public AbstractDataReader<int>
    {
    public:
        CellLocationIndicesReader(std::filesystem::path outputFolder);
        virtual ~CellLocationIndicesReader();

    };

    typedef std::shared_ptr<CellLocationIndicesReader> CellLocationIndicesReaderPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_LOCATION_INDICES_READER_HPP
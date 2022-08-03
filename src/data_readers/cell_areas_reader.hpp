#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_AREAS_READER_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_AREAS_READER_HPP

#include "abstract_data_reader.hpp"


namespace gga
{


    class CellAreasReader : public AbstractDataReader<double>
    {
    public:
        CellAreasReader(std::filesystem::path outputFolder);
        virtual ~CellAreasReader();

    protected:
        std::vector<double> interpretTimepoint(std::stringstream& ss) override;

    };

    typedef std::shared_ptr<CellAreasReader> CellAreasReaderPtr;

} // namespace gga


#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_AREAS_READER_HPP
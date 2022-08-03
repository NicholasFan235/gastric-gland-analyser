#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_AGES_HPP
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_AGES_HPP

#include "abstract_data_reader.hpp"


namespace gga
{


    class CellAgesReader : public AbstractDataReader<double>
    {
    public:
        CellAgesReader(std::filesystem::path outputFolder);
        virtual ~CellAgesReader();

    protected:
        std::vector<double> interpretTimepoint(std::stringstream& ss) override;

    };

    typedef std::shared_ptr<CellAgesReader> CellAgesReaderPtr;


} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_CELL_AGES_HPP
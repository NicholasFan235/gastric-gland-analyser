
#include "cell_ages_reader.hpp"


namespace gga
{
    

    CellAgesReader::CellAgesReader(std::filesystem::path outputFolder) :
        AbstractDataReader<double>(outputFolder / "cellages.dat")
    {}

    CellAgesReader::~CellAgesReader()=default;

    
    std::vector<double> CellAgesReader::interpretTimepoint(std::stringstream& ss)
    {
        std::vector<double> r = std::vector<double>();
        int cell_index;
        double x, y, age;
        while (ss)
        {
            ss >> cell_index >> x >> y >> age;
            r.push_back(age);
        }
        return r;
    }

}

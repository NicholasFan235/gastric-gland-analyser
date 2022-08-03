
#include "cell_areas_reader.hpp"


namespace gga
{


    CellAreasReader::CellAreasReader(std::filesystem::path outputFolder) :
        AbstractDataReader<double>(outputFolder / "cellareas.dat")
    {}

    CellAreasReader::~CellAreasReader()=default;

    std::vector<double> CellAreasReader::interpretTimepoint(std::stringstream& ss)
    {
        std::vector<double> r = std::vector<double>();
        int locationIndex, cellId;
        double x, y, area;
        while (ss)
        {
            ss >> locationIndex >> cellId >> x >> y >> area;
            r.push_back(area);
        }
        return r;
    }


} // namespace gga

#ifndef GASTRIC_GLAND_ANALYSER_DATACLASSES_CELL_HPP
#define GASTRIC_GLAND_ANALYSER_DATACLASSES_CELL_HPP

#include "proliferative_cell_types.hpp"

#include <tuple>

namespace gga
{

    struct Cell
    {
        std::pair<double, double> location = {-1,-1};
        double age = -1;
        int ancestor = -1;
        double area = -1;

        
        ProliferativeCellType proliferativeCelltype = ProliferativeCellType::None;
        int cellType = -1;
    };

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_DATACLASSES_CELL_HPP
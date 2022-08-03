#ifndef GASTRIC_GLAND_ANALYSER_DATACLASSES_PROLIFERATIVE_CELL_TYPES
#define GASTRIC_GLAND_ANALYSER_DATACLASSES_PROLIFERATIVE_CELL_TYPES

namespace gga
{

enum class ProliferativeCellType
{
    Stem=0,
    Transit=1,
    Differentiated=2,
    Base=3,
    Foveolar=4,
    Neck=5,
    Isthmus=6,
    None=-1
};

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_DATACLASSES_PROLIFERATIVE_CELL_TYPES
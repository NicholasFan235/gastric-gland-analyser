
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(
    gga_src
    dataclasses/population.cpp
    trackers/abstract_tracker.cpp
    trackers/cell_count_tracker.cpp
    trackers/foveolar_height_tracker.cpp
    trackers/neck_cell_count_tracker.cpp
    trackers/neck_height_tracker.cpp
    trackers/smallest_cell_area_tracker.cpp
    trackers/smallest_neck_cell_area_tracker.cpp
    analyser.cpp
    simulation_connection.cpp
    population_factory.cpp
    data_readers/abstract_data_reader.cpp
    data_readers/boundary_nodes_reader.cpp
    data_readers/cell_ages_reader.cpp
    data_readers/cell_ancestors_reader.cpp
    data_readers/cell_areas_reader.cpp
    data_readers/cell_location_indices_reader.cpp
    data_readers/proliferative_cell_types_reader.cpp
    data_readers/cell_types_reader.cpp
    data_readers/node_locations_reader.cpp
)

set(
    gga_hdr
    dataclasses/population.hpp
    dataclasses/cell.hpp
    dataclasses/proliferative_cell_types.hpp
    analyser.hpp
    simulation_connection.hpp
    population_factory.hpp
    trackers/abstract_tracker.hpp
    trackers/cell_count_tracker.hpp
    trackers/foveolar_height_tracker.hpp
    trackers/neck_cell_count_tracker.hpp
    trackers/neck_height_tracker.hpp
    trackers/smallest_cell_area_tracker.hpp
    trackers/smallest_neck_cell_area_tracker.hpp
    data_readers/abstract_data_reader.hpp
    data_readers/boundary_nodes_reader.hpp
    data_readers/cell_ages_reader.hpp
    data_readers/cell_ancestors_reader.hpp
    data_readers/cell_areas_reader.hpp
    data_readers/cell_location_indices_reader.hpp
    data_readers/proliferative_cell_types_reader.hpp
    data_readers/cell_types_reader.hpp
    data_readers/node_locations_reader.hpp
)

add_library(gga_lib STATIC ${gga_src} ${gga_hdr})

target_include_directories(
        gga_lib INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(gga_lib PRIVATE project_warnings project_settings)
target_link_libraries(gga_lib PRIVATE Threads::Threads)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.4)
        target_link_libraries(gga_lib PRIVATE stdc++fs)
    endif ()
endif ()

if (PYTHON_BINDINGS)
    set_target_properties(gga_lib PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
    pybind11_add_module(gga python_bindings/bindings.cpp)
    target_link_libraries(gastric_gland_analyser PRIVATE gga_lib)
endif()

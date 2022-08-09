#include "abstract_data_reader.hpp"

#include "../dataclasses/proliferative_cell_types.hpp"

#include <sstream>
#include <fstream>
#include <iostream>

namespace gga
{

    template <typename T>
    AbstractDataReader<T>::AbstractDataReader(std::filesystem::path inputFile) :
        m_inputFile(inputFile),
        m_ifs(inputFile, std::ifstream::in)
    {}

    template <typename T>
    AbstractDataReader<T>::~AbstractDataReader()=default;

    template <typename T>
    std::optional<std::pair<double, std::vector<T>>> AbstractDataReader<T>::readline(std::optional<double> expected_timepoint)
    {
        std::string line;
        std::getline(m_ifs, line, '\n');
        if (line.empty()) return std::optional<std::pair<double, std::vector<T>>>();

        std::stringstream ss(line);
        double timepoint;
        ss >> timepoint;
        if (expected_timepoint.value_or(timepoint) != timepoint)
            std::throw_with_nested(std::runtime_error("Error reading data at timepoint " + std::to_string(timepoint)
            + "\n    Expected " + std::to_string(expected_timepoint.value()) 
            + " got " + std::to_string(timepoint)));
        return std::make_pair(timepoint, interpretTimepoint(ss));
    }

    template <typename T>
    std::vector<T> AbstractDataReader<T>::interpretTimepoint(std::stringstream& ss)
    {
        std::vector<T> r = std::vector<T>();
        T val;
        while (ss)
        {
            ss >> val;
            r.push_back(val);
        }
        return r;
    }

    template<>
    std::vector<std::pair<double, double>> AbstractDataReader<std::pair<double, double>>::interpretTimepoint(std::stringstream& ss)
    {
        std::vector<std::pair<double, double>> r = std::vector<std::pair<double, double>>();
        double u, v;
        while (ss)
        {
            ss >> u >> v;
            r.push_back(std::make_pair(u,v));
        }
        return r;
    }

    template<>
    std::vector<ProliferativeCellType> AbstractDataReader<ProliferativeCellType>::interpretTimepoint(std::stringstream& ss)
    {
        std::vector<ProliferativeCellType> r = std::vector<ProliferativeCellType>();
        int c;
        while (ss)
        {
            ss >> c;
            r.push_back(static_cast<ProliferativeCellType>(c));
        }
        return r;
    }

    template <typename T>
    void AbstractDataReader<T>::skip()
    {
        std::string line;
        std::getline(m_ifs, line, '\n');
    }

    template <typename T>
    void AbstractDataReader<T>::reset()
    {
        m_ifs.clear();
        m_ifs.seekg(0, m_ifs.beg);
    }

    template class AbstractDataReader<int>;
    template class AbstractDataReader<double>;
    template class AbstractDataReader<std::pair<double, double>>;
    template class AbstractDataReader<ProliferativeCellType>;

} // namespace gga


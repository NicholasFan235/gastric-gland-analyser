#ifndef GASTRIC_GLAND_ANALYSER_DATA_READERS_ABSTRACT_DATA_READER
#define GASTRIC_GLAND_ANALYSER_DATA_READERS_ABSTRACT_DATA_READER


#include <filesystem>
#include <vector>
#include <tuple>
#include <sstream>
#include <fstream>
#include <memory>
#include <optional>

namespace gga
{

    template <typename T>
    class AbstractDataReader
    {
        protected:
            std::filesystem::path m_inputFile;
            std::ifstream m_ifs;

        public:
            AbstractDataReader(std::filesystem::path inputFile);
            virtual ~AbstractDataReader();

            virtual std::optional<std::pair<double, std::vector<T>>> readline(
                std::optional<double> timepoint = std::optional<double>());
            
            virtual void skip();

            virtual void reset();
            
        protected:
            virtual std::vector<T> interpretTimepoint(std::stringstream& ss);

    };

    template <typename T>
    using AbstractDataReaderPtr = std::shared_ptr<AbstractDataReader<T>>;

} // namespace gga

#endif // GASTRIC_GLAND_ANALYSER_DATA_READERS_ABSTRACT_DATA_READER
#include "iostream"
#include "parser.h"
#include "string"

ParserResults ArgParser::Parse(int argc, const char *argv[]) {
    if (argc == 2) {
        throw std::invalid_argument("no output file");
    }
    std::string in_file_path = argv[1];
    std::string out_file_path = argv[2];
    std::vector<std::string> names = {"-gs", "-neg", "-crop", "-sharp", "-edge", "-blur", "-pixel"};
    ParserResults result;
    result.input_file_path = in_file_path;
    result.output_file_path = out_file_path;
    FilterDefinition reading_filter;
    reading_filter.name = "";
    for (int i = 3; i < argc; ++i) {
        if (std::find(names.begin(), names.end(), argv[i]) != names.end()) {
            if (reading_filter.name != "") {
                result.filter_definitions.push_back(reading_filter);
                reading_filter = {};
            }
            reading_filter.name = static_cast<std::string>(argv[i]).substr(1);
        } else {
            reading_filter.params.push_back(argv[i]);
        }
    }
    if (argc > 3) {
        result.filter_definitions.push_back(reading_filter);
    }
    return result;
}
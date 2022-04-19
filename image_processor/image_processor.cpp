#include "lib/parser.h"
#include "lib/io.h"
#include "lib/bmp_picture.h"
#include "lib/filters_factory.h"
#include "lib/help.h"

int main(int argc, const char *argv[]) {
    if (argc == 1) {
        help();
        return 0;
    }
    ArgParser a = ArgParser();
    ParserResults parsed = a.Parse(argc, argv);
    Reader input = Reader(parsed.input_file_path);
    BMP bmp = input.read_from_file();
    auto filters = filters_factory(parsed.filter_definitions);
    for (auto filter : filters) {
        filter->apply_filter(bmp);
    }
    Writer output = Writer(parsed.output_file_path);
    output.write_in_file(bmp);
}
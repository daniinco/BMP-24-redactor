#include "filters_factory.h"
#include "iostream"

std::vector<std::shared_ptr<Filter>> filters_factory(const std::vector<FilterDefinition>& filter_defs) {
    std::vector<std::shared_ptr<Filter>> result;
    for (const FilterDefinition& fd : filter_defs) {
        if (fd.name == "gs") {
            if (!fd.params.empty()) {
                throw std::invalid_argument("too many args in gs");
            }
            result.push_back(std::make_shared<Grayscale>(Grayscale()));
        } else if (fd.name == "crop") {
            if (fd.params.size() != 2) {
                throw std::invalid_argument("wrong quantity of args in crop");
            }
            try {
                size_t width = std::stoi(fd.params[0]);
                size_t height = std::stoi(fd.params[1]);
                result.push_back(std::make_shared<Crop>(Crop(width, height)));
            } catch (...) {
                throw std::invalid_argument("params of crop not integer");
            }
        } else if (fd.name == "neg") {
            if (!fd.params.empty()) {
                throw std::invalid_argument("too many args in neg");
            }
            result.push_back(std::make_shared<Negative>(Negative()));
        } else if (fd.name == "sharp") {
            if (!fd.params.empty()) {
                throw std::invalid_argument("too many args in sharp");
            }
            result.push_back(std::make_shared<Sharpening>(Sharpening()));
        } else if (fd.name == "pixel") {
            if (fd.params.size() != 1) {
                throw std::invalid_argument("wrong quantity of args in pixel");
            }
            try {
                int pixel_size = std::stoi(fd.params[0]);
                if (pixel_size <= 0) {
                    throw std::invalid_argument("wrong params of pixel");
                }
                result.push_back(std::make_shared<Pixellate>(Pixellate(pixel_size)));
            } catch (...) {
                throw std::invalid_argument("wrong params of pixel");
            }
        } else if (fd.name == "edge") {
            if (fd.params.size() != 1) {
                throw std::invalid_argument("wrong quantity of args in edge");
            }
            try {
                float threshold = std::stof(fd.params[0]);
                result.push_back(std::make_shared<EdgeDetection>(EdgeDetection(threshold)));
            } catch (...) {
                throw std::invalid_argument("params of edge not float");
            }
        } else if (fd.name == "blur") {
            if (fd.params.size() != 1) {
                throw std::invalid_argument("wrong quantity of args in blur");
            }
            try {
                float sigma = std::stof(fd.params[0]);
                result.push_back(std::make_shared<GaussianBlur>(GaussianBlur(sigma)));
            } catch (...) {
                throw std::invalid_argument("param of blur not float");
            }
        } else {
            throw std::invalid_argument("unknown filter name");
        }
    }
    return result;
}
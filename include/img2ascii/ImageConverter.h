#pragma once
#include <string>

struct ImageConverter {
    void toPgm(const std::string& input,
               const std::string& output) const;
};

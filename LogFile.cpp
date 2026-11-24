#define _CRT_SECURE_NO_WARNINGS


#include "LogFile.h"

LogFile::LogFile(const std::string& filename) : f{ nullptr } {
    f = std::fopen(filename.c_str(), "a");
}

LogFile::~LogFile() {
    if (f) {
        std::fclose(f);
    }
}

void LogFile::write(const std::string& msg) {
    if (f) {
        std::fputs((msg + "\n").c_str(), f);
    }
}
#pragma once
#include <string>
#include <cstdio>

class LogFile {
private:
    std::FILE* f;

public:
    LogFile(const std::string& filename);
    ~LogFile();

    // Zabrana kopiranja
    LogFile(const LogFile&) = delete;
    LogFile& operator=(const LogFile&) = delete;

    void write(const std::string& msg);
};

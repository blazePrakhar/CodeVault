#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>

class FileManager
{
public:
    static std::string createSolutionFile(const std::string &title,
                                          const std::string &language);

private:
    static std::string generateFileName(const std::string &title);

    static std::string getExtension(const std::string &language);

    static std::string getFolder(const std::string &language);

    static void writeTemplate(std::ofstream &file,
                              const std::string &language);
};

#endif

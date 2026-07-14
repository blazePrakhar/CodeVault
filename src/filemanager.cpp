#include "../include/fileManager.h"

#include <algorithm>
#include <cctype>
#include <fstream>

std::string FileManager::generateFileName(const std::string &title)
{
    std::string fileName = title;

    for (char &c : fileName)
    {
        if (c == ' ')
        {
            c = '_';
        }
        else
        {
            c = std::tolower(c);
        }
    }

    return fileName;
}

std::string FileManager::getExtension(const std::string &language)
{
    if (language == "C++")
        return ".cpp";

    if (language == "Java")
        return ".java";

    if (language == "Python")
        return ".py";

    if (language == "JavaScript")
        return ".js";

    return ".txt";
}

std::string FileManager::getFolder(const std::string &language)
{
    if (language == "C++")
        return "solutions/cpp/";

    if (language == "Java")
        return "solutions/java/";

    if (language == "Python")
        return "solutions/python/";

    if (language == "JavaScript")
        return "solutions/javascript/";

    return "solutions/";
}

std::string FileManager::createSolutionFile(const std::string &title,
                                            const std::string &language)
{
    std::string fileName = generateFileName(title);

    std::string folder = getFolder(language);

    std::string extension = getExtension(language);

    std::string path = folder + fileName + extension;

    std::ofstream file(path);

    if (file)
    {
        writeTemplate(file, language);
        file.close();
    }

    return path;
}

void FileManager::writeTemplate(std::ofstream &file,
                                const std::string &language)
{
    if (language == "C++")
    {
        file << "#include <iostream>\n\n";
        file << "using namespace std;\n\n";
        file << "int main()\n";
        file << "{\n\n";
        file << "    return 0;\n";
        file << "}\n";
    }
    else if (language == "Java")
    {
        file << "public class Solution\n";
        file << "{\n";
        file << "    public static void main(String[] args)\n";
        file << "    {\n\n";
        file << "    }\n";
        file << "}\n";
    }
    else if (language == "Python")
    {
        file << "def main():\n";
        file << "    pass\n\n";
        file << "if __name__ == \"__main__\":\n";
        file << "    main()\n";
    }
    else if (language == "JavaScript")
    {
        file << "function main()\n";
        file << "{\n\n";
        file << "}\n\n";
        file << "main();\n";
    }
}

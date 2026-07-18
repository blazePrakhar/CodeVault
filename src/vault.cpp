#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "../include/vault.h"

std::string toLower(std::string text)
{
    std::transform(text.begin(),
                   text.end(),
                   text.begin(),
                   ::tolower);

    return text;
}

Vault::Vault()
{
    loadQuestionsFromFile();
}

void Vault::addQuestion(const Question &question)
{
    for (const auto &question : questions)
    {
        if (question.getTitle() == question.getTitle())
        {
            std::cout << "\n====================================\n";
            std::cout << "Question already exists!\n";
            std::cout << "====================================\n";
            return;
        }
    }
    questions.push_back(question);
    saveQuestionsToFile();
}

void Vault::displayAllQuestions() const
{
    int index = 1;

    for (const Question &question : questions)
    {
        std::cout << "\n========== Question #"
                  << index++
                  << " ==========\n";

        question.displayQuestion();

        std::cout << "-----------------------------\n";
    }
}

int Vault::getQuestionCount() const
{
    return questions.size();
}

Question *Vault::searchQuestionByTitle(const std::string &title)
{
    for (Question &question : questions)
    {
        if (question.getTitle() == title)
        {
            bool alreadyExists = false;

            for (const auto &recent : recentQuestions)
            {
                if (recent.getTitle() == question.getTitle())
                {
                    alreadyExists = true;
                    break;
                }
            }

            if (!alreadyExists)
            {
                recentQuestions.push_back(question);
            }

            return &question;
        }
    }

    return nullptr;
}

bool Vault::deleteQuestionByTitle(const std::string &title)
{
    for (auto it = questions.begin(); it != questions.end(); ++it)
    {
        if (it->getTitle() == title)
        {
            questions.erase(it);
            saveQuestionsToFile();
            return true;
        }
    }

    return false;
}

void Vault::saveQuestionsToFile() const
{
    std::ofstream file("data/questions.txt");

    if (!file)
    {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    for (const Question &question : questions)
    {
        file << question.getTitle() << "|"
             << question.getTopic() << "|"
             << question.getDifficulty() << "|"
             << question.getPlatform() << "|"
             << question.getLanguage() << "|"
             << question.getSolutionPath() << "|"
             << question.isSolved() << "|"
             << question.isFavorite()

             << std::endl;
    }

    file.close();
}

void Vault::loadQuestionsFromFile()
{
    std::ifstream file("data/questions.txt");

    if (!file)
    {
        return;
    }

    std::string line;

    while (getline(file, line))
    {
        std::stringstream ss(line);

        std::string title;
        std::string topic;
        std::string difficulty;
        std::string platform;
        std::string language;
        std::string solutionPath;
        std::string solvedString;
        std::string favoriteString;

        getline(ss, title, '|');
        getline(ss, topic, '|');
        getline(ss, difficulty, '|');
        getline(ss, platform, '|');
        getline(ss, language, '|');
        getline(ss, solutionPath, '|');
        getline(ss, solvedString, '|');
        getline(ss, favoriteString);

        bool solved = (solvedString == "1");
        bool favorite = (favoriteString == "1");

        Question question(title,
                          topic,
                          difficulty,
                          platform,
                          language,
                          solutionPath,
                          solved,
                          favorite);

        questions.push_back(question);
    }

    file.close();
}

int Vault::getSolvedCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.isSolved())
        {
            count++;
        }
    }

    return count;
}

int Vault::getFavoriteCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.isFavorite())
        {
            count++;
        }
    }

    return count;
}

void Vault::displayStatistics() const
{
    int totalQuestions = questions.size();
    int solvedQuestions = getSolvedCount();
    int favoriteQuestions = getFavoriteCount();

    int easyQuestions = getEasyCount();
    int mediumQuestions = getMediumCount();
    int hardQuestions = getHardCount();

    int cppQuestions = getCppCount();
    int javaQuestions = getJavaCount();
    int pythonQuestions = getPythonCount();
    int javascriptQuestions = getJavaScriptCount();

    int leetCodeQuestions = getLeetCodeCount();
    int geeksforGeeksQuestions = getGeeksforGeeksCount();

    int unsolvedQuestions = totalQuestions - solvedQuestions;

    double completionPercentage = 0.0;

    if (totalQuestions > 0)
    {
        completionPercentage =
            (static_cast<double>(solvedQuestions) / totalQuestions) * 100;
    }

    std::cout << "\n=========================================\n";
    std::cout << "         CodeVault Dashboard\n";
    std::cout << "=========================================\n";

    std::cout << "Total Questions : " << totalQuestions << std::endl;
    std::cout << std::endl;

    std::cout << "Solved          : " << solvedQuestions << std::endl;
    std::cout << "Unsolved        : " << unsolvedQuestions << std::endl;
    std::cout << "Completion      : "
              << std::fixed << std::setprecision(1)
              << completionPercentage << "%" << std::endl;
    std::cout << std::endl;

    std::cout << "Favorites       : " << favoriteQuestions << std::endl;

    std::cout << "\n-----------------------------------------\n";
    std::cout << "Difficulty Distribution\n\n";

    std::cout << "Easy            : "
              << easyQuestions << std::endl;

    std::cout << "Medium          : "
              << mediumQuestions << std::endl;

    std::cout << "Hard            : "
              << hardQuestions << std::endl;

    std::cout << "\n-----------------------------------------\n";
    std::cout << "Language Distribution\n\n";

    std::cout << "C++             : "
              << cppQuestions << std::endl;

    std::cout << "Java            : "
              << javaQuestions << std::endl;

    std::cout << "Python          : "
              << pythonQuestions << std::endl;

    std::cout << "JavaScript      : "
              << javascriptQuestions << std::endl;

    std::cout << "\n-----------------------------------------\n";
    std::cout << "Platform Distribution\n\n";

    std::cout << "LeetCode        : "
              << leetCodeQuestions << std::endl;

    std::cout << "GeeksforGeeks   : "
              << geeksforGeeksQuestions << std::endl;

    std::cout << "=========================================\n";
}

void Vault::exportReport() const
{
    std::ofstream outFile("data/report.txt");

    if (!outFile)
    {
        std::cout << "Failed to create report!\n";
        return;
    }

    int totalQuestions = questions.size();
    int solvedQuestions = getSolvedCount();
    int favoriteQuestions = getFavoriteCount();
    int unsolvedQuestions = totalQuestions - solvedQuestions;

    int easyQuestions = getEasyCount();
    int mediumQuestions = getMediumCount();
    int hardQuestions = getHardCount();

    int cppQuestions = getCppCount();
    int javaQuestions = getJavaCount();
    int pythonQuestions = getPythonCount();
    int javascriptQuestions = getJavaScriptCount();

    int leetCodeQuestions = getLeetCodeCount();
    int geeksforGeeksQuestions = getGeeksforGeeksCount();

    double completionPercentage = 0.0;

    if (totalQuestions > 0)
    {
        completionPercentage =
            (static_cast<double>(solvedQuestions) / totalQuestions) * 100;
    }

    outFile << "=========================================\n";
    outFile << "         CodeVault Report\n";
    outFile << "=========================================\n\n";

    outFile << "Total Questions : " << totalQuestions << '\n';
    outFile << "Solved          : " << solvedQuestions << '\n';
    outFile << "Unsolved        : " << unsolvedQuestions << '\n';
    outFile << "Completion      : "
            << std::fixed
            << std::setprecision(1)
            << completionPercentage << "%\n";
    outFile << "Favorites       : " << favoriteQuestions << "\n\n";

    outFile << "-----------------------------------------\n";
    outFile << "Difficulty Distribution\n\n";

    outFile << "Easy            : " << easyQuestions << '\n';
    outFile << "Medium          : " << mediumQuestions << '\n';
    outFile << "Hard            : " << hardQuestions << "\n\n";

    outFile << "-----------------------------------------\n";
    outFile << "Language Distribution\n\n";

    outFile << "C++             : " << cppQuestions << '\n';
    outFile << "Java            : " << javaQuestions << '\n';
    outFile << "Python          : " << pythonQuestions << '\n';
    outFile << "JavaScript      : " << javascriptQuestions << "\n\n";

    outFile << "-----------------------------------------\n";
    outFile << "Platform Distribution\n\n";

    outFile << "LeetCode        : " << leetCodeQuestions << '\n';
    outFile << "GeeksforGeeks   : " << geeksforGeeksQuestions << '\n';

    outFile << "\n=========================================\n";
    outFile << "End of Report\n";
    outFile << "=========================================\n";

    outFile.close();

    std::cout << "\n====================================\n";
    std::cout << "Report exported successfully!\n";
    std::cout << "====================================\n";
}

void Vault::filterByDifficulty(const std::string &difficulty) const
{
    bool found = false;

    std::cout << "\n====================================\n";
    std::cout << "Questions with Difficulty: " << difficulty << "\n";
    std::cout << "====================================\n";

    for (const Question &question : questions)
    {
        if (question.getDifficulty() == difficulty)
        {
            question.displayQuestion();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "\nNo questions found with this difficulty.\n";
    }
}

void Vault::filterByLanguage(const std::string &language) const
{
    bool found = false;

    std::cout << "\n====================================\n";
    std::cout << "Questions in Language: " << language << "\n";
    std::cout << "====================================\n";

    for (const Question &question : questions)
    {
        if (question.getLanguage() == language)
        {
            question.displayQuestion();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "\nNo questions found.\n";
    }
}

void Vault::filterByPlatform(const std::string &platform) const
{
    bool found = false;

    std::cout << "\n====================================\n";
    std::cout << "Questions from Platform: " << platform << "\n";
    std::cout << "====================================\n";

    for (const Question &question : questions)
    {
        if (question.getPlatform() == platform)
        {
            question.displayQuestion();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "\nNo questions found.\n";
    }
}

void Vault::showSolvedQuestions() const
{
    bool found = false;

    std::cout << "\n====================================\n";
    std::cout << "Solved Questions\n";
    std::cout << "====================================\n";

    for (const Question &question : questions)
    {
        if (question.isSolved())
        {
            question.displayQuestion();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "\nNo solved questions found.\n";
    }
}

void Vault::showFavoriteQuestions() const
{
    bool found = false;

    std::cout << "\n====================================\n";
    std::cout << "Favorite Questions\n";
    std::cout << "====================================\n";

    for (const Question &question : questions)
    {
        if (question.isFavorite())
        {
            question.displayQuestion();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "\nNo favorite questions found.\n";
    }
}

void Vault::sortByTitle()
{
    std::sort(questions.begin(),
              questions.end(),
              [](const Question &a, const Question &b)
              {
                  return a.getTitle() < b.getTitle();
              });

    std::cout << "\n====================================\n";
    std::cout << "Questions Sorted By Title\n";
    std::cout << "====================================\n";

    displayAllQuestions();
}

void Vault::sortByPlatform()
{
    std::sort(questions.begin(),
              questions.end(),
              [](const Question &a, const Question &b)
              {
                  return a.getPlatform() < b.getPlatform();
              });

    std::cout << "\n====================================\n";
    std::cout << "Questions Sorted By Platform\n";
    std::cout << "====================================\n";

    displayAllQuestions();
}

void Vault::sortByLanguage()
{
    std::sort(questions.begin(),
              questions.end(),
              [](const Question &a, const Question &b)
              {
                  return a.getLanguage() < b.getLanguage();
              });

    std::cout << "\n====================================\n";
    std::cout << "Questions Sorted By Language\n";
    std::cout << "====================================\n";

    displayAllQuestions();
}

void Vault::sortByDifficulty()
{
    auto getRank = [](const std::string &difficulty)
    {
        if (difficulty == "Easy")
            return 1;

        if (difficulty == "Medium")
            return 2;

        return 3;
    };

    std::sort(questions.begin(),
              questions.end(),
              [&](const Question &a, const Question &b)
              {
                  return getRank(a.getDifficulty()) <
                         getRank(b.getDifficulty());
              });

    std::cout << "\n====================================\n";
    std::cout << "Questions Sorted By Difficulty\n";
    std::cout << "====================================\n";

    displayAllQuestions();
}

bool Vault::questionExists(const std::string &title) const
{
    for (const Question &question : questions)
    {
        if (toLower(question.getTitle()) == toLower(title))
        {
            return true;
        }
    }

    return false;
}

int Vault::getEasyCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getDifficulty() == "Easy")
        {
            count++;
        }
    }

    return count;
}

int Vault::getMediumCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getDifficulty() == "Medium")
        {
            count++;
        }
    }

    return count;
}

int Vault::getHardCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getDifficulty() == "Hard")
        {
            count++;
        }
    }

    return count;
}

int Vault::getCppCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getLanguage() == "C++")
        {
            count++;
        }
    }

    return count;
}

int Vault::getJavaCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getLanguage() == "Java")
        {
            count++;
        }
    }

    return count;
}

int Vault::getPythonCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getLanguage() == "Python")
        {
            count++;
        }
    }

    return count;
}

int Vault::getJavaScriptCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getLanguage() == "JavaScript")
        {
            count++;
        }
    }

    return count;
}

int Vault::getLeetCodeCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getPlatform() == "LeetCode")
        {
            count++;
        }
    }

    return count;
}

int Vault::getGeeksforGeeksCount() const
{
    int count = 0;

    for (const Question &question : questions)
    {
        if (question.getPlatform() == "GeeksforGeeks")
        {
            count++;
        }
    }

    return count;
}

void Vault::backupQuestions() const
{
    std::ifstream source("data/questions.txt", std::ios::binary);
    std::ofstream backup("data/questions_backup.txt", std::ios::binary);

    if (!source || !backup)
    {
        std::cout << "\n====================================\n";
        std::cout << "Backup failed!\n";
        std::cout << "====================================\n";
        return;
    }

    backup << source.rdbuf();

    std::cout << "\n====================================\n";
    std::cout << "Backup created successfully!\n";
    std::cout << "====================================\n";
}

void Vault::restoreQuestions()
{
    std::ifstream backup("data/questions_backup.txt", std::ios::binary);
    std::ofstream original("data/questions.txt", std::ios::binary);

    if (!backup || !original)
    {
        std::cout << "\n====================================\n";
        std::cout << "Restore failed!\n";
        std::cout << "====================================\n";
        return;
    }

    original << backup.rdbuf();

    backup.close();
    original.close();

    questions.clear();
    loadQuestionsFromFile();

    std::cout << "\n====================================\n";
    std::cout << "Questions restored successfully!\n";
    std::cout << "====================================\n";
}

void Vault::viewRecentQuestions() const
{
    if (recentQuestions.empty())
    {
        std::cout << "\n====================================\n";
        std::cout << "No recently viewed questions.\n";
        std::cout << "====================================\n";
        return;
    }

    std::cout << "\n========== Recently Viewed ==========\n";

    for (const auto &question : recentQuestions)
    {
        question.displayQuestion();
    }

    std::cout << "=====================================\n";
}

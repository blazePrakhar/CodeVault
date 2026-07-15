#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/vault.h"

Vault::Vault()
{
    loadQuestionsFromFile();
}

void Vault::addQuestion(const Question &question)
{
    questions.push_back(question);
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

void Vault::displayStatistics() const
{
    int totalQuestions = questions.size();
    int solvedQuestions = 0;
    int favoriteQuestions = 0;

    for (const Question &question : questions)
    {
        if (question.isSolved())
        {
            solvedQuestions++;
        }

        if (question.isFavorite())
        {
            favoriteQuestions++;
        }
    }

    int unsolvedQuestions = totalQuestions - solvedQuestions;

    std::cout << "\n====================================\n";
    std::cout << "      CodeVault Statistics\n";
    std::cout << "====================================\n";

    std::cout << "Total Questions     : " << totalQuestions << std::endl;
    std::cout << "Solved Questions    : " << solvedQuestions << std::endl;
    std::cout << "Unsolved Questions  : " << unsolvedQuestions << std::endl;
    std::cout << "Favorite Questions  : " << favoriteQuestions << std::endl;

    std::cout << "====================================\n";
}

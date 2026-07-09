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
    for (const Question &question : questions)
    {
        question.displayQuestion();
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
             << question.getPlatform()
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

        getline(ss, title, '|');
        getline(ss, topic, '|');
        getline(ss, difficulty, '|');
        getline(ss, platform);

        Question question(title,
                          topic,
                          difficulty,
                          platform);

        questions.push_back(question);
    }

    file.close();
}


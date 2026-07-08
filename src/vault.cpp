#include <iostream>
#include <fstream>
#include "../include/vault.h"

Vault::Vault()
{
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

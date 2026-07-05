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

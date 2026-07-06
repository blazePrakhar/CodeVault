#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include "question.h"

class Vault
{
private:
    std::vector<Question> questions;

public:
    Vault();

    void addQuestion(const Question &question);

    void displayAllQuestions() const;

    int getQuestionCount() const;

    Question *searchQuestionByTitle(const std::string &title);

    bool deleteQuestionByTitle(const std::string &title);
};

#endif

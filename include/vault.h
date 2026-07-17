#ifndef VAULT_H
#define VAULT_H

#include <vector>
#include "question.h"

class Vault
{
private:
    std::vector<Question> questions;

    void saveQuestionsToFile() const;
    void loadQuestionsFromFile();

    int getSolvedCount() const;
    int getFavoriteCount() const;

public:
    Vault();

    void addQuestion(const Question &question);

    void displayAllQuestions() const;

    void displayStatistics() const;

    void filterByDifficulty(const std::string &difficulty) const;

    void filterByLanguage(const std::string &language) const;

    void filterByPlatform(const std::string &platform) const;

    void showSolvedQuestions() const;

    void showFavoriteQuestions() const;

    int getQuestionCount() const;

    Question *searchQuestionByTitle(const std::string &title);

    bool deleteQuestionByTitle(const std::string &title);

    bool questionExists(const std::string &title) const;

    void sortByTitle();

    void sortByDifficulty();

    void sortByPlatform();

    void sortByLanguage();
};

#endif

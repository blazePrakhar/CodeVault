#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question
{
private:
    std::string title;
    std::string topic;
    std::string difficulty;
    std::string platform;
    std::string language;
    std::string solutionFile;

    bool solved;
    bool favorite;

public:
    Question();

    Question(std::string title,
             std::string topic,
             std::string difficulty,
             std::string platform,
             std::string language,
             std::string solutionFile);

    void setTitle(std::string title);
    std::string getTitle() const;

    void setTopic(std::string topic);
    std::string getTopic() const;

    void setDifficulty(std::string difficulty);
    std::string getDifficulty() const;

    void setPlatform(std::string platform);
    std::string getPlatform() const;

    void setLanguage(std::string language);
    std::string getLanguage() const;

    void setSolutionFile(std::string solutionFile);
    std::string getSolutionFile() const;

    void displayQuestion() const;

    void markSolved();

    void toggleFavorite();

    bool isSolved() const;

    bool isFavorite() const;
};

#endif

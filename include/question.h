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

    bool solved;
    bool favorite;

public:
    Question();

    Question(std::string title,
             std::string topic,
             std::string difficulty,
             std::string platform);

    void setTitle(std::string title);
    std::string getTitle() const;

    void setTopic(std::string topic);
    std::string getTopic() const;

    void setDifficulty(std::string difficulty);
    std::string getDifficulty() const;

    void setPlatform(std::string platform);
    std::string getPlatform() const;


    void displayQuestion() const;

    void markSolved();

    void toggleFavorite();

    bool isSolved() const;
    
    bool isFavorite() const;
};

#endif
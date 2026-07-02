#include "../include/question.h"

Question::Question()
{
    title = "";
    topic = "";
    difficulty = "";
    platform = "";

    solved = false;
    favorite = false;
}

Question::Question(std::string title,
                   std::string topic,
                   std::string difficulty,
                   std::string platform)
{
    this->title = title;
    this->topic = topic;
    this->difficulty = difficulty;
    this->platform = platform;

    solved = false;
    favorite = false;
}

void Question::setTitle(std::string title)
{
    this->title = title;
}

std::string Question::getTitle() const
{
    return title;
}

void Question::setTopic(std::string topic)
{
    this->topic = topic;
}

std::string Question::getTopic() const
{
    return topic;
}

void Question::setDifficulty(std::string difficulty)
{
    this->difficulty = difficulty;
}

std::string Question::getDifficulty() const
{
    return difficulty;
}

void Question::setPlatform(std::string platform)
{
    this->platform = platform;
}

std::string Question::getPlatform() const
{
    return platform;
}

#include <iostream>

void Question::displayQuestion() const
{
    std::cout << "\n===== Question =====" << std::endl;

    std::cout << "Title      : " << title << std::endl;
    std::cout << "Topic      : " << topic << std::endl;
    std::cout << "Difficulty : " << difficulty << std::endl;
    std::cout << "Platform   : " << platform << std::endl;

    std::cout << "Solved     : "
              << (solved ? "Yes" : "No")
              << std::endl;

    std::cout << "Favorite   : "
              << (favorite ? "Yes" : "No")
              << std::endl;
}

void Question::markSolved()
{
    solved = true;
}

void Question::toggleFavorite()
{
    favorite = !favorite;
}

bool Question::isSolved() const
{
    return solved;
}

bool Question::isFavorite() const
{
    return favorite;
}
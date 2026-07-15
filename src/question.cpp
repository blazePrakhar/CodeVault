#include <iostream>
#include "../include/question.h"

Question::Question()
{
    title = "";
    topic = "";
    difficulty = "";
    platform = "";
    language = "";

    solved = false;
    favorite = false;
}

Question::Question(std::string title,
                   std::string topic,
                   std::string difficulty,
                   std::string platform,
                   std::string language,
                   std::string solutionPath,
                   bool solved,
                   bool favorite)
{
    this->title = title;
    this->topic = topic;
    this->difficulty = difficulty;
    this->platform = platform;
    this->language = language;
    this->solutionPath = solutionPath;

    this->solved = solved;
    this->favorite = favorite;
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

void Question::setLanguage(std::string language)
{
    this->language = language;
}

std::string Question::getLanguage() const
{
    return language;
}

void Question::setSolutionPath(std::string solutionPath)
{
    this->solutionPath = solutionPath;
}

std::string Question::getSolutionPath() const
{
    return solutionPath;
}

void Question::displayQuestion() const
{
    std::cout << "\n===== Question =====" << std::endl;

    std::cout << "Title      : " << title << std::endl;
    std::cout << "Topic      : " << topic << std::endl;
    std::cout << "Difficulty : " << difficulty << std::endl;
    std::cout << "Platform   : " << platform << std::endl;
    std::cout << "Language   : " << language << std::endl;
    std::cout << "Solution   : " << solutionPath << std::endl;

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

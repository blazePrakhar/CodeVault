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
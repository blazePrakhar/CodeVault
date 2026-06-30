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
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

};

#endif
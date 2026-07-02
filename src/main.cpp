#include <iostream>
#include "./../include/question.h"

using namespace std;

int main()
{
    Question q1("Two Sum",
                "Arrays",
                "Easy",
                "LeetCode");

    q1.markSolved();

    q1.toggleFavorite();

    q1.displayQuestion();

    return 0;
}
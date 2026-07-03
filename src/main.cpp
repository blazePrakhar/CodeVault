#include <iostream>
#include "../include/question.h"
#include "../include/vault.h"

using namespace std;

int main()
{
    Vault vault;

    Question q1("Two Sum", "Arrays", "Easy", "LeetCode");
    Question q2("Binary Search", "Arrays", "Easy", "LeetCode");
    Question q3("Merge Intervals", "Arrays", "Medium", "LeetCode");

    vault.addQuestion(q1);
    vault.addQuestion(q2);
    vault.addQuestion(q3);

    cout << "Total Questions: "
         << vault.getQuestionCount()
         << endl
         << endl;

    vault.displayAllQuestions();

    return 0;
}

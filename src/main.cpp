#include <iostream>
#include "./../include/question.h"

using namespace std;

int main()
{
    Question q1;

    q1.setTitle("Two Sum");
    q1.setTopic("Arrays");
    q1.setDifficulty("Easy");
    q1.setPlatform("LeetCode");

    cout << "===== CodeVault =====" << endl;
    cout << "Title      : " << q1.getTitle() << endl;
    cout << "Topic      : " << q1.getTopic() << endl;
    cout << "Difficulty : " << q1.getDifficulty() << endl;
    cout << "Platform   : " << q1.getPlatform() << endl;

    return 0;
}
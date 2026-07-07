#include <iostream>
#include "../include/question.h"
#include "../include/vault.h"

using namespace std;

int main()
{
    Vault vault;

    int choice;

    string title;
    string topic;
    string difficulty;
    string platform;

    Question *foundQuestion;
    bool isDeleted;

    while (true)
    {
        cout << "1. Add Question\n";
        cout << "2. Display All Questions\n";
        cout << "3. Search Question\n";
        cout << "4. Delete Question\n";
        cout << "5. Update Question\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cin.ignore();

            cout << "\nEnter Title: ";
            getline(cin, title);

            cout << "Enter Topic: ";
            getline(cin, topic);

            cout << "Enter Difficulty: ";
            getline(cin, difficulty);

            cout << "Enter Platform: ";
            getline(cin, platform);

            Question question(title,
                              topic,
                              difficulty,
                              platform);

            vault.addQuestion(question);

            cout << "\nQuestion Added Successfully!\n";

            break;
        }

        case 2:
        {
            if (vault.getQuestionCount() == 0)
            {
                cout << "\nNo Questions Available.\n";
            }
            else
            {
                vault.displayAllQuestions();
            }

            break;
        }

        case 3:
        {
            cin.ignore();

            cout << "\nEnter Question Title: ";
            getline(cin, title);

            foundQuestion = vault.searchQuestionByTitle(title);

            if (foundQuestion != nullptr)
            {
                cout << "\nQuestion Found!\n";
                foundQuestion->displayQuestion();
            }
            else
            {
                cout << "\nQuestion Not Found!\n";
            }

            break;
        }

        case 4:
        {
            cin.ignore();

            cout << "\nEnter Question Title to Delete: ";
            getline(cin, title);

            isDeleted = vault.deleteQuestionByTitle(title);

            if (isDeleted)
            {
                cout << "\nQuestion Deleted Successfully!\n";
            }
            else
            {
                cout << "\nQuestion Not Found!\n";
            }

            break;
        }

        case 5:
        {
            cin.ignore();

            cout << "\nEnter Question Title to Update: ";
            getline(cin, title);

            foundQuestion = vault.searchQuestionByTitle(title);

            if (foundQuestion != nullptr)
            {
                cout << "\nEnter New Title: ";
                getline(cin, title);

                cout << "Enter New Topic: ";
                getline(cin, topic);

                cout << "Enter New Difficulty: ";
                getline(cin, difficulty);

                cout << "Enter New Platform: ";
                getline(cin, platform);

                foundQuestion->setTitle(title);
                foundQuestion->setTopic(topic);
                foundQuestion->setDifficulty(difficulty);
                foundQuestion->setPlatform(platform);

                cout << "\nQuestion Updated Successfully!\n";
            }
            else
            {
                cout << "\nQuestion Not Found!\n";
            }

            break;
        }

        case 6:
        {
            cout << "\nThank you for using CodeVault!\n";
            return 0;
        }

        default:
        {
            cout << "Invalid Choice!\n";
        }
        }
    }
}

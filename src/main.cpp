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
        cout << "\n========== CodeVault ==========\n";
        cout << "1. Add Question\n";
        cout << "2. Display Questions\n";
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

            vault.saveQuestionsToFile();

            cout << "\n=================================\n";
            cout << "Question Added Successfully!\n";
            cout << "Current Total Questions: "
                 << vault.getQuestionCount() << endl;
            cout << "=================================\n";

            break;
        }

        case 2:
        {
            if (vault.getQuestionCount() == 0)
            {
                cout << "\n========== CodeVault ==========\n";
                cout << "No Questions Available.\n";
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
                cout << "\n========== Search Result ==========\n";
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
                vault.saveQuestionsToFile();
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
                cout << "\n===== Current Question =====\n";
                foundQuestion->displayQuestion();

                int updateChoice;

                cout << "\nWhat do you want to update?\n";
                cout << "1. Title\n";
                cout << "2. Topic\n";
                cout << "3. Difficulty\n";
                cout << "4. Platform\n";
                cout << "5. Cancel\n";

                cout << "\nEnter Choice: ";
                cin >> updateChoice;
                cin.ignore();

                switch (updateChoice)
                {
                case 1:
                {
                    cout << "Enter New Title: ";
                    getline(cin, title);

                    foundQuestion->setTitle(title);

                    cout << "\nTitle Updated Successfully!\n";
                    break;
                }

                case 2:
                {
                    cout << "Enter New Topic: ";
                    getline(cin, topic);

                    foundQuestion->setTopic(topic);

                    cout << "\nTopic Updated Successfully!\n";
                    break;
                }

                case 3:
                {
                    cout << "Enter New Difficulty: ";
                    getline(cin, difficulty);

                    foundQuestion->setDifficulty(difficulty);

                    cout << "\nDifficulty Updated Successfully!\n";
                    break;
                }

                case 4:
                {
                    cout << "Enter New Platform: ";
                    getline(cin, platform);

                    foundQuestion->setPlatform(platform);

                    cout << "\nPlatform Updated Successfully!\n";
                    break;
                }

                case 5:
                {
                    cout << "\nUpdate Cancelled.\n";
                    break;
                }

                default:
                {
                    cout << "\nInvalid Choice!\n";
                }
                }
                if (updateChoice >= 1 && updateChoice <= 4)
                {

                    vault.saveQuestionsToFile();

                    cout << "\n===== Updated Question =====\n";
                    foundQuestion->displayQuestion();
                }
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

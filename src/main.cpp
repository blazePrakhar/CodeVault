#include <iostream>
#include <cctype>
#include "../include/question.h"
#include "../include/vault.h"
#include "../include/fileManager.h"

using namespace std;

string generateFileName(string title)
{
    for (char &c : title)
    {
        if (c == ' ')
        {
            c = '_';
        }
        else
        {
            c = tolower(c);
        }
    }

    return title;
}

int main()
{
    Vault vault;

    cout << "====================================\n";
    cout << "      Welcome to CodeVault!\n";
    cout << " Your Personal Coding Manager\n";
    cout << "====================================\n\n";

    int choice;

    string title;
    string topic;
    string difficulty;
    string platform;
    string language;
    string solutionPath;

    Question *foundQuestion = nullptr;
    bool isDeleted = false;

    while (true)
    {
        cout << "\n====================================\n";
        cout << "         CodeVault v1.0\n";
        cout << "====================================\n";
        cout << "1. Add Question\n";
        cout << "2. Display Questions\n";
        cout << "3. Search Question\n";
        cout << "4. Delete Question\n";
        cout << "5. Update Question\n";
        cout << "6. Mark Question as Solved\n";
        cout << "7. Toggle Favorite\n";
        cout << "8. View Statistics\n";
        cout << "9. Exit\n";
        cout << "====================================\n";

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

            cout << "Enter Language: ";
            getline(cin, language);

            solutionPath = FileManager::createSolutionFile(title,
                                                           language);

            cout << "\nSolution File Created:\n";
            cout << solutionPath << endl;

            Question question(title,
                              topic,
                              difficulty,
                              platform,
                              language,
                              solutionPath,
                              false,
                              false);

            vault.addQuestion(question);

            vault.saveQuestionsToFile();

            cout << "\n====================================\n";
            cout << "Question Added Successfully!\n";
            cout << "Current Total Questions : "
                 << vault.getQuestionCount() << endl;

            cout << "\n========== Added Question ==========\n";
            question.displayQuestion();

            cout << "====================================\n";

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

            cout << "\nEnter Exact Question Title: ";
            getline(cin, title);

            foundQuestion = vault.searchQuestionByTitle(title);

            if (foundQuestion != nullptr)
            {
                cout << "\n====================================\n";
                cout << "Question Found Successfully!\n";
                cout << "====================================\n";

                foundQuestion->displayQuestion();
            }
            else
            {
                cout << "\n====================================\n";
                cout << "No matching question found.\n";
                cout << "====================================\n";
            }

            break;
        }

        case 4:
        {
            cin.ignore();

            cout << "\nEnter Exact Question Title to Delete: ";
            getline(cin, title);

            isDeleted = vault.deleteQuestionByTitle(title);

            if (isDeleted)
            {
                vault.saveQuestionsToFile();

                cout << "\n====================================\n";
                cout << "Question Deleted Successfully!\n";
                cout << "Remaining Questions : "
                     << vault.getQuestionCount() << endl;
                cout << "====================================\n";
            }
            else
            {
                cout << "\n====================================\n";
                cout << "Question Not Found!\n";
                cout << "====================================\n";
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

                cout << "\n====================================\n";
                cout << "What do you want to update?\n";
                cout << "====================================\n";
                cout << "1. Title\n";
                cout << "2. Topic\n";
                cout << "3. Difficulty\n";
                cout << "4. Platform\n";
                cout << "5. Language\n";
                cout << "6. Solution File\n";
                cout << "7. Cancel\n";

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
                    cout << "Enter New Language: ";
                    getline(cin, language);

                    foundQuestion->setLanguage(language);

                    cout << "\nLanguage Updated Successfully!\n";
                    break;
                }

                case 6:
                {
                    cout << "Enter New Solution File: ";
                    getline(cin, solutionPath);

                    foundQuestion->setSolutionPath(solutionPath);

                    cout << "\nSolution File Updated Successfully!\n";
                    break;
                }

                case 7:
                {
                    cout << "\nUpdate Cancelled.\n";
                    break;
                }

                default:
                {
                    cout << "\nInvalid Choice!\n";
                }
                }
                if (updateChoice >= 1 && updateChoice <= 6)
                {

                    vault.saveQuestionsToFile();

                    cout << "\n====================================\n";
                    cout << "Question Updated Successfully!\n";
                    cout << "====================================\n";

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
            cin.ignore();

            cout << "\nEnter Question Title: ";
            getline(cin, title);

            foundQuestion = vault.searchQuestionByTitle(title);

            if (foundQuestion != nullptr)
            {
                if (foundQuestion->isSolved())
                {
                    cout << "\n====================================\n";
                    cout << "Question is already marked as solved.\n";
                    cout << "====================================\n";
                }
                else
                {
                    foundQuestion->markSolved();

                    vault.saveQuestionsToFile();

                    cout << "\n====================================\n";
                    cout << "Question marked as solved successfully!\n";
                    cout << "====================================\n";

                    foundQuestion->displayQuestion();
                }
            }
            else
            {
                cout << "\n====================================\n";
                cout << "Question Not Found!\n";
                cout << "====================================\n";
            }

            break;
        }

        case 7:
        {
            cin.ignore();

            cout << "\nEnter Question Title: ";
            getline(cin, title);

            foundQuestion = vault.searchQuestionByTitle(title);

            if (foundQuestion != nullptr)
            {
                foundQuestion->toggleFavorite();

                vault.saveQuestionsToFile();

                cout << "\n====================================\n";

                if (foundQuestion->isFavorite())
                {
                    cout << "Question added to favorites!\n";
                }
                else
                {
                    cout << "Question removed from favorites!\n";
                }

                cout << "====================================\n";

                foundQuestion->displayQuestion();
            }
            else
            {
                cout << "\n====================================\n";
                cout << "Question Not Found!\n";
                cout << "====================================\n";
            }

            break;
        }

        case 8:
        {
            vault.displayStatistics();
            break;
        }

        case 9:
        {
            cout << "\n====================================\n";
            cout << "Thank you for using CodeVault!\n";
            cout << "Happy Coding!\n";
            cout << "====================================\n";
            return 0;
        }

        default:
        {
            cout << "\n====================================\n";
            cout << "Invalid Choice! Please try again.\n";
            cout << "====================================\n";
        }
        }
    }
}

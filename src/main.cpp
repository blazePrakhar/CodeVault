#include <iostream>
#include <cctype>
#include "../include/question.h"
#include "../include/vault.h"
#include "../include/fileManager.h"

using namespace std;

//==================================================
// Utility Functions
//==================================================
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

//==================================================
// UI Helper Functions
//==================================================
void showMessage(const std::string &message)
{
    cout << "\n====================================\n";
    cout << message << '\n';
    cout << "====================================\n";
}

void displayMainMenu()
{
    cout << "\n====================================\n";
    cout << "        CodeVault v2.0\n";
    cout << "====================================\n";
    cout << "1. Add Question\n";
    cout << "2. Display Questions\n";
    cout << "3. Search Question\n";
    cout << "4. Delete Question\n";
    cout << "5. Update Question\n";
    cout << "6. Mark Question as Solved\n";
    cout << "7. Toggle Favorite\n";
    cout << "8. View Statistics\n";
    cout << "9. Filter Questions\n";
    cout << "10. Sort Questions\n";
    cout << "11. Export Report\n";
    cout << "12. Backup Questions\n";
    cout << "13. Restore Questions\n";
    cout << "14. Recently Viewed Questions\n";
    cout << "15. Exit\n";
    cout << "====================================\n";
}

void displayUpdateMenu()
{
    cout << "\n====================================\n";
    cout << "          Update Menu\n";
    cout << "====================================\n";
    cout << "1. Title\n";
    cout << "2. Topic\n";
    cout << "3. Difficulty\n";
    cout << "4. Platform\n";
    cout << "5. Language\n";
    cout << "6. Solution File\n";
    cout << "7. Cancel\n";
    cout << "====================================\n";
}

void displayFilterMenu()
{
    cout << "\n====================================\n";
    cout << "        Filter Questions\n";
    cout << "====================================\n";
    cout << "1. By Difficulty\n";
    cout << "2. By Language\n";
    cout << "3. By Platform\n";
    cout << "4. Solved Questions\n";
    cout << "5. Favorite Questions\n";
    cout << "6. Back\n";
    cout << "====================================\n";
}

void displaySortMenu()
{
    cout << "\n====================================\n";
    cout << "         Sort Questions\n";
    cout << "====================================\n";
    cout << "1. By Title\n";
    cout << "2. By Difficulty\n";
    cout << "3. By Platform\n";
    cout << "4. By Language\n";
    cout << "5. Back\n";
    cout << "====================================\n";
}

void displayDeleteConfirmation(const string &title)
{
    cout << "\n====================================\n";
    cout << "Delete Confirmation\n";
    cout << "====================================\n";
    cout << "Are you sure you want to delete:\n";
    cout << title << "\n\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cout << "====================================\n";
    cout << "Enter Choice: ";
}

//==================================================
// Constants
//==================================================
const int MAX_MAIN_MENU = 15;
const int MAX_UPDATE_MENU = 7;
const int MAX_SORT_MENU = 5;
const int MAX_FILTER_MENU = 6;

//==================================================
// Main Function
//==================================================
int main()
{
    Vault vault;

    showMessage("Welcome to CodeVault!\nYour Personal Coding Manager\n");

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
        displayMainMenu();

        cout << "\nEnter Choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            showMessage("Invalid input! Please enter a number.\n");

            continue;
        }

        if (choice < 1 || choice > MAX_MAIN_MENU)
        {
            showMessage("Invalid Menu Choice!\nPlease select a valid option.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            cin.ignore();

            cout << "\nEnter Title: ";
            getline(cin, title);

            if (title.empty())
            {
                showMessage("Title cannot be empty!\n");
                break;
            }

            if (vault.questionExists(title))
            {
                showMessage("Question already exists!\n");

                break;
            }

            cout << "Enter Topic: ";
            getline(cin, topic);

            if (topic.empty())
            {
                showMessage("Topic cannot be empty!\n");
                break;
            }

            cout << "Enter Difficulty: ";
            getline(cin, difficulty);

            if (difficulty != "Easy" &&
                difficulty != "Medium" &&
                difficulty != "Hard")
            {
                showMessage("Invalid Difficulty!\nEnter only: Easy, Medium or Hard.\n");
                break;
            }

            cout << "Enter Platform: ";
            getline(cin, platform);

            if (platform.empty())
            {
                showMessage("Platform cannot be empty!\n");
                break;
            }

            cout << "Enter Language: ";
            getline(cin, language);

            if (language.empty())
            {
                showMessage("Language cannot be empty!\n");
                break;
            }

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
                showMessage("Question Found Successfully!\n");

                foundQuestion->displayQuestion();
            }
            else
            {
                showMessage("No matching question found.\n");
            }

            break;
        }

        case 4:
        {
            cin.ignore();

            cout << "\nEnter Exact Question Title to Delete: ";
            getline(cin, title);

            int confirm;

            displayDeleteConfirmation(title);
            cin >> confirm;
            cin.ignore();

            if (confirm != 1)
            {
                showMessage("Deletion Cancelled.\n");
                break;
            }

            isDeleted = vault.deleteQuestionByTitle(title);

            if (isDeleted)
            {

                cout << "\n====================================\n";
                cout << "Question Deleted Successfully!\n";
                cout << "Remaining Questions : "
                     << vault.getQuestionCount() << endl;
                cout << "====================================\n";
            }
            else
            {
                showMessage("Question Not Found!\n");
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

                displayUpdateMenu();

                cout << "\nEnter Choice: ";
                cin >> updateChoice;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');

                    showMessage("Invalid input! Please enter a number.\n");

                    continue;
                }

                if (updateChoice < 1 || updateChoice > MAX_UPDATE_MENU)
                {
                    showMessage("Invalid Update Choice!\nPlease select a valid option.\n");
                    break;
                }

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

                    showMessage("Question Updated Successfully!\n");

                    foundQuestion->displayQuestion();
                }
            }
            else
            {
                showMessage("Question Not Found!");
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
                    showMessage("Question is already marked as solved.\n");
                }
                else
                {
                    foundQuestion->markSolved();

                    showMessage("Question marked as solved successfully!\n");

                    foundQuestion->displayQuestion();
                }
            }
            else
            {
                showMessage("Question Not Found!\n");
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

                cout << "\n====================================\n";

                if (foundQuestion->isFavorite())
                {
                    showMessage("Question added to favorites!");
                }
                else
                {
                    showMessage("Question removed from favorites!");
                }

                cout << "====================================\n";

                foundQuestion->displayQuestion();
            }
            else
            {
                showMessage("Question Not Found!\n");
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
            int filterChoice;

            displayFilterMenu();

            cout << "\nEnter Choice: ";
            cin >> filterChoice;
            cin.ignore();

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');

                showMessage("Invalid input! Please enter a number.\n");

                break;
            }

            if (filterChoice < 1 || filterChoice > MAX_FILTER_MENU)
            {
                showMessage("Invalid Filter Choice!\nPlease select a valid option.\n");
                break;
            }

            switch (filterChoice)
            {
            case 1:
            {
                cout << "\nEnter Difficulty (Easy/Medium/Hard): ";
                getline(cin, difficulty);

                vault.filterByDifficulty(difficulty);

                break;
            }

            case 2:
            {
                cout << "\nEnter Language: ";
                getline(cin, language);

                vault.filterByLanguage(language);

                break;
            }

            case 3:
            {
                cout << "\nEnter Platform: ";
                getline(cin, platform);

                vault.filterByPlatform(platform);

                break;
            }

            case 4:
            {
                vault.showSolvedQuestions();
                break;
            }

            case 5:
            {
                vault.showFavoriteQuestions();
                break;
            }

            case 6:
            {
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!\n";
            }
            }

            break;
        }

        case 10:
        {
            int sortChoice;

            displaySortMenu();

            cout << "\nEnter Choice: ";
            cin >> sortChoice;
            cin.ignore();

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');

                showMessage("Invalid input! Please enter a number.");
                break;
            }
            if (sortChoice < 1 || sortChoice > MAX_SORT_MENU)
            {
                showMessage("Invalid Sort Choice!\nPlease select a valid option.\n");
                break;
            }

            switch (sortChoice)
            {
            case 1:
            {
                vault.sortByTitle();
                break;
            }

            case 2:
            {
                vault.sortByDifficulty();
                break;
            }

            case 3:
            {
                vault.sortByPlatform();
                break;
            }

            case 4:
            {
                vault.sortByLanguage();
                break;
            }

            case 5:
            {
                break;
            }

            default:
            {
                cout << "\nFeature coming soon...\n";
            }
            }

            break;
        }

        case 11:
            vault.exportReport();
            break;

        case 12:
            vault.backupQuestions();
            break;

        case 13:
            vault.restoreQuestions();
            break;

        case 14:
            vault.viewRecentQuestions();
            break;

        case 15:
        {
            showMessage("Thank you for using CodeVault!\nHappy Coding!\n");
            return 0;
        }

        default:
        {
            showMessage("Invalid Choice! Please try again.\n");
        }
        }
    }
}

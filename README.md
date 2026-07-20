# 📚 CodeVault

A C++ console-based coding question management system designed to organize programming problems efficiently. CodeVault helps developers store, search, update, categorize, and manage coding questions with persistent file storage, statistics, filtering, sorting, and backup capabilities.

## ✨ Features

- Add, update, search, and delete coding questions
- Persistent data storage using text files
- Case-insensitive search and filtering
- Sort questions by title, difficulty, platform, and language
- Track solved and favorite questions
- Generate language-specific solution files
- View coding statistics
- Backup and restore question data
- Export question reports
- Recently viewed questions
- Input validation and duplicate detection

## 🛠️ Tech Stack

| Category | Technologies |
|----------|--------------|
| Programming Language | C++ |
| Concepts Used | Object-Oriented Programming (OOP), File Handling, STL |
| Data Storage | Text Files |
| IDE | Visual Studio Code |
| Compiler | g++ |

---

## 📂 Project Structure

```
CodeVault/
│
├── assets/                 # Project assets
├── data/                   # Stores question database and backups
├── docs/                   # Documentation
├── include/                # Header files
├── screenshots/            # Application screenshots
├── solutions/              # Generated solution files
│   ├── cpp/
│   ├── java/
│   ├── javascript/
│   └── python/
├── src/                    # Source files
├── README.md
├── LICENSE
└── .gitignore
```

---

## 🚀 Installation

### Clone the Repository

```bash
git clone https://github.com/blazePrakhar/CodeVault.git
```

### Navigate to the Project Directory

```bash
cd CodeVault
```

### Compile the Project

```bash
g++ src/main.cpp src/question.cpp src/vault.cpp src/filemanager.cpp -o CodeVault
```

### Run the Application

**Windows**

```bash
CodeVault.exe
```

**Linux / macOS**

```bash
./CodeVault
```

---

## 💻 Usage

After launching the application, you can:

- ➕ Add new coding questions
- 🔍 Search questions by title
- ✏️ Update question details
- 🗑️ Delete questions
- ⭐ Mark questions as favorites
- ✅ Mark questions as solved
- 📊 View coding statistics
- 🔎 Filter questions by language, platform, or difficulty
- 📑 Sort questions for better organization
- 📤 Export reports
- 💾 Backup and restore question data
- 🕒 View recently accessed questions

---

## 🌟 Key Highlights

- 📂 Well-structured project following Object-Oriented Programming principles.
- 💾 Persistent storage using text files with automatic data loading.
- 🔍 Case-insensitive search, filtering, sorting, and duplicate detection.
- ⭐ Favorite and solved question tracking for better progress management.
- 📊 Built-in statistics and analytics for coding practice.
- 🔄 Backup and restore functionality to prevent data loss.
- 📝 Automatic generation of language-specific solution files.
- 🛡️ Input validation to handle invalid or unexpected user input gracefully.

---

## 📸 Screenshots

> Screenshots will be added soon.

Suggested screenshots:

1. Main Menu
2. Add Question
3. Display Questions
4. Search Question
5. Statistics Dashboard
6. Filter & Sort Menu

---

## 🚀 Future Enhancements

- Database integration (SQLite/MySQL)
- User authentication and profiles
- GUI version using Qt
- Cloud synchronization
- Import/Export in CSV and JSON formats
- Advanced search with multiple filters
- Coding progress dashboard
- Difficulty-wise performance tracking

---

## 👨‍💻 Author

**Prakhar**

- GitHub: https://github.com/blazePrakhar
- LinkedIn: https://www.linkedin.com/in/blazeprakhar

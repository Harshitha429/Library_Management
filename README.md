# 📚 Library Management System in C

> [!IMPORTANT]
> **Project Type:** Mini Project  
> **Language:** C  
> **Main concepts:** Structures, pointers, singly linked list (SLL), and file handling

## 🔷 Description

The Library Management System is a C mini project for managing book records. It supports adding, listing, searching, editing, counting, and taking books from the library.

> [!TIP]
> Use the menu displayed by your program to select an operation. The exact menu letters and prompts depend on your implementation.

## 🟩 Features

- Add a new book to the library.
- Display available books.
- Search by book name or author name.
- Edit book information.
- Display the count of a specific book.
- Take a book from the library.
- Save book information using file handling.
- Load saved records when the application restarts.

## 🗂️ Project File Structure

```text
Library-Management/
├── add.c
├── book.c
├── edit.c
├── file.c
├── find.c
├── list.c
├── main.c
├── take.c
├── library.h
├── Makefile
└── README.md
```

`library.h` and `Makefile` are shown here if they are part of your project.

## 🧩 File Description

| File | Purpose |
|---|---|
| `main.c` | Main program and menu |
| `add.c` | Adds new book records |
| `book.c` | Book-related operations |
| `edit.c` | Edits book information |
| `file.c` | Saves and loads book records |
| `find.c` | Searches for books |
| `list.c` | Displays book records |
| `take.c` | Handles taking books from the library |
| `library.h` | Shared declarations and definitions, if included |
| `Makefile` | Compiles the project |

## ⚙️ Compilation

### Option 1: Using Makefile

```bash
make
```

### Option 2: Using GCC

```bash
gcc main.c add.c book.c edit.c file.c find.c list.c take.c -o library
```

## ▶️ Execution

On Linux or a Linux terminal:

```bash
./library
```

> [!WARNING]
> The compilation command assumes all eight `.c` files can be compiled together and that required declarations are available. If your project has a different setup, adjust the command to match your files.

## 🧪 Test Cases

Run these tests using the options and prompts shown by your program. The expected results describe correct behavior; they are **not claims that the tests have already passed**.

| No. | Test | Input / Action | Expected result |
|---:|---|---|---|
| 1 | Start program | Run `./library` | Menu appears without crashing |
| 2 | Add a book | `C Programming`, `Dennis Ritchie`, 300 pages, quantity 3 if supported | Book is added |
| 3 | List books | Choose list option | Added book and author are displayed |
| 4 | Add another book | `The C Language`, `Kernighan`, 250 pages, quantity 2 if supported | Second book is added |
| 5 | Same author | Add a different title by `Dennis Ritchie` | Different titles by the same author are allowed |
| 6 | Duplicate book | Add the same book record again | Duplicate record is rejected according to the program's duplicate rule |
| 7 | Search title — found | Search `C Programming` | Matching book is displayed |
| 8 | Search title — missing | Search `Unknown Book` | Not-found message appears; program continues |
| 9 | Search author — found | Search `Dennis Ritchie` | Matching book or books are displayed |
| 10 | Search author — missing | Search `Unknown Author` | Not-found message appears |
| 11 | Count book — found | Count `C Programming` | Correct available quantity is displayed, if quantity tracking exists |
| 12 | Count book — missing | Count `Unknown Book` | Not-found message appears |
| 13 | Edit title | Change a book to a unique title | Updated title appears in list/search |
| 14 | Edit author | Change an existing author | Updated author is displayed |
| 15 | Edit pages | Change page count to a positive number | Updated page count is displayed |
| 16 | Edit missing book | Edit `Unknown Book` | Not-found message appears; other records remain unchanged |
| 17 | Take a book | Take one copy of a book with copies available | Available quantity decreases by one, if tracked |
| 18 | No copies available | Take a book with zero copies available | Operation is rejected; quantity does not become negative |
| 19 | Take missing book | Take `Unknown Book` | Not-found message appears |
| 20 | Save records | Choose save option | Records are saved without an error |
| 21 | Persistence | Save, quit, restart, then list | Previously saved records are loaded |
| 22 | Empty library | List/search/count with no records | Clear empty/not-found message; no crash |
| 23 | Invalid menu option | Enter an unsupported choice | Input is handled safely |
| 24 | Invalid page count | Enter text or a non-positive page count | Invalid input is rejected or handled safely |
| 25 | Empty title/author | Submit a blank title or author, if possible | Invalid record is rejected or handled clearly |
| 26 | Multiple records | Add several different books and list them | All records appear without unintended duplication or loss |
| 27 | Exit | Choose quit option | Program exits normally |

### Suggested Test Data

| Book title | Author | Pages | Quantity (if supported) |
|---|---|---:|---:|
| C Programming | Dennis Ritchie | 300 | 3 |
| The C Language | Kernighan | 250 | 2 |
| Clean Code | Robert C. Martin | 450 | 1 |
| The Pragmatic Programmer | Andrew Hunt | 320 | 2 |

> [!CAUTION]
> Quantity-related tests apply only if your program tracks available copies. The project requirements say duplicate book entries should not be stored, while different books may share the same author. Confirm that the duplicate check matches your implementation.

> [!NOTE]
> After running each test, mark it **PASS** or **FAIL** based on the actual output. Do not mark a test as passed before verifying it.

## 💾 Data Storage

File handling should save book information so that previously saved records can be loaded when the application restarts.

## 🎯 Project Objective

To develop a library management application using C, structures, pointers, a singly linked list, and file handling.

## 📝 Usage

1. Compile the program.
2. Run the application.
3. Select an operation from the menu.
4. Enter the requested book information.
5. Save the records and exit.
6. Restart the application to verify that saved records are restored.

## 👤 Author

Satya Harshitha Panuganti

---
**Library Management System — C Mini Project**

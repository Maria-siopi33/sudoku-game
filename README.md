<p align="center">
  <img src="2h%20eikona.png" alt="Sudoku Banner" width="100%">
</p>
<p align="center">
  <img src="https://img.shields.io/badge/language-C++-brightgreen" />
</p>


# 🧩 Sudoku Game
## What is Sudoku?

Sudoku is a logic-based number puzzle. The player's goal is to fill a 9x9 grid with numbers from 1 to 9 so that:  
- Each row  
- Each column  
- And each of the nine 3x3 subgrids  

contain all the numbers from 1 to 9 without any repetition.

---

## 🧩 Console Sudoku Game (C++)

This is a **console-based Sudoku game implemented in C++**.  
It offers a user-friendly experience with difficulty levels, a scoring system, and limited hint/auto-fill options to make the game more strategic and engaging.

---

## ✨ Features Included

The Sudoku application includes the following features:

### 🧠 Three Difficulty Levels
Choose between **Easy, Medium**, and **Hard**, with 10, 20, and 30 pre-filled numbers respectively.

### ⭐ Points System
- Earn **+2 points** for every correct number you place.  
- Lose **-2 points** for each mistake.

### 💡 Hint System
- You can request **only one hint** per game.  
- A hint reveals a correct number and its position.

### ⚙️ Auto-Fill Option
- You can use **only one auto-fill** per game.  
- It automatically fills in one correct number.

### ♻️ Retry Mechanism
- If you make **3 mistakes**, you have the option to buy **3 more chances** by spending **5 points**.
  
### ⏱️ Timer
- A **timer** tracks how long it takes you to complete the puzzle.  
- Your **total time is displayed at the end** of the game.
  
### 🧩 Random Puzzle Generator
- The game generates a complete and valid Sudoku solution.  
- Then it removes numbers based on the selected difficulty level.

### 🎮 Interactive Console Gameplay
Play directly from the console by typing your inputs:

- Enter: `row column number` to fill a cell (e.g., `3 4 5`)
- Type `'h'` to request a hint.
- Type `'a'` to use the auto-fill option.
- Type `'0 0 0'` to exit the game.

---

These features combine the logical essence of Sudoku with strategic elements like point management and limited help options — making the game more engaging and challenging for the player.


---
## 📸 Screenshots

### 🧠 Medium Difficulty

<p align="left">
  <img src="medium.png" alt="Sudoku Medium Difficulty" width="400px">
</p>

---

**The game kept going when I asked for the first help:**

<p align="left">
  <img src="sudoku 4.png" alt="Sudoku First Help" width="400px">
</p>

**Then I asked for the second help:**

<p align="left">
  <img src="sudoku 5.png" alt="Sudoku Second Help" width="400px">
</p>

---

**The game kept going after the first mistake:**

<p align="left">
  <img src="λάθος.png" alt="Sudoku First Mistake" width="400px">
</p>

**The game kept going after the second mistake:**

<p align="left">
  <img src="λαθος 2.png" alt="Sudoku Second Mistake" width="400px">
</p>

---

**I made a third mistake, but since I had enough points, I could buy extra chances:**

<p align="left">
  <img src="agora prospatheivn.png" alt="Sudoku Buy Chances" width="400px">
</p>

---

**I finished the game successfully:**

<p align="left">
  <img src="telos paixnidiou.png" alt="Sudoku Game Completed" width="400px">
</p>

💻 Technologies Used
Language: C++

Libraries: Standard C++ library (vector, iostream, cstdlib, etc.)

Tool: LaTeX Beamer for presentation.


- **Future extensions of the project:**
  - Development of a graphical user interface (GUI).
  - Addition of game-saving and resume functionality.
  - Support for multiple players with a leaderboard system.
  - Inclusion of a time limit or additional challenges (e.g., no hints allowed).

## 🎮 Demo Video

You can watch a full demonstration of the Sudoku game here:  
👉 [Click here to view the demo on Dropbox](https://www.dropbox.com/scl/fo/bfllfqgtvtanho4yyidyf/AEyplU1sXJVaLEChBEWjLls?rlkey=su9bmwsy5ib6wkyfa8eo0xzx1&st=7048rjel&dl=0)

The demo includes the following:

1. Video showing the main menu
2. Difficulty level selection: *Easy*, *Medium*, *Hard*
3. Use of the *Hint* function
4. Use of the *Auto-fill* function
5. Handling *mistakes* (with enough points to buy extra chances)
6. Handling *mistakes* (without enough points)
7. Exiting the game




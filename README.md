# MysteryWorld 🧩

A simple console-based game simulation built in C++ as part of a programming assignment for the **IY4101 Object-Oriented Programming** module at Kaplan International College.

> 🎯 This project was created to learn, apply, and demonstrate key **Object-Oriented Programming (OOP)** principles including **encapsulation, inheritance, polymorphism, and abstraction**.

---

## 🚀 Features

- A 10x10 game grid representing a level in the game.
- Supports both **inanimate** entities (Stone, Hole) and **animate** entities (Human, Dragon, Monster).
- Unique movement logic for each animated character:
  - Humans move right or randomly.
  - Dragons move randomly and lose random health.
  - Monsters move by strength.
- Entities placed randomly on the grid with no overlaps.
- Interactive menu system in the terminal.

---

## 🧱 Object-Oriented Design

This project follows solid OOP design with:

- `Entity` as an abstract base class
- `InanimateEntity` and `AnimateEntity` subclasses
- Polymorphic behavior via `display()` and `move()` methods
- Strong use of **inheritance**, **encapsulation**, and **abstraction**

---

## 🧪 Menu Options
1 - Display Room

2 - Move All Animated Entities

3 - Display Entity by Coordinates

4 - Reset Room

5 - Exit

## 💡 Technologies Used

- C++17
- Command-line Interface (CLI)
- Object-Oriented Programming

## 📚 Learning Purpose

This project is an academic exercise to apply:
- Class design and inheritance hierarchies
- Virtual methods and polymorphism
- C++ memory management and modularity
- Git version control for C++ projects

---

## 🧑‍💻 Author

**Yanis Kaced**  
Computer Science Student  
Kaplan International College London

---

## 📜 License

This project is for educational purposes and part of a coursework assignment. Not intended for commercial use.

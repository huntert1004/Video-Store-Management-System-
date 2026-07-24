# Video Database

A cross-platform desktop application built with **C++**, **Qt 6 Widgets**, and **nlohmann/json**. The application allows users to manage a video inventory through a graphical interface, with all video data stored locally in a JSON file.

The project uses **CMake** for building and **FetchContent** to automatically download the **nlohmann/json** library during the first build.

---

# Features

* Cross-platform (Windows, Linux, and macOS)
* Desktop GUI built with Qt Widgets
* Local JSON data storage
* C++17
* CMake build system
* Automatic download of the JSON library

---

# Requirements

## Required Software

* CMake 3.16 or newer
* A C++17 compatible compiler

  * GCC
  * Clang
  * MSVC (Visual Studio 2022 or newer)
* Git
* Internet connection (only required the first build to download the JSON library)

## Qt 6

This project uses **Qt 6 Widgets**.

Qt must be installed before building the project.

### Linux (Ubuntu / Pop!_OS)

```bash
sudo apt update
sudo apt install qt6-base-dev qt6-base-dev-tools libgl1-mesa-dev
```

### Windows

Install **Qt 6** using the Qt Online Installer or another supported package manager.

### macOS

Install **Qt 6** using the Qt Online Installer or Homebrew.

---

# Clone the Repository

```bash
git clone https://github.com/<your-username>/Video-Store-Management-System-.git
cd VideoDatabase
```

Replace `<your-username>` with your GitHub username.

---

# Build the Project

From the project root directory:

```bash
cmake -S . -B build
cmake --build build
```

During the first build, CMake automatically downloads the **nlohmann/json** library.

---

# Run the Application

## Windows

Visual Studio Generator

```bash
.\build\Debug\VideoDatabase.exe
```

Ninja or another single-configuration generator

```bash
.\build\VideoDatabase.exe
```

## Linux / macOS

```bash
./build/VideoDatabase
```

---

# Clean Rebuild

If you need to completely rebuild the project:

```bash
rm -rf build

cmake -S . -B build
cmake --build build
```

On Windows, simply delete the `build` folder and run the build commands again.

---

# Project Structure

The project is organized so that each directory has a single responsibility.

```
VideoDatabase
│
├── database/
│   └── videos.json
│
├── src/
│   ├── main.cpp
│   │
│   ├── model/
│   │
│   ├── pages/
│   │
│   └── windows/
│
├── CMakeLists.txt
└── README.md
```

## src/main.cpp

This is the entry point of the application.

It creates the `QApplication` object, initializes the program, creates the main application window, and starts the Qt event loop.

Think of this as the starting point of the entire application.

---

## src/model/

The **model** directory contains the classes responsible for managing application data.

These classes:

* Read data from `database/videos.json`
* Save new videos
* Update existing videos
* Remove videos
* Convert between C++ objects and JSON

The model layer is the **only** part of the application that interacts directly with the JSON database.

---

## src/pages/

The **pages** directory contains the primary content displayed inside the application.

Each page represents a different screen or view of the program.

Examples include:

* Home Page
* Add Video Page
* Rent Video Page
* Return Video Page
* Inventory Page

Pages are responsible for displaying information and handling user interaction.

---

## src/windows/

The **windows** directory contains the application's top-level windows.

These classes manage:

* Window creation
* Navigation between pages
* Overall application layout
* Window-specific behavior

A window acts as a container that displays one or more pages.

---

## database/videos.json

This file serves as the application's database.

All video information is stored in JSON format, including:

* Title
* Genre
* Release year
* Available copies
* Availability status

The file is automatically created or updated by the application as videos are added or modified.

---

# Technologies Used

* C++17
* Qt 6 Widgets
* CMake
* nlohmann/json
* JSON

---

# Notes

* The project uses the C++17 standard.
* `nlohmann/json` is downloaded automatically during the first build.
* Qt 6 must already be installed on the system.
* Video information is stored locally in `database/videos.json`.
* The application does not require a traditional SQL database.

---

# License

This project was created for educational purposes.

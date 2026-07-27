# Video Database

A cross-platform desktop application built with **C++**, **Qt 6 Widgets**, and **nlohmann/json**.

The application provides a graphical interface for managing a video inventory. Video information is stored locally in a JSON file.

The project uses **CMake** to configure and build the application on Windows, Linux, and macOS.

---

# Features

* Cross-platform support for Windows, Linux, and macOS
* Desktop interface built with Qt 6 Widgets
* Local JSON data storage
* Video inventory display
* Add, rent, and return video functionality
* C++17
* CMake build system

---

# Requirements

The following software and libraries must be installed before building the project:

* Git
* CMake 3.16 or newer
* A C++17-compatible compiler
* Qt 6 with the Widgets component
* nlohmann/json

Supported compilers include:

* GCC
* Clang
* MSVC
* MinGW

CMake does not download either dependency. Qt 6 and nlohmann/json must already be installed on the computer.

---

# Install Dependencies

## Linux — Ubuntu or Pop!_OS

Install the compiler, CMake, Qt 6, OpenGL development files, and nlohmann/json:

```bash
sudo apt update

sudo apt install \
    build-essential \
    cmake \
    git \
    qt6-base-dev \
    qt6-base-dev-tools \
    libgl1-mesa-dev \
    nlohmann-json3-dev
```

After installation, CMake should be able to locate both Qt 6 and nlohmann/json automatically.

---

## Windows

### 1. Install a C++ compiler

Install one of the following:

* Visual Studio 2022 with **Desktop development with C++**
* MinGW through the Qt installer

### 2. Install Qt 6

Download and run the Qt Online Installer.

During installation, select a Qt kit that matches your compiler.

Examples:

```text
MSVC 2022 64-bit
```

or:

```text
MinGW 64-bit
```

Do not mix compiler types.

For example:

* Qt MSVC must be built with Visual Studio
* Qt MinGW must be built with MinGW

### 3. Install nlohmann/json

One Windows option is vcpkg.

Clone and prepare vcpkg:

```powershell
git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
cd C:\vcpkg
.\bootstrap-vcpkg.bat
```

Install nlohmann/json:

```powershell
.\vcpkg install nlohmann-json:x64-windows
```

When configuring the project, provide the vcpkg toolchain file:

```powershell
cmake -S . -B build `
  -DCMAKE_TOOLCHAIN_FILE="C:\vcpkg\scripts\buildsystems\vcpkg.cmake"
```

CMake may also need the location of Qt:

```powershell
cmake -S . -B build `
  -DCMAKE_TOOLCHAIN_FILE="C:\vcpkg\scripts\buildsystems\vcpkg.cmake" `
  -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\msvc2022_64"
```

Replace the Qt path with the actual Qt version and kit installed on the computer.

For example:

```text
C:\Qt\6.8.3\msvc2022_64
```

When using MinGW, the path may look similar to:

```text
C:\Qt\6.8.3\mingw_64
```

---

## macOS

Install Homebrew if it is not already installed.

Then install CMake, Qt 6, and nlohmann/json:

```bash
brew install cmake qt nlohmann-json
```

CMake may need the Qt installation path:

```bash
cmake -S . -B build \
  -DCMAKE_PREFIX_PATH="$(brew --prefix qt)"
```

---

# Clone the Repository

```bash
git clone https://github.com/<your-username>/Video-Store-Management-System-.git
cd Video-Store-Management-System-
```

Replace `<your-username>` with the GitHub username or organization that owns the repository.

---

# Build the Project

## Linux

From the root project directory:

```bash
cmake -S . -B build
cmake --build build
```

---

## Windows with Visual Studio

Configure the project:

```powershell
cmake -S . -B build `
  -DCMAKE_TOOLCHAIN_FILE="C:\vcpkg\scripts\buildsystems\vcpkg.cmake" `
  -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\msvc2022_64"
```

Build the project:

```powershell
cmake --build build --config Debug
```

Replace the Qt path with the actual installation path.

---

## Windows with MinGW

Open the Qt MinGW terminal or ensure MinGW is available in the system PATH.

Configure the project:

```powershell
cmake -S . -B build `
  -G "MinGW Makefiles" `
  -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\mingw_64"
```

Build the project:

```powershell
cmake --build build
```

The installed nlohmann/json package must also be available to CMake.

---

## macOS

```bash
cmake -S . -B build \
  -DCMAKE_PREFIX_PATH="$(brew --prefix qt)"

cmake --build build
```

---

# Run the Application

The application should be run from the root project directory so it can locate:

```text
database/videos.json
```

## Linux

```bash
./build/VideoDatabase
```

## macOS

```bash
./build/VideoDatabase
```

## Windows with Visual Studio

Debug build:

```powershell
.\build\Debug\VideoDatabase.exe
```

Release build:

```powershell
.\build\Release\VideoDatabase.exe
```

## Windows with MinGW

```powershell
.\build\VideoDatabase.exe
```

---

# Clean Rebuild

A clean rebuild removes old CMake configuration files and recompiles the application.

## Linux or macOS

```bash
rm -rf build

cmake -S . -B build
cmake --build build
```

## Windows PowerShell

```powershell
Remove-Item -Recurse -Force build

cmake -S . -B build
cmake --build build --config Debug
```

Remember to include the Qt or vcpkg paths during configuration when they are required.

---

# Project Structure

```text
Video-Store-Management-System-
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

Each directory has a specific responsibility.

---

## `src/main.cpp`

This is the entry point of the application.

It:

* Creates the Qt `QApplication` object
* Creates the initial application window
* Displays the application
* Starts the Qt event loop

The program begins execution from this file.

---

## `src/model/`

The `model` directory contains classes that work with application data.

The model classes are responsible for:

* Reading video data
* Saving new videos
* Updating videos
* Removing videos
* Converting C++ objects to JSON
* Converting JSON into C++ objects

The model directory is the only part of the project that should directly interact with:

```text
database/videos.json
```

Pages and windows should call model methods instead of reading or writing the JSON file directly.

---

## `src/pages/`

The `pages` directory contains the main content displayed to the user.

Each directory inside `pages` represents a separate page or feature.

Examples include:

```text
pages/
├── home_page/
├── add_video_page/
├── rent_video_page/
└── return_video_page/
```

Pages are responsible for:

* Creating page layouts
* Displaying application data
* Providing buttons, forms, tables, and labels
* Handling user interaction
* Calling model methods when data needs to be read or changed

Pages should not directly edit the JSON database.

---

## `src/windows/`

The `windows` directory contains the application's top-level windows.

Window classes are responsible for:

* Creating application windows
* Displaying pages
* Managing navigation
* Controlling the overall application layout
* Opening dialogs or additional windows

A window acts as the container for one or more pages.

---

## `database/videos.json`

This file acts as the application's local database.

It stores video information such as:

* Title
* Genre
* Release year
* Number of available copies

Example:

```json
[
    {
        "title": "The Matrix",
        "genre": "Science Fiction",
        "year": 1999,
        "copies_available": 4
    }
]
```

The model classes read from and write to this file.

The application should be launched from the project root so the relative path remains:

```text
database/videos.json
```

---

# CMake Configuration

The project uses these manually installed dependencies:

```cmake
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(nlohmann_json CONFIG REQUIRED)
```

The application links them using:

```cmake
target_link_libraries(
    VideoDatabase
    PRIVATE
        Qt6::Widgets
        nlohmann_json::nlohmann_json
)
```

If CMake reports that it cannot find Qt or nlohmann/json, the dependency is either:

* Not installed
* Installed for a different compiler
* Not included in CMake's search paths

---

# Common Errors

## Qt 6 could not be found

Example:

```text
Could not find Qt6Config.cmake
```

Provide the Qt installation path:

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH="/path/to/Qt"
```

On Windows:

```powershell
cmake -S . -B build `
  -DCMAKE_PREFIX_PATH="C:\Qt\6.x.x\msvc2022_64"
```

---

## nlohmann/json could not be found

Example:

```text
Could not find nlohmann_jsonConfig.cmake
```

Confirm that the development package is installed.

On Ubuntu or Pop!_OS:

```bash
sudo apt install nlohmann-json3-dev
```

On macOS:

```bash
brew install nlohmann-json
```

On Windows with vcpkg:

```powershell
C:\vcpkg\vcpkg install nlohmann-json:x64-windows
```

Then configure CMake using the vcpkg toolchain file.

---

## Could not open `videos.json`

Run the program from the project root:

```bash
./build/VideoDatabase
```

Confirm that the file exists:

```text
database/videos.json
```

The file should contain at least an empty JSON array:

```json
[]
```

---

# Technologies Used

* C++17
* Qt 6 Widgets
* CMake
* nlohmann/json
* JSON

---

# Notes

* Qt 6 must be installed manually.
* nlohmann/json must be installed manually.
* CMake does not download either library.
* The installed Qt kit must match the compiler being used.
* Video data is stored locally in `database/videos.json`.
* The application does not require an SQL database.
* Build files should remain inside the `build` directory.
* The `build` directory should not be committed to Git.

---

# License

This project was created for educational purposes.

# File Search Application

This C++ application allows you to search for a file by its name in a multi-threaded manner. The search starts from the root directory ("/" on Unix-like systems or "C:\" on Windows OS) and uses multiple threads to speed up the search process.

## Requirements

- C++17 compatible compiler (e.g., GCC or G++)
- Make utility (for building the project)
- Git (optional, for version control)

## Getting Started

1. Clone the repository to your local machine:

```bash
git clone https://github.com/vitalik-ez/File-Search-Application.git
cd file-search-application
```
2. Compile the project using the provided Makefile:
```bash
make all
```
3. Run the executable to search for a file:
```bash
./main <root_directory> <filename>
```
Replace <root_directory> with the path to the directory from which you want to start the search, and <filename> with the name of the file you want to search for. The application will search for the file in the specified root directory and its subdirectories and print the full path if found.

## Additional Information
* The application uses a static library (libsearchlib.a) to perform the file search. The library's compilation is handled separately from the application's compilation.
* The search process utilizes multiple threads, making it faster for large directory structures and allowing concurrent searching of multiple subdirectories.
* Please ensure that you provide a valid and accessible root directory. Running the application with restricted access directories (e.g., system directories) may lead to permission issues.
* Running the application with elevated privileges (e.g., using sudo) is not recommended as it may cause issues with file permissions.
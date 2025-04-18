# **Shark File Tool**

**Shark** is a powerful, all-in-one command-line tool designed to simplify and centralize file operations. Instead of juggling multiple utilities for tasks like copying, moving, deleting, and searching for files, **Shark** consolidates them into a single, easy-to-use tool. With modern, intuitive commands, **Shark** streamlines your workflow, allowing you to manage files, manipulate archives, adjust permissions, synchronize directories, and much more—all with a single tool. Whether you're working with local files or need to push/pull files remotely, **Shark** handles it with speed and efficiency. Say goodbye to the clutter of multiple command tools—**Shark** does it all in one bite.

## 🦈 **shark** CLI Command Reference

| Command                          | Description                                 |
|----------------------------------|---------------------------------------------|
| `--help`, `-h`                   | Show this help message                      |
| `--version`, `-v`                | Show version information                    |
| `open <file> <mode>`            | Open a file with specified mode             |
| `copy <src> <dst>`              | Copy file from source to destination        |
| `append <file> <data>`          | Append string data to a file                |
| `info <file>`                   | Show info about a file                      |
| `remove <file>`                 | Delete a file                               |
| `backup <file> <suffix>`        | Backup a file with a suffix                 |
| `read <file>`                   | Read and print contents of a file           |
| `write <file> <data>`           | Overwrite a file with given data            |
| `rename <oldname> <newname>`    | Rename a file                               |

---

## **Prerequisites**

Ensure you have the following installed before starting:

- **Meson Build System**: This project relies on Meson. For installation instructions, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html).

## **Setting Up Meson Build**

1. **Install Meson**:
    - Follow the installation guide on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## **Setting Up, Compiling, Installing, and Running the Project**

1. **Clone the Repository**:

    ```sh
    git clone https://github.com/fossillogic/shark.git
    cd shark
    ```

2. **Configure the Build**:

    ```sh
    meson setup builddir
    ```

3. **Compile the Project**:

    ```sh
    meson compile -C builddir
    ```

4. **Install the Project**:

    ```sh
    meson install -C builddir
    ```

5. **Run the Project**:

    ```sh
    shark
    ```

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/shark).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/fossil-app/shark).

## **License**

This project is licensed under the [Mozilla Public License](LICENSE).

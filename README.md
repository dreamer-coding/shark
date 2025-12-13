<p align="center">
    <img src=".github/logo.png" alt="Shark Tool Logo" width="620"/>
</p>

### A Command-Line Administration Power Utility by **Fossil Logic**

Shark Tool is the ultimate **all-in-one system and administration utility**. Designed for system administrators, DevOps engineers, and power users, Shark unifies essential tasks—ranging from user and permission management, process monitoring, and system configuration, to file management, automation, and analysis—into a single, powerful command-line interface. Its unique commands, such as `grammar` for advanced text analysis, `summary` for structured file summaries, and `introspect` for deep file inspection, set Shark apart by providing administrative capabilities rarely found in traditional CLI utilities.

---

## Features

- Comprehensive file and directory operations (`show`, `copy`, `move`, `delete`, `rename`, `create`)
- Powerful archive creation, extraction, and listing (zip, tar, gz)
- Advanced recursive search by name or content with filtering options
- Smart file timestamp and metadata management
- Cross-platform compatibility (Linux, macOS, Windows)
- Command palette for quick access to all features
- Grammar analysis, correction, and tone detection via SOAP API
- Structured file summaries and statistics (keywords, topics, entropy)
- File synchronization and backup with flexible options
- Real-time file monitoring and change detection

## Command Palette

---

### Core File Operations

| **Command** | **Description** | **Common Flags** |
|-------------|-----------------|-----------------|
| `show` | Display files and directories. | `-a, --all` Show hidden files<br>`-l, --long` Detailed info<br>`-h, --human` Human-readable sizes<br>`-r, --recursive` Include subdirs<br>`-d, --depth <n>` Limit recursion depth<br>`--as` Format: **list**, **tree**, **graph**<br>`--time` Show timestamps<br>`--threads <n>` Number of threads to use |
| `move` | Move or rename files/directories. | `-f, --force` Overwrite without prompt<br>`-i, --interactive` Ask before overwrite<br>`-b, --backup` Backup before move<br>`--threads <n>` Parallel moves |
| `copy` | Copy files or directories. | `-r, --recursive` Copy subdirectories<br>`-u, --update` Only copy newer<br>`-p, --preserve` Keep permissions/timestamps<br>`--threads <n>` Parallel copy |
| `remove` / `delete` | Delete files or directories. | `-r, --recursive` Delete contents<br>`-f, --force` No confirmation<br>`-i, --interactive` Confirm per file<br>`--trash` Move to system trash<br>`--threads <n>` Parallel deletion |
| `rename` | Rename files or directories. | `-f, --force` Overwrite target<br>`-i, --interactive` Confirm before overwrite |
| `create` | Create new directories or files. | `-p, --parents` Create parent dirs<br>`-t, --type <file|dir>` Specify type |
| `search` | Find files by name or content. | `-r, --recursive` Include subdirs<br>`-n, --name <pattern>` Match filename<br>`-c, --content <pattern>` Search in file contents<br>`-i, --ignore-case` Case-insensitive<br>`--regex` Regex mode<br>`--glob` Glob pattern<br>`--type <file/dir/link>` Object type filter<br>`--size <expr>` Size filter<br>`--mtime <expr>` Modified time<br>`--threads <n>` Parallel search |
| `archive` | Create, extract, or list archives. | `-c, --create` New archive<br>`-x, --extract` Extract contents<br>`-l, --list` List archive<br>`-f <format>` Format: zip/tar/gz<br>`-p, --password <pw>` Encrypt archive<br>`--threads <n>` Parallel processing |
| `view` | Output file contents to terminal. | `-n, --number` Number all lines<br>`-b, --non-blank` Number non-empty lines<br>`-s, --squeeze` Remove blank lines<br>`-h, --head <n>` First *n* lines<br>`-t, --tail <n>` Last *n* lines<br>`--time` Show timestamps |
| `compare` | Compare two files/directories (text or binary). | `-t, --text` Line diff<br>`-b, --binary` Binary diff<br>`--context <n>` Show context lines<br>`--ignore-case` Ignore case differences<br>`--threads <n>` Parallel compare |
| `sync` | Synchronize files/directories. | `-r, --recursive` Include subdirs<br>`-u, --update` Copy only newer<br>`--delete` Remove extraneous files from target<br>`--threads <n>` Parallel sync |
| `watch` | Continuously monitor files or directories. | `-r, --recursive` Include subdirs<br>`-e, --events <list>` Filter events: create/modify/delete<br>`-t, --interval <n>` Poll interval in seconds |
| `rewrite` | Modify or update file contents, timestamps, or size. | `-a, --append` Append instead of overwrite<br>`--in-place` Edit in place<br>`--access-time` Update access time<br>`--mod-time` Update mod time<br>`--size <n>` Set exact file size<br>`--threads <n>` Parallel rewrite |
| `introspect` | Examine file contents, type, or metadata. | `--head <n>` First n lines<br>`--tail <n>` Last n lines<br>`--count` Count lines/words/bytes<br>`--type` Show MIME/type<br>`--fson` FSON output<br>`--threads <n>` Parallel analysis |
| `manage` | Manage user and group permissions. | `--user <name>` Specify user<br>`--group <name>` Specify group<br>`--add <perm>` Add permission<br>`--remove <perm>` Remove permission<br>`--list` List permissions<br>`--set <perm>` Set permissions explicitly |
| `grammar` | Grammar analysis, correction, tone detection, and risk scanning (SOAP API). | `--check` Run grammar check<br>`--fix` Auto-correct<br>`--sanitize` Remove meme/rot-brain<br>`--suggest` Suggest alternatives<br>`--tone` Detect tone<br>`--detect <type>` Detector: ragebait, clickbait, spam, woke, bot, sarcasm, formal, snowflake, offensive, neutral, hype, quality, political, conspiracy, marketing, technobabble<br>`--threads <n>` Parallel document analysis |
| `summary` | Generate a structured summary of files (text, logs, code, docs). | `-l, --lines <n>` Limit lines<br>`--auto` Auto-detect file type<br>`--keywords` Extract keywords<br>`--topics` Topic clustering<br>`--stats` File statistics<br>`--fson` FSON summary<br>`--threads <n>` Parallel summarization |
| `storage` | Manage disks and filesystems. | `--dedupe` Deduplicate<br>`--catalog` Catalog<br>`--index` Index<br>`--snapshot` Snapshot<br>`--prune` Prune<br>`--threads <n>` Parallel scanning |
| `play` | Play classic text-based terminal games. | `--list` List available games<br>`--rules` Show game rules<br>`--seed <n>` Deterministic randomness<br>`--rounds <n>` Number of rounds<br>`--difficulty <easy/normal/hard>` Set difficulty<br>`--stats` Show win/loss stats<br>`--reset` Reset stored stats<br>`--ascii` Force ASCII output<br>`--no-color` Disable ANSI colors<br>`--fson` Structured results<br>`--sandbox` Disable filesystem/network |
| `help` | Display help and examples. | `--examples` Usage examples<br>`--man` Full manual |

---

### Global Flags (Available to All Commands)

| **Flag** | **Description** |
|-----------|-----------------|
| `--help` | Show command help. |
| `--version` | Display Shark Tool version. |
| `--name` | Display the current user or session name. |
| `-v, --verbose` | Enable detailed output. |
| `-q, --quiet` | Suppress standard output. |
| `--dry-run` | Simulate actions without changes. |
| `--color` | Colorize output where applicable. |
| `--clear` | Clear the terminal or output screen before running. |
| `--time` | Display timestamps in output. |

---

### Usage Examples

| **Example** | **Description** |
|--------------|-----------------|
| `shark archive -c -f tar project.tar src/` | Create a TAR archive from the `src/` directory. |
| `shark compare -t main_v1.c main_v2.c --context 5` | Show a line-by-line diff of two files with 5 lines of context. |
| `shark copy -rp src/ backup/` | Recursively copy the `src/` directory to `backup/`, preserving permissions and timestamps. |
| `shark create -p -t dir logs/archive/2024/` | Create a nested directory structure for logs. |
| `shark grammar --check --tone notes.txt` | Run a grammar check and detect tone in a text file. |
| `shark help --examples` | Show usage examples for Shark commands. |
| `shark introspect --mime report.pdf` | Show the MIME type of a file. |
| `shark manage --add-user alice --add-group devs` | Add a user `alice` and create group `devs`. |
| `shark move -i -b old.txt archive/old.txt` | Move a file interactively, creating a backup before moving. |
| `shark play --game dice` | Play one round of dice. |
| `shark play --game rps --rounds 3` | Play 3 rounds of rock-paper-scissors. |
| `shark play --game guess --difficulty medium` | Play guess-the-number on medium difficulty. |
| `shark process --list` | List all running processes. |
| `shark rename -i draft.md final.md` | Rename a file with confirmation before overwriting the target. |
| `shark remove -r --trash temp/` | Recursively move the `temp/` directory and its contents to the system trash. |
| `shark search -rc "config"` | Recursively search for the string "config" inside files. |
| `shark show -alh --as=tree --time` | List all files (including hidden) in long, human-readable format as a tree, with timestamps. |
| `shark storage --dedupe --catalog ~/Documents/` | Deduplicate files and create a catalog of your Documents directory. |
| `shark summary --auto --keywords --stats article.md` | Generate an automatic structured summary with keywords and statistics for a document. |
| `shark sync -ru src/ dest/` | Synchronize files from `src/` to `dest/`, copying only newer files recursively. |
| `shark system --info --disk --memory` | Show system information, disk usage, and memory stats. |
| `shark watch -r -e create,delete src/` | Monitor the `src/` directory recursively for file creation and deletion events. |
| `shark rewrite -i --append log.txt "New entry"` | Append a new entry to a log file in-place. |
| `shark view -n -h 20 --time notes.txt` | View the first 20 lines of a file with line numbers and timestamps. |

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
    shark --help
    ```

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/shark).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/shark/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).

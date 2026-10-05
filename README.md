# The hangman

This is the game named "the hangman".
It works on Linux and Mac OS.

### Dictionary file
The file that contain the words is in italian.<br>If you want to insert a vocabulary just create a file called "vocabulary.txt", inserting the words in your language
The words must contains letter between a and z. Other characters are not included in the <b>insert</b> function.

### Build
To compile the project use the provided `Makefile`:

```
make
```

This command builds a `hangman` executable by compiling `main.c` and `hangman.c` separately and linking them together. Clean the generated files with:

```
make clean
```

# Simple Shell in C

This is a basic implementation of a shell in the C programming language. The purpose of this shell is to demonstrate the fundamental concepts of a Unix-like command-line interface.

## Features

- Accepts and executes simple shell commands.
- Supports basic command-line operations like redirection (`>`, `<`) and piping (`|`).
- Provides a basic error handling mechanism.
- Allows users to exit the shell using the `exit` command.

## How to Compile

To compile the shell, use the following command:

bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## How to Run

To run the shell, simply execute the compiled binary:

bash
./hsh


## Usage

Once the shell is running, you can enter commands just like you would in a standard Unix shell. Here are some examples:

- Run a command: `ls`, `pwd`, `echo Hello, World!`
- Redirect output to a file: `ls > output.txt`
- Redirect input from a file: `sort < input.txt`
- Use pipes to combine commands: `ls | grep shell`

To exit the shell, type:

bash
exit


## Examples

Here are some usage examples to help you get started:

1. Running basic commands:

   bash
   $ ls
   $ pwd
   $ echo Hello, World!

2. Redirecting output to a file:
iiiiiiiii
   bash
   $ ls > output.txt

3. Redirecting input from a file:

   bash
   $ sort < input.txt

4. Using pipes to combine commands:

   bash
   $ ls | grep shell

## Limitations

- This shell is a simplified version and may not handle all edge cases or advanced features found in full-fledged shells like Bash.
- Error handling is minimal, and there may be room for improvement.

## Contributing

Ottah Samuel <michaelsamuelpedro@gmail.com>

## License

This project is open-source and distributed under the [MIT License](LICENSE).

This extended README provides more details about compiling, running, usage examples, contributing, and licensing for your simple shell project. Feel free to customize it further according to your project's specific needs.

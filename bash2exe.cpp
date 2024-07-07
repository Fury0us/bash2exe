#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// Function to encrypt a file using OpenSSL
void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& password) {
    std::string command = "openssl enc -aes-256-cbc -in " + inputFile + " -out " + outputFile + " -pass pass:" + password;
    system(command.c_str());
}

// Function to compile a Bash script to an executable
void compileScript(const std::string& scriptFile, const std::string& outputFile) {
    std::string command = "gcc -o " + outputFile + " -x c - ";
    std::ifstream script(scriptFile);
    std::string line;
    while (std::getline(script, line)) {
        command += line + "\n";
    }
    system(command.c_str());
}

int main() {
    // Ask user for input Bash script file
    std::string scriptFile;
    std::cout << "Enter the Bash script file: ";
    std::getline(std::cin, scriptFile);

    // Ask user for input password for encryption
    std::string password;
    std::cout << "Enter the password for encryption: ";
    std::getline(std::cin, password);

    // Ask user for output encrypted executable file
    std::string outputFile;
    std::cout << "Enter the output encrypted executable file: ";
    std::getline(std::cin, outputFile);

    // Compile the Bash script to a temporary executable
    std::string tempFile = "temp.exe";
    compileScript(scriptFile, tempFile);

    // Encrypt the temporary executable
    encryptFile(tempFile, outputFile, password);

    // Remove the temporary file
    std::remove(tempFile.c_str());

    std::cout << "Encrypted executable file generated: " << outputFile << std::endl;

    return 0;
}

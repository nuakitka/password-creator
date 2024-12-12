// Password creator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

void file_creating(const std::string password);

void generate_password(int length, bool use_uppercase, bool use_lowercase, bool use_digits, bool use_special) {
    const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lower = "abcdefghijklmnopqrstuvwxyz";
    const std::string digits = "0123456789";
    const std::string special = "!@#$%^&*()_-+=[]{}|;:,.<>?";

    std::string characters;
    if (use_uppercase) characters += upper;
    if (use_lowercase) characters += lower;
    if (use_digits) characters += digits;
    if (use_special) characters += special;

    std::string password;
    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        password += characters[index];
    }
	file_creating(password);
}

void file_creating(std::string password) 
{
    cout << "Enter the file name" << endl;
	std::string file_name;
	ofstream out;
    cin.ignore();
	std::getline(std::cin, file_name);
	// используем getline тк в названии могут быть пробелы
	out.open("D:/Password creator/passwords/" + file_name);
	//создаем файл с названием, которое передаем в file_name
	if (out.is_open())
	{
		out << password << endl;
        std::cout << "Password saved to " << file_name << ".txt" << std::endl;
        std::cout << "Your password is: " << password;
    }
    else {
        std::cout << "Error opening file!" << std::endl;
	}
	out.close();
}


int main()
{
    srand(static_cast<unsigned int>(time(0))); // Инициализируем генератор случайных чисел

    int length;
    cout << "Enter the length of the password: ";
    cin >> length;
    cin.ignore(); // Игнорируем оставшийся символ новой строки после ввода числа

    bool use_uppercase, use_lowercase, use_digits, use_special;
    cout << "Use uppercase letters? (1 for yes, 0 for no): ";
    cin >> use_uppercase;
    cout << "Use lowercase letters? (1 for yes, 0 for no): ";
    cin >> use_lowercase;
    cout << "Use digits? (1 for yes, 0 for no): ";
    cin >> use_digits;
    cout << "Use special characters? (1 for yes, 0 for no): ";
    cin >> use_special;

    generate_password(length, use_uppercase, use_lowercase, use_digits, use_special);
    return 0;
}



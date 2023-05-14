#include "Trie.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	setlocale(LC_ALL, "RU");

	TrieNode* root = getNewNode();

	writeInTrie(root);

	int variant;
	std::string text;
	while (text != "ex") {
		std::cout << "\033[33m" << "Введите префикс(часть слова состоящая из маленьких букв английского алфавита)" << std::endl;
		std::cout << "\033[1;31m"  << "'ex' - Выход!" << "\033[32m" << std::endl;
		std::cin >> text;
		if (text != "ex") {
			std::vector<std::string> words = searchForWordsByPrefix(root, text);
			for (auto i = 0; i < words.size(); ++i)
			{
				std::cout << "\033[36m" << i << " - " << words[i] << std::endl;
			}
			(std::cin >> variant).get();
			std::cout << "\033[32m";
			text.clear();
			for (size_t i = 0; i < words.size(); ++i)
			{
				if (!((variant >= 0) && (variant < (words.size()))))
				{
					std::cout << "Не верный выбор" << std::endl;
					break;
				}
				else
				{
					std::cout << words[variant] << std::endl;
					break;
				}
			}
			std::cout << text << std::endl;
		}
	}
	return 0;
}
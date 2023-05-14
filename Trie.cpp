#include <iostream>
#include "Trie.h"

// Возвращет новый узел с пустыми детьми
TrieNode* getNewNode(void)
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве литового т.е. конец слова
void insert(TrieNode* root, std::string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфавите через смещение относительно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index]) {
            node->children[index] = getNewNode();
        }
        node = node->children[index];
    }
    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

std::vector<std::string> searchForWordsByPrefix(struct TrieNode* root, std::string& key)
{
    std::vector<std::string> res;
    struct TrieNode* node = root;
    char buf[ALPHABET_SIZE];
    int ind = 0;

    for (size_t i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        buf[ind] = key[i];
        ind++;
        if (!node->children[index])
            return res;

        node = node->children[index];
    }
    writeInVector(node, buf, ind, res);
    return res;
}

void writeInVector(struct TrieNode* root, char buf[], int ind, std::vector<std::string>& res) {
    if (root->isEndOfWord) {
        buf[ind] = '\0';
        res.push_back(buf);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            buf[ind] = i + 'a';
            writeInVector(root->children[i], buf, ind + 1, res);
        }
    }
}

void writeInTrie(struct TrieNode* root)
{
    insert(root, "air");
    insert(root, "animal");
    insert(root, "answer");
    insert(root, "apple");
    insert(root, "area");
    insert(root, "art");
    insert(root, "bird");
    insert(root, "body");
    insert(root, "book");
    insert(root, "boy");
    insert(root, "brother");
    insert(root, "business");
    insert(root, "can");
    insert(root, "canoe");
    insert(root, "car");
    insert(root, "case");
    insert(root, "change");
    insert(root, "child");
    insert(root, "children");
    insert(root, "city");
    insert(root, "clear");
    insert(root, "color");
    insert(root, "company");
    insert(root, "day");
    insert(root, "death");
    insert(root, "dog");
    insert(root, "door");
    insert(root, "east");
    insert(root, "education");
    insert(root, "end");
    insert(root, "example");
    insert(root, "eye");
    insert(root, "face");
    insert(root, "fact");
    insert(root, "family");
    insert(root, "father");
    insert(root, "feet");
    insert(root, "fire");
    insert(root, "fish");
    insert(root, "food");
    insert(root, "force");
    insert(root, "game");
    insert(root, "girl");
    insert(root, "god");
    insert(root, "government");
    insert(root, "group");
    insert(root, "guy");
    insert(root, "hand");
    insert(root, "head");
    insert(root, "health");
    insert(root, "history");
    insert(root, "honey");
    insert(root, "home");
    insert(root, "horse");
    insert(root, "hour");
    insert(root, "house");
    insert(root, "idea");
    insert(root, "information");
    insert(root, "job");
    insert(root, "juce");
    insert(root, "jungle");
    insert(root, "kid");
    insert(root, "kind");
    insert(root, "king");
    insert(root, "land");
    insert(root, "law");
    insert(root, "letter");
    insert(root, "level");
    insert(root, "life");
    insert(root, "line");
    insert(root, "list");
    insert(root, "man");
    insert(root, "member");
    insert(root, "milk");
    insert(root, "minute");
    insert(root, "mom");
    insert(root, "moment");
    insert(root, "money");
    insert(root, "month");
    insert(root, "morning");
    insert(root, "mother");
    insert(root, "music");
    insert(root, "name");
    insert(root, "nature");
    insert(root, "night");
    insert(root, "north");
    insert(root, "number");
    insert(root, "office");
    insert(root, "orange");
    insert(root, "order");
    insert(root, "page");
    insert(root, "paper");
    insert(root, "pen");
    insert(root, "person");
    insert(root, "picture");
    insert(root, "plant");
    insert(root, "point");
    insert(root, "power");
    insert(root, "product");
    insert(root, "program");
    insert(root, "queen");
    insert(root, "reason");
    insert(root, "research");
    insert(root, "result");
    insert(root, "right");
    insert(root, "river");
    insert(root, "rock");
    insert(root, "room");
    insert(root, "school");
    insert(root, "sea");
    insert(root, "service");
    insert(root, "ship");
    insert(root, "side");
    insert(root, "sister");
    insert(root, "sound");
    insert(root, "space");
    insert(root, "student");
    insert(root, "sun");
    insert(root, "table");
    insert(root, "teacher");
    insert(root, "team");
    insert(root, "thing");
    insert(root, "time");
    insert(root, "tree");
    insert(root, "ultimate");
    insert(root, "vertex");
    insert(root, "war");
    insert(root, "watch");
    insert(root, "water");
    insert(root, "way");
    insert(root, "week");
    insert(root, "west");
    insert(root, "wind");
    insert(root, "woman");
    insert(root, "word");
    insert(root, "world");
    insert(root, "xenon");
    insert(root, "year");
    insert(root, "zebra");
}
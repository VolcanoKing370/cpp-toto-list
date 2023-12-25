// cpp-toto=list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        // RNG between 1 to 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }
    void makeComplete(bool boolin) {
        completed = boolin;
    }
};

int main()
{
    std::string version = "v0.1.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;
    
    // Inputs
    char input_sel;
    int input_id;
    std::string input_desc;

    srand(time(NULL));

    //initialize the list (clearing it)
    todoItems.clear();

    /* The following block creates a test TodoItem, please comment it out during production! */
    /*TodoItem test;
    test.create("this is a test item");
    todoItems.push_back(test);*/

    while (1) {
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completion = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it->getDescription() << " | " << completion << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Add your first todo item!";
        }

        std::cout << std::endl << std::endl << std::endl << "[a]dd a new todo" << std::endl;
        std::cout << "[c]omplete a todo" << std::endl;
        std::cout << "[q]uit" << std::endl << std::endl;
        std::cout << "What will you do?: ";

        std::cin >> input_sel;

        switch (input_sel) {
        case 'q':
            std::cout << "Bye!";
            return 0;
        case 'a': {
            std::cout << "Add new task description: ";
            std::cin.clear();                                   // clear the input buffer
            std::cin.ignore();                                  // ignore first return 
            std::getline(std::cin, input_desc);     // ensures that we can add spaces to our description string for TodoItem
            TodoItem newItem;
            newItem.create(input_desc);
            todoItems.push_back(newItem);
            break;
        }
        case 'c':
            std::cout << "Enter teh id of todo to mark as complete: ";
            std::cin >> input_id;
            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                if (input_id == it->getId()) {
                    it->makeComplete(true);
                    break;
                }
            }
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
        
    }
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

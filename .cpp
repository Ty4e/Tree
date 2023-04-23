#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm> 
#include "binarytree.h"

using namespace std;

void traversal(binaryTreeType<string>& tree) {
    cout <<"Pre"<< endl;
    tree.preorderTraversal();
    cout <<"In"<< endl;
    tree.inorderTraversal();
    cout <<"Post"<< endl;
    tree.postorderTraversal();
}

void search(binaryTreeType<string>& tree) {
    string key;
    cout << "Enter the key to search for: ";
    cin >> key;

    bool found = false;
    tree.search(key, found);

    if (found) {
        cout << key << " is in the tree." << endl;
    } else {
        cout << key << " is not in the tree." << endl;
    }
}

void update(binaryTreeType<string>& tree) {
    string key;
    string newInfo;
    cout << "Enter the key to update: ";
    cin >> key;

    bool found = false;
    tree.search(key, found);

    if (found) {
        cout << "Enter the new information: ";
        cin >> newInfo;
        tree.updateNode(key, newInfo);
        cout << "Node updated." << endl;
    } else {
        cout << key << " is not in the tree." << endl;
    }
}

void addNode(binaryTreeType<string>& tree) {
    string parent;
    string side;
    string key;
    string info;
    cout << "Enter the parent node: ";
    cin >> parent;
    cout << "Enter the side (left or right): ";
    cin >> side;
    cout << "Enter the key for the new node: ";
    cin >> key;
    cout << "Enter the information for the new node: ";
    cin >> info;

    bool found = false;
    tree.search(parent, found);

    if (found) {
        if (side == "left") {
            tree.insertLeft(parent, key, info);
        } else if (side == "right") {
            tree.insertRight(parent, key, info);
        } else {
            cout << "Invalid side. Please try again." << endl;
        }
    } else {
        cout << parent << " is not in the tree." << endl;
    }
}

void findOutcome(binaryTreeType<string>& tree) {
    binaryTreeNode<string>* node = tree.getRoot();
    while (node->llink != nullptr && node->rlink != nullptr) {
        string response;
        cout << node->info << "? (y/n): ";
        cin >> response;
        if (response == "y") {
            node = node->llink;
        } else if (response == "n") {
            node = node->rlink;
        } else {
            cout << "Invalid response. Please try again." << endl;
        }
    }
    cout << "Outcome: " << node->info << endl;
}

int main() {
   binaryTreeType<string> animal("Has feathers?");

animal.add_decision("Has feathers?", "left", "Can fly?");  
animal.add_decision("Has feathers?", "right", "Has fins?");

animal.add_decision("Can fly?", "left", "Hawk");
animal.add_decision("Can fly?", "right", "Penguin");  

animal.add_decision("Has fins?", "left", "Dolphin");
animal.add_decision("Has fins?", "right", "Bear"); 

animal.add_decision("Hawk", "left", "Color?");
animal.add_decision("Hawk", "right", "Is diurnal?");

animal.add_decision("Color?", "left", "Red");
animal.add_decision("Color?", "right", "Brown");

animal.add_decision("Red", "left", "Red-tailed Hawk"); 
animal.add_decision("Red", "right", "Red-shouldered Hawk");

animal.add_decision("Is diurnal?", "left", "Swainson's Hawk");  
animal.add_decision("Is diurnal?", "right", "Rough-legged Hawk");

animal.add_decision("Brown", "left", "Ferruginous Hawk"); 
animal.add_decision("Brown", "right", "Harris's Hawk");

animal.add_decision("Dolphin","left","Color?");
animal.add_decision("Dolphin","right","Size?");

animal.add_decision("Color?", "left", "Gray");
animal.add_decision("Color?", "right", "Black/White");  

animal.add_decision("Gray", "left", "Common Dolphin");
animal.add_decision("Gray", "right", "Risso's Dolphin");  

animal.add_decision("Black/White", "left", "Bottlenose Dolphin");  
animal.add_decision("Black/White", "right", "Spotted Dolphin");

animal.add_decision("Size?", "left", "Large");
animal.add_decision("Size?", "right", "Small");  

animal.add_decision("Large", "left", "Killer Whale");
animal.add_decision("Large", "right", "False Killer Whale");  

animal.add_decision("Small", "left", "Harbor Porpoise");
animal.add_decision("Small", "right", "Dusky Dolphin");
 
 animal.preorderTraversal();

}

    int choice;

    do {
        cout << "MENU" << endl;
        cout << "1: Traversal" << endl;
        cout << "2: Search the tree" << endl;
        cout << "3: Update a Node" << endl;
        cout << "4: Add a node to the decision tree" << endl;
        cout << "5: Use the tree to find outcome" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traversal(animal);
                break;
            case 2:
                search(animal);
                break;
            case 3:
                update(animal);
                break;
            case 4:
                addNode(animal);
                break;
            case 5:
                findOutcome(animal);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}
}

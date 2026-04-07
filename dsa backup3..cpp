#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Staff {
    int id;
    string name;
    string role;
    double salary;
    Staff* next;
};

struct StaffNode {
    Staff* staff;
    StaffNode* left;
    StaffNode* right;
    StaffNode(Staff* s) : staff(s), left(nullptr), right(nullptr) {}
};

Staff* head = nullptr;
StaffNode* root = nullptr;

Staff* createStaff(int id, const string& name, const string& role, double salary) {
    Staff* node = new Staff();
    node->id = id;
    node->name = name;
    node->role = role;
    node->salary = salary;
    node->next = nullptr;
    return node;
}

bool insertIntoList(Staff* staff) {
    if (!head) {
        head = staff;
        return true;
    }
    Staff* cur = head;
    while (cur) {
        if (cur->id == staff->id) return false;
        if (!cur->next) break;
        cur = cur->next;
    }
    cur->next = staff;
    return true;
}

StaffNode* insertIntoTree(StaffNode* rootNode, Staff* staff) {
    if (!rootNode) return new StaffNode(staff);
    if (staff->id < rootNode->staff->id) {
        rootNode->left = insertIntoTree(rootNode->left, staff);
    } else if (staff->id > rootNode->staff->id) {
        rootNode->right = insertIntoTree(rootNode->right, staff);
    }
    return rootNode;
}

Staff* searchById(StaffNode* rootNode, int id) {
    while (rootNode) {
        if (id == rootNode->staff->id) return rootNode->staff;
        rootNode = (id < rootNode->staff->id) ? rootNode->left : rootNode->right;
    }
    return nullptr;
}

StaffNode* findMinNode(StaffNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

StaffNode* removeFromTree(StaffNode* node, int id) {
    if (!node) return nullptr;
    if (id < node->staff->id) {
        node->left = removeFromTree(node->left, id);
    } else if (id > node->staff->id) {
        node->right = removeFromTree(node->right, id);
    } else {
        if (!node->left) {
            StaffNode* rightChild = node->right;
            delete node;
            return rightChild;
        }
        if (!node->right) {
            StaffNode* leftChild = node->left;
            delete node;
            return leftChild;
        }
        StaffNode* minNode = findMinNode(node->right);
        node->staff = minNode->staff;
        node->right = removeFromTree(node->right, minNode->staff->id);
    }
    return node;
}

bool removeFromList(int id) {
    Staff* cur = head;
    Staff* prev = nullptr;
    while (cur) {
        if (cur->id == id) {
            if (prev) prev->next = cur->next;
            else head = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void displayAll() {
    if (!head) {
        cout << "No staff records available.\n";
        return;
    }
    cout << "Staff List:\n";
    Staff* cur = head;
    while (cur) {
        cout << "ID: " << cur->id
             << ", Name: " << cur->name
             << ", Role: " << cur->role
             << ", Salary: " << cur->salary << "\n";
        cur = cur->next;
    }
}

void addStaff() {
    int id;
    string name;
    string role;
    double salary;
    cout << "Enter staff ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter role: ";
    getline(cin, role);
    cout << "Enter salary: ";
    cin >> salary;

    if (searchById(root, id)) {
        cout << "A staff member with ID " << id << " already exists.\n";
        return;
    }

    Staff* staff = createStaff(id, name, role, salary);
    insertIntoList(staff);
    root = insertIntoTree(root, staff);
    cout << "Staff added.\n";
}

void searchStaff() {
    int id;
    cout << "Enter staff ID to search: ";
    cin >> id;
    Staff* staff = searchById(root, id);
    if (!staff) {
        cout << "Staff not found.\n";
    } else {
        cout << "Found staff: "
             << "ID: " << staff->id
             << ", Name: " << staff->name
             << ", Role: " << staff->role
             << ", Salary: " << staff->salary << "\n";
    }
}

void deleteStaff() {
    int id;
    cout << "Enter staff ID to delete: ";
    cin >> id;
    if (!searchById(root, id)) {
        cout << "Staff not found.\n";
        return;
    }
    bool removedList = removeFromList(id);
    if (removedList) {
        root = removeFromTree(root, id);
        cout << "Staff removed.\n";
    } else {
        cout << "Unable to remove staff.\n";
    }
}

int main() {
    int choice = 0;
    while (true) {
        cout << "\nStaff Management\n";
        cout << "1. Add staff\n";
        cout << "2. Display all staff\n";
        cout << "3. Search staff by ID\n";
        cout << "4. Delete staff by ID\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStaff();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchStaff();
                break;
            case 4:
                deleteStaff();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}

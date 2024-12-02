#include <iostream>
#include <vector>
#include <string>

class File {
public:
    std::string name;
    bool isFolder;
    std::vector<File*> children; 

    File(std::string name, bool isFolder) : name(name), isFolder(isFolder) {}

    void addChild(File* child) {
        if (isFolder) {
            children.push_back(child);
        } else {
            std::cout << "Cannot add child to a file." << std::endl;
        }
    }

    bool hasEmptySubfolder() {
        if (!isFolder) {
            return false;
        }

        for (File* child : children) {
            if (child->isFolder && child->children.empty()) {
                return true; 
            }
        }
        return false; 
    }
};

int main() {
    File* root = new File("root", true);

    File* folder1 = new File("folder1", true);
    File* folder2 = new File("folder2", true);
    File* folder3 = new File("folder3", true);

    File* file1 = new File("file1.txt", false);
    File* file2 = new File("file2.txt", false);
    File* file3 = new File("file3.txt", false);

    root->addChild(folder1);
    root->addChild(folder2);
    root->addChild(folder3);
    root->addChild(file1);
    root->addChild(file2);
    root->addChild(file3);
    folder1->addChild(new File("subfolder1", true)); 
    folder2->addChild(new File("subfolder2", true)); 
    folder3->addChild(new File("subfolder3", true));  

    if (root->hasEmptySubfolder()) {
        std::cout << "The root folder contains at least one empty subfolder." << std::endl;
    } else {
        std::cout << "The root folder does not contain any empty subfolders." << std::endl;
    }

    delete root;
    delete folder1;
    delete folder2;
    delete folder3;
    delete file1;
    delete file2;

    return 0;
}

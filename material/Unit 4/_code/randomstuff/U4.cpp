#include<iostream>
#include<string>
#include<vector>
class FileSystemEntry {
public:
    virtual void print() = 0;
};

class File : public FileSystemEntry {
public:
    File(std::string name) : name_(name) {}

    void print() {
        std::cout << "File: " << name_ << std::endl;
    }

private:
    std::string name_;
};

class Directory : public FileSystemEntry {
public:
    Directory(std::string name) : name_(name) {}

    void addEntry(FileSystemEntry* entry) {
        entries_.push_back(entry);
    }

    void print() {
        std::cout << "Directory: " << name_ << std::endl;
        for (auto entry : entries_) {
            entry->print();
        }
    }

private:
    std::string name_;
    std::vector<FileSystemEntry*> entries_;
};
int main() {
    auto* root = new Directory("root");
    auto* usr = new Directory("usr");
    auto* etc = new Directory("etc");
    auto* home = new Directory("home");

    auto* file1 = new File("file1.txt");
    auto* file2 = new File("file2.txt");

    root->addEntry(usr);
    root->addEntry(etc);
    root->addEntry(home);
    root->addEntry(file1);

    usr->addEntry(file2);

    root->print();
}

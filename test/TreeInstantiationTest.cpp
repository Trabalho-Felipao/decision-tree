#include "../include/BinaryTree.h"

int main(int argc, char* argv[]) {
    BinaryTree* tree = BinaryTree::readTreeFromFile(argv[1]);
    tree->showTreeInformations();
    delete tree;
}
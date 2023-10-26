/**
 * @file BinaryTree.cpp
 * 
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * 
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/BinaryTree.h"
#include <fstream>
#include <iostream>
#include <iomanip> // !!! Debugging only

BinaryTree::TreeNode::TreeNode(std::string nodeValue):
    entry(nodeValue),
    leftSubTree(nullptr),
    rightSubTree(nullptr)
{}

BinaryTree::BinaryTree():
    root(nullptr)
{}

BinaryTree::~BinaryTree() {

}

BinaryTree& BinaryTree::readTreeFromFile(std::string&& filepath) {
    std::ifstream treeFile(filepath, std::ios::in);
    std::string node, leftSubTree, rightSubTree;
    treeFile >> node >> leftSubTree >> rightSubTree;
    return BinaryTree()
        .withInitialNode(node, leftSubTree, rightSubTree)
        .followedBy(std::move(treeFile));
}

BinaryTree& BinaryTree::withInitialNode(std::string initialNode,
        std::string leftSubTree, std::string rightSubTree) {
    this->root = new TreeNode(initialNode);
    this->root->setSubsequentSubTrees(leftSubTree, rightSubTree);
    return *this;
}

void BinaryTree::TreeNode::setSubsequentSubTrees(std::string leftSubTree,
        std::string rightSubTree) {
    this->leftSubTree = leftSubTree == "X" ? nullptr : new TreeNode(leftSubTree);
    this->rightSubTree = rightSubTree == "X" ? nullptr : new TreeNode(rightSubTree);
}

BinaryTree& BinaryTree::followedBy(std::ifstream&& treeFile) {
    std::string nodeValue, leftSubTreeValue, rightSubTreeValue;
    while (treeFile >> nodeValue >> leftSubTreeValue >>rightSubTreeValue
            && nodeValue != "X")
        this->findPositionThenSetSubtrees(root, nodeValue, leftSubTreeValue, rightSubTreeValue);
    treeFile.close();
    return *this;
}

void BinaryTree::findPositionThenSetSubtrees(TreePointer currentNode,
        std::string nodeValue, std::string leftSubTreeValue, std::string rightSubTreeValue) {
    if (currentNode == nullptr)
        return;
    if (currentNode->entry == nodeValue) {
        currentNode->setSubsequentSubTrees(leftSubTreeValue, rightSubTreeValue);
        return;
    }
    findPositionThenSetSubtrees(currentNode->leftSubTree, nodeValue, leftSubTreeValue, rightSubTreeValue);
    findPositionThenSetSubtrees(currentNode->rightSubTree, nodeValue, leftSubTreeValue, rightSubTreeValue);
}

void BinaryTree::showTreeInformations() {

}

// !!! Debugging only
void BinaryTree::printTree(){
    printTree(root, 0);
}

// !!! Debugging only
void BinaryTree::printTree(TreePointer &t, int s){
    int i;
    if(t!=NULL){
        printTree(t->rightSubTree, s+3);
        for(i=1; i<=s; i++)
            std::cout << " ";
        std::cout << std::setw(6) <<t->entry <<std::endl;
        printTree(t->leftSubTree, s+3);
    }
}
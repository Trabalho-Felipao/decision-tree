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

BinaryTree::TreeNode::TreeNode(const std::string nodeValue):
    entry(nodeValue),
    leftSubTree(nullptr),
    rightSubTree(nullptr)
{}

BinaryTree::TreeNode* BinaryTree::TreeNode::createNode(const std::string nodeValue){
    TreePointer pointer = new TreeNode(nodeValue);

    if(pointer == nullptr){
        std::cerr << "Falha na alocação de recursos!" << std::endl;
        abort();
    }

    return pointer;
}

BinaryTree::BinaryTree():
    root(nullptr)
{}

BinaryTree::~BinaryTree(){
    
    destroyTree(root);
}

void BinaryTree::destroyTree(TreePointer node){
    if(node == nullptr)
        return;
    
    destroyTree(node->leftSubTree);
    destroyTree(node->rightSubTree);

    delete node;
}

BinaryTree* BinaryTree::readTreeFromFile(const std::string&& filepath) {
    std::ifstream treeFile(filepath, std::ios::in);
    std::string node, leftSubTree, rightSubTree;
    treeFile >> node >> leftSubTree >> rightSubTree;
    return (new BinaryTree())
        ->withInitialNode(node, leftSubTree, rightSubTree)
        ->followedBy(std::move(treeFile));
}

BinaryTree* BinaryTree::withInitialNode(const std::string initialNode,
        const std::string leftSubTree, const std::string rightSubTree) {
    this->root = TreeNode::createNode(initialNode);
    this->root->setSubsequentSubTrees(leftSubTree, rightSubTree);
    return this;
}

void BinaryTree::TreeNode::setSubsequentSubTrees(const std::string leftSubTree,
        const std::string rightSubTree) {
    this->leftSubTree = leftSubTree == "X" ? nullptr : TreeNode::createNode(leftSubTree);
    this->rightSubTree = rightSubTree == "X" ? nullptr : TreeNode::createNode(rightSubTree);
}

BinaryTree* BinaryTree::followedBy(std::ifstream&& treeFile) {
    std::string nodeValue, leftSubTreeValue, rightSubTreeValue;
    while (treeFile >> nodeValue >> leftSubTreeValue >> rightSubTreeValue
            && nodeValue != "X")
        this->findPositionThenSetSubtrees(root, nodeValue, leftSubTreeValue, rightSubTreeValue);
    treeFile.close();
    return this;
}

void BinaryTree::findPositionThenSetSubtrees(TreePointer currentNode,
        const std::string nodeValue, const std::string leftSubTreeValue,
        const std::string rightSubTreeValue) {
    if (currentNode == nullptr)
        return;
    if (currentNode->entry == nodeValue) {
        currentNode->setSubsequentSubTrees(leftSubTreeValue, rightSubTreeValue);
        return;
    }
    findPositionThenSetSubtrees(currentNode->leftSubTree, nodeValue, leftSubTreeValue, rightSubTreeValue);
    findPositionThenSetSubtrees(currentNode->rightSubTree, nodeValue, leftSubTreeValue, rightSubTreeValue);
}

BinaryTree* BinaryTree::showTreeInformations() {
    int totalOfNodes = 0, totalOfLeaves = 0;
    showTreeInformations(root, totalOfNodes, totalOfLeaves);
    std::cout << totalOfNodes << " " << totalOfLeaves << std::endl;
    return this;
}

void BinaryTree::showTreeInformations(TreePointer &r, int &totalOfNodes, int &totalOfLeaves){
    if(r == NULL) return;
    totalOfNodes++;
    printNode(r, totalOfLeaves);
    showTreeInformations(r->leftSubTree, totalOfNodes, totalOfLeaves);
    showTreeInformations(r->rightSubTree, totalOfNodes, totalOfLeaves);
}

void BinaryTree::printNode(TreePointer &node, int &totalOfLeaves) const {
    int numberOfChildren;
    if(node->leftSubTree != NULL && node->rightSubTree != NULL) numberOfChildren = 2;
    else if(node->leftSubTree != NULL || node->rightSubTree != NULL) numberOfChildren = 1;
    else numberOfChildren = 0;
    std::string nodeType;
    if(node->leftSubTree != NULL && node->rightSubTree != NULL) nodeType = "ED";
    else if(node->leftSubTree != NULL) nodeType = 'E';
    else if(node->rightSubTree != NULL) nodeType = 'D';
    else {nodeType = 'F'; totalOfLeaves++;}
    std::cout << node->entry << " " << numberOfChildren << " " << nodeType << std::endl;
}
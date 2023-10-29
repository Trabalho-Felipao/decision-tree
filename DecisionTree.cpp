/**
 * @file DecisionTree.cpp
 * 
 * @brief Trabalho de Estrutura De Dados - 4º Semestre - 2º Bimestre
 *  Implementação de uma árvore binária de decisão.
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

#include "include/BinaryTree.h"
#include <memory>

int main(int argc __attribute__((unused)), char *argv[]) {
    BinaryTree::readTreeFromFile(std::move(argv[1]))->showTreeInformations();
}
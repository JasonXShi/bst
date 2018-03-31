#include "Node.h"
#include <cstddef>

Node::Node(){
  left = NULL;
  right = NULL;
  parent = NULL;
content = NULL;
}

Node* Node::getRight(){
  return right;
}
Node* Node::getLeft(){
  return left;
}
Node* Node::getParent(){
  return parent;
}
int Node::getContent(){
  return content;
}
void Node::setContent(int newContent){
  content = newContent;
}
void Node::setRight(Node* newRight){
  right = newRight;
}
void Node::setLeft(Node* newLeft){
  left = newLeft;
}
void Node::setParent(Node* newParent){
  parent = newParent;
}

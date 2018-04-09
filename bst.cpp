/*
 *	Binary Search Tree
 *	Written by Jason Shi
 *	Allows the user to create a binary search tree and delete, add, and print out the tree.
 *	This tree does not allow duplicates (there are several trains of thought on this so I just chose this method.
 *
 */



#include "Node.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
void addNode(Node* head, int number){
	if(head->getContent()==NULL){
		head->setContent(number);
		return;
	}else if(head->getContent()>number){
		if(head->getLeft() != NULL){
                        Node* temp = head->getLeft();
                        addNode(temp, number);
                }else{
                        Node* temp = new Node();
                        temp->setContent(number);
                        head->setLeft(temp);
                        return;
                }
	}else if(head->getContent()<number){
		if(head->getRight() != NULL){
			Node* temp = head->getRight();
			addNode(temp, number);
		}else{
			Node* temp = new Node();
			temp->setContent(number);
			head->setRight(temp);
			return;
		}
	}else{
		return;
	}

}

void printTree(Node* head, int space){
    if (head == NULL)
    	return;
    space += 10;
    printTree(head->getRight(), space);
    cout << '\n';
    for (int i = 10; i < space; i++)
        cout << " ";
	cout <<head->getContent();
 
    printTree(head->getLeft(), space);
}

Node* minValueNode(Node* node){
	Node* current = node;
	while(current->getLeft()!=NULL){
		current = current->getLeft();
	}
	return current;
}
Node* deleteNode(Node* head, int number){
  	
    if(head->getContent()> number){
    		head->setLeft(deleteNode(head->getLeft(), number));
 	 }else if(number > head->getContent()){
    		head->setRight(deleteNode(head->getRight(), number));
	}else{
		if(head->getLeft() == NULL){
			Node* temp = head->getRight();
			free(head);
			return temp;
		}else if(head->getRight() == NULL){
			Node* temp = head->getLeft();
			free(head);
			return temp;
		}
		Node* temp = minValueNode(head->getRight());
		head->setContent(temp->getContent());
		head->setRight(deleteNode(head->getRight(), temp->getContent()));
	}
}


int main(){
//get input 
	char* text = new char[400];
	cout << "Enter input as file or in console? (Type 'FILE' or 'CONSOLE')" << endl;
	cin.getline(text, 50);
	int count = 0;
	int * stor = new int[1000];
	if(strcmp(text, "FILE")==0){
		//gets filename
		cout << "Enter the filename: (Ex. 'text.txt') (Make sure to seperate the numbers just by spaces.)" << endl;
		char* filename = new char[50];
		cin.getline(filename, 50);
		ifstream inFile;
		inFile.open(filename);
		int a = 0;
		//puts all into the storage of numbers starting from 1
		while(inFile >> a){
			stor[count] = a;
			count++;
		}

	}else if(strcmp(text, "CONSOLE")==0){
		//gets input
		cout << "Enter the numbers you want to add to the tree, seperated by commas and spaces(Ex. 1, 2, 3)" << endl;
		char* input2  = new char[400];		
		cin.getline(input2, 400);
		char* token = strtok(input2, ", ");
		
		while(token != NULL){
			//changes it to int and puts it in the array starting from 1
			stor[count] = atoi(token);
			//deletes token
			token = strtok(NULL, ", ");
			count ++;
		}
		
	}
	Node* head = new Node();
	for(int i =0; i< count; i++){
		addNode(head, stor[i]);
	}	
	
	while(1){
		cout << '\n' <<"Enter a command:" << endl;
		cout << "'ADD' to add a number." << endl;
		cout << "'PRINT' to print the tree." << endl; 
		cout << "'DELETE' to delete a number." << endl;
		cout << "Or 'EXIT' to exit the program" << endl;
		char* command = new char[10];
		cin.getline(command, 10);
		int number = 0;
		if(strcmp(command, "ADD") == 0){
			cout << "Enter the number you want to add: " <<endl;
			cin >> number;
			cin.get();
			addNode(head, number);
		}else if(strcmp(command, "PRINT") == 0){
			
            if(head->getContent() == NULL){
                    
                    cout << "There is nothing in the tree" << endl;
                    }else{
                printTree(head, 0);
            }
		}else if(strcmp(command, "DELETE") == 0){
			cout << "Enter the number you want to delete: " << endl;
			cin >> number;
			cin.get();
			if(head->getLeft() == NULL & head->getRight() == NULL){
                head->setContent(NULL);
            }else{
                 head = deleteNode(head, number);
            }
        }else if(strcmp(command, "EXIT") == 0){
			exit(0);
		}
	
	}	

}

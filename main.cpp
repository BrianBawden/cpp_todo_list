//
//  main.cpp
//  toDoList
//
//  Created by Brian Bawden on 6/9/22.
//
/*
 Helpful websites:
   *https://www.programiz.com/cpp-programming/structure#:~:text=The%20struct%20keyword%20defines%20a,int%20age%3B%20float%20salary%3B%20%7D%3B
      * how to use structures in c++
   * https://www.youtube.com/watch?v=vLnPwxZdW4Y&t=12943s
      * c++ tutorial
    * https://linuxhint.com/remove-specific-element-vector-cpp/
        * how to erase a specific vector
 * https://linuxhint.com/create-vector-structs-cpp/
     * how to create a vector
 *https://www.programiz.com/cpp-programming/structure#:~:text=The%20struct%20keyword%20defines%20a,int%20age%3B%20float%20salary%3B%20%7D%3B
        * structures in c++
 Create a class for todo's with a function that uses the 'struct' command to create a grouping of characteristics  for the todo list like:
 * task name
 * due date
 * priority level 1-5
 * estimated time to complete
 *(maybe) notes on task
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


struct Task
{
    int taskId;
    std::string taskName;
    std::string dueDate;
    std::string reqTime;
    std::string taskNote;
    std::string priorityLevel;
}newTasks;

std::vector<Task> taskVector(10);


void getTaskInfo();
void saveTask();
void viewTasks();
void completeTask();

int count = 0;


int main() {
    // insert code here...
    
    char decision = '0';
    while(decision != '4'){
    std::cout
    << "Enter your selection: \n"
    << "'1' to add new task: \n"
    << "'2' to view task(s): \n"
    << "'3' to make a task complete: \n"
    << "'4' to quit: \n";
    std::cin >> decision;
        
        switch (decision){
            case '1':
                std::cout << "Add a new task: ";
                getTaskInfo();
                break;
            case '2':
                std::cout << "view task(s): \n";
                viewTasks();
                break;
            case '3':
                std::cout << "task id completed: \n";
                completeTask();
                break;
            case '4':
                std::cout << "good bye: \n";
                break;
            default:
                std::cout << "invalid entry\n";
        }

    }
    return 0;
}

void saveTask() {
    taskVector[newTasks.taskId].taskId = newTasks.taskId;
    taskVector[newTasks.taskId].taskName = newTasks.taskName;
    taskVector[newTasks.taskId].dueDate = newTasks.dueDate;
    taskVector[newTasks.taskId].reqTime = newTasks.reqTime;
    taskVector[newTasks.taskId].taskNote = newTasks.taskNote;
    taskVector[newTasks.taskId].priorityLevel = newTasks.priorityLevel;
    
};


void getTaskInfo(){
    

    std::cout << "Enter task id: ";
    std::cin >> newTasks.taskId;
    std::cin.ignore();
    std::cout << "Enter task name: ";
    getline(std::cin, newTasks.taskName);
    std::cout << "Enter task due date for " << newTasks.taskName << ": ";
    getline(std::cin, newTasks.dueDate);
    std::cout << "Enter priority level 1-5 for " << newTasks.taskName << ": ";
    getline(std::cin, newTasks.priorityLevel);
    std::cout << "Enter estimated time required for " << newTasks.taskName << ": ";
    getline(std::cin, newTasks.reqTime);
    std::cout << "Enter notes for " << newTasks.taskName << ": ";
    getline(std::cin, newTasks.taskNote);
    
    count++;
    
    saveTask();

};

void viewTasks(){
    for (int i = 1; i <= count; i++){
        std::cout <<"\ntask Id: "             << taskVector[i].taskId << "\n";
        std::cout <<"task name: "           << taskVector[i].taskName << "\n";
        std::cout <<"task due date: "       << taskVector[i].dueDate << "\n";
        std::cout <<"task priority level: " << taskVector[i].priorityLevel << "\n";
        std::cout <<"task estimated time: " << taskVector[i].reqTime << "\n";
        std::cout <<"task notes: "          << taskVector[i].taskNote << "\n\n";
        
    };
};

void completeTask(){
    int taskid;
    for (int i = 1; i <= count; i++){
        std::cout <<"\ntask Id: "           << taskVector[i].taskId << "\n";
        std::cout <<"task name: "           << taskVector[i].taskName << "\n";
    };
    std::cout <<"enter task Id completed: ";
    std::cin >> taskid;
    taskVector.erase(taskVector.begin() + taskid);
    
    count--;
};

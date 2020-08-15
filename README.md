# Some 

* Read about [prefix](https://stackoverflow.com/questions/226510/django-forms-how-to-use-prefix-parameter) while adding more than one forms in same form tag.

* Read about ManyToOne relationship


# TASQ
<strong>T</strong>ake <strong>A</strong>nother <strong>S</strong>imple <strong>Q</strong>uiz.

A Django web app.

# Blog
This repo is ment for the Blog-website created using php-mysql.

### Screenshots:
![homepage](https://user-images.githubusercontent.com/46635452/70455800-ec694e00-1ad2-11ea-8bde-8004cf1c35a5.png)
<br>

![uploadBlog](https://user-images.githubusercontent.com/46635452/70455464-63521700-1ad2-11ea-9118-15da356c2e42.png)



### Features :
- [x] Can Add New Posts
- [x] Can delete old posts
- [x] Search posts by specific author/date
- [x] Authentication for admin (Only admin can post)
- [ ] Adding users that can post
- [x] Buttons for easy navigation
- [x] Display less posts per page (reduce cluttering)
- [x] Adding images to posts
- [ ] Make some arrangement for posts with no images
- [x] Store posts in database (mysql)
- [x] Add CSS/Bootstrap4 and JS to make it usable


# academic_records_management
A C-program for academic records management. [![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/) [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues) [![Open Source Love png2](https://badges.frapsoft.com/os/v2/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)

### What does it do ?  :thinking:❓
It stores academic records of students, instructors and courses in a college.

### How is it implemented ? :man_shrugging:
- The ideas used are :
	- [x] structure
	- [x] pointers
	- [x] file-handling
	- [x] dynamic-memory allocation
	- [x] linked-list
	- [x] signal-handling
	- [x] basics of C language like if-else,switch conditionals

### Is a demo available ?
Yeah, here you go :smiley: 
![Screenshot](https://user-images.githubusercontent.com/46635452/61709077-f977e180-ad6b-11e9-9239-b5ffacee1c12.png)

### Well, that seems great. Can I get a detailed idea about its code base ?
Sure, :cowboy_hat_face: Here it is :


#### file-handling 	:open_file_folder:
The program uses text files for storing data in specified format. Every time the program is executed or terminated, the data in text file is updated. This is done by using the [file handling](https://www.geeksforgeeks.org/basics-file-handling-c/) of C language along with jumping technique of [fseek](https://www.geeksforgeeks.org/fseek-in-c-with-example/) to maintain the order in which data is saved. 



#### linked-list :link:
A [linked-list](https://www.geeksforgeeks.org/linked-list-set-1-introduction/) is maintained to store the data once it is read. This data-structure is chosen to make the insertion and deletion of data faster paying little cost while finding a particular data. Each of the category has a separate linked list to make sure that modifications in one category doesn't affect the other.



#### Structures :paperclip:
Each category has a separate [structure](https://www.geeksforgeeks.org/structures-c/) for storing the data about them. They contain all the essential data that a object of that category is supposed to have.



#### Pointers and dynamic memory allocation
Insertion of new data is handled by creating new structures inplace. This is done by using the concept of [dynamic memory allocation](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/). The newly created structure is then added to the corresponding linked list.



#### Signal handling :white_check_mark:
The database is prone to threat if the programme exits unexpectedly (e.g. forced inturption using ctrl+c) as the data is saved only when the programme exits. [Signal handling](https://www.geeksforgeeks.org/write-a-c-program-that-doesnt-terminate-when-ctrlc-is-pressed/) concepts are used to make sure that the programme exits in the way it is expected to be and data is saved before exiting.

That's all in a nutshell. Please go through code as I've added lots of comments. Feel free to contribute and use. For further interactions one may contact via [e mail](harshraj22aug@gmail.com)



# CP_command_Ubuntu
> A mimic of CP command of Ubuntu using C.

### Concepts learned :
   Command line argument, file handling, pointers and other common concepts like use of ',' as separator and operator.

### Overview : 
   The programme takes the file name and the address to be copied as Command Line Argument and copies the file content to the desired location with same name . 


# Four_In_A_Row
A C program to play Four In A Row game. [![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/) [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues) [![Open Source Love png2](https://badges.frapsoft.com/os/v2/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)

## How To Play : 🤔❓

 #### 1. Setup :
  ##### 1.1 Download Game.c file  ⬇️
  * Download the file by using the given command ```git clone https://github.com/harshraj22/four_in_a_row.git ``` . This creates a local coppy of this git repository on your local machine. Now move to created directory by typing 
  ``` cd four_in_a_row ```
  
  :champagne: 🎉🎉 Congrats !! You successfully installed the file to your local repository .
* Compile on linux machine using gcc compiler by running the command
```  gcc Game.c  ```
  * In case you get error like ```gcc not found, but can be installed with ...``` run the following command
  ```sudo apt install gcc```  followed by entering your password. This command installs gcc compiler on your machine, which is important for compilation of Game.c file.
* After installing and compiling, make sure an object file named a.out is created in your current directory. This can be done either manually or using the command ``` ls | grep a.out ```. This basically lists out every file and folder in your current working directory and searches for a.out named file .
   * Note that you can choose any other name for your object file using ``` gcc -o FILE_NAME Game.c``` where FILE_NAME is the custom name that you want to give to your object. The default file name is given a.out.
* Now once the object file is created, simply execute your object file using ```./a.out```. This commands excecutes an executable file named a.out in current directory.
* The details of playing are provided [below](####-2.-play-). In case you like the game but don't like to go the specific directory every time to compile and execute, you may add the compiled object file to the path of environment variables. Follow the below steps for the same : 
    
    #### 1.1 Make the game accessible from any directory : 📂
    * Compile Game.c file using the steps explained above using a name other than a.out . The other name is important so that in future if you compile and run some other code, your machine is not confused as which a.out should be executed. 
    * Run the following command ```sudo mv FILE_NAME /usr/bin/``` and then enter your password if required. This basically moves your object file to a directory named bin where many globally accessible executable files are stored. 
    * Now you can execute your object file from any location by just typing FILE_NAME on your command line.
    * Anytime you feel to remove the file from the folder of globally executables, type the following command 
    ``` sudo rm /usr/bin/FILE_NAME ``` followed by your password. Note that after using this command, you will no longer be able to run your object file from any director just by typing FILE_NAME on the command line unless you add the file to any one of the locations contained in PATH variable. More details about PATH variable can be found [ here ]( https://stackoverflow.com/questions/37676849/where-is-path-variable-set-in-ubuntu ).
    
    
    
 #### 2. Play : ▶️
 ![Game_initial](https://user-images.githubusercontent.com/46635452/58410401-c5e04a00-808f-11e9-9509-5f8590f6f78e.png)
   * The game requires two players who have to enter their name after executing the object file. The first three letters of their name should be diffrent to avoid confusion.
     ##### 2.1 Rules : 📜📜
        * The first player to enter name takes first turn and then both play alternate turns. 
        * In this version of game, there are 5 rows and 5 columns. The player has to pick a column that isn't full. The lowest empty space in that column will be occupied by him. 
        * The first player to occupy any 4 consecutive places in any 8 possible direction wins. 
        * In case of tie, no player is declared winner.
        * Compete among yourselves and have fun . ✌️😊
![Game_final](https://user-images.githubusercontent.com/46635452/58410556-08a22200-8090-11e9-98c7-421f6571e0c3.png)

# gaussian_elimination
This repo contains implementation of Gaussian Elimination to solve set of Linear Equations.


# Text_Based_Adventure_Game

  > A text based adventure game built using Python.  
 [![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/) [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues) [![Open Source Love png2](https://badges.frapsoft.com/os/v2/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)

### Concepts used : :pencil:
   - [x] Class 
  
   - [x] File handling  
  
   - [x] Other basics like loop , dictionary ,list, string and its methods, random e.t.c
  
### Insight : 
  Like normal text based adventure games, this game is divided into various breakpoints. Each breakpoint is assigned with unique id . All the informations like allowed path to proceed, view of surrounding etc are then tagged to the corresponding id.  
 ###  

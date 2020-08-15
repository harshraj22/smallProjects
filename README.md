
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

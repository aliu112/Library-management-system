

 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Library System
 Authors: \<[Chandler Mahkorn](https://github.com/CMahk)\> \<[Aaron Liu](https://github.com/aliu112)\>

## Project Description
The Library System is a tool that allows for the client to add media like books or magazines to a database, which they can then search through to find media similar to the criteria they are looking for.

## Why a Library System as the Project?
 **Aaron:** This is an interesting project because it dips into the realm of databases and how you can use them to display information that the users needs. These needs include what books we have and possibily the location of the book like real libraries display.
 
 **Chandler:** I have worked with small database objects in personal projects, so I wanted to further experiment with them in a group project.

## Languages and Technologies
* Primary Programming language: C++ 11
* Qt (https://www.qt.io/) - Qt is a cross-platform application development framework for desktop, embedded and mobile. It is a cross-platform frontend for platform-native build systems, like GNU Make, Visual Studio and Xcode
* **Inputs and outputs**
	* Not all inputs and outputs will be available depending on the given book. For example, a book may not a have cover or an author, or if it is an old book, it may not have a specified year when it was published.
	* **Input:** Books, user text
        	* Specific details per product: Title, author, cover, genre, sub-genre, date published, description, price, availability, and location
	* **Output:** Same as input if applicable (printed), book categories (printed), book hierarchy (printed), book hierarchy (text file)
 
* **Design Patterns:** Facade, Composite

	* **Aaron:** To implement the interface of this library system I have decided to use the design pattern Facade. This is the perfect design pattern for creating the interface because it essentially hides all of the complex code that the user does not need to see. It basically will mask all the code that we use to acheive the data. The user will only see a simple webpage that will display the information they need to get their book.
 
	* **Chandler:** To create a functional database of consumable media, the Composite design pattern will be used. This design pattern can be used to create an a base class that can then be utilized to create a hierarchy of objects representing the library's database. This database can then be traversed easily to present the data that the user requests, including individual books and entire categories of books.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
![](https://github.com/cs100/final-project-cmahk001-kdo055-aliu112/blob/master/Facade.png)
This diagram shows how I will be utilizing the facade design pattern to conceal all of the complex code from the user. The Library_Facade will be the class that the user will be interacting with to perform all the actions such as borrowing a book, logging in, creating an account, paying off an debts, etc. There are multiple classes that the facade will be essentially be assisting the facade in retreving, adding, or removing any of the necessary information. After the interface is implemented, the user will simply have to click buttons which will then call the functions within the Library_Facade class. The Library_Facade class will then utilize the other classes to correctly perform the action. For example, if the user wants to login, they will simply have to type in their username and password. The Library_Facade will then utilize the class User to check and see if the inputs values are already in the system. If it is then the user will be logged in, and if not the user will be given an error message. The bookManager is there as a place holder because Chandler will be handling the database part of the project.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 

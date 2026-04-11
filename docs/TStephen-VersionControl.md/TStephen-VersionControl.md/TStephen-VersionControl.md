# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Version Control & Markdown Documentation <-- Replace all text in brackets ]

- **[ Tyreece Stephen ]**
- **[ 04/11/2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ CMD ]: Clear the Screen 
- clear
- [ CMD ]: Print the "Working Directory"
- pwd
- [ CMD ]: List files and folders
- ls
- [ CMD ]: List files and folders, including invisible files
- ls -a
- [ CMD ]: List all files and folders, in human readable form
- ls -lah
- [ CMD ]: Change directory
- cd
- [ CMD ]: Change directory, go to root directory
- cd /
- [ CMD ]: Change directory and go to user home directory
- cd ~
- [ CMD ]: Change directory, go up one folder level
- cd ..
- [ CMD ]: Change directory, go up two folder levels
- cd ../..
- [ CMD ]: Change directory to my desktop!
- cd ~/Desktop

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ I dragged and dropped one of my repo folders and it copied the path to that folder into the terminal]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

Local - This is the method that most people implement. 
It involves copying files from one directory into another or simply saving a file with a new version number. 

Centralized (CVCS) - This method is utilized when developers need to collaborate on a single server. A developer simply checks out the latest piece of code on which work is to be completed

Distributed (DVCS) - This method allows the developer to make an exact copy of the repository and store it on the local drive

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone repository_url ]: Clone a repository
- [ git config --global user.name "name"]: Set-up a global user name
- [ git config --global user.email "email" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add . ]: Add modified files to the next commit
- [ git commit -m "message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ if i have a github repository that I want to make a local version of I can use git clone on the url for the github repository, otherwise if I have a local repository that i wanna connect to github I can do so by doing git remote add origin and then the url for my github repository]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [files that you dont want git to keep track of]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [it's a macos thing and it's for personal mac finder settings, other developers wouldn't have any use for that's why ignore it]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [node_modules, .env files node_modules because it would add unnecessary files to your repository, and .env because it has secret information that you don't want to share]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Three Types of Version Control**  
[Site Address](https://www.someaddress.com/full/url/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://www.someaddress.com/full/url/)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.someaddress.com/full/url/)

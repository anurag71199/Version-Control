### Version Control System ###
### README ###

How to run : 

1. Compile the code using the command : 'g++ git.cpp -o git'
   (An executable file with the name 'git' will appear in the current folder)

2. To run the program and use the functionalities of git : 
	2.1 Init : './git init' 
		*A hidden folder with the name '.git' will be created in the current folder
	
	2.2 Add : './git add <filename/foldername>'
		Example: ./git add folder1
		*Takes one folder/file at a time
	
	2.3 Status : './git status'
		*Displays tracked, untracked and modified files
	
	2.4 Commit : './git commit <mode> <message>'
		Additional modes:
			
			2.4.1 Commit without a message : './git commit'
			
			2.4.2 Adding a message along with the commit (-m) : './git commit -m <message>
			      Example: ./git commit -m My first commit
	
	2.5 Rollback : './git rollback'
		Additional modes:
			
			2.5.1 Rollback to previous version : './git rollback'
			
			2.5.2 Rollback to certain checkpoints back at once (-c) : './git rollback -c <number of hops>
			      Example: ./git rollback -c 3 (will go three versions back. Eg: V5 -> V2)
			
			2.5.3 Rollback to a specific version : './git rollback -vn V<version number>
			      Example: ./git rollback -vn V2 (will rollback from current version to Version 2)
			
	2.6 Log : './git log'
		*Shows version logs
	       
	

Write down Linux commands for following statements: 
1.	Redirect the output of ls command to a file named outfile. Use this as an input file for remaining commands. 

ls > outfile


2.	To select the lines in a file which has digit as one of the character in that line and redirect the output to the file named list. 

grep '[0-9]' outfile > list


3.	Assign execute permission to owner and remove read permission from other for an ordinary file named test by relative way. 

chmod u+x,o-r test


4.	Create an alias named rm that always deletes file interactively.

alias rm='rm -i'


5.	Count the currently login users to the system.

who | wc -l

6.	Redirect the output of cat command to a file named outfile. Use this as an input file for remaining commands. 

cat > outfile


7.	List all hidden files under current directory and store in “hidden” file 

ls -a | grep '^\.' > hidden


8.	Assign write permission to owner and remove execute permission from other for an ordinary file named test by absolute way. 

chmod 600 /path/to/test


9.	To create soft and hard link for given file 

Soft link = ln -s /path/to/original /path/to/link

Hard link = ln /path/to/original /path/to/link


10.	To convert lowercase to upper case of a given file 

tr '[:lower:]' '[:upper:]' < inputfile > outputfile


11.	To extract 1st and 10th character of a given file 

cut -c 1,10 inputfile > outputfile


12.	To display how many times lines are repeated in a given

sort filename | uniq -c

13.	To redirect the output of cp command to a file named outfile. Use this as an input file for remaining commands. 

cp sourcefile outfile


14.	To select the lines in a file which has 4 letter words in that line and redirect the output to the file named list. 

grep -Eow '[[:alpha:]]{4}' outfile > list


15.	Assign write permission to owner and remove read permission from group user for an ordinary file named test by relative way. 

chmod u+w,g-r test


16.	Create an alias named ls that always lists all the files including hidden files.

alias ls='ls -a'


17.	Count the number of words in the list file.

wc -w list

18.	Redirect the output of mv command to a file named outfile. Use this as an input file for remaining commands. 

mv sourcefile destinationfile > outfile


19.	List all hidden files under current directory and store in “hidden” file 

ls -a | grep '^\.' > hidden


20.	 Assign write permission to group user and remove execute permission from owner for an ordinary file named test by absolute way 

chmod g+w,o-x /path/to/test


21.	To create soft and hard link for given file 

Soft link = ln -s /path/to/original /path/to/link

Hard link = ln /path/to/original /path/to/link

22.	To convert lowercase to upper case of a given file 

tr '[:lower:]' '[:upper:]' < inputfile > outputfile


23.	To extract 2 nd and 3 rd character of a given file 

cut -c 2-3 inputfile > outputfile


24.	To display how many times lines are repeated in a given file

sort filename | uniq -c



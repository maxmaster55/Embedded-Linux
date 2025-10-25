# Task one

1. Ubuntu - Arch - VoidLinux

2. the man command is used to view the manual of any command on linux, the man pages are downloaded alongside the the command package.

3. *rm:* is used to delete files, dirs, and anything found on the os
   *rmdir:* is used to delete empty dirs only

4. the commands are

   ```bash
   mkdir -p ~/dir1/dir1{1..2} docs Documents
   touch ~/dir1/dir11/file1 ./docs/mucv ./Documents/OldFiles
   ```

   a. the dir could not be deleted because it was not empty

   - used **rm** 

   b. could not remove the file using **rmdir** `Not a directory` 

   - to solve this just use rm

   c. **/home/user/docs/mycv**
   
   
   5. ```bash 
      cp /etc/passwd mypasswd
      ```
   
   6. ```bash 
      mv mypasswd oldpasswd
      ```
   
   7. 1. cd ~
      2. cd /home/user
      3. cd ../../home/user
      4. cd
   
   8. ```bash 
      ls /usr/bin/w*
      ```
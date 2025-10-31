## Section 2 answers

1. commands for the user are found in ```/usr/bin``` 

   ```bash
   ls /usr/bin > /tmp/commands.list
   ```

2. by adding the ```date``` command to the ```.profile``` file

3. the command is ```wc``` 

   1. ```bash 
      ls /usr/bin | wc
      ```

4. The command order changes to this 

   1. ```bash
      cat: filename2cat: filename1: No such file or directory
      ```

   2. rm will not work

      ```bash
      rm: missing operand
      ```

   3. wc will read the line numbers of ls which is one
      ```bash
      ls /etc/passwd | wc -l
      1
      ```

5. command to search for ```.profile```
   ```bash
   find / -iname ".profile"
   ```

6. done using
   ```bash
   ls -id / /etc/ /etc/hosts
   ```

7. I could, but if you mean in ```/boot/efi``` i could not ```Operation not permitted``` 

8. same as above, but this time it's because i have the boot dir in another partition, and hard-linking is not allowed between different partitions.

9. the value ```PS1``` is the "Main prompt" but to change the > in the echo command we have to change the secondary prompt by changing ```PS2``` using this
   ```bash
   PS2=": "
   # or this
   export PS2=": "
   ```

   


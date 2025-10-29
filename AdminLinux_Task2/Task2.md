1. Done 

2. the application ran correctly, because the path ``` /usr/local/bin``` is already in the **PATH** variable.

3. 1. used command 

      ```bash
      echo /etc/shells
      ```

   2. used command 

      ```bash
      printenv
      ```

   3. use command

      ```bash
      echo $SHELL
      ```

4. in screen shot

5. in screen shot

   ```bash
   alias printPath="echo $PATH"
   ```

6. used command

   ```bash
   sudo ln /etc/passwd /boot/efi/
   ```

   it did not work: **because the boot partition *nvme0n1p2* is on another partition *sda1* **
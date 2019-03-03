## Linux版本dnw使用说明

```
1. dnw是一个USB工具，通过USB发送文件给具有USB下载功能的bootloader。
命令的使用方法为(要发送成功，单板必须运行具有USB下载功能的bootloader)：
sudo dnw <file> [address]
意思为：它将文件<file>通过USB口发送到单板上；
        [address]用来表示dnw想告诉开发板，这个文件想保存在的SDRAM地址；
        可以不写[address]，默认为0x30000000；
        bootloader会自己决定把文件保存在SDRAM哪里，是否使用[address]取决于bootloader。


2. 开发板的u-boot启动时，在串口工具上输入空格键，u-boot将输出如下菜单：
##### 100ask Bootloader for OpenJTAG #####
[n] Download u-boot to Nand Flash
[o] Download u-boot to Nor Flash               // 如果是Nand Flash启动的话，这个菜单项没有
[k] Download Linux kernel uImage
[j] Download root_jffs2 image
[y] Download root_yaffs image
[d] Download to SDRAM & Run
[z] Download zImage into RAM
[g] Boot linux from RAM
[f] Format the Nand Flash
[s] Set the boot parameters
[b] Boot the system
[r] Reboot u-boot
[q] Quit from menu

输入前面的小写字母即可启动下载，然后使用dnw工具发送文件。
比如：
a. 在u-boot界面输入k后，u-boot将等待主机发出内核映象，这时在主机上运行“sudo dnw uImage”即可发送内核给u-boot；
b. 在u-boot界面输入y后，u-boot将等待主机发出yaffs文件系统映象，这时在主机上运行“sudo dnw fs_mini_mdev.yaffs2”即可发送给u-boot；
c. 在u-boot界面输入d后，u-boot将等待主机发出文件，这时在主机上运行“sudo dnw uart.bin 0x31000000”即可把uart.bin发送给u-boot，
   u-boot接收到文件及地址0x31000000，会把uart.bin的内容存放在0x31000000处，然后跳转去执行它
   
   
3. 也可以不使用u-boot的菜单，输入q退出菜单，然后使用u-boot的命令进行操作。
usb命令的使用方法可以输入“help usbslave”命令看到：
usbslave [wait] [loadAddress]
"wait" is 0 or 1, 0 means for return immediately, not waits for the finish of transferring

这表示：运行usbslave即可启动USB下载，[wait]、[loadAddress]这两个地址是可选的；
        如果[wait]的值是0，u-boot将不等待USB传输完成，这时你可以立刻输入下一条u-boot命令；
        如果[wait]的值是1，u-boto将等待USB传输完成，完成之后你才能输入下一个u-boot命令；
        如果指定[loadAddress]，那么下载的文件将保存在SDRAM地址[loadAddress]处，否则存放地址由主机的dnw命令指定。
``` 



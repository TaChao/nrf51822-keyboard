# nrf51822-keyboard

## 概述

这是一个基于nrf51822蓝牙键盘的固件，使用了nRF SDK 10.0作为底层硬件驱动，并使用TMK键盘库作为键盘功能的上部实现。

## 软件

目录说明：

- bootloader：用于DFU更新固件的Bootloader（暂时无效）
- main：键盘主程序
- sdk：nRF SDK 10.0 里用到的源码文件
- tmk：TMK源码
- usb：双模的USB部分固件
- KeymapDownloader：配列下载器源码
- hex：预编译的固件hex文件

## 硬件

最初这个固件是[Jim](https://www.lotlab.org/)为BLE4100设计的，关于BLE4100可以参见[这个页面](https://wiki.lotlab.org/page/ble4100/advanced/)

后续Jim加入了tmk的支持，并首先加入了基于GH60的60%键盘：Lot60-BLE

后面个人采用E73-2G4M04S1D这个蓝牙模块重新设计了个人的60%键盘：GT-BLE60 (注：此分支不再适合Lot60-BLE)

硬件部分采用NRF51822作为键盘主控、蓝牙模块。CH552T（或CH554T）通过UART和NRF51822通讯，实现USB模块。详细硬件列表可以参看BOM清单

<img alt="Keyboard图片" src="https://notes.glab.online/img/ble60.pcb2.jpg" width="60%" />

## 编译

1. 键盘固件编译  

   安装keil，并打开`main/project/arm5_no_packs/`目录下的keil工程，编译键盘固件；

   安装keil，并打开`bootloader/project/arm5_no_packs/`目录下的keil工程，编译DFU升级Bootloader固件；
   
2. USB模块固件编译  

   安装Code Blocks，SDCC，并打开`usb/project/CH554.cbp`工程文件，编译USB模块固件
   
## 烧录

1. 键盘固件需要Jlink通过SWD接口（PCB有预留）烧入，后续烧录可通过烧入的Bootloader程序DFU升级

2. USB模块固件可用PC程序WCHISPTool直接通过USB连接烧入

## 键盘使用说明 

-  **开机按键：SPACE+U** - 每次自动休眠或手动休眠后按任意键唤醒键盘，同时按下SPACE+U方可开机。
  
-  **清空蓝牙绑定信息按键：SPACE+E** - 每次休眠后唤醒同时按SPACE+E可以清空蓝牙绑定信息。操作方式为按下SPACE+U开机后立即按下SPACE+E；
  
-  **切换连接模式按键：Fn2+TAB** - 在通过USB和蓝牙同时连接一台设备（也可通过USB连接一台设备、蓝牙连接另一台设备）的情况下，按Fn2+TAB可以切换连接模式。如未同时使用USB模式和蓝牙模式，此按键无效。*注:GT-BLE60默认将APP/MENU键设定为Fn2键,可通过配例自由设定更改*
  
-  **休眠按键：Fn2+ESC** - 按Fn2+ESC键可以直接进入休眠模式，再按SPACE+U进行开机。

-  **清空Keymap自定义配例：SPACE+BACKSPACE** -  每次休眠后唤醒同时按SPACE+BACKSPACE可以清空自定义配例信息。如果出现按键错乱，也可以采用此键恢复初始配例。其余BOOTMAGIC键参考TMK，是基本一样的。
  
-  **关于耗电** - 由于硬件上采用的低功耗蓝牙芯片，功耗控制的相当的好。官方数据来看，使用时耗电每小时为10ma左右，休眠时耗电为5ua。从自己使用感受看，1000mah的锂电池，每天2小时使用时间，大体使用时间为80天以上。如果自己调整源码的相关省电参数，功耗还可以继续降低。 

-  **关于蓝牙通讯** - 蓝牙通讯上，延迟基本不存在，通过KeyboardTest测试出来的延迟，蓝牙模式下单按大约是120ms，双按键大概是2ms，USB模式下单按键大约是135ms，双按键大约是2ms（个人认为这个测试数据仅供参考，并不一定科学，因为居然比AKKO 3108的数据还好 ））。由于是低功耗，实测有效使用距离是5米内。耗电也和蓝牙信号有关，信号越好，耗电越低。
  
-  **相关参数的设定** - 考虑到耗电问题，正常键盘扫描按键输入为8ms一次，回报率为125Mhz;如果两分钟不按键转入慢速扫描，100ms一次，当有按键按下，又自动转入正常扫描速度10ms一次；如果15分钟无按键行为将自动转入休眠模式，此时要重新启用键盘，只需要SPACE+U就可唤醒（唤醒动作后约1-2s可以正常输入）。

- **自定义配例** - 自定义配例采用Tkg网页+配例下载工具的方式实现：通过网站（http://kb.glab.online）配置好配例，然后下载keymap.eep文件，通过KeymapDownloader刷配例软件刷入蓝牙芯片。


更多内容可以参看[这里](https://notes.glab.online)
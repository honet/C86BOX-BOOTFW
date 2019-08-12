# C86BOX Bootloader Firmware
<img src="http://c86box.com/images/c86box_wpc2.jpg" width=800>
Bootloader Firmware for C86BOX (NEC PC-98Series C-BUS to USB Bridge BOX).   

C86BOX http://c86box.com/ の内部ファームウェア（ブートローダー部）です。
PSoC Creator 用のプロジェクトファイルです。


## 関連ソフト
#### C86BoxFirmware Bootloader 
C86BOXファームウェアのブートローダ部。本ソフト。  
https://github.com/honet/C86BOX-BOOTFW

#### C86BoxFirmware
C86BOXファームウェアの本体。  
https://github.com/honet/C86BOX-FW

#### C86CTL
C86BOXをWindowsから制御する際に使うライブラリ  
https://github.com/honet/c86ctl

#### C86BoxConfig, Util, Sample
C86BOXへボード種別を指定したりするためのwindows用ユーティリティ  
https://github.com/honet/C86BoxUtils

#### C86BoxFirmwareUpdater
ブートローダが書き込まれたC86BOXのファームウェアを更新するためのwindows用ユーティリティ  
https://github.com/honet/C86BoxUpdater



## NOTE
- リリース時は PSoC Creator 3.0 でビルドしています。3.x系であれば問題無くビルド出来ると思います。
- デバッグを行う際や、ブートローダFWを書き込むには
[miniProg3](https://japan.cypress.com/documentation/development-kitsboards/cy8ckit-002-psoc-miniprog3-program-and-debug-kit
)
を利用します。

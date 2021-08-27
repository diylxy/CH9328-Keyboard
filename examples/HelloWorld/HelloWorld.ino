/*
 * CH9328Keyboard Library example(Hello World).
 * CH9328键盘库范例程序
 * ===============English Ver.=================== 
 * Connect your CH9328's RST to Arduino/ESP8266/ESP32's any GPIO and 
 * connect your CH9328's RxD to Arduino/ESP8266/ESP32's TxD.
 * Maybe you can use a software serial, but I haven't tested it.
 * Tested on ESP8266.
 * ==================中文原版===================== 
 * CH9328的复位连接到Arduino的任意一引脚，RxD连到TxD
 * 可能可以用软件串口，但是我还没试过。
 * 在ESP8266上测试通过。
 * 如果你想改变默认的9600波特率，在Library/CH9328Keyboard/extra下有配置工具，同时也有数据手册，可以参考。
====================== License ========================

Copyright (c) Lxy <1452206376@qq.com>. All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
=======================================================
 */

#include <CH9328Keyboard.h>
#define PINRST 10
#define BAUDRATE 9600              //Default is 9600.
void setup()
{
  Serial.end();
  Keyboard.begin(&Serial, PINRST, BAUDRATE);
  delay(1000);
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.println("notepad");
  delay(1000);
  Keyboard.print("Hello world From CH9328Keyboard Library\n");
  Keyboard.write('\n');
  delay(10);
  Keyboard.press(KEY_LEFT_GUI);
  delay(10);
  Keyboard.release(KEY_LEFT_GUI);
}

void loop()
{
  delay(10);
}

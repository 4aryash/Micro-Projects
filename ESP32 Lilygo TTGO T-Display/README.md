# Initial Setup Process for ESP32 Lilygo TTGO T-Display
<br>

#### Links I used to get started
https://www.lilygo.cc/products/lilygo%C2%AE-ttgo-t-display-1-14-inch-lcd-esp32-control-board <br>
https://www.reddit.com/r/esp32/comments/vlxpl7/readymade_projects_for_lilygo_ttgo_tdisplay/ <br>
https://youtu.be/b8254--ibmM?si=lmYXBd2JqC5Z2a9K<br> <br>

#### Steps to get started (Windows):
<ul>
  <li>Download the Arduino IDE</li>
  <li>Go to File>Preferences>Additional Boards Manager URLs and enter "https://dl.espressif.com/dl/package_esp32_index.json".</li>
  <li>Now go to Boards Manager on the IDE and search/install esp32 board manager module. 2.0.17. Also, open the Library Manager on the IDE and search/install the library - TFT_eSPI.</li>
  <li>Open File Explorer and go to /Arduino/libraries/TFT_eSPI. Find the "User_Setup_Select.h" and open it with notepad/editor. Comment out the <code>#include <User_Setup.h></code> and uncomment the <code>#include <User_Setups/Setup25_TTGO_T_Display.h></code> Save the file and exit.</li>
  <li>Plug in your ESP32 Lilygo TTGO T-Display. Then go to Arduino IDE, open Tools tab and select the <code>TTGO LoRa32-OLED</code> board.</li>
  <li>Select the corresponding port (if you're not sure of the port - go to Device Manager in Control Panel > Drop open the Ports tab and you'll see a list of all communication ports active on your machine > Unplug your Lilygo TTGO T-Display and check which COM port got disconnected. In my case, it was <code>USB-Enhanced-SERIAL CH9102 (COM14)</code></li>
  <li>Now go back to your Arduino IDE and select the correct board and port.</li>
  <li>To test the whole setup, click on File>Examples>TFT_eSPI (Scroll to the bottom)>160 x 128>TFT_Print_Test</li>
  <li>Compile and Upload the code, and your display should look like this below</li><br>
  <img src="https://github.com/4aryash/Micro-Projects/assets/31902160/5b1ca434-ee71-400f-aada-3ed5786894c0" width="600"/>
</ul> <br>

##### PS
<p>It took me a while to setup my board because I found out that Espressif recently rolled out a new version 3.0 of their board manager, and I was on the 3.0.1 version (which gave me multiple compiling errors). At this time, switching back to the 2.0.17 version solved my problem and gave me immense relief from digging the internet for 2 days to get my display running. <br>
Thanks to this article - https://github.com/Bodmer/TFT_eSPI/issues/3346
</p><br>

#### Key Takeaway
<p>Always google your compilation errors if you can't understand what they mean. You're not the first one, and there's almost always someone else who's encountered it before you.</p> <br>

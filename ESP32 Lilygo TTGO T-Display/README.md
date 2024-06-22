## Initial Setup Process for ESP32 Lilygo TTGO T-Display
<br>
<a href= "https://www.lilygo.cc/products/lilygo%C2%AE-ttgo-t-display-1-14-inch-lcd-esp32-control-board">Link to the board</a>
<br><br>

<p>Links I used to get started</p>
https://www.reddit.com/r/esp32/comments/vlxpl7/readymade_projects_for_lilygo_ttgo_tdisplay/ <br>
https://youtu.be/b8254--ibmM?si=lmYXBd2JqC5Z2a9K<br> <br>

<p>It took me a while to setup my board because I found out that Espressif recently rolled out a new version 3.0 of their board manager, and I was on the 3.0.1 version (which gave me multiple compiling errors).
At this time, switching back to the 2.17 version solved my problem and gave me immense relief from digging the internet to get my display running. Thanks to this article - https://github.com/Bodmer/TFT_eSPI/issues/3346
<br><br>
Key Takeaway - Always google your compilation errors if you can't understand what they mean. You're not the first one, and there's almost always someone else who's encountered it before you.
</p>

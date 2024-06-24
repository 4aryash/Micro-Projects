import time
from sense_hat import SenseHat

sense = SenseHat()

for i in reversed(range(0,10)):
	sense.show_letter(str(i))
	time.sleep(1)

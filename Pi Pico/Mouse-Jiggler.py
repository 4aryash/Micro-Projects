import pyautogui as pag
import random
import time

for i in range(5):
	r1 = random.randint(0,1200)
	r2 = random.randint(0,600)
	pag.moveTo(r1, r2)
	time.sleep(1)

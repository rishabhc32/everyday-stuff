import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while(True):

  ret,fire = cap.read()

  fire = cv2.GaussianBlur(fire,(7,7),0)
  fire = cv2.resize(fire, (0,0), fx=0.2, fy=0.2) 
  #fire2 = cv2.resize(fire2, (0,0), fx=0.2, fy=0.2) 

  for i in range(fire.shape[0]):
    for j in range(fire.shape[1]):
      if (fire[i,j,2] > 240) and (fire[i,j,2] <= 250) and (fire[i,j,2] > fire[i,j,1]) and (fire[i,j,2] > fire[i,j,0]):
        pass
      else:
        fire[i,j] = [0,0,0]

  fire3 = cv2.cvtColor(fire, cv2.COLOR_BGR2HSV)

  gray = cv2.cvtColor(fire, cv2.COLOR_BGR2GRAY)

  ret,thresh = cv2.threshold(gray,127,255,0)

  image,contours,_ = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_NONE)

  if contours:
    contours = max(contours,key = cv2.contourArea)

    print(cv2.contourArea(contours))

    if cv2.contourArea(contours) > 400:
      print("YES")
    else:
      print("NO")

  cv2.imshow('frame', fire3)
  
  if cv2.waitKey(1) == 27:
    break

cap.release()
cv2.destroyAllWindows()
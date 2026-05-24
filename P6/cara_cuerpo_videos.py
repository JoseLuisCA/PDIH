import cv2

# Cargamos clasificadores para cara y cuerpo
modeloCara = cv2.CascadeClassifier('xml/haarcascade_frontalface_default.xml')
modeloCuerpo  = cv2.CascadeClassifier('xml/haarcascade_fullbody.xml')

# abrimos el flujo de vídeo desde la cámara o desde un vídeo
#camara = cv2.VideoCapture(-1)
camara = cv2.VideoCapture('mp4/v5.mp4')

while camara.isOpened():
    _, img = camara.read()
    color = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)

    faces = modeloCara.detectMultiScale(color, 1.3, 4)
    for (x, y , w ,h) in faces:
        # Dibujamos rectángulo en las caras detectadas
        cv2.rectangle(img, (x,y), (x + w, y + h), (255, 0 , 0), 3)

    bodies = modeloCuerpo.detectMultiScale(color, 1.1, 10)
    for (x, y , w ,h) in bodies:
        # Dibujamos rectángulo en los cuerpos detectados
        cv2.rectangle(img, (x,y), (x + w, y + h), (0, 255 , 0), 3)

    cv2.imshow('img', img)
    key = cv2.waitKey(1)
    if key == 27:
        break

camara.release()
cv2.destroyAllWindows()

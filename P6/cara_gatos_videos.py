import cv2

# Cargamos el modelo clasificador para la cara del gato
modeloCara = cv2.CascadeClassifier('xml/haarcascade_frontalcatface.xml')

# Abrimos la cámara o cargamos un vídeo:
#camara = cv2.VideoCapture(-1)
camara = cv2.VideoCapture('mp4/v6.mp4')

while camara.isOpened():
    # Cargamos en img lo capturado por la cámara
    _, img = camara.read()

    color = cv2.cvtColor(img, cv2.COLOR_BGR2BGRA)

    # Detectamos la cara del gato
    faces = modeloCara.detectMultiScale(color, 1.1, 4)

    # Pintamos el rectángulo sobre la cara del gato
    for (x, y , w ,h) in faces:
        cv2.rectangle(img, (x,y), (x+w, y+h), (255, 0 , 0), 3)

    # Lo mostramos en pantalla mientras no pulsemos la tecla 'esc'
    cv2.imshow('img', img)
    key = cv2.waitKey(1)
    if key == 27:
        break

camara.release()
cv2.destroyAllWindows()

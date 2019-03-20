import cv2
import numpy


class Face:

    def __init__(self):
        self.face_detector = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

    def locations(self, image: numpy.ndarray) -> []:
        if len(image.shape) == 3:
            image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        image = cv2.equalizeHist(image)
        return self.face_detector.detectMultiScale(image,
                                                   scaleFactor=1.1,
                                                   minNeighbors=3,
                                                   minSize=(32, 32))

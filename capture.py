import cv2


class Capture:
    def __init__(self, id_or_path=0):
        self.capture = cv2.VideoCapture(id_or_path)
        self.fps = 0.0

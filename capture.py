import cv2
import numpy


class Capture:
    def __init__(self, id_or_path=0):
        # capture
        self.capture = cv2.VideoCapture(id_or_path)
        # parameters
        self.fps = round(self.capture.get(cv2.CAP_PROP_FPS), 2)
        self.width = round(self.capture.get(cv2.CAP_PROP_FRAME_WIDTH), 2)
        self.height = round(self.capture.get(cv2.CAP_PROP_FRAME_HEIGHT), 2)

    def __del__(self):
        self.capture.release()

    def frame(self, ratio: float = 1.00) -> numpy.ndarray:
        if self.capture.isOpened():
            ret, frame = self.capture.read()
            if ret:
                return cv2.resize(frame, (0, 0), fx=ratio, fy=ratio)
        return numpy.ndarray([0, 0])

CC = g++

CFLAGS += -g -O3 -Wall -IC:/Develop/MSYS2/mingw64/include/opencv4
LDFLAGS += -LC:/Develop/MSYS2/mingw64/lib \
	-lopencv_aruco \
	-lopencv_bgsegm \
	-lopencv_calib3d \
	-lopencv_ccalib \
	-lopencv_core \
	-lopencv_datasets \
	-lopencv_dnn -lopencv_dnn_objdetect \
	-lopencv_dpm \
	-lopencv_face \
	-lopencv_features2d -lopencv_xfeatures2d \
	-lopencv_flann \
	-lopencv_fuzzy \
	-lopencv_gapi \
	-lopencv_hdf \
	-lopencv_hfs \
	-lopencv_highgui \
	-lopencv_img_hash \
	-lopencv_imgcodecs -lopencv_imgproc -lopencv_ximgproc \
	-lopencv_line_descriptor \
	-lopencv_ml \
	-lopencv_objdetect -lopencv_xobjdetect \
	-lopencv_optflow \
	-lopencv_ovis \
	-lopencv_phase_unwrapping \
	-lopencv_photo -lopencv_xphoto \
	-lopencv_plot \
	-lopencv_reg \
	-lopencv_rgbd \
	-lopencv_saliency \
	-lopencv_sfm \
	-lopencv_shape \
	-lopencv_stereo \
	-lopencv_stitching \
	-lopencv_structured_light \
	-lopencv_superres \
	-lopencv_surface_matching \
	-lopencv_text \
	-lopencv_tracking \
	-lopencv_video -lopencv_videoio -lopencv_videostab \
	-lopengl32 \
	-lglu32


MONITOR = monitor.exe
MONITOR_OBJS = monitor.o \
	video/capture.o \
	face/face.o \
	piggy/piggy.o

RECORDER = recorder.exe
RECORDER_OBJS = recorder.o \
	video/capture.o \
	video/writer.o \
	face/face.o \
	piggy/piggy.o

OBAMA = obama.exe
OBAMA_OBJS = obama.o \
	face/face.o \
	piggy/piggy.o

# all objs
OBJS = monitor.o \
	recorder.o \
	video/capture.o \
	video/writer.o \
	face/face.o \
	piggy/piggy.o \
	obama.o

all:$(MONITOR) $(RECORDER) $(OBAMA)
$(MONITOR):$(MONITOR_OBJS)
	$(CC) $(CFLAGS) $(MONITOR_OBJS) -o $(MONITOR) $(LDFLAGS)
$(RECORDER):$(RECORDER_OBJS)
	$(CC) $(CFLAGS) $(RECORDER_OBJS) -o $(RECORDER) $(LDFLAGS)
$(OBAMA):$(OBAMA_OBJS)
	$(CC) $(CFLAGS) $(OBAMA_OBJS) -o $(OBAMA) $(LDFLAGS)
$(OBJS):%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

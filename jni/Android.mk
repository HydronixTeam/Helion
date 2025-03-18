LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := dobby
LOCAL_SRC_FILES := $(LOCAL_PATH)/libraries/Dobby/$(TARGET_ARCH_ABI)/libdobby.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := helion
LOCAL_STATIC_LIBRARIES := dobby
LOCAL_SRC_FILES := sources/Helion.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/includes
LOCAL_LDLIBS := -landroid -llog
include $(BUILD_SHARED_LIBRARY)


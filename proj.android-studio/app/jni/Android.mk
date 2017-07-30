LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame


HELLOCPP_FILES  := $(wildcard $(LOCAL_PATH)/hellocpp/*.cpp)
HELLOCPP_FILES  := $(HELLOCPP_FILES:$(LOCAL_PATH)/%=%)

CLASSES_FILES   := $(wildcard $(LOCAL_PATH)/../../../Classes/*.cpp)
CLASSES_FILES   := $(CLASSES_FILES:$(LOCAL_PATH)/%=%)

LOCAL_SRC_FILES := $(HELLOCPP_FILES)
LOCAL_SRC_FILES += $(CLASSES_FILES)

# LOCAL_SRC_FILES := hellocpp/main.cpp \
#                    ../../../Classes/AppDelegate.cpp \
#                    ../../../Classes/MainScene.cpp \
# 									 ../../../Classes/FieldCell.cpp \
# 									 ../../../Classes/GameField.cpp \
# 									 ../../../Classes/Grid.cpp \
# 									 ../../../Classes/Tank.cpp \
# 									 ../../../Classes/Weapon.cpp \
# 									 ../../../Classes/Bullet.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END

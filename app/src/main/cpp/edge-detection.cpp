#include <jni.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_YashUppal_edgedetectionviewer_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    return env->NewStringUTF("Hello from JNI");
}

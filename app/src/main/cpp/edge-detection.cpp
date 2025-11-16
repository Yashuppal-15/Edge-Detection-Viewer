#include <jni.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <android/log.h>

#define LOG_TAG "EdgeDetection"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

using namespace cv;

extern "C" JNIEXPORT jbyteArray JNICALL
Java_com_YashUppal_edgedetectionviewer_MainActivity_detectEdges(
        JNIEnv* env,
        jobject /* this */,
        jbyteArray yuv420Data,
        jint width,
        jint height) {

    jbyte* yuvData = env->GetByteArrayElements(yuv420Data, nullptr);
    jsize yuvSize = env->GetArrayLength(yuv420Data);

    // Convert YUV420 to grayscale
    Mat yuvMat(height + height/2, width, CV_8UC1, (uchar*)yuvData);
    Mat gray(height, width, CV_8UC1, (uchar*)yuvData);

    // Apply Canny edge detection
    Mat edges;
    Canny(gray, edges, 100, 200);

    // Convert edges to byte array
    jbyteArray result = env->NewByteArray(edges.total());
    env->SetByteArrayRegion(result, 0, edges.total(), (jbyte*)edges.data);

    env->ReleaseByteArrayElements(yuv420Data, yuvData, JNI_ABORT);

    LOGI("Edge detection completed");
    return result;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_YashUppal_edgedetectionviewer_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    return env->NewStringUTF("OpenCV Edge Detection Ready");
}

#include <jni.h>
#include <string>
#include "cppdemo/unicom.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_org_example_android_1jni_1demo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    hello.append("\n\n");
    hello.append(cppdemo::currentDate());
    return env->NewStringUTF(hello.c_str());
}

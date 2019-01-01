#include <napi.h>

Napi::Value Add(const Napi::CallbackInfo& Info) {
    Napi::Env env = Info.Env();

    if(Info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if(!Info[0].IsNumber() || !Info[1].IsNumber()) {
        Napi::TypeError::New(env, "Wrong number of arguments");
        return env.Null();
    }

    double num1 = Info[0].As<Napi::Number>().DoubleValue();
    double num2 = Info[1].As<Napi::Number>().DoubleValue();

    Napi::Number num = Napi::Number::New(env, num1+num2);

    return num;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "addNum"), 
        Napi::Function::New(env, Add));

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

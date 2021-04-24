#include "pch.h"
#include "CPPFuns.h"
#include "string"

std::string s_strDemo[2] = { "string_0", "string_1" };

extern "C" {
    CPPFuns_API int CPPFuns_Init() {
        printf("in cpp: CPPFuns_Init\n");
        return 0;
    }
    CPPFuns_API int CPPFuns_Cleanup() {
        printf("in cpp: CPPFuns_Cleanup\n");
        return 0;
    }
    CPPFuns_API int CPPFuns_GetStringLength(const char* sz) {
        if (sz == nullptr) {
            printf("in cpp: CPPFuns_GetStringLength(null)\n");
            return 0;
        }
        printf("in cpp: CPPFuns_GetStringLength(%s)\n", sz);
        return (int)strlen(sz);
    }
    CPPFuns_API const char* CPPFuns_GetDemoString(int index) {
        printf("in cpp: CPPFuns_GetDemoString(%d)\n", index);
        if (index == 0) {
            return s_strDemo[0].c_str();
        }
        else {
            return s_strDemo[1].c_str();
        }
    }

    struct param {
        int a;
        int b;
        char c;
        char* s;
        float f;
        int arr[3];
    };

    void CPPFuns_API CPPFuns_PrintStruct(struct param arg){
        printf("in cpp: CPPFuns_PrintStruct:%d, %d, %c, %s, %f, [%d, %d, %d]\n",
            arg.a, arg.b, arg.c, arg.s, arg.f, 
            arg.arr[0], arg.arr[1], arg.arr[2]);
    }

    void CPPFuns_API CPPFuns_PrintStructPoint(struct param* arg){
        printf("in cpp: CPPFuns_PrintStruct:%d, %d, %c, %s, %f, [%d, %d, %d]\n",
            arg->a, arg->b, arg->c, arg->s, arg->f,
            arg->arr[0], arg->arr[1], arg->arr[2]);
    }
}
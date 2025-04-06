#include <iostream>

using namespace std;

class Json {
public:
    static Json Serialize(char* data) {
        return move(_Serialize(data));
    }

    static string Deserialize_string(Json object, bool throwError = false) {
        string ret;
        char* deserialized = _Deserialize_c(object);
        ret = deserialized;
        delete deserialized;
        return move(ret);
    }

    static char* Deserialize_c(Json object, bool throwError = false) {
        return _Deserialize_c(object, throwError);
    }
private:
    static Json _Serialize(char* data) {

    }

    static inline char* _Deserialize_c(const Json object, bool throwError = false) {
        char* ret;

        
        return ret;
    }
};

int main() {
}
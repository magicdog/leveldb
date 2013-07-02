#include <iostream>
#include <cstring>
using namespace std;

bool isLittle = false;// low value in low address

void encode_fixed32(char *buf, unsigned int value) {
    if (isLittle)  {
        memcpy(buf, &value, sizeof(value));
    } else {
        buf[0] = value & 0xff;
        buf[1] = (value>>8) & 0xff;
        buf[2] = (value>>16) & 0xff;
        buf[3] = (value>>24) & 0xff;
    }
}

char * encode_varint32(char *dst, unsigned int value) {
    if ()
}

char* encode_varint64(char *dst, unsigned int value) {
}

unsigned int decode_fixed32(const char* ptr) {
}

const char* decode_varint32(const char* p, const char* limit, unsigned int *value) {

}


int main() {
    char * buffer = new char[5];
    memset(buffer,0,sizeof(buffer));
    encode_fixed32(buffer, 2);
    for (int i=0;i<5;i++)
       cout <<(int) buffer[i] << endl;
    return 0;
}


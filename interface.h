#include <cstdint>

class Interface
{
    enum spi_mode_t
    {
        MODE_WRITE = 0,
        MODE_READ = 1
    };

private:

    uint8_t _sck;   // serial clock
    uint8_t _data;  // data line
    uint8_t _res;   // reset
    uint8_t _wr;    // select mode (write/read)
    uint8_t _ce;    // chip enable

public:

    void read(char *data);
    void writeByte(uint8_t byte);
    void writeMsg(char *data, uint8_t len);
    void start();           // sck 0, ce 0
    void stop();            // ce 1
    void mode(int mode);    // 0 - write, 1 - read
    void reset();           // reset = 1
};



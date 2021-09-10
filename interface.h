/**
 * @file interface.h
 * @author Vladislav Bakanov
 * @brief My interface
 * @version 0.1
 * @date 2021-09-10
 */
#include <cstdint>

class Interface
{
    /// Перечисление режимов порта data
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

    /**
     * @brief Чтение данных
     * @param data Указатель на массив для записи полученных данных
     */
    void read(char *data);

    /**
     * @brief Передача 1 байта данных
     * @param byte Байт, который следует передать
     */
    void writeByte(uint8_t byte);

    /**
     * @brief Передача сообщения произвольной длинны
     * @param data  Указатель на отправляемое сообщение
     * @param len   Дина сообщения
     */
    void writeMsg(char *data, uint8_t len);

    /**
     * @brief Изменение значения портов sck, ce для начала чтения/записи
     */
    void start(); 

    /**
     * @brief Изменение значения портов sck, ce для конца чтения/записи
     */
    void stop();            

    /**
     * @brief Выбор режима чтения или записи 
     * @param mode  Режим чтения или записи
     */
    void mode(int mode); 

    /**
     * @brief Изменение параметра линии res для вызова сброса
     */
    void reset();           
};



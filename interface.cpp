#include "interface.h"

void Interface::writeByte(uint8_t byte)
{
    start();
    for(int i = 0; i < 8; i++)
    {
        if (byte & 0x80)
        _data = 1;
        else
        _data = 0;
        byte << 1;

        _sck = 1; 
        /* convert byte */
        //if (_data)
        //byte |= 0x01;
        _sck = 0; 
    }
    stop();
}


void Interface::writeMsg(char *data, uint8_t len)
{
    Interface::mode(spi_mode_t::MODE_WRITE);
    for (int8_t i = 0; i < len; i++)
    {
        writeByte((uint8_t)data[i]);
    }
}


void Interface::read(char *data)
{
    int size = 0;
    uint8_t byte;
    Interface::mode(spi_mode_t::MODE_READ);
    start();
    while (!_ce)
    {
        byte = 0;
        for (int i = 0; i < 8; i++)
        {
            if (_data)
            {
                byte |= 0x01;
                byte << 1;
            }
            else
            {
                byte << 1;
            }
        }
        data[size] = (char)byte;
    }
    stop();
}


void Interface::mode(int mode)
{
    if (mode)
    {
        Interface::_wr = 1;
    }
    else
    {
        Interface::_wr = 0;
    }
}


void Interface::start()
{
    Interface::_sck = 0;
    Interface::_ce = 0;
}


void Interface::stop()
{
    Interface::_ce = 1;
}


void Interface::reset()
{
    Interface::_res = 1;
}
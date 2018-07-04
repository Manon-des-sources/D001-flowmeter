#include"mb_master.h"

uint16_t mb_make_crc16(uint16_t count, uint8_t *pdata)
{
    uint16_t i, j;
    uint16_t crc16 = 0;
    crc16 = 0xFFFF;  	            //step 1
    for(i = 0; i < count; i++)      //step 6
    {
        crc16 ^= *(pdata + i);      //step 2 CRC与校验数据异或	 //得出数据的按位反
        for(j = 0; j < 8; j++)      //step5
        {
            if(crc16 & 0x1)  	    //step 4  最低位是否为1
            {
                crc16 >>= 1;  	    //step 3
                crc16 ^= 0xA001;
            }
            else
                crc16 >>= 1;   	    //step 3
        }      		                //step 5
    }
    return crc16;
}

#include <QCoreApplication>
#include "stdio.h"
#include "stdlib.h"


struct frame{
    uint8_t addr;
    uint8_t func;
    uint8_t data_size;
    uint8_t data12[12];
        uint8_t crcL;
        uint8_t crcH;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}


uint8_t  *T  = "{\"温度\":";
uint8_t  *PH = ",\"PH\":";
uint8_t  *DO = ",\"余氯\":";
uint8_t  *NTU= ",\"浊度\":";
uint8_t  *GC = ",\"电导\":";
void Unpack(uint8_t byte)
{
    static uint16_t received_bytes = 0;
    uint16_t read_index = 0;
    struct frame *packet;
    uint8_t tmp[15];
    uint16_t crc;
    uint8_t Jsion[1];

    if(received_bytes >= sizeof(RX1_Buffer)) received_bytes=0;
    RX1_Buffer[received_bytes] = byte;
  received_bytes++;
    while(received_bytes>=17)
    {
       packet = (struct frame*) &RX1_Buffer[read_index];
         if(packet->addr == 0x01 && packet->func == 0x03)
         {
//		   printf("1\r\n");
//			 TX1_write2buff(packet->data_size);
           if(packet->data_size + 5 > received_bytes) return;
//			 printf("2\r\n");
             memcpy(tmp,&RX1_Buffer[read_index],packet->data_size+3); //将所需数据考出
             crc = crc16(tmp,packet->data_size+3);
             TX1_write2buff(crc>>8&0xff);
//			 TX1_write2buff(crc&0xff);

//        TX1_write2buff(packet->crcH);
                TX1_write2buff(packet->crcL);
             if((packet->crcL == (crc>>8&0xff))&&(packet->crcH == (crc&0xff)))
             {
                    TX1_write2buff(packet->crcL);
                //memcpy(tmp,packet,packet); //将所需数据考出
                 sprintf(Jsion,"%s%.2f%s%d",
                          T,packet->data12[0]<<8|packet->data12[1]/100,
//									PH,packet->data12[2]<<8|packet->data12[3]/1000,
//									DO,packet->data12[4]<<8|packet->data12[5]/1000,
//									NTU,packet->data12[6]<<8|packet->data12[7]/100,
                                    GC,packet->data12[8]<<8|packet->data12[9]
                                    );
                    printf("%s",Jsion);

                    received_bytes -= 17;
          read_index += 17;
                    continue;
             }
         }
         received_bytes--;
     read_index++;

    }
    if(read_index != 0)
        memmove(RX1_Buffer, &RX1_Buffer [read_index], received_bytes);
}


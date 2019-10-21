void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

// USAGE: calculate the CRC for a message and update the message CRC
unsigned short crc = crc16_lsb(msg, msg [1]-2);
msg [msg [1]-2] = (unsigned char) (crc&0xFF);
msg [msg [1]-1] = (unsigned char) (crc>>8);

unsigned short crc16_lsb(unsigned char *pData, int length)
     {
        unsigned char i;
        unsigned short data, crc;
crc = 0xFFFF;
        if (length == 0)
           return 0;
do {
data = (unsigned int)0x00FF & *pData++;
crc = crc ^ data;
for (i = 8; i > 0; i--)
{
   if (crc & 0x0001)
     crc = (crc >> 1) ^ 0x8408;
   else
     crc >>= 1;
     }
   }while (--length);
crc = ~crc;
  return (crc);
}

#ifndef _CRC_H
#define _CRC_H

/********************************************************************************************/
//�������Ͷ��壺�ڲ�ͬ�ı�����������ϵͳ�н�������
/********************************************************************************************/
typedef  unsigned char		crc_uint8;
typedef  unsigned short		crc_uint16;
typedef  unsigned int		crc_uint32;
/********************************************************************************************/

/********************************************************************************************/
//��������BOOL���͵ı�����
/********************************************************************************************/
//typedef  bool				crc_bool;
typedef  char				crc_bool;
#define  crc_true			1		// true  ���� 1
#define  crc_false			0		// false ���� 0
/********************************************************************************************/

//CRC���㺯��
crc_uint8  Crc_Calculate_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout);
crc_uint16 Crc_Calculate_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout);
crc_uint32 Crc_Calculate_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout);
//CRCУ�麯��
crc_bool Crc_Check_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout);
crc_bool Crc_Check_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout);
crc_bool Crc_Check_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout);
//CRC���ú���
crc_uint8 Crc_Calculate_Crc8(crc_uint8* data, crc_uint32 len);
crc_bool  Crc_Check_Crc8(crc_uint8* data, crc_uint32 len);
crc_uint8 Crc_Calculate_Crc8_Itu(crc_uint8* data, crc_uint32 len);
crc_bool  Crc_Check_Crc8_Itu(crc_uint8* data, crc_uint32 len);
crc_uint8 Crc_Calculate_Crc8_Rohc(crc_uint8* data, crc_uint32 len);
crc_bool  Crc_Check_Crc8_Rohc(crc_uint8* data, crc_uint32 len);



#endif
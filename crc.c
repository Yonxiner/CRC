#include "crc.h"

/********************************************************************************************/
//���ܣ�8BIT�����ݱ�����λ��ת������ȡ����0��7������1��6������������
//���룺data��8BITԴ����
//���أ���ת�������
/********************************************************************************************/
crc_uint8 Reverse_Bit8(crc_uint8 data)
{

	data = ((data >> 1) & 0x55) | ((data << 1) & 0xAA);
	data = ((data >> 2) & 0x33) | ((data << 2) & 0xCC);
	data = ((data >> 4) & 0x0F) | ((data << 4) & 0xF0);
	return data;
}
/********************************************************************************************/
//���ܣ�16BIT�����ݱ�����λ��ת������ȡ����0��15������1��14������������
//���룺data��16BITԴ����
//���أ���ת�������
/********************************************************************************************/
crc_uint16 Reverse_Bit16(crc_uint16 data)
{
	data = ((data >> 1) & 0x5555) | ((data << 1) & 0xAAAA);
	data = ((data >> 2) & 0x3333) | ((data << 2) & 0xCCCC);
	data = ((data >> 4) & 0x0F0F) | ((data << 4) & 0xF0F0);
	data = ((data >> 8) & 0x00FF) | ((data << 8) & 0xFF00);
	return data;
}
/********************************************************************************************/
//���ܣ�32BIT�����ݱ�����λ��ת������ȡ����0��31������1��30������������
//���룺data��32BITԴ����
//���أ���ת�������
/********************************************************************************************/
crc_uint32 Reverse_Bit32(crc_uint32 data)
{
	data = ((data >> 1) & 0x55555555) | ((data << 1) & 0xAAAAAAAA);
	data = ((data >> 2) & 0x33333333) | ((data << 2) & 0xCCCCCCCC);
	data = ((data >> 4) & 0x0F0F0F0F) | ((data << 4) & 0xF0F0F0F0);
	data = ((data >> 8) & 0x00FF00FF) | ((data << 8) & 0xFF00FF00);
	data = ((data >> 16) & 0x0000FFFF) | ((data << 16) & 0xFFFF0000);
	return data;
}
/********************************************************************************************/
//���ܣ�����CRC8
//���룺data  ��Ҫ�����Դ����
//���룺len   ��Ҫ�����Դ���ݵĳ���
//���룺poly  ������ʽֵ
//���룺init  �������ʼֵ
//���룺xorout���������Ҫ����ֵ
//���룺refin �����������Ƿ�ת
//���룺refout���������Ƿ�ת
//���أ�CRC����
/********************************************************************************************/
crc_uint8 Crc_Calculate_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint8	value = init;
	crc_uint8	temp = 0;

	while (len--)
	{
		temp = *(data++);
		//�������ݷ�ת
		if (refin == crc_true) temp = Reverse_Bit8(temp);
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x80) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	//�������������
	value ^= xorout;
	//������ݷ�ת
	if (refout == crc_true) return  Reverse_Bit8(value);
	//������ݲ���ת
	else return value;
}
/********************************************************************************************/
//���ܣ�����CRC16
//���룺data  ��Ҫ�����Դ����
//���룺len   ��Ҫ�����Դ���ݵĳ���
//���룺poly  ������ʽֵ
//���룺init  �������ʼֵ
//���룺xorout���������Ҫ����ֵ
//���룺refin �����������Ƿ�ת
//���룺refout���������Ƿ�ת
//���أ�CRC����
/********************************************************************************************/
crc_uint16 Crc_Calculate_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint16	value = init;
	crc_uint16	temp = 0;

	while (len--)
	{
		temp = *(data++);
		//�������ݷ�ת
		if (refin == crc_true) temp = Reverse_Bit16(temp);
		//�������ݲ���ת
		else temp = temp << 8;
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x8000) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	//�������������
	value ^= xorout;
	//������ݷ�ת
	if (refout == crc_true) return  Reverse_Bit16(value);
	//������ݲ���ת
	else  return value;
}

/********************************************************************************************/
//���ܣ�����CRC32
//���룺data  ��Ҫ�����Դ����
//���룺len   ��Ҫ�����Դ���ݵĳ���
//���룺poly  ������ʽֵ
//���룺init  �������ʼֵ
//���룺xorout���������Ҫ����ֵ
//���룺refin �����������Ƿ�ת
//���룺refout���������Ƿ�ת
//���أ�CRC����
/********************************************************************************************/
crc_uint32 Crc_Calculate_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout)
{
	crc_uint8	count = 0;
	crc_uint32	value = init;
	crc_uint32	temp = 0;

	while (len--)
	{
		temp = *(data++);
		//�������ݷ�ת
		if (refin == crc_true) temp = Reverse_Bit32(temp);
		//�������ݲ���ת
		else temp = temp << 24;
		value ^= temp;
		for (count = 0; count < 8; count++)
		{
			if (value & 0x80000000) value = (value << 1) ^ poly;
			else value = value << 1;
		}
	}
	//�������������
	value ^= xorout;
	//������ݷ�ת
	if (refout == crc_true) return  Reverse_Bit32(value);
	//������ݲ���ת
	else  return value;
}

/********************************************************************************************/
//���ܣ����CRC8
//���룺data  ��Ҫ����Դ����
//���룺len   ��Ҫ����Դ���ݵĳ���
//���룺poly  ������ʽֵ
//���룺init  �������ʼֵ
//���룺xorout���������Ҫ����ֵ
//���룺refin �����������Ƿ�ת
//���룺refout���������Ƿ�ת
//���أ��ɹ�/ʧ��
/********************************************************************************************/
crc_bool Crc_Check_8(crc_uint8* data, crc_uint32 len, crc_uint8 poly, crc_uint8 init, crc_uint8 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_8(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}

/********************************************************************************************/
//���ܣ����CRC16
//���룺data  ��Ҫ����Դ����
//���룺len   ��Ҫ����Դ���ݵĳ���
//���룺poly  ������ʽֵ
//���룺init  �������ʼֵ
//���룺xorout���������Ҫ����ֵ
//���룺refin �����������Ƿ�ת
//���룺refout���������Ƿ�ת
//���أ��ɹ�/ʧ��
/********************************************************************************************/
crc_bool Crc_Check_16(crc_uint8* data, crc_uint32 len, crc_uint16 poly, crc_uint16 init, crc_uint16 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_16(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}

/********************************************************************************************/
//���ܣ����CRC32
//���룺data  ��Ҫ����Դ����
//���룺len   ��Ҫ����Դ���ݵĳ���
//���룺poly  ������ʽֵ
//���룺init  �������ʼֵ
//���룺xorout���������Ҫ����ֵ
//���룺refin �����������Ƿ�ת
//���룺refout���������Ƿ�ת
//���أ��ɹ�/ʧ��
/********************************************************************************************/
crc_bool Crc_Check_32(crc_uint8* data, crc_uint32 len, crc_uint32 poly, crc_uint32 init, crc_uint32 xorout, crc_bool refin, crc_bool refout)
{
	if (Crc_Calculate_32(data, len, poly, init, xorout, refin, refout) == 0)
		return crc_true;
	else return crc_false;
}
/********************************************************************************************/
//���ܣ�����CRC8�����棩
//���룺data  ��Ҫ�����Դ����
//���룺len   ��Ҫ�����Դ���ݵĳ���
//���أ�CRC����
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0x00, 0x00, crc_false, crc_false);
}
/********************************************************************************************/
//���ܣ����CRC8�����棩
//���룺data  ��Ҫ����Դ����
//���룺len   ��Ҫ����Դ���ݵĳ���
//���أ��ɹ�/ʧ��
/********************************************************************************************/
crc_bool Crc_Check_Crc8(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0x00, 0x00, crc_false, crc_false);
}
/********************************************************************************************/
//���ܣ�����CRC8��ITU��
//���룺data  ��Ҫ�����Դ����
//���룺len   ��Ҫ�����Դ���ݵĳ���
//���أ�CRC����
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Itu(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0x00, 0x55, crc_false, crc_false);
}
/********************************************************************************************/
//���ܣ����CRC8��ITU��
//���룺data  ��Ҫ����Դ����
//���룺len   ��Ҫ����Դ���ݵĳ���
//���أ��ɹ�/ʧ��
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Itu(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0x00, 0x55, crc_false, crc_false);
}

/********************************************************************************************/
//���ܣ�����CRC8��ROHC��
//���룺data  ��Ҫ�����Դ����
//���룺len   ��Ҫ�����Դ���ݵĳ���
//���أ�CRC����
/********************************************************************************************/
crc_uint8 Crc_Calculate_Crc8_Rohc(crc_uint8* data, crc_uint32 len)
{
	return Crc_Calculate_8(data, len, 0x07, 0xFF, 0x00, crc_true, crc_true);
}
/********************************************************************************************/
//���ܣ����CRC8��ROHC��
//���룺data  ��Ҫ����Դ����
//���룺len   ��Ҫ����Դ���ݵĳ���
//���أ��ɹ�/ʧ��
/********************************************************************************************/
crc_bool Crc_Check_Crc8_Rohc(crc_uint8* data, crc_uint32 len)
{
	return Crc_Check_8(data, len, 0x07, 0xFF, 0x00, crc_true, crc_true);
}



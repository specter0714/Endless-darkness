//��˼����queue������ͼƬ�������pop��ռ���ڴ�С-------2024.12.20��17:22



//��˼����sleep��������ÿ�μ���ͼƬ��ʱ�����ﵽÿһ�δ�ӡͼƬ��ʱ��������ͬ�� ���ǻ�����ʱһ��ѭ��Ҫ���ض���ͼƬ�����ĵ�ʱ�䳤�����¶���Ҫô���٣� Ҫô����֡�ʵͣ�
//		�����ڿ��ǵļ��ֽ��������1. ÿ��ѭ��ֻloadimageһ��ͼƬ 2. ȡ��ʹ��queue���������飬ѭ��֮ǰ��loadimageȫ��ͼƬ 3. ����ͼƬ����
//		���ڻ���Ҫѧϰ��֪ʶ���Ż��������⣺1. ˫���� 2. ���߳�--------2025.01.01��21:13



//���������ھ���ʹ��vector��ѭ��֮ǰ����ͼƬ��ʹ����ѭ��whileѭ��ʱֻ��Ҫ��ȾͼƬ����-------2025.01.0��21:00



//ѧϰ��ѧϰ��ʵ��˫����ĺ��� beginbatchdraw() �� flushbatchdraw() ����-------2025.01.03��13:21

//��������˫�˶�ս�о��ܸ��ӣ����Ҳ�������Ҫ����ϷЧ����Ȼ������ҪBOOS�ļ��ܺܶ��ǿ��Ч��������������ƫ�ڰ��ģ���Ϊ�ز�ֻ�ҵ�һ�����ڰ���������������ļ��ܹ�����������Ҳ����ͬ
// ���������ݶ���ϷΪ������Ϸ��ֻ��һ������ද������С�֣���BOOS--------2025.01.04�� 20:04

#include<iostream>
#include<windows.h>
#include<string>
#include<easyx.h>
#include<graphics.h>
#include"keyboard.h"
#include"enemy_water.h"
#include"Player.h"
#include"background.h"

#pragma comment(lib, "MSIMG32.LIB")

int main()
{
	initgraph(1280, 720, EW_SHOWCONSOLE);

	bool running = true;





//��������
	//�������
	Player player(17, 6, 5, 3, 4, 7, 7, 3, 18);
	//ˮԪ�ط�ʦ���
	Enemy_water water(8, 10, 8, 3, 3, 6, 7, 21, 27, 32, 12, 12, 7, 16, 8);
	
	//����
	Background background;







	ExMessage msg;//���������Ϣ�ı���

	//���ر���
	background.load_background();

	BeginBatchDraw();

	while (running)
	{

		while (peekmessage(&msg))//��ȡ������Ϣ�����ⲿ���뷵��1������ڹ���ʱ����Ͳ�����ѭ��
		{
			if (msg.message == WM_KEYDOWN)//���̰���
			{
				switch (msg.vkcode)//��ֵ
				{
				case VK_A:
					water.is_move_left = true;
					water.point_right = false;
					break;

				case VK_D:
					water.is_move_right = true;
					water.point_right = true;
					break;

				case VK_W:

					break;

				case VK_S:
					break;

				case VK_U:
					
					break;

				case VK_L:
					
					break;

				case VK_I:
					
					break;

				case VK_K:
					break;

				case VK_O:
					break;
				}
			}
			else if (msg.message == WM_KEYUP)//����̧��
			{
				switch(msg.vkcode)//��ֵ
				{
				case VK_A:
					water.is_move_left = false;
					break;

				case VK_D:
					water.is_move_right = false;
					break;

				case VK_W:
					break;

				case VK_S:
					break;
				}
			}
		}





		//��Ⱦ����
		background.put_background();

		//���ﶯ��
		water.put_idle();
		player.put_idle();

		unsigned long end_time = GetTickCount();//��ȡ��һ֡����ʱ��
		unsigned long delta_time = end_time - water.start_time;

		//��ʱ����ʹÿһ֡��ʱ����һ����
		if (delta_time < 1000 / 60)
		{
			Sleep(1000 / 60 - delta_time);
		}
		
		FlushBatchDraw();

		water.start_time = GetTickCount();//��һ֡��ʼʱ��
	}

	EndBatchDraw();

	return 0;
}

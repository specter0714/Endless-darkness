//��˼����queue������ͼƬ�������pop��ռ���ڴ�С-------2024.12.20��17:22



//��˼����sleep��������ÿ�μ���ͼƬ��ʱ�����ﵽÿһ�δ�ӡͼƬ��ʱ��������ͬ�� ���ǻ�����ʱһ��ѭ��Ҫ���ض���ͼƬ�����ĵ�ʱ�䳤�����¶���Ҫô���٣� Ҫô����֡�ʵͣ�
//		�����ڿ��ǵļ��ֽ��������1. ÿ��ѭ��ֻloadimageһ��ͼƬ 2. ȡ��ʹ��queue���������飬ѭ��֮ǰ��loadimageȫ��ͼƬ 3. ����ͼƬ����
//		���ڻ���Ҫѧϰ��֪ʶ���Ż��������⣺1. ˫���� 2. ���߳�--------2025.01.01��21:13



//���������ھ���ʹ��vector��ѭ��֮ǰ����ͼƬ��ʹ����ѭ��whileѭ��ʱֻ��Ҫ��ȾͼƬ���ɣ����ٿ���-------2025.01.0��21:00



//ѧϰ��ѧϰ��ʵ��˫����ĺ��� beginbatchdraw() �� flushbatchdraw() ����-------2025.01.03��13:21

//��������˫�˶�ս�о��ܸ��ӣ����Ҳ�������Ҫ����ϷЧ����Ȼ������ҪBOOS�ļ��ܺܶ��ǿ��Ч��������������ƫ�ڰ��ģ���Ϊ�ز�ֻ�ҵ�һ�����ڰ���������������ļ��ܹ�����������Ҳ����ͬ
// ���������ݶ���ϷΪ������Ϸ��ֻ��һ������ද������С�֣���BOOS--------2025.01.04�� 20:04

//�������о�Ū�ܶ�������Ҫ��ʱ��̫���ˣ�����ֻ��һ��boos----------2025.01.20,  10:14

//���ȣ���֡�ʴ�60֡������30֡���ǻ����������������---------2025.01.31,    12:33
#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include<string>
#include<easyx.h>
#include<graphics.h>
#include"keyboard.h"
#include"enemy_water.h"
#include"Player.h"
#include"background.h"
#include"BOOS.h"

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")



int main()
{
	//��������
	mciSendString(L"open \"./image_source/music/7.mp3\" alias music", NULL, 0, NULL);
	mciSendString(L"setaudio music volume to 550", NULL, 0, NULL);
	mciSendString(L"play music repeat from 0", NULL, 0, NULL);
	/*mciSendString(L"open \"./image_source/music/1.mp3\" alias music1", NULL, 0, NULL);
	mciSendString(L"play music1 repeat from 0", NULL, 0, NULL);*/

	//�Ų���
	mciSendString(L"open \"./sound/run.wav\" alias run", NULL, 0, NULL);


	//attack��
	mciSendString(L"open \"./sound/player/attack1.wav\" alias attack1", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/attack2.wav\" alias attack2", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/attack_impact1.wav\" alias attack_impact1", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/attack_impact2.wav\" alias attack_impact2", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/dash.wav\" alias dash", NULL, 0, NULL);
	

	initgraph(1280, 720, EW_SHOWCONSOLE);

	bool running = true;




//��������
	//�������
	Player player(17, 6, 5, 3, 4, 7, 7, 3, 18, 15);
	//ˮԪ�ط�ʦ���
	Enemy_water water(8, 10, 8, 3, 3, 6, 7, 21, 27, 32, 12, 12, 7, 16, 8);
	
	//����
	Background background;







	ExMessage msg;//���������Ϣ�ı���

	//����ʱ��
	unsigned long start_time = 0;
	unsigned long end_time = 0;

	//���ر���
	background.load_background();

	BeginBatchDraw();

	while (running)
	{
		while (peekmessage(&msg))//��ȡ������Ϣ�����ⲿ���뷵��1������ڹ���ʱ����Ͳ�����ѭ��
		{
			if (msg.message == WM_KEYDOWN && !player.dash_ing)//���̰���
			{
				switch (msg.vkcode)//��ֵ
				{
				case VK_A:
					player.is_move_left = true;
					player.point_right = false;
					break;

				case VK_D:
					player.is_move_right = true;   
					player.point_right = true;
					break;

				case VK_W:

					break;

				case VK_S:
					break;

				case VK_U:

					break;

				case VK_L:
					if (!player.no_dash) {
						player.dash_ing = 5;
						player.no_dash = 20;
					}
					break;  

				case VK_I:

					break;

				case VK_K:
					player.is_j_up = true;
					break;

				case VK_O:
					break;

				case VK_J:
					if (!player.atk_1_ing && !player.atk_time && !player.atk_2_ing) {
						player.atk_1_ing = 7;
						player.atk_time = 14;
					}
					else if (!player.atk_1_ing && player.atk_time && !player.atk_2_ing) {
						player.atk_2_ing = 7;
					}
				}
			}
			else if (msg.message == WM_KEYUP)//����̧��
			{
				switch (msg.vkcode)//��ֵ
				{
				case VK_A:
					player.is_move_left = false;
					break;

				case VK_D:
					player.is_move_right = false;
					break;

				case VK_W:

					break;

				case VK_S:
					
					break;
				case VK_K:
					player.is_j_up = false;
				}
			}
		}





		//��Ⱦ����
		background.put_background();


		//�����ж�
		if (player.atk_1_ing || player.atk_2_ing) {
			if (player.point_right && water.enemy_point.x + 288 > player.enemy_point.x + 80 && water.enemy_point.x + 288 < player.enemy_point.x + 155 && water.enemy_point.y + 178 > player.enemy_point.y + 25 && water.enemy_point.y + 178 < player.enemy_point.y + 125) {
				water.take_hit_ing = 7;
			}
			else if (!player.point_right && water.enemy_point.x + 288 > player.enemy_point.x - 5 && water.enemy_point.x + 288 < player.enemy_point.x + 60 && water.enemy_point.y + 178 > player.enemy_point.y + 25 && water.enemy_point.y + 178 < player.enemy_point.y + 125) {
				water.take_hit_ing = 7;
			}
		}

		//���ﶯ��
		if (player.is_move_right && !player.is_move_left)player.point_right = true;
		if (!player.is_move_right && player.is_move_left)player.point_right = false;


		//enemy�����޸�

		//enemyͼ���޸�

		if (water.take_hit_ing) {
			water.put_take_hit();
		}
		else {
			water.put_idle();
		}

		//player�����޸�
		if (player.dash_ing && !player.dash_count) {
			player.dash_ing--;
			player.atk_1_ing = 0;
			player.atk_2_ing = 0;
			if (player.point_right)player.enemy_point.x += 40;
			else player.enemy_point.x -= 40;
			if (player.enemy_point.x < 0)player.enemy_point.x = 0;
			if (player.enemy_point.x > 1280 - 150)player.enemy_point.x = 1280 - 150;
			player.put_dash();
			mciSendString(L"play dash from 0", NULL, 0, NULL);
		}
		else {
			//�����޸�
			if (player.YSPEED && player.dash_ing)player.dash_count++;

			if (player.is_move_left) player.enemy_point.x -= player.XSPEED;
			if (player.is_move_right) player.enemy_point.x += player.XSPEED;
			if (player.enemy_point.x < 0)player.enemy_point.x = 0;
			if (player.enemy_point.x > 1280 - 150)player.enemy_point.x = 1280 - 150;


			if (player.is_j_up && player.height == player.enemy_point.y) {
				player.YSPEED = -27;
				player.enemy_point.y += player.YSPEED;
			}
			else if (player.height != player.enemy_point.y) {
				player.YSPEED += player.g;
				player.enemy_point.y += player.YSPEED;
			}
			else if (!player.is_j_up && player.height == player.enemy_point.y) {
				player.YSPEED = 0;
				player.dash_count = 0;
			}



			//playerͼ����Ⱦ
			if (player.atk_1_ing) {
				player.put_attack_1();
				if (water.take_hit_ing && !player.no_attack_impact1) {
					mciSendString(L"play attack_impact1 from 0", NULL, 0, NULL);
					player.no_attack_impact1 = 7;
				}
				else if(!player.no_attack1 && !player.no_attack_impact1) {
					mciSendString(L"play attack1 from 0", NULL, 0, NULL);
					player.no_attack_impact1 = 7;
				}

			}
			else if (player.atk_2_ing) {
				player.put_attack_2();
				if (water.take_hit_ing && !player.no_attack_impact2) {
					mciSendString(L"play attack_impact2 from 0", NULL, 0, NULL);
					player.no_attack_impact2 = 7;
				}
				else if (!player.no_attack2 && !player.no_attack_impact2) {
					mciSendString(L"play attack2 from 0", NULL, 0, NULL);
					player.no_attack_impact2 = 7;
				}
			}
			else if (player.enemy_point.y != player.height) {
					if (player.YSPEED < 0) {
						player.put_j_up();
					}
					else if (player.YSPEED >= 0) {
						if (player.YSPEED > 15) {
							player.put_land();
						}
						else {
							player.put_j_down();
						}
					}
			}
			else if ((player.is_move_left && player.is_move_right) || (!player.is_move_left && !player.is_move_right)) {
				player.put_idle();
			}
			else {
				player.put_run();
				//�Ų���
				if (!player.no_run_sound) {
					mciSendString(L"play run from 0", NULL, 0, NULL);
					player.no_run_sound = 6;
				}
			}
		}

		//player
		if (player.no_dash) {
			player.no_dash--;
		}
		if (player.atk_1_ing) {
			player.atk_1_ing--;
		}
		if (player.atk_2_ing) {
			player.atk_2_ing--;
		}
		if (player.atk_time) {
			player.atk_time--;
		}
		if (player.no_run_sound) {
			player.no_run_sound--;
		}
		if (player.no_attack1) {
			player.no_attack1--;
		}
		if (player.no_attack2) {
			player.no_attack2--;
		}
		if (player.no_attack_impact1) {
			player.no_attack_impact1--;
		}
		if (player.no_attack_impact2) {
			player.no_attack_impact2--;
		}




		//player
		if (water.take_hit_ing) {
			water.take_hit_ing--;
		}



		end_time = GetTickCount();//��ȡ��һ֡����ʱ��
		unsigned long delta_time = end_time - start_time;

		//��ʱ����ʹÿһ֡��ʱ����һ����
		if (delta_time < 1000 / 32)
		{
			Sleep(1000 / 32 - delta_time);
		}
		
		FlushBatchDraw();

		start_time = GetTickCount();//��һ֡��ʼʱ��
	}

	EndBatchDraw();

	// �ر���Ƶ��Դ
	mciSendString(L"close music", NULL, 0, NULL);

	return 0;
}

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
#include<math.h>

#include"keyboard.h"
#include"enemy_water.h"
#include"Player.h"
#include"background.h"
#include"BOOS.h"
#include"bullet.h"

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")



int main()
{
	//��������
	mciSendString(L"open \"./image_source/music/2.mp3\" alias music1", NULL, 0, NULL);
	mciSendString(L"setaudio music1 volume to 550", NULL, 0, NULL);
	//��������
	mciSendString(L"open \"./image_source/music/7.mp3\" alias music", NULL, 0, NULL);
	mciSendString(L"setaudio music volume to 550", NULL, 0, NULL);
	/*mciSendString(L"open \"./image_source/music/1.mp3\" alias music1", NULL, 0, NULL);
	mciSendString(L"play music1 repeat from 0", NULL, 0, NULL);*/


	//player��Ч

	//�Ų���
	mciSendString(L"open \"./sound/run4.wav\" alias run", NULL, 0, NULL);


	//attack��
	mciSendString(L"open \"./sound/player/attack1.wav\" alias attack1", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/attack2.wav\" alias attack2", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/attack_impact1.wav\" alias attack_impact1", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/attack_impact2.wav\" alias attack_impact2", NULL, 0, NULL);
	mciSendString(L"open \"./sound/player/dash.wav\" alias dash", NULL, 0, NULL);
	


	initgraph(1280, 720, EW_SHOWCONSOLE);

	bool running = true;

	//water����
	int water_time = 0;
	//player����
	int player_time = 0;


//��������
	//�������
	Player player(17, 6, 5, 3, 4, 7, 7, 3, 19, 15);
	//ˮԪ�ط�ʦ���
	Enemy_water water(8, 10, 8, 3, 3, 6, 7, 21, 27, 21, 12, 12, 7, 16, 8);
	//�ӵ�
	Bullet bullet(4, 6, 4, 5, 5);
	
	//����
	Background background;

	//���������Ϣ�ı���
	ExMessage msg;



	//����ʱ��
	unsigned long start_time = 0;
	unsigned long end_time = 0;

	//���ر���
	background.load_background();
	background.load_ui();

	//���Ž�������
	mciSendString(L"play music1 repeat from 0", NULL, 0, NULL);
	BeginBatchDraw();
	while (running)
	{
		bool is_Mouse_Down = false;
		static int mouse_x;
		static int mouse_y;

		static int count_time = 0;
		static bool check1 = false;
		static bool check2 = false;
		while (peekmessage(&msg))//��ȡ������Ϣ�����ⲿ���뷵��1������ڹ���ʱ����Ͳ�����ѭ��
		{
			if (msg.message == WM_LBUTTONDOWN)//���̰���
			{
				is_Mouse_Down = true;
			}
			else if (msg.message == WM_LBUTTONUP)//����̧��
			{
				is_Mouse_Down = false;
			}
			else if (msg.message == WM_MOUSEMOVE)//����ƶ�
			{
				mouse_x = msg.x;
				mouse_y = msg.y;
			}



		}

		background.put_background();


		player.put_start();


		if (is_Mouse_Down && (mouse_x >= 659 && mouse_x <= 659 + 90) && (mouse_y >= 550 && mouse_y <= 550 + 90)) {
			background.put_ui2();
			check1 = true;
		}
		else if (is_Mouse_Down && check1) {
			background.put_ui2();
		}
		else if (check1 && !is_Mouse_Down) {
			background.put_ui1();
			check2 = true;
		}
		else {
			background.put_ui1();
		}


		if (check2) {
			count_time++;
		}

		if (count_time >= 10) {
			break;
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

	//������������
	mciSendString(L"close music1", NULL, 0, NULL);





















	//���ű�������
	mciSendString(L"play music repeat from 0", NULL, 0, NULL);


	BeginBatchDraw();

	while (running)
	{
		while (peekmessage(&msg) && water.HP > 0 && player.HP > 0)//��ȡ������Ϣ�����ⲿ���뷵��1������ڹ���ʱ����Ͳ�����ѭ��
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

		//player��enemy��λ�ò�
		int player_xx = player.enemy_point.x + 75;
		int player_yy = player.enemy_point.y + 75;
		int water_xx = water.enemy_point.x + 288;
		int water_yy = water.enemy_point.y + 213;
		int bullet_xx = bullet.bullet_point.x + 48;
		int bullet_yy = bullet.bullet_point.y + 68;

		int dif = player_xx - water_xx;
		int dif_h = player_yy - water_yy ;

		int dif_bullet = 10000;
		for (int i = -150 * 4; i <= 150 * 4; i += 150) {
			dif_bullet = min(dif_bullet, abs(player_xx + i - bullet_xx));
		}
		int dif_bullet_h = player_yy - bullet_yy;


		//��Ⱦ����
		background.put_background();
		player.put_hp();


		//water������ʱ
		if (water.HP <= 0 || player.HP <= 0) {

		}
		else if (water.act_time % (32 * 4) == 20) {
			water.surf_ing = 40;
		}
		else if (water.act_time % (32 * 4) == 32 * 2 + 20 && water.HP <= 100) {
			water.sp_attack = 42;
		}



		//�����ж�or�����ж�
		if ((player.atk_1_ing || player.atk_2_ing) && !water.surf_ing && !water.sp_attack) {
			if (player.point_right && water.enemy_point.x + 288 > player.enemy_point.x + 80 && water.enemy_point.x + 288 < player.enemy_point.x + 155 && water.enemy_point.y + 178 > player.enemy_point.y + 25 && water.enemy_point.y + 178 < player.enemy_point.y + 125) {
				water.take_hit_ing = 7;
				water.HP--;
			}
			else if (!player.point_right && water.enemy_point.x + 288 > player.enemy_point.x - 5 && water.enemy_point.x + 288 < player.enemy_point.x + 60 && water.enemy_point.y + 178 > player.enemy_point.y + 25 && water.enemy_point.y + 178 < player.enemy_point.y + 125) {
				water.take_hit_ing = 7;
				water.HP--;
			}
		}
		if (abs(dif) <= 30 && !player.no_enemy_time && !player.take_hit_ing && dif_h >= -50) {
			player.take_hit_ing = 6;
			player.no_enemy_time = 70;
		}
		if (abs(dif_bullet) <= 40 && !player.no_enemy_time && !player.take_hit_ing && abs(dif_bullet_h) <= 150) {
			player.take_hit_ing = 6;
			player.no_enemy_time = 70;
		}
		if (water.sp_attack <= 20 && water.sp_attack >= 4) {
			if (water.point_right && player_xx >= water_xx && player_xx <= water_xx + 192) {
				player.take_hit_ing = 6;
				player.no_enemy_time = 70;
				std::cout << "kkkk";
			}
			else if(player_xx <= water_xx && player_xx >= water_xx - 192){
				player.take_hit_ing = 6;
				player.no_enemy_time = 70;
			}
		}



		//���ﶯ��
		if (player.is_move_right && !player.is_move_left)player.point_right = true;
		if (!player.is_move_right && player.is_move_left)player.point_right = false;


		//bullet�����޸�
		if (water.sp_attack >= 4) {
			if (water.sp_attack <= 20) {
				bullet.bullet_point.y += bullet.down_speed;
			}
		}



		//bulletͼ���޸�
		if (water.sp_attack >= 4) {
			bullet.put_bullet();
		}







		//enemy�����޸�
		if (player.HP <= 0) {
			if (player_time <= 10) {
				if (dif >= 0) {
					water.enemy_point.x -= 25;
				}
				else {
					water.enemy_point.x += 25;
				}
			}
		}
		else if (water.HP <= 0) {
			if (water_time <= 10) {
				if (dif >= 0) {
					water.enemy_point.x -= 25;
				}
				else {
					water.enemy_point.x += 25;
				}
			}
		}
		else if (water.sp_attack) {
			if (water.sp_attack == 21) {
				if (dif >= 0) {
					water.point_right = true;
				}
				else {
					water.point_right = false;
				}
			}
		}
		else if (water.surf_ing) {
			if (water.surf_ing == 40) {
				if (dif >= 0) {
					water.point_right = true;
				}
				else {
					water.point_right = false;
				}
			}
			if (water.point_right) {
				if (water.surf_ing >= 35) {
					water.enemy_point.x -= water.S_SPEED;
				}
				else {
					water.enemy_point.x += water.S_SPEED;
				}
			}
			else {
				if (water.surf_ing >= 35) {
					water.enemy_point.x += water.S_SPEED;
				}
				else {
					water.enemy_point.x -= water.S_SPEED;
				}
			}
		}
		else if (water.take_hit_ing) {
				if (dif >= 0) {
					water.enemy_point.x -= 3;
				}
				else {
					water.enemy_point.x += 3;
				}
		}
		else if (dif >= 0) {
			water.point_right = true;
			water.enemy_point.x += water.MOVE_SPEED;
		}
		else {
			water.point_right = false;
			water.enemy_point.x -= water.MOVE_SPEED;
		}
		//water�߽�����
		if (water.enemy_point.x > 900)water.enemy_point.x = 900;
		if (water.enemy_point.x < -200)water.enemy_point.x = -200;
		

		//enemyͼ���޸�
		if (player.HP <= 0) {
			if (player_time <= 10) {
				water.put_take_hit();
			}
			else {
				water.put_idle();
			}
		}
		else if (water.HP <= 0) {
			if (water_time <= 10) {
				water.put_take_hit();
			}
			else {
				water.put_death();
			}
			if ((water_time - 10) / 40 == 16) {
				std::cout << "you are winner" << "\n\n" << "thank your playing\n\n";
				break;
			}

		}
		else if (water.sp_attack) {
			water.put_sp_attack();
		}
		else if (water.surf_ing) {
			water.put_surf();
		}
		else if (water.take_hit_ing) {
			water.put_take_hit();
		}
		else {
			water.put_walk();
		}

		//player�����޸�
		if (player.HP <= 0) {
			if (player_time == 0) {
				player.is_move_left = false;
				player.is_move_right = false;
				player.is_j_up = false;
				player.dash_ing = 0;
				if (dif >= 0) {
					player.point_right = false;
				}
				else {
					player.point_right = true;
				}
			}
			if (player_time <= 10) {
				if (dif >= 0) {
					player.enemy_point.x += 25;
				}
				else {
					player.enemy_point.x -= 25;
				}
			}
		}
		else if (water.HP <= 0) {  //water����
			if (water_time == 0) {
				player.is_move_left = false;
				player.is_move_right = false;
				player.is_j_up = false;
				player.dash_ing = 0;
				if (dif >= 0) {
					player.point_right = false;
				}
				else {
					player.point_right = true;
				}
			}
			if (water_time <= 10) {
				if (dif >= 0) {
					player.enemy_point.x += 25;
				}
				else {
					player.enemy_point.x -= 25;
				}
			}
		}
		else if (player.take_hit_ing) {//player�ܵ�����
			player.dash_ing = 0;
			player.atk_1_ing = 0;
			player.atk_2_ing = 0;
			if (player.take_hit_ing == 6)player.HP--;
			if (water.surf_ing) {
				if (dif >= 0) {
					player.enemy_point.x += 60;
				}
				else {
					player.enemy_point.x -= 60;
				}
			}
			else {
				if (dif >= 0) {
					player.enemy_point.x += 22;
				}
				else {
					player.enemy_point.x -= 22;
				}
			}
		}
		else if (player.dash_ing && !player.dash_count) {//���
			player.dash_ing--;
			player.atk_1_ing = 0;
			player.atk_2_ing = 0;
			if (player.point_right)player.enemy_point.x += 40;
			else player.enemy_point.x -= 40;
		}
		else {
			//�����޸�
			if (player.YSPEED && player.dash_ing)player.dash_count++;

			if (player.is_move_left) player.enemy_point.x -= player.XSPEED;
			if (player.is_move_right) player.enemy_point.x += player.XSPEED;


			if (player.is_j_up && player.height == player.enemy_point.y) {
				player.YSPEED = -27;
				player.enemy_point.y += player.YSPEED;
			}
		}

		//���������������޸�
		if (player.height != player.enemy_point.y) {
			player.YSPEED += player.g;
			player.enemy_point.y += player.YSPEED;
		}
		else if (!player.is_j_up && player.height == player.enemy_point.y) {
			player.YSPEED = 0;
			player.dash_count = 0;
		}




		//player�߽�����
		if (player.enemy_point.x < 0)player.enemy_point.x = 0;
		if (player.enemy_point.x > 1280 - 150)player.enemy_point.x = 1280 - 150;


		//playerͼ����Ⱦ
		if (player.HP <= 0) {
			if (player_time <= 10) {
				player.put_take_hit();
			}
			else {
				player.put_death();
			}
			if ((player_time - 10) / 40 == 19) {
				std::cout << "you are dead\n\n" << "thank your playing\n";
				break;
			}
		}
		else if (water.HP <= 0 && water_time <= 10) {
			player.put_take_hit();
		}
		else if (player.take_hit_ing) {
			player.put_take_hit();
		}
		else if (player.dash_ing) {
			player.put_dash();
			mciSendString(L"play dash from 0", NULL, 0, NULL);
		}
		else if (player.atk_1_ing) {
			player.put_attack_1();
			if (water.take_hit_ing && !player.no_attack_impact1) {
				mciSendString(L"play attack_impact1 from 0", NULL, 0, NULL);
				player.no_attack_impact1 = 7;
			}
			else if (!player.no_attack1 && !player.no_attack_impact1) {
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
		if (player.take_hit_ing) {
			player.take_hit_ing--;
		}
		if (player.no_enemy_time) {
			player.no_enemy_time--;
		}

		if (player.HP <= 0) {
			player_time++;
		}


		//water
		if (water.take_hit_ing) {
			water.take_hit_ing--;
		}
		if (water.surf_ing) {
			water.surf_ing--;
		}
		if (water.sp_attack) {
			if (water.sp_attack == 4) {
				bullet.restart();
			}
			water.sp_attack--;
		}

		if (water.HP <= 0) {
			water_time++;
		}
		
		water.act_time++;


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

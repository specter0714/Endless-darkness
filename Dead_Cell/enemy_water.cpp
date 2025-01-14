#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"enemy_water.h"
#include"putimage_alpha.h"

Enemy_water::Enemy_water(int IDLE, int WALK, int SURF, int J_UP, int J_DOWN, int TUMBLE, int ATK_1, int ATK_2, int ATK_3, int SP_ATK, int HEAL, int DEFEND, int TAKE_HIT, int DEATH, int AIR_ATK)
{
	_IDLE = IDLE;
	_SP_ATK = SP_ATK;
	_WALK = WALK;
	_SURF = SURF;
	_ATK_1 = ATK_1;
	_ATK_2 = ATK_2;
	_ATK_3 = ATK_3;
	_J_UP = J_UP;
	_J_DOWN = J_DOWN;
	_TUMBLE = TUMBLE;
	_HEAL = HEAL;
	_DEFEND = DEFEND;
	_TAKE_HIT = TAKE_HIT;
	_DEATH = DEATH;
	_AIR_ATK = AIR_ATK;


	load_idle();
	load_sp_attack();
	load_walk();
	load_surf();
	load_attack_1();
	load_attack_2();
	load_attack_3();
	load_j_up();
	load_j_down();
	load_tumble();
	load_heal();
	load_defend();
	load_take_hit();
	load_death();
	load_air_attack();
}

Enemy_water::~Enemy_water()
{
	printf("have deleted");
}


//����ͼƬ����


void Enemy_water::load_idle()
{
	//����idle
	if (!img_idle_left.size() || !img_idle_right.size()) {

		static int run_time = 0;
		run_time++;
		if (run_time == 2) {
			run_time = 0;
			idle_ing = false;
		}

		for (int i = 0; i < _IDLE; i++)
		{
			std::wstring path = L"./image_source/water/idle/idle_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_idle_right.push_back(img);
		}
		for (int i = 0; i < _IDLE; i++)
		{
			std::wstring path = L"./image_source/water/idle/idle_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_idle_left.push_back(img);
		}
	}
}

void Enemy_water::load_sp_attack()
{
	//����sp_atk
	if (!img_sp_attack_right.size() || !img_sp_attack_left.size()) {
		for (int i = 0; i < _SP_ATK; i++)
		{
			std::wstring path = L"./image_source/water/sp_atk/sp_atk_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_sp_attack_right.push_back(img);
		}
		for (int i = _SP_ATK - 1, j = 1; i > 0; i--, j++)
		{
			std::wstring path = L"./image_source/water/sp_atk/sp_atk_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_sp_attack_left.push_back(img);
		}
	}
}

void Enemy_water::load_walk()
{
	//����walk
	for (int i = 0; i < _WALK; i++)
	{
		std::wstring path = L"./image_source/water/walk/walk_" + std::to_wstring(i + 1) + L".png";
		IMAGE img;
		loadimage(&img, path.c_str(), 576, 256, true);
		img_walk_right.push_back(img);
	}
	for (int i = 0; i < _WALK; i++)
	{
		std::wstring path = L"./image_source/water/walk/walk_0" + std::to_wstring(i + 1) + L".png";
		IMAGE img;
		loadimage(&img, path.c_str(), 576, 256, true);
		img_walk_left.push_back(img);
	}
}

void Enemy_water::load_surf()
{
	//����surf
	
		for (int i = 0; i < _SURF; i++)
		{
			std::wstring path = L"./image_source/water/surf/surf_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_surf_right.push_back(img);
		}
		for (int i = 0; i < _SURF; i++)
		{
			std::wstring path = L"./image_source/water/surf/surf_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_surf_left.push_back(img);
		}
	
}

void Enemy_water::load_attack_1()
{
	//����attack_1
	if (!img_attack_1_right.size() || !img_attack_1_left.size())
	{
		for (int i = 0; i < _ATK_1; i++)
		{
			std::wstring path = L"./image_source/water/atk_1/1_atk_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_attack_1_right.push_back(img);
		}
		for (int i = 0; i < _ATK_1; i++)
		{
			std::wstring path = L"./image_source/water/atk_1/1_atk_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_attack_1_left.push_back(img);
		}
	}
}

void Enemy_water::load_attack_2()
{
	//����attack_2
	if (!img_attack_2_right.size() || !img_attack_2_left.size())
	{
		for (int i = 0; i < _ATK_1; i++)
		{
			std::wstring path = L"./image_source/water/atk_2/2_atk_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_attack_2_right.push_back(img);
		}
		for (int i = 0; i < _ATK_1; i++)
		{
			std::wstring path = L"./image_source/water/atk_2/2_atk_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_attack_2_left.push_back(img);
		}
	}
}

void Enemy_water::load_attack_3()
{
	//����atk_3
	if (!img_attack_3_right.size() || !img_attack_3_left.size())
	{
		for (int i = 0; i < _ATK_3; i++)
		{
			std::wstring path = L"./image_source/water/atk_3/3_atk_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_attack_3_right.push_back(img);
		}
		for (int i = 0; i < _ATK_3; i++)
		{
			std::wstring path = L"./image_source/water/atk_3/3_atk_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_attack_3_left.push_back(img);
		}
	}
}

void Enemy_water::load_j_up()
{
	//����j_up
	if (!img_j_up_right.size() || !img_j_up_left.size())
	{
		for (int i = 0; i < _J_UP; i++)
		{
			std::wstring path = L"./image_source/water/j_up/j_up_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_j_up_right.push_back(img);
		}
		for (int i = 0; i < _J_UP; i++)
		{
			std::wstring path = L"./image_source/water/j_up/j_up_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_j_up_left.push_back(img);
		}
	}
}

void Enemy_water::load_j_down()
{
	//����j_ down
	if (!img_j_down_right.size() || !img_j_down_left.size())
	{
		for (int i = 0; i < _J_DOWN; i++)
		{
			std::wstring path = L"./image_source/water/j_down/j_down_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_j_down_right.push_back(img);
		}
		for (int i = 0; i < _J_UP; i++)
		{
			std::wstring path = L"./image_source/water/j_down/j_down_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_j_down_left.push_back(img);
		}
	}
}

void Enemy_water::load_tumble()
{
	//����tumble
	if (!img_tumble_right.size() || !img_tumble_left.size())
	{
		for (int i = 0; i < _TUMBLE; i++)
		{
			std::wstring path = L"./image_source/water/tumble/tumble_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_tumble_right.push_back(img);
		}
		for (int i = 0; i < _TUMBLE; i++)
		{
			std::wstring path = L"./image_source/water/tumble/tumble_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_tumble_left.push_back(img);
		}
	}
}

void Enemy_water::load_heal()
{
	//����heal
	if (!img_heal_right.size() || !img_heal_left.size())
	{
		for (int i = 0; i < _HEAL; i++)
		{
			std::wstring path = L"./image_source/water/heal/heal_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_heal_right.push_back(img);
		}
		for (int i = 0; i < _HEAL; i++)
		{
			std::wstring path = L"./image_source/water/heal/heal_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_heal_left.push_back(img);
		}
	}
}

void Enemy_water::load_defend()
{
	//����defend
	if (!img_defend_right.size() || !img_defend_left.size())
	{
		for (int i = 0; i < _DEFEND; i++)
		{
			std::wstring path = L"./image_source/water/heal/heal_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_defend_right.push_back(img);
		}
		for (int i = 0; i < _DEFEND; i++)
		{
			std::wstring path = L"./image_source/water/heal/heal_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_defend_left.push_back(img);
		}
	}
}

void Enemy_water::load_take_hit()
{
	//����take_hit
	if (!img_take_hit_right.size() || !img_take_hit_left.size())
	{
		for (int i = 0; i < _TAKE_HIT; i++)
		{
			std::wstring path = L"./image_source/water/take_hit/take_hit_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_take_hit_right.push_back(img);
		}
		for (int i = 0; i < _TAKE_HIT; i++)
		{
			std::wstring path = L"./image_source/water/take_hit/take_hit_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_take_hit_left.push_back(img);
		}
	}
}

void Enemy_water::load_death()
{
	//����death
	if (!img_death_right.size() || !img_death_left.size())
	{
		for (int i = 0; i < _TAKE_HIT; i++)
		{
			std::wstring path = L"./image_source/water/death/death_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_take_hit_right.push_back(img);
		}
		for (int i = 0; i < _TAKE_HIT; i++)
		{
			std::wstring path = L"./image_source/water/death/death_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_take_hit_left.push_back(img);
		}
	}
}

void Enemy_water::load_air_attack()
{
	//����air_attack
	if (!img_air_attack_right.size() || !img_air_attack_left.size())
	{
		for (int i = 0; i < _AIR_ATK; i++)
		{
			std::wstring path = L"./image_source/water/air_atk/air_atk_" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_air_attack_right.push_back(img);
		}
		for (int i = 0; i < _AIR_ATK; i++)
		{
			std::wstring path = L"./image_source/water/air_atk/air_atk_0" + std::to_wstring(i + 1) + L".png";
			IMAGE img;
			loadimage(&img, path.c_str(), 576, 256, true);
			img_air_attack_left.push_back(img);
		}
	}
}



//��ȾͼƬ����
void Enemy_water::put_idle()
{
	static int time = 0;
	if(point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_sp_attack()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_walk()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _WALK)time = 0;
}

void Enemy_water::put_surf()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_attack_1()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_attack_2()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_attack_3()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_j_up()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_j_down()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_tumble()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_heal()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_defend()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_take_hit()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_death()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}

void Enemy_water::put_air_attack()
{
	static int time = 0;
	if (point_right)Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_right[time / 2]);
	else Putimage_alpha::putimage_alpha(enemy_point.x, enemy_point.y, &img_idle_left[time / 2]);
	time++;
	if (time / 2 == _IDLE)time = 0;
}



void Enemy_water::change_data()
{
	
}

void Enemy_water::player_action()
{

}
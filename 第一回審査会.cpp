//
// ミニゲーム雛形
//

#include "appEnv.hpp"
#include <windows.h>
#include <time.h>

// アプリのウインドウサイズ
enum Window {
	WIDTH = 800,
	HEIGHT = 502
};

int i = 30, HP1 = 1, HP2 = 1, HP3 = 1, HP4 = 1, waiban_HP = 1000, oonamazu_HP = 1200, oneirosu_HP = 2000, maou_HP = 1700, 

t = 1, w = 0, t1 = 1, t2 = 2, t3 = 3, t4 = 4, t5 = 5, t6 = 6, t7 = 7, t8 = 8, 

a = 0, s = 0, b = 0, b1_1 = 0, b1_2 = 0, b1_3 = 0, b1_4 = 0, b2 = 0, b3_1 = 1, b3_2 = 1, b3_3 = 1, b3_4 = 1,e = 0,

x1 = 0, x2 = 0, x3 = 0, x4 = 0, 

BOSS = 4, dead = 0, dm_1 = 0, dm_2 = 0, dm_3 = 0, dm_4 = 0,

skill_1 = 0,skill_2 = 0, skill_3 = 0, skill_4 = 0,

ch_1 = 0, ch_2 = 0, ch_3 = 0, ch_4 = 0,

BOSS_x = 0, BOSS_effect = 0,

attack_1 = 0,attack_2 = 0, attack_3 = 0, attack_4 = 0,

effect = 0, effect_1 = 0, effect_2 = 0, effect_3 = 0, effect_4 = 0, 

BOSS_air = 0,

archar_effect_1 = 0, archar_effect_2 = 0, archar_effect_3 = 0, archar_effect_4 = 0, 

magician_effect_1 = 0, magician_effect_2 = 0,magician_effect_3 = 0, magician_effect_4 = 0, 

healer_effect_1 = 0, healer_effect_2 = 0, healer_effect_3 = 0, healer_effect_4 = 0,

HP_sub1 = 1, HP_sub2 = 1, HP_sub3 = 1, HP_sub4 = 1, 

healer_player1 = 0, healer_player2 = 0, healer_player3 = 0, healer_player4 = 0,

C1_h = 0, C2_h = 0, C3_h = 0, C4_h = 0, 

h_1 = 0, h_2 = 0, h_3 = 0, h_4 = 0, 

c = 0, 

buff_t = 0,

debuff_t = 0, 

dancer_effect_1 = 0, dancer_effect_2 = 0, dancer_effect_3 = 0, dancer_effect_4 = 0, 

thief_effect_1 = 0, thief_effect_2 = 0, thief_effect_3 = 0, thief_effect_4 = 0, 

skill_limit = 0,

BOSS_t = -1,

enemy = 1,status = 1,

 g = 0,

v= 0,

enemy_dead = 0;

float C1 = 0, C2 = 0, C3 = 0, C4 = 0, 

buff = 10,

debuff = 10,

enemy_dead2 = 1;


//こうげき関数
void attack(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& effect_a, const Media& zan_sound, const Media& zaku_sound, const Media& ban_sound){
	//斬撃
	if (effect_a == 1){
		if (attack_1 == 1 && t == 1){
			zan_sound.play();
			Sleep(200);
			t++;

		}
		if (attack_2 == 1 && t == 3){
			zan_sound.play();
			Sleep(200);
			t++;
		}
		if (attack_3 == 1 && t == 5){
			zan_sound.play();
			Sleep(200);
			t++;
		}
		if (attack_4 == 1 && t == 7){
			zan_sound.play();
			Sleep(200);
			t++;
		}
		//弓
		if (attack_1 == 2 && t == 1){
			effect++;
			drawTextureBox(30 + effect * 8, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			if (effect == 1)zaku_sound.play();
			if (effect > 40){
				t++;
				effect = 0;
			}
		}
		if (attack_2 == 2 && t == 3){
			effect++;
			drawTextureBox(30 + effect * 8, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			if (effect == 1)zaku_sound.play();
			if (effect > 40){
				t++;
				effect = 0;
			}
		}
		if (attack_3 == 2 && t == 5){
			effect++;
			drawTextureBox(30 + effect * 8, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			if (effect == 1)zaku_sound.play();
			if (effect > 40){
				t++;
				effect = 0;
			}
		}
		if (attack_4 == 2 && t == 7){
			effect++;
			drawTextureBox(30 + effect * 8, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			if (effect == 1)zaku_sound.play();
			if (effect > 40){
				t++;
				effect = 0;
			}
		}
		//魔法
		if (attack_1 == 3 && t == 1){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_2 == 3 && t == 3){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_3 == 3 && t == 5){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_4 == 3 && t == 7){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		//魔法2
		if (attack_1 == 4 && t == 1){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_2 == 4 && t == 3){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_3 == 4 && t == 5){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_4 == 4 && t == 7){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
			if (effect == 1)ban_sound.play();
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
	}
	if (t == turn_plus1 && a == 1){
		if (xx == 50){
			xx = 0;
		}

		a = 0;
		t++;
		effect_a = 0;
	}
	if (a == 0){
		if (t == turn){
			if (pos.x() > -400 + 62){
				if (pos.x() < -400 + 173){
					if (pos.y() < -135){
						if (pos.y() > -161){
							if (left_click){
								BOSS_HP -= damage * (buff / 10);
								a = 1;
								//t++;
								xx = 50;
								effect_a = 1;
								drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
									texture,
									Color(1, 1, 1));

							}
						}
					}
				}
			}
		}
	}
}
//ぼうぎょ
void defense(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& HP, int& b1, int& b3){
	if (t == turn_plus1 && b1 == 1){
		if (xx == 50){
			Sleep(400);
			xx = 0;
		}

		t++;
	}
	if (b == 0){
		if (t == turn){
			if (pos.x() > -400 + 244){
				if (pos.x() < -400 + 360){
					if (pos.y() < -135){
						if (pos.y() > -161){
							if (left_click){
								b3 = 0;
								b1 = 1;
								b = 1;
								t++;
								xx = 50;
								drawTextureBox(-400, 250 - 128, 128, 128, 0, 0, 128, 128,
									texture,
									Color(1, 1, 1));
							}
						}
					}
				}
			}
		}
	}
	if (t == 1){
		b1 = 0;
		b = 0;
		b3 = 1;
	}
}

//にげる
void escape(const Texture& texture, int& turn, Vec2f pos, bool left_click){
	if (e == 0){
		if (t == turn){
			if (pos.x() > -400 + 244){
				if (pos.x() < -400 + 330){
					if (pos.y() < 250 - 422){
						if (pos.y() > 250 - 450){
							if (left_click){
								e = 1;
							}
						}
					}
				}
			}
		}
	}
	if (e == 1){
		drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
			texture,
			Color(1, 1, 1));
		if (left_click){
			if (pos.x() > -400 + 241){
				if (pos.x() < -400 + 279){
					if (pos.y() < 250 - 317){
						if (pos.y() > 250 - 334){
							e = 2;
						}
					}
				}
			}
		}
		if (left_click){
			if (pos.x() > -400 + 321){
				if (pos.x() < -400 + 379){
					if (pos.y() < 250 - 317){
						if (pos.y() > 250 - 334){
							e = 0;
						}
					}
				}
			}
		}
	}
}

//とくぎ(warrior)
void w_skill(int& turn_plus1, int& xx, const Texture& texture, const Texture& texture2, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, Media& zan2_sound){
	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			Sleep(250);
			xx = 0;
		}
		BOSS_HP -= damage * 1.5 * (buff / 10);
		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									s = 1;
									t++;
									xx = 50;
									skill_limit++;
									zan2_sound.play();
									drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
										texture,
										Color(1, 1, 1));

									drawTextureBox(10, -100, 256, 256, 0, 0, 256, 256,
										texture2,
										Color(1, 1, 1));
								}
							}
						}
					}
				}
			}
		}
	}
}

//とくぎ(archer)
void a_skill(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& archar_effect, Media& zaku_sound){
	if (archar_effect == 1){
		effect++;
		drawTextureBox(30 + effect * 8, -100, 256, 256, 0, 0, 256, 256,
			texture,
			Color(1, 1, 1));
		if (effect > 40){
			t++;
			effect = 0;
			archar_effect = 0;
		}
	}
	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			Sleep(250);
			xx = 0;
		}
		BOSS_HP -= damage * (buff / 10);
		if (BOSS_air){
			BOSS_HP -= damage * 2 * (buff / 10);
		}
		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									s = 1;
									//t++;
									xx = 50;
									skill_limit++;
									zaku_sound.play();
									drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
										texture,
										Color(1, 1, 1));
									archar_effect = 1;
								}
							}
						}
					}
				}
			}
		}
	}
}

//とくぎ(magician)
void m_skill(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& magician_effect, Media& ban_sound){
	if (magician_effect == 1){
		effect++;
		if (effect % 2 + 1 == 1){
			drawTextureBox(-400 + 344, 250 - 342, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 2 + 1 == 2){
			drawTextureBox(-400 + 462, 250 - 462, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 2 + 1 == 1){
			drawTextureBox(-400 + 514, 250 - 306, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect == 6){
			ban_sound.play();
		}
		if (effect == 12){
			ban_sound.play();
		}
		if (effect == 18){
			ban_sound.play();
		}
		if (effect > 20){
			t++;
			effect = 0;
			magician_effect = 0;
		}
	}
	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			xx = 0;
		}
		BOSS_HP -= damage * 1.5 * (buff / 10);
		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									s = 1;
									//t++;
									xx = 50;
									skill_limit++;
									drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
										texture,
										Color(1, 1, 1));
									magician_effect = 1;
								}
							}
						}
					}
				}
			}
		}
	}
}
//とくぎ(healer)
void h_skill(int& turn_plus1, int& xx, const Texture& texture, const Texture& texture_h, int& turn, Vec2f pos, bool left_click, int& healer_effect, Media& heal_sound){
	if (healer_effect == 1){
		effect++;
		//player1
		if (healer_player1 == 1){
			C1_h = 0;
			if (HP1 > 0){
				if (HP1 != HP_sub1){
					HP1++;
				}
				if (effect % 2 == 0){
					drawTextureBox(-400 + 100 * 2 - 10, 250 - 125 - 12, 128, 128, 0, 0, 128, 128,
						texture,
						Color(1, 1, 1));
					Sleep(20);
				}
				if (effect % 2 == 1){
					drawTextureBox(-400 + 100 * 2 - 10, 250 - 125 - 12, 128, 128, 0, 0, 128, 128,
						texture,
						Color(0, 1, 0));
					Sleep(20);
				}
			}
			if (effect == 30){
				C1 = 0;
				t++;
				effect = 0;
				healer_effect = 0;
				healer_player1 = 0;
			}
		}


		//player2
		if (healer_player2 == 1){
			C2_h = 0;
			if (HP2 > 0){
				if (HP2 != HP_sub2){
					HP2++;
				}
				if (effect % 2 == 0){
					drawTextureBox(-400 + 100 * 2 - 10, 250 - 125 * 2 - 12, 128, 128, 0, 0, 128, 128,
						texture,
						Color(1, 1, 1));
					Sleep(20);
				}
				if (effect % 2 == 1){
					drawTextureBox(-400 + 100 * 2 - 10, 250 - 125 * 2 - 12, 128, 128, 0, 0, 128, 128,
						texture,
						Color(0, 1, 0));
					Sleep(20);
				}
			}
			if (effect == 30){
				C2 = 0;
				t++;
				effect = 0;
				healer_effect = 0;
				healer_player2 = 0;
			}
		}

		//player3
		if (healer_player3 == 1){
			C3_h = 0;
			if (HP3 > 0){
				if (HP3 != HP_sub3){
					HP3++;
				}
				if (effect % 2 == 0){
					drawTextureBox(-400 + 100 * 1 - 10, 250 - 125 * 1 - 62, 128, 128, 0, 0, 128, 128,
						texture,
						Color(1, 1, 1));
					Sleep(20);
				}
				if (effect % 2 == 1){
					drawTextureBox(-400 + 100 * 1 - 10, 250 - 125 * 1 - 62, 128, 128, 0, 0, 128, 128,
						texture,
						Color(0, 1, 0));
					Sleep(20);
				}
			}
			if (effect == 30){
				C3 = 0;
				t++;
				effect = 0;
				healer_effect = 0;
				healer_player3 = 0;
			}
		}
		//player4
		if (healer_player4 == 1){
			C4_h = 0;
			if (HP4 > 0){
				if (HP4 != HP_sub4){
					HP4++;
				}
				if (effect % 2 == 0){
					drawTextureBox(-400 + 100 * 1 - 10, 250 - 125 * 2 - 62, 128, 128, 0, 0, 128, 128,
						texture,
						Color(1, 1, 1));
					Sleep(20);
				}
				if (effect % 2 == 1){
					drawTextureBox(-400 + 100 * 1 - 10, 250 - 125 * 2 - 62, 128, 128, 0, 0, 128, 128,
						texture,
						Color(0, 1, 0));
					Sleep(20);
				}
			}
			if (effect == 30){
				C4 = 0;
				t++;
				effect = 0;
				healer_effect = 0;
				healer_player4 = 0;
			}
		}

	}
	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			xx = 0;
		}
		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									h_1 = 1;
									skill_limit++;
								}
							}
						}
					}
				}
			}
		}
	}

	if (h_1 == 1){
		drawTextureBox(-400, -250, 1024, 512, 0, 0, 1024, 512,
			texture_h,
			Color(1, 1, 1));
		//player1
		if (t == turn){
			if (pos.x() > -400 + 200 && pos.x() < -400 + 280 && pos.y() < 250 - 30 && pos.y() > 250 - 120){
				C1 = 1;
				C1_h = 1;
				if (left_click){
					s = 1;
					//t++;
					xx = 50;
					healer_effect = 1;
					healer_player1 = 1;
					h_1 = 0;
					heal_sound.play();
				}
			}
			else{
				C1 = 0;
				C1_h = 0;
			}
		}
		//player2
		if (t == turn){
			if (pos.x() > -400 + 200 && pos.x() < -400 + 280 && pos.y() < 250 - 155 && pos.y() > 250 - 245){
				C2 = 1;
				C2_h = 1;
				if (left_click){
					s = 1;
					//t++;
					xx = 50;
					healer_effect = 1;
					healer_player2 = 1;
					h_1 = 0;
					heal_sound.play();
				}
			}
			else{
				C2 = 0;
				C2_h = 0;
			}
		}
		//player3
		if (t == turn){
			if (pos.x() > -400 + 100 && pos.x() < -400 + 180 && pos.y() < 250 - 80 && pos.y() > 250 - 170){
				C3 = 1;
				C3_h = 1;
				if (left_click){
					s = 1;
					//t++;
					xx = 50;
					healer_effect = 1;
					healer_player3 = 1;
					h_1 = 0;
					heal_sound.play();
				}
			}
			else{
				C3 = 0;
				C3_h = 0;
			}
		}
		//player4
		if (t == turn){
			if (pos.x() > -400 + 100 && pos.x() < -400 + 180 && pos.y() < 250 - 205 && pos.y() > 250 - 295){
				C4 = 1;
				C4_h = 1;
				if (left_click){
					s = 1;
					//t++;
					xx = 50;
					healer_effect = 1;
					healer_player4 = 1;
					h_1 = 0;
					heal_sound.play();
				}
			}
			else{
				C4 = 0;
				C4_h = 0;
			}
		}
	}
}

//とくぎ(thief)
void t_skill(int& turn_plus1, int& xx, const Texture& texture1, const Texture& texture2, const Texture& texture3, int& turn, Vec2f pos, bool left_click, int& thief_effect, Media& debuff_sound){
	if (thief_effect == 1){
		effect++;
		if (effect % 4 == 0){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture1,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 4 == 1){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture2,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 4 == 2){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture1,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 4 == 0){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture3,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect > 25){
			t++;
			effect = 0;
			thief_effect = 0;
		}
	}

	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			xx = 0;
		}
		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									s = 1;
									//t++;
									skill_limit++;
									xx = 50;
									thief_effect = 1;
									debuff = 8;
									debuff_t = 0;
									debuff_sound.play();
								}
							}
						}
					}
				}
			}
		}
	}
}

//とくぎ(dancer)
void d_skill(int& turn_plus1, int& xx, const Texture& texture1, const Texture& texture2, const Texture& texture3, int& turn, Vec2f pos, bool left_click, int& dancer_effect, Media& buff_sound){
	if (dancer_effect == 1){
		effect++;
		if (effect % 4 == 0){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture1,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 4 == 1){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture2,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 4 == 2){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture1,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect % 4 == 0){
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				texture3,
				Color(1, 1, 1));
			Sleep(20);
		}
		if (effect > 25){
			t++;
			effect = 0;
			dancer_effect = 0;
		}
	}

	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			xx = 0;
		}
		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									s = 1;
									//t++;
									skill_limit++;
									xx = 50;
									dancer_effect = 1;
									buff = 12;
									buff_t = 0;
									buff_sound.play();
								}
							}
						}
					}
				}
			}
		}
	}
}
//とくぎ(samurai)
void s_skill(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& HP, Media& samurai_sound){
	if (t == turn_plus1 && s == 1){
		if (xx == 50){
			Sleep(250);
			xx = 0;
		}
		HP -= 20;
		if (HP < 0){
			HP = 1;
		}
		BOSS_HP -= damage * 2.5 * (buff / 10);

		s = 0;
		t++;
	}
	if (skill_limit < 2){
		if (s == 0){
			if (t == turn){
				if (pos.x() > -400 + 62){
					if (pos.x() < -400 + 143){
						if (pos.y() < 250 - 422){
							if (pos.y() > 250 - 450){
								if (left_click){
									s = 1;
									skill_limit++;
									t++;
									xx = 50;
									drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
										texture,
										Color(1, 1, 1));
									samurai_sound.play();
								}
							}
						}
					}
				}
			}
		}
	}
}

//プレイヤー1
void player1(Texture& texture_w, Texture& texture_a, Texture& texture_m, Texture& texture_h, Texture& texture_t, Texture& texture_d, Texture& texture_s, Texture& texture2, int& skill){

	if (HP1 > 0){

		//キャラ表示
		//戦士
		if (ch_1 == 1){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_w,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 1;
			attack_1 = 1;
		}
		//狩人
		if (ch_1 == 2){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_a,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 2;
			attack_1 = 2;
		}
		//魔法使い
		if (ch_1 == 3){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_m,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 3;
			attack_1 = 3;
		}
		//僧侶
		if (ch_1 == 4){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_h,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 4;
			attack_1 = 4;
		}
		//盗賊
		if (ch_1 == 5){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_t,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 5;
			attack_1 = 1;
		}
		//踊り子
		if (ch_1 == 6){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_d,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 6;
			attack_1 = 1;
		}
		//侍
		if (ch_1 == 7){
			drawTextureBox(-400 + 100 * 2 + x1, 250 - 125, 128, 128, 0, 0, 128, 128,
				texture_s,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125, HP_sub1, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125, HP1, 4, Color(0.2, 0.8, 0.2));
			skill_1 = 7;
			attack_1 = 1;
		}


	}

}


//プレイヤー2
void player2(Texture& texture_w, Texture& texture_a, Texture& texture_m, Texture& texture_h, Texture& texture_t, Texture& texture_d, Texture& texture_s, Texture& texture2, int& skill){

	if (HP2 > 0){

		//キャラ表示
		//戦士
		if (ch_2 == 1){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_w,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 1;
			attack_2 = 1;
		}
		//狩人
		if (ch_2 == 2){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_a,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 2;
			attack_2 = 2;
		}
		//魔法使い
		if (ch_2 == 3){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_m,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 3;
			attack_2 = 3;
		}
		//僧侶
		if (ch_2 == 4){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_h,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 4;
			attack_2 = 4;
		}
		//盗賊
		if (ch_2 == 5){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_t,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 5;
			attack_2 = 1;
		}
		//踊り子
		if (ch_2 == 6){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_d,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 6;
			attack_2 = 1;
		}
		//侍
		if (ch_2 == 7){
			drawTextureBox(-400 + 100 * 2 + x2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
				texture_s,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 2, 250 - 125 * 2, HP_sub2, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 2, 250 - 125 * 2, HP2, 4, Color(0.2, 0.8, 0.2));
			skill_2 = 7;
			attack_2 = 1;
		}


	}
}

//プレイヤー3
void player3(Texture& texture_w, Texture& texture_a, Texture& texture_m, Texture& texture_h, Texture& texture_t, Texture& texture_d, Texture& texture_s, Texture& texture2, int& skill){

	if (HP3 > 0){

		//キャラ表示
		//戦士
		if (ch_3 == 1){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_w,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 1;
			attack_3 = 1;
		}
		//狩人
		if (ch_3 == 2){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_a,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 2;
			attack_3 = 2;
		}
		//魔法使い
		if (ch_3 == 3){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_m,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 3;
			attack_3 = 3;
		}
		//僧侶
		if (ch_3 == 4){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_h,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 4;
			attack_3 = 4;
		}
		//盗賊
		if (ch_3 == 5){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_t,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 5;
			attack_3 = 1;
		}
		//踊り子
		if (ch_3 == 6){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_d,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 6;
			attack_3 = 1;
		}
		//侍
		if (ch_3 == 7){
			drawTextureBox(-400 + 100 * 1 + x3, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
				texture_s,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP_sub3, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 1 - 50, HP3, 4, Color(0.2, 0.8, 0.2));
			skill_3 = 7;
			attack_3 = 1;
		}


	}

}

//プレイヤー4
void player4(Texture& texture_w, Texture& texture_a, Texture& texture_m, Texture& texture_h, Texture& texture_t, Texture& texture_d, Texture& texture_s, Texture& texture2, int& skill){

	if (HP4 > 0){

		//キャラ表示
		//戦士
		if (ch_4 == 1){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_w,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 1;
			attack_4 = 1;
		}
		//狩人
		if (ch_4 == 2){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_a,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 2;
			attack_4 = 2;
		}
		//魔法使い
		if (ch_4 == 3){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_m,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 3;
			attack_4 = 3;
		}
		//僧侶
		if (ch_4 == 4){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_h,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 4;
			attack_4 = 4;
		}
		//盗賊
		if (ch_4 == 5){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_t,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 5;
			attack_4 = 1;
		}
		//踊り子
		if (ch_4 == 6){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_d,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 6;
			attack_4 = 1;
		}
		//侍
		if (ch_4 == 7){
			drawTextureBox(-400 + 100 * 1 + x4, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
				texture_s,
				Color(1, 1, 1));
			drawBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP_sub4, 4, 2, Color(0, 0, 0));
			drawFillBox(-400 + 100 * 1, 250 - 125 * 2 - 50, HP4, 4, Color(0.2, 0.8, 0.2));
			skill_4 = 7;
			attack_4 = 1;
		}


	}
}



// 
// メインプログラム
// 
int main() {
	// アプリウインドウの準備
	AppEnv app_env(Window::WIDTH, Window::HEIGHT);
	// メインループ
	//	while (1) {
	// ウィンドウが閉じられたらアプリを終了
	if (!app_env.isOpen()) return 0;

	// 描画準備
	app_env.setupDraw();
	//画像
	Texture title_image("res/title.png");
	Texture CLICK_TO_START_image("res/CLICK TO START.png");

	Texture jobchange_image("res/jobchange.png");

	Texture BG_1("res/BG_1.png");
	Texture BG_2("res/BG_2.png");
	Texture BG_3("res/BG_3.png");
	Texture BOSS_1("res/waiba-n.png");
	Texture oonamazu_image("res/oonamazu.png");
	Texture oneirosu_image("res/oneirosu.png");
	Texture maou_image("res/maou.png");
	Texture warrior_image("res/warrior.png");
	Texture archer_image("res/archer.png");
	Texture magician_image("res/magician.png");
	Texture healer_image("res/healer.png");
	Texture thief_image("res/thief.png");
	Texture dancer_image("res/dancer.png");
	Texture samurai_image("res/samurai.png");
	Texture coffin_image("res/coffin.png");
	Texture command_image("res/command.png");
	Texture healer_command_image("res/healer_command.png");
	Texture effect_zan_image("res/effect_zan.png");
	Texture effect_zan2_image("res/effect_zan2.png");
	Texture effect_zan3_image("res/effect_zan3.png");
	Texture effect_zan4_image("res/effect_zan4.png");
	Texture effect_zaku_image("res/effect_zaku.png");
	Texture effect_zaku2_image("res/effect_zaku2.png");
	Texture effect_ban_red_image("res/effect_ban_red.png");
	Texture effect_ban_white_image("res/effect_ban_white.png");
	Texture effect_heal_image("res/effect_heal.png");
	Texture effect_buff1_image("res/effect_buff1.png");
	Texture effect_buff2_image("res/effect_buff2.png");
	Texture effect_buff3_image("res/effect_buff3.png");
	Texture effect_debuff1_image("res/effect_debuff1.png");
	Texture effect_debuff2_image("res/effect_debuff2.png");
	Texture effect_debuff3_image("res/effect_debuff3.png");
	Texture effect_defense_image("res/defense.png");
	Texture effect_BOSS_fire_image("res/effect_BOSS_fire.png");
	Texture effect_BOSS_water_image("res/effect_BOSS_water.png");
	Texture effect_BOSS_beam_image("res/effect_BOSS_beam.png");
	Texture f_image("res/1.png");
	Texture s_image("res/2.png");
	Texture t_image("res/3.png");
	Texture escape_image("res/escape.png");
	Texture gameover_image("res/gameover.png");
	Texture player1_1_image("res/player1_1.png");
	Texture player2_1_image("res/player2_1.png");
	Texture player3_1_image("res/player3_1.png");
	Texture player4_1_image("res/player4_1.png");
	Texture player1_2_image("res/player1_2.png");
	Texture player2_2_image("res/player2_2.png");
	Texture player3_2_image("res/player3_2.png");
	Texture player4_2_image("res/player4_2.png");
	Texture clear_1_image("res/clear_1.png");
	Texture clear_2_image("res/clear_2.png");
	Texture clear_3_image("res/clear_3.png");
	Texture clear_4_image("res/clear_4.png");
	Texture waiban_job_image("res/waiban_job.png");
	Texture oonamazu_job_image("res/oonamazu_job.png");
	Texture maou_job_image("res/maou_job.png");
	Texture oneirosu_job_image("res/oneirosu_job.png");
	Texture game_rule_image("res/game_rule.png");
	Texture job_image("res/job.png");
	Texture CS_image("res/CS_image.png");
	Texture area1_1("res/1-1.png");
	Texture area1_2("res/1-2.png");
	Texture area1_3("res/1-3.png");
	Texture area1_4("res/1-4.png");
	Texture buff_image("res/buff.png");
	Texture debuff_image("res/debuff.png");
	Texture enemy_dead_image("res/enemy_dead.png");

	//音
	Media title_sound("res/title_sound.wav");
	Media job_sound("res/job_sound.wav");
	Media waiban_sound("res/waiban_sound.wav");
	Media oonamazu_sound("res/oonamazu_sound.wav");
	Media oneirosu_sound("res/oneirosu_sound.wav");
	Media maou_sound("res/maou_sound.wav");
	Media OK_sound("res/OK_sound.wav");
	Media ch_sound("res/ch_sound.wav");
	Media cancel_sound("res/cancel_sound.wav");
	Media zan_sound("res/zan_sound.wav");
	Media zan2_sound("res/zan2_sound.wav");
	Media zaku_sound("res/zaku_sound.wav");
	Media ban_sound("res/ban_sound.wav");
	Media heal_sound("res/heal_sound.wav");
	Media debuff_sound("res/debuff_sound.wav");
	Media buff_sound("res/buff_sound.wav");
	Media samurai_sound("res/samurai_sound.wav");
	Media BOSS_fire_sound("res/BOSS_fire_sound.wav");
	Media BOSS_water_sound("res/BOSS_water_sound.wav");
	Media BOSS_beam_sound("res/BOSS_beam_sound.wav");
	Media BOSS_zan_sound("res/zan2_sound.wav");
	Media BOSS_maou_sound("res/BOSS_maou_sound.wav");
	Media clear_sound("res/clear.wav");
	Media gameover_sound("res/game_over.wav");

	//曲ループ処理
	title_sound.looping(1);
	job_sound.looping(1);
	waiban_sound.looping(1);
	oonamazu_sound.looping(1);
	oneirosu_sound.looping(1);

	//バック音楽(タイトル)
	title_sound.play();

	//タイトル
	{
		while (1){
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			//コンティニュー用

			//タイトル画面
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				title_image,
				Color(1, 1, 1));
			//ENTER TO START
			i++;
			int ii;
			ii = (i / 6) % 2;
			if (ii){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					CLICK_TO_START_image,
					Color(1, 1, 1));
			}
			if (left_click)  break;


			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
		bool left_click = app_env.isPushButton(Mouse::LEFT);
		left_click = 0;
	}
	//ゲームルール
	{
		while (1){

			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			//ゲームルール画面
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				game_rule_image,
				Color(1, 1, 1));
			if (left_click)  break;

			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
		bool left_click = app_env.isPushButton(Mouse::LEFT);
		left_click = 0;
	}


	title_sound.stop();
	job_sound.play();

	//キャラ選択画面
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);
			if (enemy != 0 && status != 0){
				//メイン画面
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					jobchange_image,
					Color(1, 1, 1));
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					area1_1,
					Color(1, 1, 1));

				//キャラ選択(プレイヤー1)
				//戦士
				if (ch_1 == 0){
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 96){
								if (pos.y() > 250 - 139){
									if (left_click){
										ch_1 = 1;
										HP1 = 100;
										HP_sub1 = 100;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;

									}
								}
							}
						}
					}
					//狩人
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 149){
								if (pos.y() > 250 - 192){
									if (left_click){
										ch_1 = 2;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//魔法使い
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 211){
							if (pos.y() < 250 - 204){
								if (pos.y() > 250 - 244){
									if (left_click){
										ch_1 = 3;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 70;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//僧侶
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 261){
								if (pos.y() > 250 - 302){
									if (left_click){
										ch_1 = 4;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 30;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//盗賊
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 314){
								if (pos.y() > 250 - 356){
									if (left_click){
										ch_1 = 5;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//踊り子
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 170){
							if (pos.y() < 250 - 366){
								if (pos.y() > 250 - 408){
									if (left_click){
										ch_1 = 6;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//侍
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 81){
							if (pos.y() < 250 - 418){
								if (pos.y() > 250 - 460){
									if (left_click){
										ch_1 = 7;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 60;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_1 == 1){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_1 == 2){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_1 == 3){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_1 == 4){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_1 == 5){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_1 == 6){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_1 == 7){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}


				// キャラ選択(プレイヤー2)
				//戦士
				if (ch_1 != 0){
					if (ch_2 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_2 = 1;
											HP2 = 100;
											HP_sub2 = 100;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_2 = 2;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_2 = 3;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_2 = 4;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_2 = 5;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_2 = 6;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_2 = 7;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_2 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_2 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_2 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_2 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_2 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_2 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_2 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー3)
				//戦士
				if (ch_2 != 0){
					if (ch_3 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_3 = 1;
											HP3 = 100;
											HP_sub3 = 100;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_3 = 2;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_3 = 3;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_3 = 4;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_3 = 5;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_3 = 6;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_3 = 7;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_3 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_3 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_3 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_3 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_3 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_3 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_3 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー4)
				//戦士
				if (ch_3 != 0){
					if (ch_4 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_4 = 1;
											HP4 = 100;
											HP_sub4 = 100;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_4 = 2;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_4 = 3;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_4 = 4;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_4 = 5;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_4 = 6;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_4 = 7;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_4 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_4 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_4 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_4 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_4 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_4 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_4 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				//OK判定
				if (ch_1 != 0 && ch_2 != 0 && ch_3 != 0 && ch_4 != 0){
					if (pos.x() > -400 + 407){
						if (pos.x() < -400 + 478){
							if (pos.y() < 250 - 449){
								if (pos.y() > 250 - 495){
									if (left_click){
										OK_sound.play();
										break;
										left_click = false;
									}
								}
							}
						}
					}
				}
				//取り消し判定
				if (pos.x() > -400 + 488){
					if (pos.x() < -400 + 632){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									cancel_sound.play();
									ch_1 = 0;
									ch_2 = 0;
									ch_3 = 0;
									ch_4 = 0;
								}
							}
						}
					}
				}
			}
			//敵情報確認
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 449){
						if (pos.y() > 250 - 495){
							if (left_click){
								enemy = 0;
							}
						}
					}
				}
			}
			if (enemy == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					waiban_job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									enemy = 1;
								}
							}
						}
					}
				}
			}
			//キャラステータス
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 396){
						if (pos.y() > 250 - 438){
							if (left_click){
								status = 0;
							}
						}
					}
				}
			}
			if (status == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 460){
							if (pos.y() > 250 - 495){
								if (left_click){
									status = 1;
								}
							}
						}
					}
				}
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	job_sound.stop();
	waiban_sound.play();

	//ゲーム本編
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;
			//アプリ終了
			if (e == 2) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			//背景
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				BG_1,
				Color(1, 1, 1));
			//コマンド
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				command_image,
				Color(1, 1, 1));

			//敵の動き
			if (t == 0){
				BOSS_effect += 1;
				if (BOSS == 0){
					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 220, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 250, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 190, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
				}
				if (BOSS == 1){

					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 350, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 350 + 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 350 - 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));

					}
				}
				if (BOSS == 2){

					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 283, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 283 + 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 283 - 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));

					}
				}

				if (BOSS == 3){

					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 403, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 403 + 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 403 - 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_fire_image,
							Color(1, 1, 1));

					}
				}
			}

			if (BOSS_effect > 80){

				if (BOSS == 0 && b3_1 == 1)HP1 -= (50 * (debuff / 10));
				if (BOSS == 1 && b3_2 == 1)HP2 -= (50 * (debuff / 10));
				if (BOSS == 2 && b3_3 == 1)HP3 -= (50 * (debuff / 10));
				if (BOSS == 3 && b3_4 == 1)HP4 -= (50 * (debuff / 10));
				t = 1;
				BOSS_effect = 0;
				BOSS = 4;
				BOSS_x = 0;
			}


			if (t == 10){
				BOSS_fire_sound.play();
			}

			if (t == 10){
				t = 0;
				skill_limit = 0;
			}

			if (waiban_HP > 0){
				if (t == 9){
					time_t date;
					srand(time(&date));
					BOSS = rand() % 4;
					if (HP1 > 0){
						if (BOSS == 0){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP2 > 0){
						if (BOSS == 1){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP3 > 0){
						if (BOSS == 2){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP4 > 0){
						if (BOSS == 3){
							BOSS_x = 20;
							t = 10;
						}
					}
				}
			}

			//敵の表示
			if (waiban_HP > 0){
				drawTextureBox(-800 / 2 - BOSS_x, -500 / 2, 800, 500, 0, 0, 800, 500,
					BOSS_1,
					Color(1, 1, 1));
				drawBox(60, 110, 200, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, waiban_HP / 5, 4, Color(0.2, 0.8, 0.2));
			}
			else{
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					BOSS_1,
					Color(1, 1, 1, enemy_dead2));
				enemy_dead2 -= 0.05;
				drawBox(60, 110, 200, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, waiban_HP / 5, 4, Color(0.2, 0.8, 0.2));
				drawTextureBox(16, -128, 256, 256, 0, 0, 256, 256,
					enemy_dead_image,
					Color(1, enemy_dead % 2, 0,0.5));
				if (i % 3 == 0){
					enemy_dead++;
				}
				i++;
				if (enemy_dead > 30)break;
			}
			BOSS_air = 1;


			//player文字表示
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player1_1_image,
				Color(1, 1 - C1_h, 1 - C1));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player2_1_image,
				Color(1, 1 - C2_h, 1 - C2));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player3_1_image,
				Color(1, 1 - C3_h, 1 - C3));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player4_1_image,
				Color(1, 1 - C4_h, 1 - C4));
			if (t == 1){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player1_2_image,
					Color(1, 1, 1));
			}
			if (t == 3){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player2_2_image,
					Color(1, 1, 1));
			}
			if (t == 5){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player3_2_image,
					Color(1, 1, 1));
			}
			if (t == 7){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player4_2_image,
					Color(1, 1, 1));
			}

			//player表示色変え
			if (t == 1){ C1 = 1; C4 = 0; }
			if (t == 2){ C1 = 0; C4 = 0; }
			if (t == 3){ C2 = 1; C1 = 0; }
			if (t == 4){ C2 = 0; C1 = 0; }
			if (t == 5){ C3 = 1; C2 = 0; }
			if (t == 6){ C3 = 0; C2 = 0; }
			if (t == 7){ C4 = 1; C3 = 0; }
			if (t == 8){ C4 = 0; C3 = 0; }

			//プレイヤー1コマンド
			if (HP1 > 0){
				//コマンド系
				if (attack_1 == 1){
					attack(t2, x1, effect_zan_image, t1, pos, left_click, waiban_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 2){
					attack(t2, x1, effect_zaku_image, t1, pos, left_click, waiban_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 3){
					attack(t2, x1, effect_ban_red_image, t1, pos, left_click, waiban_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 4){
					attack(t2, x1, effect_ban_white_image, t1, pos, left_click, waiban_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_1 == 1){
					w_skill(t2, x1, effect_zan_image, effect_zan2_image, t1, pos, left_click, waiban_HP, dm_1, zan2_sound);
				}
				if (skill_1 == 2){
					a_skill(t2, x1, effect_zaku2_image, t1, pos, left_click, waiban_HP, dm_1, archar_effect_1, zaku_sound);
				}
				if (skill_1 == 3){
					m_skill(t2, x1, effect_ban_red_image, t1, pos, left_click, waiban_HP, dm_1, magician_effect_1, ban_sound);
				}
				if (skill_1 == 4){
					h_skill(t2, x1, effect_heal_image, healer_command_image, t1, pos, left_click, healer_effect_1, heal_sound);
				}
				if (skill_1 == 5){
					t_skill(t2, x1, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t1, pos, left_click, thief_effect_1, debuff_sound);
				}
				if (skill_1 == 6){
					d_skill(t2, x1, effect_buff1_image, effect_buff2_image, effect_buff3_image, t1, pos, left_click, dancer_effect_1, buff_sound);
				}
				if (skill_1 == 7){
					s_skill(t2, x1, effect_zan3_image, t1, pos, left_click, waiban_HP, dm_1, HP1, samurai_sound);
				}
				defense(t2, x1, effect_defense_image, t1, pos, left_click, HP1, b1_1, b3_1);
				escape(escape_image, t1, pos, left_click);
			}
			//プレイヤー2コマンド
			if (HP2 > 0){
				//コマンド系
				if (attack_2 == 1){
					attack(t4, x2, effect_zan_image, t3, pos, left_click, waiban_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 2){
					attack(t4, x2, effect_zaku_image, t3, pos, left_click, waiban_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 3){
					attack(t4, x2, effect_ban_red_image, t3, pos, left_click, waiban_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 4){
					attack(t4, x2, effect_ban_white_image, t3, pos, left_click, waiban_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_2 == 1){
					w_skill(t4, x2, effect_zan_image, effect_zan2_image, t3, pos, left_click, waiban_HP, dm_2, zan2_sound);
				}
				if (skill_2 == 2){
					a_skill(t4, x2, effect_zaku2_image, t3, pos, left_click, waiban_HP, dm_2, archar_effect_2, zaku_sound);
				}
				if (skill_2 == 3){
					m_skill(t4, x2, effect_ban_red_image, t3, pos, left_click, waiban_HP, dm_1, magician_effect_2, ban_sound);
				}
				if (skill_2 == 4){
					h_skill(t4, x2, effect_heal_image, healer_command_image, t3, pos, left_click, healer_effect_2, heal_sound);
				}
				if (skill_2 == 5){
					t_skill(t4, x2, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t3, pos, left_click, thief_effect_2, debuff_sound);
				}
				if (skill_2 == 6){
					d_skill(t4, x2, effect_buff1_image, effect_buff2_image, effect_buff3_image, t3, pos, left_click, dancer_effect_2, buff_sound);
				}
				if (skill_2 == 7){
					s_skill(t4, x2, effect_zan3_image, t3, pos, left_click, waiban_HP, dm_2, HP2, samurai_sound);
				}
				defense(t4, x2, effect_defense_image, t3, pos, left_click, HP2, b1_2, b3_2);
				escape(escape_image, t3, pos, left_click);
			}
			//プレイヤー3コマンド
			if (HP3 > 0){

				//コマンド系
				if (attack_3 == 1){
					attack(t6, x3, effect_zan_image, t5, pos, left_click, waiban_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 2){
					attack(t6, x3, effect_zaku_image, t5, pos, left_click, waiban_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 3){
					attack(t6, x3, effect_ban_red_image, t5, pos, left_click, waiban_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 4){
					attack(t6, x3, effect_ban_white_image, t5, pos, left_click, waiban_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_3 == 1){
					w_skill(t6, x3, effect_zan_image, effect_zan2_image, t5, pos, left_click, waiban_HP, dm_3, zan2_sound);
				}
				if (skill_3 == 2){
					a_skill(t6, x3, effect_zaku2_image, t5, pos, left_click, waiban_HP, dm_3, archar_effect_3, zaku_sound);
				}
				if (skill_3 == 3){
					m_skill(t6, x3, effect_ban_red_image, t5, pos, left_click, waiban_HP, dm_1, magician_effect_3, ban_sound);
				}
				if (skill_3 == 4){
					h_skill(t6, x3, effect_heal_image, healer_command_image, t5, pos, left_click, healer_effect_3, heal_sound);
				}
				if (skill_3 == 5){
					t_skill(t6, x3, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t5, pos, left_click, thief_effect_3, debuff_sound);
				}
				if (skill_3 == 6){
					d_skill(t6, x3, effect_buff1_image, effect_buff2_image, effect_buff3_image, t5, pos, left_click, dancer_effect_3, buff_sound);
				}
				if (skill_3 == 7){
					s_skill(t6, x3, effect_zan3_image, t5, pos, left_click, waiban_HP, dm_3, HP3, samurai_sound);
				}
				defense(t6, x3, effect_defense_image, t5, pos, left_click, HP3, b1_3, b3_3);
				escape(escape_image, t5, pos, left_click);
			}
			//プレイヤー4コマンド
			if (HP4 > 0){
				//コマンド系
				if (attack_4 == 1){
					attack(t8, x4, effect_zan_image, t7, pos, left_click, waiban_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 2){
					attack(t8, x4, effect_zaku_image, t7, pos, left_click, waiban_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 3){
					attack(t8, x4, effect_ban_red_image, t7, pos, left_click, waiban_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 4){
					attack(t8, x4, effect_ban_white_image, t7, pos, left_click, waiban_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_4 == 1){
					w_skill(t8, x4, effect_zan_image, effect_zan2_image, t7, pos, left_click, waiban_HP, dm_4, zan2_sound);
				}
				if (skill_4 == 2){
					a_skill(t8, x4, effect_zaku2_image, t7, pos, left_click, waiban_HP, dm_4, archar_effect_4, zaku_sound);
				}
				if (skill_4 == 3){
					m_skill(t8, x4, effect_ban_red_image, t7, pos, left_click, waiban_HP, dm_1, magician_effect_4, ban_sound);
				}
				if (skill_4 == 4){
					h_skill(t8, x4, effect_heal_image, healer_command_image, t7, pos, left_click, healer_effect_4, heal_sound);
				}
				if (skill_4 == 5){
					t_skill(t8, x4, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t7, pos, left_click, thief_effect_4, debuff_sound);
				}
				if (skill_4 == 6){
					d_skill(t8, x4, effect_buff1_image, effect_buff2_image, effect_buff3_image, t7, pos, left_click, dancer_effect_4, buff_sound);
				}
				if (skill_4 == 7){
					s_skill(t8, x4, effect_zan3_image, t7, pos, left_click, waiban_HP, dm_4, HP4, samurai_sound);
				}
				defense(t8, x4, effect_defense_image, t7, pos, left_click, HP4, b1_4, b3_4);
				escape(escape_image, t7, pos, left_click);
			}

			//バフ関連
			if (buff == 12){
				if (t == 10){
					buff_t++;
				}
				if (buff_t == 2){
					buff = 10;
					buff_t = 0;
				}
				drawTextureBox(-WIDTH / 2, -HEIGHT / 2, 800, 500, 0, 0, 800, 500,
					buff_image,
					Color(1, 1, 1));
			}
			//デバフ関連
			if (debuff == 8){
				if (t == 10){
					debuff_t++;
				}
				if (debuff_t == 3){
					debuff = 10;
					debuff_t = 0;
				}
				drawTextureBox(-WIDTH / 2, -HEIGHT / 2, 800, 500, 0, 0, 800, 500,
					debuff_image,
					Color(1, 1, 1));
			}

			//ボスターン処理
			if (t == 10){
				BOSS_t++;
			}

			//プレイヤー1表示
			if (HP1 > 0){
				player1(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_1);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 1){
					t += 2;
				}
			}

			//プレイヤー2表示
			if (HP2 > 0){
				player2(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_2);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 3){
					t += 2;
				}
			}

			//プレイヤー3表示
			if (HP3 > 0){
				player3(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_3);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 5){
					t += 2;
				}
			}

			//プレイヤー4表示
			if (HP4 > 0){
				player4(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_4);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 7){
					t += 2;
				}
			}

			//ゲームオーバー画面
			if (dead == 1){
				Sleep(500);
				waiban_sound.stop();
				if (g == 0){
					g = 1;
					gameover_sound.play();
				}
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					gameover_image,
					Color(1, 1, 1));
				if (left_click){
					e = 2;
				}
			}
			if (HP1 <= 0 && HP2 <= 0 && HP3 <= 0 && HP4 <= 0){
				dead = 1;
			}

			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	waiban_sound.stop();
	clear_sound.play();

	//クリア画面
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				clear_1_image,
				Color(1, 1, 1));
			if (left_click){
				break;
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	clear_sound.stop();
	//変数初期化
	i = 30; HP1 = 1; HP2 = 1; HP3 = 1; HP4 = 1; waiban_HP = 1000; t = 1; w = 0; t1 = 1; t2 = 2; t3 = 3; t4 = 4; t5 = 5;
	t6 = 6; t7 = 7; t8 = 8; a = 0; s = 0; b = 0; b1_1 = 0; b1_2 = 0; b1_3 = 0; b1_4 = 0; b2 = 0; b3_1 = 1; b3_2 = 1; b3_3 = 1;
	b3_4 = 1; e = 0; x1 = 0; x2 = 0; x3 = 0; x4 = 0; BOSS = 4; dead = 0; dm_1 = 0; dm_2 = 0; dm_3 = 0; dm_4 = 0; skill_1 = 0;
	skill_2 = 0; skill_3 = 0; skill_4 = 0; ch_1 = 0; ch_2 = 0; ch_3 = 0; ch_4 = 0; BOSS_x = 0; BOSS_effect = 0; attack_1 = 0;
	attack_2 = 0; attack_3 = 0; attack_4 = 0; effect = 0; effect_1 = 0; effect_2 = 0; effect_3 = 0; effect_4 = 0; BOSS_air = 0;
	archar_effect_1 = 0; archar_effect_2 = 0; archar_effect_3 = 0; archar_effect_4 = 0; magician_effect_1 = 0; magician_effect_2 = 0;
	magician_effect_3 = 0; magician_effect_4 = 0; healer_effect_1 = 0; healer_effect_2 = 0; healer_effect_3 = 0; healer_effect_4 = 0;
	HP_sub1 = 1; HP_sub2 = 1; HP_sub3 = 1; HP_sub4 = 1; healer_player1 = 0; healer_player2 = 0; healer_player3 = 0; healer_player4 = 0;
	C1_h = 0; C2_h = 0; C3_h = 0; C4_h = 0; h_1 = 0; h_2 = 0; h_3 = 0; h_4 = 0; c = 0; buff_t = 0; debuff_t = 0; dancer_effect_1 = 0;
	dancer_effect_2 = 0; dancer_effect_3 = 0; dancer_effect_4 = 0; thief_effect_1 = 0; thief_effect_2 = 0; thief_effect_3 = 0;
	thief_effect_4 = 0; skill_limit = 0; BOSS_t = -1; oonamazu_HP = 1200; enemy = 1; status = 1; g = 0, enemy_dead = 0,enemy_dead2 = 1;

	C1 = 0; C2 = 0; C3 = 0; C4 = 0; buff = 10; debuff = 10;

	job_sound.play();

	//キャラ選択画面
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			if (enemy != 0 && status != 0){
				//メイン画面
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					jobchange_image,
					Color(1, 1, 1));
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					area1_2,
					Color(1, 1, 1));

				//キャラ選択(プレイヤー1)
				//戦士
				if (ch_1 == 0){
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 96){
								if (pos.y() > 250 - 139){
									if (left_click){
										ch_1 = 1;
										HP1 = 100;
										HP_sub1 = 100;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;

									}
								}
							}
						}
					}
					//狩人
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 149){
								if (pos.y() > 250 - 192){
									if (left_click){
										ch_1 = 2;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//魔法使い
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 211){
							if (pos.y() < 250 - 204){
								if (pos.y() > 250 - 244){
									if (left_click){
										ch_1 = 3;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 70;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//僧侶
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 261){
								if (pos.y() > 250 - 302){
									if (left_click){
										ch_1 = 4;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 30;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//盗賊
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 314){
								if (pos.y() > 250 - 356){
									if (left_click){
										ch_1 = 5;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//踊り子
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 170){
							if (pos.y() < 250 - 366){
								if (pos.y() > 250 - 408){
									if (left_click){
										ch_1 = 6;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//侍
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 81){
							if (pos.y() < 250 - 418){
								if (pos.y() > 250 - 460){
									if (left_click){
										ch_1 = 7;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 60;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_1 == 1){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_1 == 2){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_1 == 3){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_1 == 4){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_1 == 5){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_1 == 6){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_1 == 7){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}


				// キャラ選択(プレイヤー2)
				//戦士
				if (ch_1 != 0){
					if (ch_2 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_2 = 1;
											HP2 = 100;
											HP_sub2 = 100;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_2 = 2;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_2 = 3;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_2 = 4;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_2 = 5;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_2 = 6;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_2 = 7;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_2 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_2 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_2 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_2 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_2 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_2 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_2 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー3)
				//戦士
				if (ch_2 != 0){
					if (ch_3 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_3 = 1;
											HP3 = 100;
											HP_sub3 = 100;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_3 = 2;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_3 = 3;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_3 = 4;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_3 = 5;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_3 = 6;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_3 = 7;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_3 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_3 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_3 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_3 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_3 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_3 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_3 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー4)
				//戦士
				if (ch_3 != 0){
					if (ch_4 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_4 = 1;
											HP4 = 100;
											HP_sub4 = 100;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_4 = 2;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 40;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_4 = 3;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_4 = 4;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_4 = 5;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_4 = 6;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 40;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_4 = 7;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_4 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_4 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_4 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_4 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_4 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_4 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_4 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				//OK判定
				if (ch_1 != 0 && ch_2 != 0 && ch_3 != 0 && ch_4 != 0){
					if (pos.x() > -400 + 407){
						if (pos.x() < -400 + 478){
							if (pos.y() < 250 - 449){
								if (pos.y() > 250 - 495){
									if (left_click){
										OK_sound.play();
										break;
										left_click = false;
									}
								}
							}
						}
					}
				}
				//取り消し判定
				if (pos.x() > -400 + 488){
					if (pos.x() < -400 + 632){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									cancel_sound.play();
									ch_1 = 0;
									ch_2 = 0;
									ch_3 = 0;
									ch_4 = 0;
								}
							}
						}
					}
				}
			}

			//敵情報確認
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 449){
						if (pos.y() > 250 - 495){
							if (left_click){
								enemy = 0;
							}
						}
					}
				}
			}
			if (enemy == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					oonamazu_job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									enemy = 1;
								}
							}
						}
					}
				}
			}

			//キャラステータス
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 396){
						if (pos.y() > 250 - 438){
							if (left_click){
								status = 0;
							}
						}
					}
				}
			}
			if (status == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 460){
							if (pos.y() > 250 - 495){
								if (left_click){
									status = 1;
								}
							}
						}
					}
				}
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	job_sound.stop();
	oonamazu_sound.play();


	//ゲーム本編2
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;
			//アプリ終了
			if (e == 2) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			//背景
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				BG_2,
				Color(1, 1, 1));
			//コマンド
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				command_image,
				Color(1, 1, 1));


			//敵の動き
			if (BOSS_t % 3 != 0){
				if (t == 0){
					BOSS_effect += 1;
					if (BOSS == 0){
						if (BOSS_effect > 0){
							drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 220, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 220, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 40){
							drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 220, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
					}
					if (BOSS == 1){

						if (BOSS_effect > 0){
							drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 350, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 350, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 40){
							drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 350, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));

						}
					}
					if (BOSS == 2){

						if (BOSS_effect > 0){
							drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 283, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 283, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 40){
							drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 283, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));

						}
					}

					if (BOSS == 3){

						if (BOSS_effect > 0){
							drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 403, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 403, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 40){
							drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 403, 256, 256, 0, 0, 256, 256,
								effect_BOSS_water_image,
								Color(1, 1, 1));

						}
					}
				}
			}

			if (BOSS_t % 3 == 0){
				if (t == 0){
					BOSS_effect++;
					if (BOSS_effect > 15){
						drawTextureBox(-400, -100, 800, 500, 0, 0, 800, 500,
							f_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 30){
						drawTextureBox(-400, -100, 800, 500, 0, 0, 800, 500,
							t_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 45){
						drawTextureBox(-400, -100, 800, 500, 0, 0, 800, 500,
							t_image,
							Color(1, 1, 1));
					}
				}
			}
			if (BOSS_t % 3 != 0){
				if (BOSS_effect > 80){

					if (BOSS == 0 && b3_1 == 1)HP1 -= (50 * (debuff / 10));
					if (BOSS == 1 && b3_2 == 1)HP2 -= (50 * (debuff / 10));
					if (BOSS == 2 && b3_3 == 1)HP3 -= (50 * (debuff / 10));
					if (BOSS == 3 && b3_4 == 1)HP4 -= (50 * (debuff / 10));
					t = 1;
					BOSS_effect = 0;
					BOSS = 4;
					BOSS_x = 0;
				}
			}
			if (BOSS_t % 3 == 0){
				if (BOSS_effect > 60){
					if (b3_1 == 1)HP1 -= (20 * (debuff / 10));
					if (b3_2 == 1)HP2 -= (20 * (debuff / 10));
					if (b3_3 == 1)HP3 -= (20 * (debuff / 10));
					if (b3_4 == 1)HP4 -= (20 * (debuff / 10));
					t = 1;
					BOSS_effect = 0;
					BOSS = 4;
					BOSS_x = 0;
				}
			}

			if (t == 10){
				if (BOSS_t % 3 != 0){
					BOSS_fire_sound.play();
				}
			}

			if (t == 10){
				if (BOSS_t % 3 == 0){
					BOSS_water_sound.play();
				}
			}

			if (t == 10){
				t = 0;
				skill_limit = 0;
			}

			if (oonamazu_HP > 0){
				if (t == 9){
					time_t date;
					srand(time(&date));
					BOSS = rand() % 4;
					if (HP1 > 0){
						if (BOSS == 0){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP2 > 0){
						if (BOSS == 1){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP3 > 0){
						if (BOSS == 2){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP4 > 0){
						if (BOSS == 3){
							BOSS_x = 20;
							t = 10;
						}
					}
				}
			}

			//敵の表示
			if (oonamazu_HP > 0){
				drawTextureBox(-800 / 2 - BOSS_x, -500 / 2, 800, 500, 0, 0, 800, 500,
					oonamazu_image,
					Color(1, 1, 1));
				drawBox(60, 110, 240, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, oonamazu_HP / 5, 4, Color(0.2, 0.8, 0.2));
			}
			else{
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					oonamazu_image,
					Color(1, 1, 1, enemy_dead2));
				enemy_dead2 -= 0.05;
				drawBox(60, 110, 240, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, oonamazu_HP / 5, 4, Color(0.2, 0.8, 0.2));
				drawTextureBox(16, -128, 256, 256, 0, 0, 256, 256,
					enemy_dead_image,
					Color(1, enemy_dead % 2, 0, 0.5));

				if (i % 3 == 0){
					enemy_dead++;
				}
				i++;
				if (enemy_dead > 30)break;

			}
			BOSS_air = 0;


			//player文字表示
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player1_1_image,
				Color(1, 1 - C1_h, 1 - C1));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player2_1_image,
				Color(1, 1 - C2_h, 1 - C2));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player3_1_image,
				Color(1, 1 - C3_h, 1 - C3));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player4_1_image,
				Color(1, 1 - C4_h, 1 - C4));
			if (t == 1){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player1_2_image,
					Color(1, 1, 1));
			}
			if (t == 3){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player2_2_image,
					Color(1, 1, 1));
			}
			if (t == 5){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player3_2_image,
					Color(1, 1, 1));
			}
			if (t == 7){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player4_2_image,
					Color(1, 1, 1));
			}

			//player表示色変え
			if (t == 1){ C1 = 1; C4 = 0; }
			if (t == 2){ C1 = 0; C4 = 0; }
			if (t == 3){ C2 = 1; C1 = 0; }
			if (t == 4){ C2 = 0; C1 = 0; }
			if (t == 5){ C3 = 1; C2 = 0; }
			if (t == 6){ C3 = 0; C2 = 0; }
			if (t == 7){ C4 = 1; C3 = 0; }
			if (t == 8){ C4 = 0; C3 = 0; }

			//プレイヤー1コマンド
			if (HP1 > 0){
				//コマンド系
				if (attack_1 == 1){
					attack(t2, x1, effect_zan_image, t1, pos, left_click, oonamazu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 2){
					attack(t2, x1, effect_zaku_image, t1, pos, left_click, oonamazu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 3){
					attack(t2, x1, effect_ban_red_image, t1, pos, left_click, oonamazu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 4){
					attack(t2, x1, effect_ban_white_image, t1, pos, left_click, oonamazu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_1 == 1){
					w_skill(t2, x1, effect_zan_image, effect_zan2_image, t1, pos, left_click, oonamazu_HP, dm_1, zan2_sound);
				}
				if (skill_1 == 2){
					a_skill(t2, x1, effect_zaku2_image, t1, pos, left_click, oonamazu_HP, dm_1, archar_effect_1, zaku_sound);
				}
				if (skill_1 == 3){
					m_skill(t2, x1, effect_ban_red_image, t1, pos, left_click, oonamazu_HP, dm_1, magician_effect_1, ban_sound);
				}
				if (skill_1 == 4){
					h_skill(t2, x1, effect_heal_image, healer_command_image, t1, pos, left_click, healer_effect_1, heal_sound);
				}
				if (skill_1 == 5){
					t_skill(t2, x1, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t1, pos, left_click, thief_effect_1, debuff_sound);
				}
				if (skill_1 == 6){
					d_skill(t2, x1, effect_buff1_image, effect_buff2_image, effect_buff3_image, t1, pos, left_click, dancer_effect_1, buff_sound);
				}
				if (skill_1 == 7){
					s_skill(t2, x1, effect_zan3_image, t1, pos, left_click, oonamazu_HP, dm_1, HP1, samurai_sound);
				}
				defense(t2, x1, effect_defense_image, t1, pos, left_click, HP1, b1_1, b3_1);
				escape(escape_image, t1, pos, left_click);
			}
			//プレイヤー2コマンド
			if (HP2 > 0){
				//コマンド系
				if (attack_2 == 1){
					attack(t4, x2, effect_zan_image, t3, pos, left_click, oonamazu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 2){
					attack(t4, x2, effect_zaku_image, t3, pos, left_click, oonamazu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 3){
					attack(t4, x2, effect_ban_red_image, t3, pos, left_click, oonamazu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 4){
					attack(t4, x2, effect_ban_white_image, t3, pos, left_click, oonamazu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_2 == 1){
					w_skill(t4, x2, effect_zan_image, effect_zan2_image, t3, pos, left_click, oonamazu_HP, dm_2, zan2_sound);
				}
				if (skill_2 == 2){
					a_skill(t4, x2, effect_zaku2_image, t3, pos, left_click, oonamazu_HP, dm_2, archar_effect_2, zaku_sound);
				}
				if (skill_2 == 3){
					m_skill(t4, x2, effect_ban_red_image, t3, pos, left_click, oonamazu_HP, dm_1, magician_effect_2, ban_sound);
				}
				if (skill_2 == 4){
					h_skill(t4, x2, effect_heal_image, healer_command_image, t3, pos, left_click, healer_effect_2, heal_sound);
				}
				if (skill_2 == 5){
					t_skill(t4, x2, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t3, pos, left_click, thief_effect_2, debuff_sound);
				}
				if (skill_2 == 6){
					d_skill(t4, x2, effect_buff1_image, effect_buff2_image, effect_buff3_image, t3, pos, left_click, dancer_effect_2, buff_sound);
				}
				if (skill_2 == 7){
					s_skill(t4, x2, effect_zan3_image, t3, pos, left_click, oonamazu_HP, dm_2, HP2, samurai_sound);
				}
				defense(t4, x2, effect_defense_image, t3, pos, left_click, HP2, b1_2, b3_2);
				escape(escape_image, t3, pos, left_click);
			}
			//プレイヤー3コマンド
			if (HP3 > 0){

				//コマンド系
				if (attack_3 == 1){
					attack(t6, x3, effect_zan_image, t5, pos, left_click, oonamazu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 2){
					attack(t6, x3, effect_zaku_image, t5, pos, left_click, oonamazu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 3){
					attack(t6, x3, effect_ban_red_image, t5, pos, left_click, oonamazu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 4){
					attack(t6, x3, effect_ban_white_image, t5, pos, left_click, oonamazu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_3 == 1){
					w_skill(t6, x3, effect_zan_image, effect_zan2_image, t5, pos, left_click, oonamazu_HP, dm_3, zan2_sound);
				}
				if (skill_3 == 2){
					a_skill(t6, x3, effect_zaku2_image, t5, pos, left_click, oonamazu_HP, dm_3, archar_effect_3, zaku_sound);
				}
				if (skill_3 == 3){
					m_skill(t6, x3, effect_ban_red_image, t5, pos, left_click, oonamazu_HP, dm_1, magician_effect_3, ban_sound);
				}
				if (skill_3 == 4){
					h_skill(t6, x3, effect_heal_image, healer_command_image, t5, pos, left_click, healer_effect_3, heal_sound);
				}
				if (skill_3 == 5){
					t_skill(t6, x3, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t5, pos, left_click, thief_effect_3, debuff_sound);
				}
				if (skill_3 == 6){
					d_skill(t6, x3, effect_buff1_image, effect_buff2_image, effect_buff3_image, t5, pos, left_click, dancer_effect_3, buff_sound);
				}
				if (skill_3 == 7){
					s_skill(t6, x3, effect_zan3_image, t5, pos, left_click, oonamazu_HP, dm_3, HP3, samurai_sound);
				}
				defense(t6, x3, effect_defense_image, t5, pos, left_click, HP3, b1_3, b3_3);
				escape(escape_image, t5, pos, left_click);
			}
			//プレイヤー4コマンド
			if (HP4 > 0){
				//コマンド系
				if (attack_4 == 1){
					attack(t8, x4, effect_zan_image, t7, pos, left_click, oonamazu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 2){
					attack(t8, x4, effect_zaku_image, t7, pos, left_click, oonamazu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 3){
					attack(t8, x4, effect_ban_red_image, t7, pos, left_click, oonamazu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 4){
					attack(t8, x4, effect_ban_white_image, t7, pos, left_click, oonamazu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_4 == 1){
					w_skill(t8, x4, effect_zan_image, effect_zan2_image, t7, pos, left_click, oonamazu_HP, dm_4, zan2_sound);
				}
				if (skill_4 == 2){
					a_skill(t8, x4, effect_zaku2_image, t7, pos, left_click, oonamazu_HP, dm_4, archar_effect_4, zaku_sound);
				}
				if (skill_4 == 3){
					m_skill(t8, x4, effect_ban_red_image, t7, pos, left_click, oonamazu_HP, dm_1, magician_effect_4, ban_sound);
				}
				if (skill_4 == 4){
					h_skill(t8, x4, effect_heal_image, healer_command_image, t7, pos, left_click, healer_effect_4, heal_sound);
				}
				if (skill_4 == 5){
					t_skill(t8, x4, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t7, pos, left_click, thief_effect_4, debuff_sound);
				}
				if (skill_4 == 6){
					d_skill(t8, x4, effect_buff1_image, effect_buff2_image, effect_buff3_image, t7, pos, left_click, dancer_effect_4, buff_sound);
				}
				if (skill_4 == 7){
					s_skill(t8, x4, effect_zan3_image, t7, pos, left_click, oonamazu_HP, dm_4, HP4, samurai_sound);
				}
				defense(t8, x4, effect_defense_image, t7, pos, left_click, HP4, b1_4, b3_4);
				escape(escape_image, t7, pos, left_click);
			}

			//バフ関連
			if (buff == 12){
				if (t == 10){
					buff_t++;
				}
				if (buff_t == 2){
					buff = 10;
					buff_t = 0;
				}
			}
			//デバフ
			if (debuff == 8){
				if (t == 10){
					debuff_t++;
				}
				if (debuff_t == 3){
					debuff = 10;
					debuff_t = 0;
				}
			}

			//ボスターン処理
			if (t == 10){
				BOSS_t++;
			}

			//プレイヤー1表示
			if (HP1 > 0){
				player1(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_1);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 1){
					t += 2;
				}
			}

			//プレイヤー2表示
			if (HP2 > 0){
				player2(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_2);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 3){
					t += 2;
				}
			}

			//プレイヤー3表示
			if (HP3 > 0){
				player3(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_3);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 5){
					t += 2;
				}
			}

			//プレイヤー4表示
			if (HP4 > 0){
				player4(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_4);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 7){
					t += 2;
				}
			}

			//ゲームオーバー画面
			if (dead == 1){
				Sleep(500);
				oonamazu_sound.stop();
				if (g == 0){
					g = 1;
					gameover_sound.play();
				}
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					gameover_image,
					Color(1, 1, 1));
				if (left_click){
					e = 2;
				}
			}
			if (HP1 <= 0 && HP2 <= 0 && HP3 <= 0 && HP4 <= 0){
				dead = 1;
			}


			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	oonamazu_sound.stop();
	clear_sound.play();

	//クリア画面2
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				clear_2_image,
				Color(1, 1, 1));
			if (left_click)break;

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}
	clear_sound.stop();

	//変数初期化
	i = 30; HP1 = 1; HP2 = 1; HP3 = 1; HP4 = 1; waiban_HP = 1000; t = 1; w = 0; t1 = 1; t2 = 2; t3 = 3; t4 = 4; t5 = 5;
	t6 = 6; t7 = 7; t8 = 8; a = 0; s = 0; b = 0; b1_1 = 0; b1_2 = 0; b1_3 = 0; b1_4 = 0; b2 = 0; b3_1 = 1; b3_2 = 1; b3_3 = 1;
	b3_4 = 1; e = 0; x1 = 0; x2 = 0; x3 = 0; x4 = 0; BOSS = 4; dead = 0; dm_1 = 0; dm_2 = 0; dm_3 = 0; dm_4 = 0; skill_1 = 0;
	skill_2 = 0; skill_3 = 0; skill_4 = 0; ch_1 = 0; ch_2 = 0; ch_3 = 0; ch_4 = 0; BOSS_x = 0; BOSS_effect = 0; attack_1 = 0;
	attack_2 = 0; attack_3 = 0; attack_4 = 0; effect = 0; effect_1 = 0; effect_2 = 0; effect_3 = 0; effect_4 = 0; BOSS_air = 0;
	archar_effect_1 = 0; archar_effect_2 = 0; archar_effect_3 = 0; archar_effect_4 = 0; magician_effect_1 = 0; magician_effect_2 = 0;
	magician_effect_3 = 0; magician_effect_4 = 0; healer_effect_1 = 0; healer_effect_2 = 0; healer_effect_3 = 0; healer_effect_4 = 0;
	HP_sub1 = 1; HP_sub2 = 1; HP_sub3 = 1; HP_sub4 = 1; healer_player1 = 0; healer_player2 = 0; healer_player3 = 0; healer_player4 = 0;
	C1_h = 0; C2_h = 0; C3_h = 0; C4_h = 0; h_1 = 0; h_2 = 0; h_3 = 0; h_4 = 0; c = 0; buff_t = 0; debuff_t = 0; dancer_effect_1 = 0;
	dancer_effect_2 = 0; dancer_effect_3 = 0; dancer_effect_4 = 0; thief_effect_1 = 0; thief_effect_2 = 0; thief_effect_3 = 0;
	thief_effect_4 = 0; skill_limit = 0; BOSS_t = -1; oonamazu_HP = 1200, oneirosu_HP = 2000; enemy = 1; status = 1; g = 0, enemy_dead = 0, enemy_dead2 = 1;

	C1 = 0; C2 = 0; C3 = 0; C4 = 0; buff = 10; debuff = 10;

	job_sound.play();

	//キャラ選択3
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			if (enemy != 0 && status != 0){
				//メイン画面
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					jobchange_image,
					Color(1, 1, 1));
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					area1_3,
					Color(1, 1, 1));

				//キャラ選択(プレイヤー1)
				//戦士
				if (ch_1 == 0){
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 96){
								if (pos.y() > 250 - 139){
									if (left_click){
										ch_1 = 1;
										HP1 = 100;
										HP_sub1 = 100;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;

									}
								}
							}
						}
					}
					//狩人
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 149){
								if (pos.y() > 250 - 192){
									if (left_click){
										ch_1 = 2;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//魔法使い
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 211){
							if (pos.y() < 250 - 204){
								if (pos.y() > 250 - 244){
									if (left_click){
										ch_1 = 3;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 70;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//僧侶
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 261){
								if (pos.y() > 250 - 302){
									if (left_click){
										ch_1 = 4;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 30;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//盗賊
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 314){
								if (pos.y() > 250 - 356){
									if (left_click){
										ch_1 = 5;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//踊り子
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 170){
							if (pos.y() < 250 - 366){
								if (pos.y() > 250 - 408){
									if (left_click){
										ch_1 = 6;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//侍
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 81){
							if (pos.y() < 250 - 418){
								if (pos.y() > 250 - 460){
									if (left_click){
										ch_1 = 7;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 60;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_1 == 1){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_1 == 2){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_1 == 3){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_1 == 4){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_1 == 5){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_1 == 6){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_1 == 7){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}


				// キャラ選択(プレイヤー2)
				//戦士
				if (ch_1 != 0){
					if (ch_2 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_2 = 1;
											HP2 = 100;
											HP_sub2 = 100;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_2 = 2;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_2 = 3;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_2 = 4;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_2 = 5;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_2 = 6;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_2 = 7;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_2 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_2 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_2 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_2 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_2 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_2 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_2 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー3)
				//戦士
				if (ch_2 != 0){
					if (ch_3 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_3 = 1;
											HP3 = 100;
											HP_sub3 = 100;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_3 = 2;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_3 = 3;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_3 = 4;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_3 = 5;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_3 = 6;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_3 = 7;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_3 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_3 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_3 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_3 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_3 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_3 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_3 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー4)
				//戦士
				if (ch_3 != 0){
					if (ch_4 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_4 = 1;
											HP4 = 100;
											HP_sub4 = 100;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_4 = 2;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_4 = 3;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_4 = 4;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_4 = 5;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_4 = 6;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_4 = 7;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_4 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_4 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_4 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_4 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_4 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_4 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_4 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				//OK判定
				if (ch_1 != 0 && ch_2 != 0 && ch_3 != 0 && ch_4 != 0){
					if (pos.x() > -400 + 407){
						if (pos.x() < -400 + 478){
							if (pos.y() < 250 - 449){
								if (pos.y() > 250 - 495){
									if (left_click){
										OK_sound.play();
										break;
										left_click = false;
									}
								}
							}
						}
					}
				}
				//取り消し判定
				if (pos.x() > -400 + 488){
					if (pos.x() < -400 + 632){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									cancel_sound.play();
									ch_1 = 0;
									ch_2 = 0;
									ch_3 = 0;
									ch_4 = 0;
								}
							}
						}
					}
				}
			}

			//敵情報確認
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 449){
						if (pos.y() > 250 - 495){
							if (left_click){
								enemy = 0;
							}
						}
					}
				}
			}
			if (enemy == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					oneirosu_job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									enemy = 1;
								}
							}
						}
					}
				}
			}

			//キャラステータス
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 396){
						if (pos.y() > 250 - 438){
							if (left_click){
								status = 0;
							}
						}
					}
				}
			}
			if (status == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 460){
							if (pos.y() > 250 - 495){
								if (left_click){
									status = 1;
								}
							}
						}
					}
				}
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	job_sound.stop();
	oneirosu_sound.play();

	//ゲーム本編3
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;
			//アプリ終了
			if (e == 2) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			//背景
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				BG_3,
				Color(1, 1, 1));
			//コマンド
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				command_image,
				Color(1, 1, 1));


			//敵の動き
			if (t == 0){
				BOSS_effect += 1;
				if (BOSS == 0){
					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 220, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 250, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 190, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
				}
				if (BOSS == 1){

					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 350, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 350 + 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 350 - 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));

					}
				}
				if (BOSS == 2){

					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 283, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 283 + 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 283 - 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));

					}
				}

				if (BOSS == 3){

					if (BOSS_effect > 0){
						drawTextureBox(-400 + 240 - (BOSS_effect - 15) * 8, 250 - 403, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 20){
						drawTextureBox(-400 + 300 - (BOSS_effect - 20) * 8, 250 - 403 + 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));
					}
					if (BOSS_effect > 40){
						drawTextureBox(-400 + 210 - (BOSS_effect - 40) * 8, 250 - 403 - 30, 256, 256, 0, 0, 256, 256,
							effect_BOSS_beam_image,
							Color(1, 1, 1));

					}
				}
			}

			if (BOSS_effect > 80){

				if (BOSS == 0 && b3_1 == 1)HP1 -= (40 * (debuff / 10));
				if (BOSS == 1 && b3_2 == 1)HP2 -= (40 * (debuff / 10));
				if (BOSS == 2 && b3_3 == 1)HP3 -= (40 * (debuff / 10));
				if (BOSS == 3 && b3_4 == 1)HP4 -= (40 * (debuff / 10));
				t = 1;
				BOSS_effect = 0;
				BOSS = 4;
				BOSS_x = 0;
			}


			if (t == 10){
				BOSS_beam_sound.play();
			}

			if (t == 10){
				t = 0;
				skill_limit = 0;
			}

			if (oneirosu_HP > 0){
				if (t == 9){
					time_t date;
					srand(time(&date));
					BOSS = rand() % 4;
					if (HP1 > 0){
						if (BOSS == 0){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP2 > 0){
						if (BOSS == 1){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP3 > 0){
						if (BOSS == 2){
							BOSS_x = 20;
							t = 10;
						}
					}
					if (HP4 > 0){
						if (BOSS == 3){
							BOSS_x = 20;
							t = 10;
						}
					}
				}
			}

			//敵の表示
			if (oneirosu_HP > 0){
				drawTextureBox(-800 / 2 - BOSS_x, -500 / 2, 800, 500, 0, 0, 800, 500,
					oneirosu_image,
					Color(1, 1, 1));
				drawBox(60, 110, 333, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, oneirosu_HP / 6, 4, Color(0.2, 0.8, 0.2));
			}
			else{
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					oneirosu_image,
					Color(1, 1, 1, enemy_dead2));
				enemy_dead2 -= 0.05;
				drawBox(60, 110, 333, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, oneirosu_HP / 6, 4, Color(0.2, 0.8, 0.2));
				drawTextureBox(16, -128, 256, 256, 0, 0, 256, 256,
					enemy_dead_image,
					Color(1, enemy_dead % 2, 0, 0.5));
				if (i % 3 == 0){
					enemy_dead++;
				}
				i++;
				if (enemy_dead > 30)break;
			}
			BOSS_air = 0;


			//player文字表示
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player1_1_image,
				Color(1, 1 - C1_h, 1 - C1));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player2_1_image,
				Color(1, 1 - C2_h, 1 - C2));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player3_1_image,
				Color(1, 1 - C3_h, 1 - C3));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player4_1_image,
				Color(1, 1 - C4_h, 1 - C4));
			if (t == 1){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player1_2_image,
					Color(1, 1, 1));
			}
			if (t == 3){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player2_2_image,
					Color(1, 1, 1));
			}
			if (t == 5){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player3_2_image,
					Color(1, 1, 1));
			}
			if (t == 7){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player4_2_image,
					Color(1, 1, 1));
			}

			//player表示色変え
			if (t == 1){ C1 = 1; C4 = 0; }
			if (t == 2){ C1 = 0; C4 = 0; }
			if (t == 3){ C2 = 1; C1 = 0; }
			if (t == 4){ C2 = 0; C1 = 0; }
			if (t == 5){ C3 = 1; C2 = 0; }
			if (t == 6){ C3 = 0; C2 = 0; }
			if (t == 7){ C4 = 1; C3 = 0; }
			if (t == 8){ C4 = 0; C3 = 0; }

			//プレイヤー1コマンド
			if (HP1 > 0){
				//コマンド系
				if (attack_1 == 1){
					attack(t2, x1, effect_zan_image, t1, pos, left_click, oneirosu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 2){
					attack(t2, x1, effect_zaku_image, t1, pos, left_click, oneirosu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 3){
					attack(t2, x1, effect_ban_red_image, t1, pos, left_click, oneirosu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 4){
					attack(t2, x1, effect_ban_white_image, t1, pos, left_click, oneirosu_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_1 == 1){
					w_skill(t2, x1, effect_zan_image, effect_zan2_image, t1, pos, left_click, oneirosu_HP, dm_1, zan2_sound);
				}
				if (skill_1 == 2){
					a_skill(t2, x1, effect_zaku2_image, t1, pos, left_click, oneirosu_HP, dm_1, archar_effect_1, zaku_sound);
				}
				if (skill_1 == 3){
					m_skill(t2, x1, effect_ban_red_image, t1, pos, left_click, oneirosu_HP, dm_1, magician_effect_1, ban_sound);
				}
				if (skill_1 == 4){
					h_skill(t2, x1, effect_heal_image, healer_command_image, t1, pos, left_click, healer_effect_1, heal_sound);
				}
				if (skill_1 == 5){
					t_skill(t2, x1, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t1, pos, left_click, thief_effect_1, debuff_sound);
				}
				if (skill_1 == 6){
					d_skill(t2, x1, effect_buff1_image, effect_buff2_image, effect_buff3_image, t1, pos, left_click, dancer_effect_1, buff_sound);
				}
				if (skill_1 == 7){
					s_skill(t2, x1, effect_zan3_image, t1, pos, left_click, oneirosu_HP, dm_1, HP1, samurai_sound);
				}
				defense(t2, x1, effect_defense_image, t1, pos, left_click, HP1, b1_1, b3_1);
				escape(escape_image, t1, pos, left_click);
			}
			//プレイヤー2コマンド
			if (HP2 > 0){
				//コマンド系
				if (attack_2 == 1){
					attack(t4, x2, effect_zan_image, t3, pos, left_click, oneirosu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 2){
					attack(t4, x2, effect_zaku_image, t3, pos, left_click, oneirosu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 3){
					attack(t4, x2, effect_ban_red_image, t3, pos, left_click, oneirosu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 4){
					attack(t4, x2, effect_ban_white_image, t3, pos, left_click, oneirosu_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_2 == 1){
					w_skill(t4, x2, effect_zan_image, effect_zan2_image, t3, pos, left_click, oneirosu_HP, dm_2, zan2_sound);
				}
				if (skill_2 == 2){
					a_skill(t4, x2, effect_zaku2_image, t3, pos, left_click, oneirosu_HP, dm_2, archar_effect_2, zaku_sound);
				}
				if (skill_2 == 3){
					m_skill(t4, x2, effect_ban_red_image, t3, pos, left_click, oneirosu_HP, dm_1, magician_effect_2, ban_sound);
				}
				if (skill_2 == 4){
					h_skill(t4, x2, effect_heal_image, healer_command_image, t3, pos, left_click, healer_effect_2, heal_sound);
				}
				if (skill_2 == 5){
					t_skill(t4, x2, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t3, pos, left_click, thief_effect_2, debuff_sound);
				}
				if (skill_2 == 6){
					d_skill(t4, x2, effect_buff1_image, effect_buff2_image, effect_buff3_image, t3, pos, left_click, dancer_effect_2, buff_sound);
				}
				if (skill_2 == 7){
					s_skill(t4, x2, effect_zan3_image, t3, pos, left_click, oneirosu_HP, dm_2, HP2, samurai_sound);
				}
				defense(t4, x2, effect_defense_image, t3, pos, left_click, HP2, b1_2, b3_2);
				escape(escape_image, t3, pos, left_click);
			}
			//プレイヤー3コマンド
			if (HP3 > 0){

				//コマンド系
				if (attack_3 == 1){
					attack(t6, x3, effect_zan_image, t5, pos, left_click, oneirosu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 2){
					attack(t6, x3, effect_zaku_image, t5, pos, left_click, oneirosu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 3){
					attack(t6, x3, effect_ban_red_image, t5, pos, left_click, oneirosu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 4){
					attack(t6, x3, effect_ban_white_image, t5, pos, left_click, oneirosu_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_3 == 1){
					w_skill(t6, x3, effect_zan_image, effect_zan2_image, t5, pos, left_click, oneirosu_HP, dm_3, zan2_sound);
				}
				if (skill_3 == 2){
					a_skill(t6, x3, effect_zaku2_image, t5, pos, left_click, oneirosu_HP, dm_3, archar_effect_3, zaku_sound);
				}
				if (skill_3 == 3){
					m_skill(t6, x3, effect_ban_red_image, t5, pos, left_click, oneirosu_HP, dm_1, magician_effect_3, ban_sound);
				}
				if (skill_3 == 4){
					h_skill(t6, x3, effect_heal_image, healer_command_image, t5, pos, left_click, healer_effect_3, heal_sound);
				}
				if (skill_3 == 5){
					t_skill(t6, x3, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t5, pos, left_click, thief_effect_3, debuff_sound);
				}
				if (skill_3 == 6){
					d_skill(t6, x3, effect_buff1_image, effect_buff2_image, effect_buff3_image, t5, pos, left_click, dancer_effect_3, buff_sound);
				}
				if (skill_3 == 7){
					s_skill(t6, x3, effect_zan3_image, t5, pos, left_click, oneirosu_HP, dm_3, HP3, samurai_sound);
				}
				defense(t6, x3, effect_defense_image, t5, pos, left_click, HP3, b1_3, b3_3);
				escape(escape_image, t5, pos, left_click);
			}
			//プレイヤー4コマンド
			if (HP4 > 0){
				//コマンド系
				if (attack_4 == 1){
					attack(t8, x4, effect_zan_image, t7, pos, left_click, oneirosu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 2){
					attack(t8, x4, effect_zaku_image, t7, pos, left_click, oneirosu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 3){
					attack(t8, x4, effect_ban_red_image, t7, pos, left_click, oneirosu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 4){
					attack(t8, x4, effect_ban_white_image, t7, pos, left_click, oneirosu_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_4 == 1){
					w_skill(t8, x4, effect_zan_image, effect_zan2_image, t7, pos, left_click, oneirosu_HP, dm_4, zan2_sound);
				}
				if (skill_4 == 2){
					a_skill(t8, x4, effect_zaku2_image, t7, pos, left_click, oneirosu_HP, dm_4, archar_effect_4, zaku_sound);
				}
				if (skill_4 == 3){
					m_skill(t8, x4, effect_ban_red_image, t7, pos, left_click, oneirosu_HP, dm_1, magician_effect_4, ban_sound);
				}
				if (skill_4 == 4){
					h_skill(t8, x4, effect_heal_image, healer_command_image, t7, pos, left_click, healer_effect_4, heal_sound);
				}
				if (skill_4 == 5){
					t_skill(t8, x4, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t7, pos, left_click, thief_effect_4, debuff_sound);
				}
				if (skill_4 == 6){
					d_skill(t8, x4, effect_buff1_image, effect_buff2_image, effect_buff3_image, t7, pos, left_click, dancer_effect_4, buff_sound);
				}
				if (skill_4 == 7){
					s_skill(t8, x4, effect_zan3_image, t7, pos, left_click, oneirosu_HP, dm_4, HP4, samurai_sound);
				}
				defense(t8, x4, effect_defense_image, t7, pos, left_click, HP4, b1_4, b3_4);
				escape(escape_image, t7, pos, left_click);
			}

			//バフ関連
			if (buff == 12){
				if (t == 10){
					buff_t++;
				}
				if (buff_t == 2){
					buff = 10;
					buff_t = 0;
				}
			}
			//デバフ関連
			if (debuff == 8){
				if (t == 10){
					debuff_t++;
				}
				if (debuff_t == 3){
					debuff = 10;
					debuff_t = 0;
				}
			}

			//ボスターン処理
			if (t == 10){
				BOSS_t++;
			}

			//プレイヤー1表示
			if (HP1 > 0){
				player1(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_1);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 1){
					t += 2;
				}
			}

			//プレイヤー2表示
			if (HP2 > 0){
				player2(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_2);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 3){
					t += 2;
				}
			}

			//プレイヤー3表示
			if (HP3 > 0){
				player3(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_3);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 5){
					t += 2;
				}
			}

			//プレイヤー4表示
			if (HP4 > 0){
				player4(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_4);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 7){
					t += 2;
				}
			}



			//ゲームオーバー画面
			if (dead == 1){
				Sleep(500);
				oneirosu_sound.stop();
				if (g == 0){
					g = 1;
					gameover_sound.play();
				}
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					gameover_image,
					Color(1, 1, 1));
				if (left_click){
					e = 2;
				}
			}
			if (HP1 <= 0 && HP2 <= 0 && HP3 <= 0 && HP4 <= 0){
				dead = 1;
			}


			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	oneirosu_sound.stop();
	clear_sound.play();

	//クリア画面3
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				clear_3_image,
				Color(1, 1, 1));
			if (left_click){
				break;
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	clear_sound.stop();

	//変数初期化
	i = 30; HP1 = 1; HP2 = 1; HP3 = 1; HP4 = 1; waiban_HP = 1000; t = 1; w = 0; t1 = 1; t2 = 2; t3 = 3; t4 = 4; t5 = 5;
	t6 = 6; t7 = 7; t8 = 8; a = 0; s = 0; b = 0; b1_1 = 0; b1_2 = 0; b1_3 = 0; b1_4 = 0; b2 = 0; b3_1 = 1; b3_2 = 1; b3_3 = 1;
	b3_4 = 1; e = 0; x1 = 0; x2 = 0; x3 = 0; x4 = 0; BOSS = 4; dead = 0; dm_1 = 0; dm_2 = 0; dm_3 = 0; dm_4 = 0; skill_1 = 0;
	skill_2 = 0; skill_3 = 0; skill_4 = 0; ch_1 = 0; ch_2 = 0; ch_3 = 0; ch_4 = 0; BOSS_x = 0; BOSS_effect = 0; attack_1 = 0;
	attack_2 = 0; attack_3 = 0; attack_4 = 0; effect = 0; effect_1 = 0; effect_2 = 0; effect_3 = 0; effect_4 = 0; BOSS_air = 0;
	archar_effect_1 = 0; archar_effect_2 = 0; archar_effect_3 = 0; archar_effect_4 = 0; magician_effect_1 = 0; magician_effect_2 = 0;
	magician_effect_3 = 0; magician_effect_4 = 0; healer_effect_1 = 0; healer_effect_2 = 0; healer_effect_3 = 0; healer_effect_4 = 0;
	HP_sub1 = 1; HP_sub2 = 1; HP_sub3 = 1; HP_sub4 = 1; healer_player1 = 0; healer_player2 = 0; healer_player3 = 0; healer_player4 = 0;
	C1_h = 0; C2_h = 0; C3_h = 0; C4_h = 0; h_1 = 0; h_2 = 0; h_3 = 0; h_4 = 0; c = 0; buff_t = 0; debuff_t = 0; dancer_effect_1 = 0;
	dancer_effect_2 = 0; dancer_effect_3 = 0; dancer_effect_4 = 0; thief_effect_1 = 0; thief_effect_2 = 0; thief_effect_3 = 0;
	thief_effect_4 = 0; skill_limit = 0; BOSS_t = -1; oonamazu_HP = 1200; enemy = 1; status = 1; g = 0, enemy_dead = 0, enemy_dead2 = 1;

	C1 = 0; C2 = 0; C3 = 0; C4 = 0; buff = 10; debuff = 10;

	job_sound.play();

	//キャラ選択画面4
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			if (enemy != 0 && status != 0){
				//メイン画面
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					jobchange_image,
					Color(1, 1, 1));
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					area1_4,
					Color(1, 1, 1));

				//キャラ選択(プレイヤー1)
				//戦士
				if (ch_1 == 0){
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 96){
								if (pos.y() > 250 - 139){
									if (left_click){
										ch_1 = 1;
										HP1 = 100;
										HP_sub1 = 100;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;

									}
								}
							}
						}
					}
					//狩人
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 149){
								if (pos.y() > 250 - 192){
									if (left_click){
										ch_1 = 2;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//魔法使い
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 211){
							if (pos.y() < 250 - 204){
								if (pos.y() > 250 - 244){
									if (left_click){
										ch_1 = 3;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 70;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//僧侶
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 261){
								if (pos.y() > 250 - 302){
									if (left_click){
										ch_1 = 4;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 30;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//盗賊
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 134){
							if (pos.y() < 250 - 314){
								if (pos.y() > 250 - 356){
									if (left_click){
										ch_1 = 5;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//踊り子
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 170){
							if (pos.y() < 250 - 366){
								if (pos.y() > 250 - 408){
									if (left_click){
										ch_1 = 6;
										HP1 = 70;
										HP_sub1 = 70;
										dm_1 = 50;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
					//侍
					if (pos.x() > -400 + 42){
						if (pos.x() < -400 + 81){
							if (pos.y() < 250 - 418){
								if (pos.y() > 250 - 460){
									if (left_click){
										ch_1 = 7;
										HP1 = 80;
										HP_sub1 = 80;
										dm_1 = 60;
										ch_sound.play();
										left_click = false;
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_1 == 1){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_1 == 2){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_1 == 3){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_1 == 4){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_1 == 5){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_1 == 6){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_1 == 7){
					drawTextureBox(-400 + 593, 250 - 105, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}


				// キャラ選択(プレイヤー2)
				//戦士
				if (ch_1 != 0){
					if (ch_2 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_2 = 1;
											HP2 = 100;
											HP_sub2 = 100;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_2 = 2;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_2 = 3;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_2 = 4;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_2 = 5;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_2 = 6;
											HP2 = 70;
											HP_sub2 = 70;
											dm_2 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_2 = 7;
											HP2 = 80;
											HP_sub2 = 80;
											dm_2 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_2 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_2 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_2 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_2 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_2 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_2 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_2 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 2, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー3)
				//戦士
				if (ch_2 != 0){
					if (ch_3 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_3 = 1;
											HP3 = 100;
											HP_sub3 = 100;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_3 = 2;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_3 = 3;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_3 = 4;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_3 = 5;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_3 = 6;
											HP3 = 70;
											HP_sub3 = 70;
											dm_3 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_3 = 7;
											HP3 = 80;
											HP_sub3 = 80;
											dm_3 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_3 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_3 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_3 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_3 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_3 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_3 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_3 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 3, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				// キャラ選択(プレイヤー4)
				//戦士
				if (ch_3 != 0){
					if (ch_4 == 0){
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 96){
									if (pos.y() > 250 - 139){
										if (left_click){
											ch_4 = 1;
											HP4 = 100;
											HP_sub4 = 100;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//狩人
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 149){
									if (pos.y() > 250 - 192){
										if (left_click){
											ch_4 = 2;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 40;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//魔法使い
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 211){
								if (pos.y() < 250 - 204){
									if (pos.y() > 250 - 244){
										if (left_click){
											ch_4 = 3;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 70;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//僧侶
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 261){
									if (pos.y() > 250 - 302){
										if (left_click){
											ch_4 = 4;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 30;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//盗賊
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 134){
								if (pos.y() < 250 - 314){
									if (pos.y() > 250 - 356){
										if (left_click){
											ch_4 = 5;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 50;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//踊り子
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 170){
								if (pos.y() < 250 - 366){
									if (pos.y() > 250 - 408){
										if (left_click){
											ch_4 = 6;
											HP4 = 70;
											HP_sub4 = 70;
											dm_4 = 40;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
						//侍
						if (pos.x() > -400 + 42){
							if (pos.x() < -400 + 81){
								if (pos.y() < 250 - 418){
									if (pos.y() > 250 - 460){
										if (left_click){
											ch_4 = 7;
											HP4 = 80;
											HP_sub4 = 80;
											dm_4 = 60;
											ch_sound.play();
											left_click = false;
										}
									}
								}
							}
						}
					}
				}
				//戦士表示
				if (ch_4 == 1){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						warrior_image,
						Color(1, 1, 1));
				}
				//狩人表示
				if (ch_4 == 2){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						archer_image,
						Color(1, 1, 1));
				}
				//魔法使い
				if (ch_4 == 3){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						magician_image,
						Color(1, 1, 1));
				}
				//僧侶表示
				if (ch_4 == 4){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						healer_image,
						Color(1, 1, 1));
				}
				//盗賊表示
				if (ch_4 == 5){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						thief_image,
						Color(1, 1, 1));
				}
				//踊り子
				if (ch_4 == 6){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						dancer_image,
						Color(1, 1, 1));
				}
				//侍
				if (ch_4 == 7){
					drawTextureBox(-400 + 593, 250 - 105 * 4, 128, 128, 0, 0, 128, 128,
						samurai_image,
						Color(1, 1, 1));
				}
				//OK判定
				if (ch_1 != 0 && ch_2 != 0 && ch_3 != 0 && ch_4 != 0){
					if (pos.x() > -400 + 407){
						if (pos.x() < -400 + 478){
							if (pos.y() < 250 - 449){
								if (pos.y() > 250 - 495){
									if (left_click){
										OK_sound.play();
										break;
										left_click = false;
									}
								}
							}
						}
					}
				}
				//取り消し判定
				if (pos.x() > -400 + 488){
					if (pos.x() < -400 + 632){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									cancel_sound.play();
									ch_1 = 0;
									ch_2 = 0;
									ch_3 = 0;
									ch_4 = 0;
								}
							}
						}
					}
				}
			}

			//敵情報確認
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 449){
						if (pos.y() > 250 - 495){
							if (left_click){
								enemy = 0;
							}
						}
					}
				}
			}
			if (enemy == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					maou_job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 449){
							if (pos.y() > 250 - 495){
								if (left_click){
									enemy = 1;
								}
							}
						}
					}
				}
			}

			//キャラステータス
			if (pos.x() > -400 + 642){
				if (pos.x() < -400 + 758){
					if (pos.y() < 250 - 396){
						if (pos.y() > 250 - 438){
							if (left_click){
								status = 0;
							}
						}
					}
				}
			}
			if (status == 0){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					job_image,
					Color(1, 1, 1));
				if (pos.x() > -400 + 512){
					if (pos.x() < -400 + 607){
						if (pos.y() < 250 - 460){
							if (pos.y() > 250 - 495){
								if (left_click){
									status = 1;
								}
							}
						}
					}
				}
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	job_sound.stop();
	maou_sound.play();


	//ゲーム本編4
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;
			//アプリ終了
			if (e == 2) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			//背景
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				BG_1,
				Color(1, 1, 1));
			//コマンド
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				command_image,
				Color(1, 1, 1));


			//敵の動き
			if (BOSS_t == 0 || BOSS_t == 1){
				if (t == 0){
					BOSS_effect += 1;
					if (BOSS == 0){
						if (BOSS_effect > 0){
							drawTextureBox(-400 + 122, 250 - 201, 256, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 122, 250 - 201, 256, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 0.3, 0.3));
						}
					}
					if (BOSS == 1){

						if (BOSS_effect > 0){
							drawTextureBox(-400 + 105, 250 - 336, 238, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 105, 250 - 336, 238, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 0.3, 0.3));
						}
					}
					if (BOSS == 2){

						if (BOSS_effect > 0){
							drawTextureBox(-400 + 5, 250 - 270, 238, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 5, 250 - 270, 238, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 0.3, 0.3));
						}
					}

					if (BOSS == 3){

						if (BOSS_effect > 0){
							drawTextureBox(-400 + 4, 250 - 391, 238, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 1, 1));
						}
						if (BOSS_effect > 20){
							drawTextureBox(-400 + 4, 250 - 391, 238, 256, 0, 0, 256, 256,
								effect_zan4_image,
								Color(1, 0.3, 0.3));
						}
					}
				}
			}

			if (BOSS_t == 2 || BOSS_t == 3){
				if (t == 0){
					BOSS_effect++;
					drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
						CS_image,
						Color(1, 1, 1));
				}
			}

			if (BOSS_t == 4){
				if (t == 0){
					BOSS_effect++;
					v += 4;
					drawCircle(0, 0, 20 + v, 20 + v, 100, 4, Color(0.5, 0.1, 0.1));

					if (v > 50){
						drawCircle(0, 0, 20 + v - 50, 20 + v - 50, 100, 4, Color(0.5, 0.1, 0.1));
					}
					if (v > 100){
						drawCircle(0, 0, 20 + v - 100, 20 + v - 100, 100, 4, Color(0.5, 0.1, 0.1));
					}
					if (v > 150){
						drawCircle(0, 0, 20 + v - 150, 20 + v - 150, 100, 4, Color(0.5, 0.1, 0.1));
					}
				}
			}

			//			if (BOSS_t % 3 != 0){
			if (BOSS_t == 0 || BOSS_t == 1){
				if (BOSS_effect > 60){

					if (BOSS == 0 && b3_1 == 1)HP1 -= (70 * (debuff / 10));
					if (BOSS == 1 && b3_2 == 1)HP2 -= (70 * (debuff / 10));
					if (BOSS == 2 && b3_3 == 1)HP3 -= (70 * (debuff / 10));
					if (BOSS == 3 && b3_4 == 1)HP4 -= (70 * (debuff / 10));
					t = 1;
					BOSS_effect = 0;
					BOSS = 4;
					BOSS_x = 0;
				}
			}
			//			}
			if (BOSS_t == 2 || BOSS_t == 3){
				if (BOSS_effect > 60){
					t = 1;
					BOSS_effect = 0;
					BOSS = 4;
					BOSS_x = 0;
				}
			}

			if (BOSS_t == 4){
				if (BOSS_effect > 120){
					if (b3_1 == 1)HP1 -= (80 * (debuff / 10));
					if (b3_2 == 1)HP2 -= (80 * (debuff / 10));
					if (b3_3 == 1)HP3 -= (80 * (debuff / 10));
					if (b3_4 == 1)HP4 -= (80 * (debuff / 10));
					BOSS_t = -1;
					t = 1;
					BOSS_effect = 0;
					BOSS = 4;
					BOSS_x = 0;
				}
			}

			if (t == 10){
				if (BOSS_t == 0 || BOSS_t == 1){
					BOSS_zan_sound.play();
					BOSS_zan_sound.pitch(0.4);
				}
			}
			if (t == 10){
				if (BOSS_t == 4){
					BOSS_maou_sound.play();
				}
			}

			if (t == 10){
				t = 0;
				skill_limit = 0;
			}

			if (maou_HP > 0){
			if (t == 9){
				time_t date;
				srand(time(&date));
				BOSS = rand() % 4;
				if (HP1 > 0){
					if (BOSS == 0){
						BOSS_x = 20;
						t = 10;
					}
				}
				if (HP2 > 0){
					if (BOSS == 1){
						BOSS_x = 20;
						t = 10;
					}
				}
				if (HP3 > 0){
					if (BOSS == 2){
						BOSS_x = 20;
						t = 10;
					}
				}
				if (HP4 > 0){
					if (BOSS == 3){
						BOSS_x = 20;
						t = 10;
					}
				}
			}
		}

			//敵の表示
			if (maou_HP > 0){
				drawTextureBox(-800 / 2 - BOSS_x, -500 / 2, 800, 500, 0, 0, 800, 500,
					maou_image,
					Color(1, 1, 1));
				drawBox(60, 110, 266, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, maou_HP / 6, 4, Color(0.2, 0.8, 0.2));
			}
			else{
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					maou_image,
					Color(1, 1, 1, enemy_dead2));
				enemy_dead2 -= 0.05;
				drawBox(60, 110, 266, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, maou_HP / 6, 4, Color(0.2, 0.8, 0.2));
				drawTextureBox(16, -128, 256, 256, 0, 0, 256, 256,
					enemy_dead_image,
					Color(1, enemy_dead % 2, 0, 0.5));
				if (i % 3 == 0){
					enemy_dead++;
				}
				i++;
				if (enemy_dead > 30)break;
			}
			BOSS_air = 1;


			//player文字表示
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player1_1_image,
				Color(1, 1 - C1_h, 1 - C1));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player2_1_image,
				Color(1, 1 - C2_h, 1 - C2));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player3_1_image,
				Color(1, 1 - C3_h, 1 - C3));
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				player4_1_image,
				Color(1, 1 - C4_h, 1 - C4));
			if (t == 1){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player1_2_image,
					Color(1, 1, 1));
			}
			if (t == 3){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player2_2_image,
					Color(1, 1, 1));
			}
			if (t == 5){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player3_2_image,
					Color(1, 1, 1));
			}
			if (t == 7){
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					player4_2_image,
					Color(1, 1, 1));
			}

			//player表示色変え
			if (t == 1){ C1 = 1; C4 = 0; }
			if (t == 2){ C1 = 0; C4 = 0; }
			if (t == 3){ C2 = 1; C1 = 0; }
			if (t == 4){ C2 = 0; C1 = 0; }
			if (t == 5){ C3 = 1; C2 = 0; }
			if (t == 6){ C3 = 0; C2 = 0; }
			if (t == 7){ C4 = 1; C3 = 0; }
			if (t == 8){ C4 = 0; C3 = 0; }

			//プレイヤー1コマンド
			if (HP1 > 0){
				//コマンド系
				if (attack_1 == 1){
					attack(t2, x1, effect_zan_image, t1, pos, left_click, maou_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 2){
					attack(t2, x1, effect_zaku_image, t1, pos, left_click, maou_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 3){
					attack(t2, x1, effect_ban_red_image, t1, pos, left_click, maou_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_1 == 4){
					attack(t2, x1, effect_ban_white_image, t1, pos, left_click, maou_HP, dm_1, effect_1, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_1 == 1){
					w_skill(t2, x1, effect_zan_image, effect_zan2_image, t1, pos, left_click, maou_HP, dm_1, zan2_sound);
				}
				if (skill_1 == 2){
					a_skill(t2, x1, effect_zaku2_image, t1, pos, left_click, maou_HP, dm_1, archar_effect_1, zaku_sound);
				}
				if (skill_1 == 3){
					m_skill(t2, x1, effect_ban_red_image, t1, pos, left_click, maou_HP, dm_1, magician_effect_1, ban_sound);
				}
				if (skill_1 == 4){
					h_skill(t2, x1, effect_heal_image, healer_command_image, t1, pos, left_click, healer_effect_1, heal_sound);
				}
				if (skill_1 == 5){
					t_skill(t2, x1, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t1, pos, left_click, thief_effect_1, debuff_sound);
				}
				if (skill_1 == 6){
					d_skill(t2, x1, effect_buff1_image, effect_buff2_image, effect_buff3_image, t1, pos, left_click, dancer_effect_1, buff_sound);
				}
				if (skill_1 == 7){
					s_skill(t2, x1, effect_zan3_image, t1, pos, left_click, maou_HP, dm_1, HP1, samurai_sound);
				}
				defense(t2, x1, effect_defense_image, t1, pos, left_click, HP1, b1_1, b3_1);
				escape(escape_image, t1, pos, left_click);
			}
			//プレイヤー2コマンド
			if (HP2 > 0){
				//コマンド系
				if (attack_2 == 1){
					attack(t4, x2, effect_zan_image, t3, pos, left_click, maou_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 2){
					attack(t4, x2, effect_zaku_image, t3, pos, left_click, maou_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 3){
					attack(t4, x2, effect_ban_red_image, t3, pos, left_click, maou_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_2 == 4){
					attack(t4, x2, effect_ban_white_image, t3, pos, left_click, maou_HP, dm_2, effect_2, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_2 == 1){
					w_skill(t4, x2, effect_zan_image, effect_zan2_image, t3, pos, left_click, maou_HP, dm_2, zan2_sound);
				}
				if (skill_2 == 2){
					a_skill(t4, x2, effect_zaku2_image, t3, pos, left_click, maou_HP, dm_2, archar_effect_2, zaku_sound);
				}
				if (skill_2 == 3){
					m_skill(t4, x2, effect_ban_red_image, t3, pos, left_click, maou_HP, dm_1, magician_effect_2, ban_sound);
				}
				if (skill_2 == 4){
					h_skill(t4, x2, effect_heal_image, healer_command_image, t3, pos, left_click, healer_effect_2, heal_sound);
				}
				if (skill_2 == 5){
					t_skill(t4, x2, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t3, pos, left_click, thief_effect_2, debuff_sound);
				}
				if (skill_2 == 6){
					d_skill(t4, x2, effect_buff1_image, effect_buff2_image, effect_buff3_image, t3, pos, left_click, dancer_effect_2, buff_sound);
				}
				if (skill_2 == 7){
					s_skill(t4, x2, effect_zan3_image, t3, pos, left_click, maou_HP, dm_2, HP2, samurai_sound);
				}
				defense(t4, x2, effect_defense_image, t3, pos, left_click, HP2, b1_2, b3_2);
				escape(escape_image, t3, pos, left_click);
			}
			//プレイヤー3コマンド
			if (HP3 > 0){

				//コマンド系
				if (attack_3 == 1){
					attack(t6, x3, effect_zan_image, t5, pos, left_click, maou_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 2){
					attack(t6, x3, effect_zaku_image, t5, pos, left_click, maou_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 3){
					attack(t6, x3, effect_ban_red_image, t5, pos, left_click, maou_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_3 == 4){
					attack(t6, x3, effect_ban_white_image, t5, pos, left_click, maou_HP, dm_3, effect_3, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_3 == 1){
					w_skill(t6, x3, effect_zan_image, effect_zan2_image, t5, pos, left_click, maou_HP, dm_3, zan2_sound);
				}
				if (skill_3 == 2){
					a_skill(t6, x3, effect_zaku2_image, t5, pos, left_click, maou_HP, dm_3, archar_effect_3, zaku_sound);
				}
				if (skill_3 == 3){
					m_skill(t6, x3, effect_ban_red_image, t5, pos, left_click, maou_HP, dm_1, magician_effect_3, ban_sound);
				}
				if (skill_3 == 4){
					h_skill(t6, x3, effect_heal_image, healer_command_image, t5, pos, left_click, healer_effect_3, heal_sound);
				}
				if (skill_3 == 5){
					t_skill(t6, x3, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t5, pos, left_click, thief_effect_3, debuff_sound);
				}
				if (skill_3 == 6){
					d_skill(t6, x3, effect_buff1_image, effect_buff2_image, effect_buff3_image, t5, pos, left_click, dancer_effect_3, buff_sound);
				}
				if (skill_3 == 7){
					s_skill(t6, x3, effect_zan3_image, t5, pos, left_click, maou_HP, dm_3, HP3, samurai_sound);
				}
				defense(t6, x3, effect_defense_image, t5, pos, left_click, HP3, b1_3, b3_3);
				escape(escape_image, t5, pos, left_click);
			}
			//プレイヤー4コマンド
			if (HP4 > 0){
				//コマンド系
				if (attack_4 == 1){
					attack(t8, x4, effect_zan_image, t7, pos, left_click, maou_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 2){
					attack(t8, x4, effect_zaku_image, t7, pos, left_click, maou_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 3){
					attack(t8, x4, effect_ban_red_image, t7, pos, left_click, maou_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}
				if (attack_4 == 4){
					attack(t8, x4, effect_ban_white_image, t7, pos, left_click, maou_HP, dm_4, effect_4, zan_sound, zaku_sound, ban_sound);
				}

				if (skill_4 == 1){
					w_skill(t8, x4, effect_zan_image, effect_zan2_image, t7, pos, left_click, maou_HP, dm_4, zan2_sound);
				}
				if (skill_4 == 2){
					a_skill(t8, x4, effect_zaku2_image, t7, pos, left_click, maou_HP, dm_4, archar_effect_4, zaku_sound);
				}
				if (skill_4 == 3){
					m_skill(t8, x4, effect_ban_red_image, t7, pos, left_click, maou_HP, dm_1, magician_effect_4, ban_sound);
				}
				if (skill_4 == 4){
					h_skill(t8, x4, effect_heal_image, healer_command_image, t7, pos, left_click, healer_effect_4, heal_sound);
				}
				if (skill_4 == 5){
					t_skill(t8, x4, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t7, pos, left_click, thief_effect_4, debuff_sound);
				}
				if (skill_4 == 6){
					d_skill(t8, x4, effect_buff1_image, effect_buff2_image, effect_buff3_image, t7, pos, left_click, dancer_effect_4, buff_sound);
				}
				if (skill_4 == 7){
					s_skill(t8, x4, effect_zan3_image, t7, pos, left_click, maou_HP, dm_4, HP4, samurai_sound);
				}
				defense(t8, x4, effect_defense_image, t7, pos, left_click, HP4, b1_4, b3_4);
				escape(escape_image, t7, pos, left_click);
			}

			//バフ関連
			if (buff == 12){
				if (t == 10){
					buff_t++;
				}
				if (buff_t == 2){
					buff = 10;
					buff_t = 0;
				}
			}
			//デバフ
			if (debuff == 8){
				if (t == 10){
					debuff_t++;
				}
				if (debuff_t == 3){
					debuff = 10;
					debuff_t = 0;
				}
			}

			//ボスターン処理
			if (t == 10){
				BOSS_t++;
			}

			//プレイヤー1表示
			if (HP1 > 0){
				player1(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_1);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 1){
					t += 2;
				}
			}

			//プレイヤー2表示
			if (HP2 > 0){
				player2(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_2);
			}
			else{
				drawTextureBox(-400 + 100 * 2, 250 - 125 * 2, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 3){
					t += 2;
				}
			}

			//プレイヤー3表示
			if (HP3 > 0){
				player3(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_3);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 1 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 5){
					t += 2;
				}
			}

			//プレイヤー4表示
			if (HP4 > 0){
				player4(warrior_image, archer_image, magician_image, healer_image, thief_image, dancer_image, samurai_image, coffin_image, skill_4);
			}
			else{
				drawTextureBox(-400 + 100 * 1, 250 - 125 * 2 - 50, 128, 128, 0, 0, 128, 128,
					coffin_image,
					Color(1, 1, 1));
				if (t == 7){
					t += 2;
				}
			}

			//ゲームオーバー画面
			if (dead == 1){
				Sleep(500);
				maou_sound.stop();
				if (g == 0){
					g = 1;
					gameover_sound.play();
				}
				drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
					gameover_image,
					Color(1, 1, 1));
				if (left_click){
					e = 2;
				}
			}
			if (HP1 <= 0 && HP2 <= 0 && HP3 <= 0 && HP4 <= 0){
				dead = 1;
			}


			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	maou_sound.stop();
	clear_sound.play();

	//クリア画面4
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				clear_4_image,
				Color(1, 1, 1));
			if (left_click){
				break;
			}

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}
	clear_sound.stop();
	//アプリの終了	
	//}
	return 0;
}
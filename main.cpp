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

int i = 30, HP1 = 1, HP2 = 1, HP3 = 1, HP4 = 1, waiban_HP = 1000, t = 1, w = 0, t1 = 1, t2 = 2, t3 = 3, t4 = 4, t5 = 5,
t6 = 6, t7 = 7, t8 = 8, a = 0, s = 0, b = 0, b1_1 = 0, b1_2 = 0, b1_3 = 0, b1_4 = 0, b2 = 0, b3_1 = 1, b3_2 = 1, b3_3 = 1,
b3_4 = 1, e = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0, BOSS = 4, dead = 0, dm_1 = 0, dm_2 = 0, dm_3 = 0, dm_4 = 0, skill_1 = 0,
skill_2 = 0, skill_3 = 0, skill_4 = 0, ch_1 = 0, ch_2 = 0, ch_3 = 0, ch_4 = 0, BOSS_x = 0, BOSS_effect = 0, attack_1 = 0,
attack_2 = 0, attack_3 = 0, attack_4 = 0, effect = 0, effect_1 = 0, effect_2 = 0, effect_3 = 0, effect_4 = 0, BOSS_air = 0,
archar_effect_1 = 0, archar_effect_2 = 0, archar_effect_3 = 0, archar_effect_4 = 0, magician_effect_1 = 0, magician_effect_2 = 0,
magician_effect_3 = 0, magician_effect_4 = 0, healer_effect_1 = 0, healer_effect_2 = 0, healer_effect_3 = 0, healer_effect_4 = 0,
HP_sub1 = 1, HP_sub2 = 1, HP_sub3 = 1, HP_sub4 = 1, healer_player1 = 0, healer_player2 = 0, healer_player3 = 0, healer_player4 = 0,
C1_h = 0, C2_h = 0, C3_h = 0, C4_h = 0, h_1 = 0, h_2 = 0, h_3 = 0, h_4 = 0, c = 0, buff_t = 0, debuff_t = 0, dancer_effect_1 = 0,
dancer_effect_2 = 0, dancer_effect_3 = 0, dancer_effect_4 = 0, thief_effect_1 = 0, thief_effect_2 = 0, thief_effect_3 = 0,
thief_effect_4 = 0, skill_limit = 0;

float C1 = 0, C2 = 0, C3 = 0, C4 = 0, buff = 10, debuff = 10;


//こうげき関数
void attack(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& effect_a){
	if (effect_a == 1){
		if (attack_1 == 1 && t == 1){
			Sleep(200);
			t++;
		}
		if (attack_2 == 1 && t == 3){
			Sleep(200);
			t++;
		}
		if (attack_3 == 1 && t == 5){
			Sleep(200);
			t++;
		}
		if (attack_4 == 1 && t == 7){
			Sleep(200);
			t++;
		}
		if (attack_1 == 2 && t == 1){
			effect++;
			drawTextureBox(30 + effect * 8, -100, 256, 256, 0, 0, 256, 256,
				texture,
				Color(1, 1, 1));
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
			if (effect > 40){
				t++;
				effect = 0;
			}
		}
		if (attack_1 == 3 && t == 1){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
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
			if (effect > 25){
				t++;
				effect = 0;
			}
		}
		if (attack_1 == 4 && t == 1){
			effect++;
			if (effect == 5 || effect == 10 || effect == 15 || effect == 20){
				drawTextureBox(30, -100, 256, 256, 0, 0, 256, 256,
					texture,
					Color(1, 1, 1));
				Sleep(20);
			}
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
void w_skill(int& turn_plus1, int& xx, const Texture& texture, const Texture& texture2, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage){
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
void a_skill(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& archar_effect){
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
void m_skill(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& magician_effect){
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
void h_skill(int& turn_plus1, int& xx, const Texture& texture, const Texture& texture_h, int& turn, Vec2f pos, bool left_click, int& healer_effect){
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
void t_skill(int& turn_plus1, int& xx, const Texture& texture1, const Texture& texture2, const Texture& texture3, int& turn, Vec2f pos, bool left_click, int& thief_effect){
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
void d_skill(int& turn_plus1, int& xx, const Texture& texture1, const Texture& texture2, const Texture& texture3, int& turn, Vec2f pos, bool left_click, int& dancer_effect){
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
void s_skill(int& turn_plus1, int& xx, const Texture& texture, int& turn, Vec2f pos, bool left_click, int& BOSS_HP, int& damage, int& HP){
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
	Texture BOSS_1("res/waiba-n.png");
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


	//タイトル
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			//コンティニュー用
			waiban_HP = 1000;
			t = 1, dead = 0;

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
			if (app_env.isPushButton(Mouse::LEFT))  break;

			// 画面を更新
			app_env.update();
		}
		//入力のフラッシュ
		app_env.flushInput();
	}

	//キャラ選択画面
	{
		while (1){
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			Vec2f pos = app_env.mousePosition();
			bool left_click = app_env.isPushButton(Mouse::LEFT);
			bool right_click = app_env.isPushButton(Mouse::RIGHT);

			//メイン画面
			drawTextureBox(-800 / 2, -500 / 2, 800, 500, 0, 0, 800, 500,
				jobchange_image,
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
									dm_1 = 40;
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
									dm_1 = 40;
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
										dm_2 = 40;
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
										dm_2 = 40;
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
										dm_3 = 40;
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
										dm_3 = 40;
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
								ch_1 = 0;
								ch_2 = 0;
								ch_3 = 0;
								ch_4 = 0;
							}
						}
					}
				}
			}
			//デモ戦闘判定
			if (pos.x() > -400 + 640){
				if (pos.x() < -400 + 785){
					if (pos.y() < 250 - 449){
						if (pos.y() > 250 - 495){
							if (left_click){
								ch_1 = 1;
								ch_2 = 2;
								ch_3 = 3;
								ch_4 = 4;
								break;
							}
						}
					}
				}
			}
			if (right_click)break;

			// 画面を更新
			app_env.update();

		}
		//入力のフラッシュ
		app_env.flushInput();
	}



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


			//テストダメージ
			if (right_click){
				HP1 -= 0;
				HP2 -= 40;
				HP3 -= 40;
				HP4 -= 40;
			}


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

				if (BOSS == 0 && b3_1 == 1)HP1 -= (60 * (debuff / 10));
				if (BOSS == 1 && b3_2 == 1)HP2 -= (60 * (debuff / 10));
				if (BOSS == 2 && b3_3 == 1)HP3 -= (60 * (debuff / 10));
				if (BOSS == 3 && b3_4 == 1)HP4 -= (60 * (debuff / 10));
				t = 1;
				BOSS_effect = 0;
				BOSS = 4;
				BOSS_x = 0;
			}

			if (t == 10){
				t = 0;
				skill_limit = 0;
			}

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
					Color(1, 1, 1));
				drawBox(60, 110, 200, 4, 2, Color(0, 0, 0));
				drawFillBox(60, 110, waiban_HP / 5, 4, Color(0.2, 0.8, 0.2));
				if (i == 0){
					Sleep(500);
					break;
				}
				i = 0;
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
					attack(t2, x1, effect_zan_image, t1, pos, left_click, waiban_HP, dm_1, effect_1);
				}
				if (attack_1 == 2){
					attack(t2, x1, effect_zaku_image, t1, pos, left_click, waiban_HP, dm_1, effect_1);
				}
				if (attack_1 == 3){
					attack(t2, x1, effect_ban_red_image, t1, pos, left_click, waiban_HP, dm_1, effect_1);
				}
				if (attack_1 == 4){
					attack(t2, x1, effect_ban_white_image, t1, pos, left_click, waiban_HP, dm_1, effect_1);
				}

				if (skill_1 == 1){
					w_skill(t2, x1, effect_zan_image, effect_zan2_image, t1, pos, left_click, waiban_HP, dm_1);
				}
				if (skill_1 == 2){
					a_skill(t2, x1, effect_zaku2_image, t1, pos, left_click, waiban_HP, dm_1, archar_effect_1);
				}
				if (skill_1 == 3){
					m_skill(t2, x1, effect_ban_red_image, t1, pos, left_click, waiban_HP, dm_1, magician_effect_1);
				}
				if (skill_1 == 4){
					h_skill(t2, x1, effect_heal_image, healer_command_image, t1, pos, left_click, healer_effect_1);
				}
				if (skill_1 == 5){
					t_skill(t2, x1, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t1, pos, left_click, thief_effect_1);
				}
				if (skill_1 == 6){
					d_skill(t2, x1, effect_buff1_image, effect_buff2_image, effect_buff3_image, t1, pos, left_click, dancer_effect_1);
				}
				if (skill_1 == 7){
					s_skill(t2, x1, effect_zan3_image, t1, pos, left_click, waiban_HP, dm_1, HP1);
				}
				defense(t2, x1, effect_defense_image, t1, pos, left_click, HP1, b1_1, b3_1);
				escape(escape_image, t1, pos, left_click);
			}
			//プレイヤー2コマンド
			if (HP2 > 0){
				//コマンド系
				if (attack_2 == 1){
					attack(t4, x2, effect_zan_image, t3, pos, left_click, waiban_HP, dm_2, effect_2);
				}
				if (attack_2 == 2){
					attack(t4, x2, effect_zaku_image, t3, pos, left_click, waiban_HP, dm_2, effect_2);
				}
				if (attack_2 == 3){
					attack(t4, x2, effect_ban_red_image, t3, pos, left_click, waiban_HP, dm_2, effect_2);
				}
				if (attack_2 == 4){
					attack(t4, x2, effect_ban_white_image, t3, pos, left_click, waiban_HP, dm_2, effect_2);
				}

				if (skill_2 == 1){
					w_skill(t4, x2, effect_zan_image, effect_zan2_image, t3, pos, left_click, waiban_HP, dm_2);
				}
				if (skill_2 == 2){
					a_skill(t4, x2, effect_zaku2_image, t3, pos, left_click, waiban_HP, dm_2, archar_effect_2);
				}
				if (skill_2 == 3){
					m_skill(t4, x2, effect_ban_red_image, t3, pos, left_click, waiban_HP, dm_1, magician_effect_2);
				}
				if (skill_2 == 4){
					h_skill(t4, x2, effect_heal_image, healer_command_image, t3, pos, left_click, healer_effect_2);
				}
				if (skill_2 == 5){
					t_skill(t4, x2, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t3, pos, left_click, thief_effect_2);
				}
				if (skill_2 == 6){
					d_skill(t4, x2, effect_buff1_image, effect_buff2_image, effect_buff3_image, t3, pos, left_click, dancer_effect_2);
				}
				if (skill_2 == 7){
					s_skill(t4, x2, effect_zan3_image, t3, pos, left_click, waiban_HP, dm_2, HP2);
				}
				defense(t4, x2, effect_defense_image, t3, pos, left_click, HP2, b1_2, b3_2);
				escape(escape_image, t3, pos, left_click);
			}
			//プレイヤー3コマンド
			if (HP3 > 0){

				//コマンド系
				if (attack_3 == 1){
					attack(t6, x3, effect_zan_image, t5, pos, left_click, waiban_HP, dm_3, effect_3);
				}
				if (attack_3 == 2){
					attack(t6, x3, effect_zaku_image, t5, pos, left_click, waiban_HP, dm_3, effect_3);
				}
				if (attack_3 == 3){
					attack(t6, x3, effect_ban_red_image, t5, pos, left_click, waiban_HP, dm_3, effect_3);
				}
				if (attack_3 == 4){
					attack(t6, x3, effect_ban_white_image, t5, pos, left_click, waiban_HP, dm_3, effect_3);
				}

				if (skill_3 == 1){
					w_skill(t6, x3, effect_zan_image, effect_zan2_image, t5, pos, left_click, waiban_HP, dm_3);
				}
				if (skill_3 == 2){
					a_skill(t6, x3, effect_zaku2_image, t5, pos, left_click, waiban_HP, dm_3, archar_effect_3);
				}
				if (skill_3 == 3){
					m_skill(t6, x3, effect_ban_red_image, t5, pos, left_click, waiban_HP, dm_1, magician_effect_3);
				}
				if (skill_3 == 4){
					h_skill(t6, x3, effect_heal_image, healer_command_image, t5, pos, left_click, healer_effect_3);
				}
				if (skill_3 == 5){
					t_skill(t6, x3, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t5, pos, left_click, thief_effect_3);
				}
				if (skill_3 == 6){
					d_skill(t6, x3, effect_buff1_image, effect_buff2_image, effect_buff3_image, t5, pos, left_click, dancer_effect_3);
				}
				if (skill_3 == 7){
					s_skill(t6, x3, effect_zan3_image, t5, pos, left_click, waiban_HP, dm_3, HP3);
				}
				defense(t6, x3, effect_defense_image, t5, pos, left_click, HP3, b1_3, b3_3);
				escape(escape_image, t5, pos, left_click);
			}
			//プレイヤー4コマンド
			if (HP4 > 0){
				//コマンド系
				if (attack_4 == 1){
					attack(t8, x4, effect_zan_image, t7, pos, left_click, waiban_HP, dm_4, effect_4);
				}
				if (attack_4 == 2){
					attack(t8, x4, effect_zaku_image, t7, pos, left_click, waiban_HP, dm_4, effect_4);
				}
				if (attack_4 == 3){
					attack(t8, x4, effect_ban_red_image, t7, pos, left_click, waiban_HP, dm_4, effect_4);
				}
				if (attack_4 == 4){
					attack(t8, x4, effect_ban_white_image, t7, pos, left_click, waiban_HP, dm_4, effect_4);
				}

				if (skill_4 == 1){
					w_skill(t8, x4, effect_zan_image, effect_zan2_image, t7, pos, left_click, waiban_HP, dm_4);
				}
				if (skill_4 == 2){
					a_skill(t8, x4, effect_zaku2_image, t7, pos, left_click, waiban_HP, dm_4, archar_effect_4);
				}
				if (skill_4 == 3){
					m_skill(t8, x4, effect_ban_red_image, t7, pos, left_click, waiban_HP, dm_1, magician_effect_4);
				}
				if (skill_4 == 4){
					h_skill(t8, x4, effect_heal_image, healer_command_image, t7, pos, left_click, healer_effect_4);
				}
				if (skill_4 == 5){
					t_skill(t8, x4, effect_debuff1_image, effect_debuff2_image, effect_debuff3_image, t7, pos, left_click, thief_effect_4);
				}
				if (skill_4 == 6){
					d_skill(t8, x4, effect_buff1_image, effect_buff2_image, effect_buff3_image, t7, pos, left_click, dancer_effect_4);
				}
				if (skill_4 == 7){
					s_skill(t8, x4, effect_zan3_image, t7, pos, left_click, waiban_HP, dm_4, HP4);
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



			if (dead == 1){
				Sleep(500);
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
	//アプリの終了	
	//}
	return 0;
}
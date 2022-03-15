#include "GameMain.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GMainConfig.h"

// �ϐ���`
int GMainImg[IMG_MAX] = {};						// �摜�p�ϐ�
int GMainSnd[SND_MAX] = {};						// �����p�ϐ�
int Score[TYPE_MAX] = {};						// �X�R�A�Ǘ��z��
int	WorldTime;									// ��������
T_PLAYER Player;								// �v���C���[
T_ENEMY Apple[APPLE_MAX] = {};					// ���������S
T_ENEMY	AppleStd;								// �����S�������
// �v���g�^�C�v�錾
void stage_background(void);					// �w�i�`�揈��
void player_ctrl(void);							// �v���C���[���䏈��
void apple_ctrl(void);							// �����S���䏈��
void create_apple(void);						// �����S��������
void stage_ui_ctrl(void);						// UI�`�揈��
int hitcheck(T_PLAYER *p, T_ENEMY *e);			// �����蔻�菈��

// �Q�[�����C���@�\����������
void GMainInit(void)
{
	int i;

	// �v���C���[������
	Player.pos.x = PSTD_POS_X;
	Player.pos.y = PSTD_POS_Y;
	Player.scale.x = PSTD_WIDTH;
	Player.scale.y = PSTD_HEIGHT;
	Player.angle = 0.0f;
	Player.img = GMainImg[PLAYER_STD];
	Player.flg = true;

	// �����S������
	AppleStd.pos.x = APPLE_STX;
	AppleStd.pos.y = APPLE_STY;
	AppleStd.scale.x = APPLE_SCALE;
	AppleStd.scale.y = APPLE_SCALE;
	AppleStd.flg = false;
	for (i = 0; i < APPLE_MAX; i++) {
		Apple[i] = AppleStd;
	}
	for (i = 0; i < TYPE_MAX; i++) {
		Score[i] = 0;
	}
	WorldTime = SET_TIME;
}
// �Q�[�����C���@�\�X�V����
void GMainUpdate(void)
{
	// �w�i�`�揈��
	stage_background();
	// �v���C���[���䏈��
	player_ctrl();
	// �����S���䏈��
	apple_ctrl();
	// UI�`�揈��
	stage_ui_ctrl();
	if (WorldTime-- <= 0) {
		Set_SceneMng_Next(E_GAME_MODE::TITLE);
	}
}
// �Q�[�����C���@�\�摜�ǂݍ��ݏ���
int  LoadGMainImg(void)
{
	int i;

	// �摜�ǂݍ���
	GMainImg[BACK_GROUND] = LoadGraph("../images/bg_natural_mori.png");
	GMainImg[APPLE_RED] = LoadGraph("../images/fruit_ringo.png");
	GMainImg[APPLE_YLW] = LoadGraph("../images/fruit_apple_yellow.png");
	GMainImg[APPLE_GRN] = LoadGraph("../images/fruit_ao_ringo.png");
	GMainImg[APPLE_AST] = LoadGraph("../images/fruit_apple_shiwashiwa.png");
	GMainImg[PLAYER_STD] = LoadGraph("../images/Player01.png");
	GMainImg[PLAYER_RUN] = LoadGraph("../images/Player02.png");
	LoadDivGraph("../images/number-simple-01.png", 10, 5, 2, 1, 1, &GMainImg[NUMBER]);

	// �G���[�`�F�b�N
	for (i = 0; i < IMG_MAX; i++) {
		if (GMainImg[i] == -1) {
			return -1;
		}
	}

	return 0;
}
// �Q�[�����C���@�\�����ǂݍ��ݏ���
int  LoadGMainSnd(void)
{
	int i;

	for (i = 0; i < SND_MAX; i++) {
		if (GMainSnd[i] == -1) {
			return -1;
		}
	}
	return 0;
}
// �w�i�`�揈��
void stage_background(void)
{
	//�`��\�G���A��F��
	SetDrawArea(0, 0, BG_AREA_X, BG_AREA_Y);
	// �w�i�摜�̕`��
	DrawRotaGraph(BG_POS_X, BG_POS_Y, BG_EXT, 0, GMainImg[BACK_GROUND], TRUE);

	//�G���A��߂�
	SetDrawArea(0, 0, 640, 480);
	//	//�X�e�[�W�w�i
	DrawBox(BG_AREA_X, 0, 640, 480, 0xFF66FF, TRUE);
}
// �v���C���[���䏈��
void player_ctrl(void)
{
	int flip = FALSE;
	if (GetInputKey(PAD_INPUT_LEFT)) {			// �����L�[���͎�
		Player.img = GMainImg[PLAYER_RUN];
		Player.scale.x = PMOV_WIDTH;
		Player.scale.y = PMOV_HEIGHT;
		if (Player.pos.x >= (Player.scale.x >> 1)) {
			Player.pos.x -= PSTD_SPEED;
		}
	}
	else if (GetInputKey(PAD_INPUT_RIGHT)) {	// �E���L�[���͎�
		Player.img = GMainImg[PLAYER_RUN];
		flip = TRUE;
		Player.scale.x = PMOV_WIDTH;
		Player.scale.y = PMOV_HEIGHT;
		if (Player.pos.x <= (BG_AREA_X - (Player.scale.x >> 1))) {
			Player.pos.x += PSTD_SPEED;
		}		
	}
	else {										// �����͎�
		Player.img = GMainImg[PLAYER_STD];
		Player.scale.x = PSTD_WIDTH;
		Player.scale.y = PSTD_HEIGHT;
	}


	// �����蔻�������
	/*DrawBox((Player.pos.x - (Player.scale.x >> 1)), (Player.pos.y - (Player.scale.y >> 1)), 
			(Player.pos.x + (Player.scale.x >> 1)), (Player.pos.y + (Player.scale.y >> 1)),
			0x00000000, FALSE);*/
	DrawRotaGraph(Player.pos.x, Player.pos.y, PSTD_EXT, Player.angle, Player.img, TRUE, flip, FALSE);
}
// �����S���䏈��
void apple_ctrl(void)
{
	int i, j;
	for (i = 0; i < APPLE_MAX; i++) {
		if (Apple[i].flg) {
			
			DrawRotaGraph(Apple[i].pos.x, Apple[i].pos.y, APPLE_EXT, 0.0, Apple[i].img, TRUE);
			/*DrawBox((Apple[i].pos.x - (Apple[i].scale.x >> 1)), (Apple[i].pos.y - (Apple[i].scale.y >> 1)),
				(Apple[i].pos.x + (Apple[i].scale.x >> 1)), (Apple[i].pos.y + (Apple[i].scale.y >> 1)),
				0x00000000, FALSE);*/
			if (!Player.flg) {
				continue;
			}
			// �����S�ɂ���ė������x���ω�
			switch (Apple[i].type) {
				case APPLE_RED:
					Apple[i].pos.y += APPLE_FALLSP / 5;
					break;
				case APPLE_YLW:
					Apple[i].pos.y += APPLE_FALLSP / 2;
					break;
				case APPLE_GRN:
					Apple[i].pos.y += APPLE_FALLSP;
					break;
				default:
					Apple[i].pos.y += APPLE_FALLSP / 10;
					break;
			}
			// ��ʊO�ɍs������폜
			if (Apple[i].pos.y > 480 + Apple[i].scale.y) {
				Apple[i].flg = false;
			}
			// �����蔻��
			if (hitcheck(&Player, &Apple[i])) {
				Apple[i].flg = false;
				if (Apple[i].type < APPLE_AST){
					Score[Apple[i].type]++;
				}
				if(Apple[i].type == APPLE_AST) {
					for (j = 0; j < APPLE_AST; j++) {
						if (Score[j] > 0) {
							Score[j]--;
						}
					}
				}
			}
		}
	}
	// ���Ԍo�߂Ő���������
	if (WorldTime % 60 == 0) {
		create_apple();
	}
}
// �����S��������
void create_apple(void)
{
	int i, tmp;

	for (i = 0; i < APPLE_MAX; i++) {
		if (!Apple[i].flg) {
			Apple[i] = AppleStd;
			tmp = GetRand(TYPE_MAX - 1);
			if (tmp) {
				tmp = GetRand(TYPE_MAX - 1);
			}
			Apple[i].type = tmp;
			Apple[i].img = GMainImg[Apple[i].type];
			Apple[i].pos.x = GetRand(6) * APPLE_CRWD + Apple[i].scale.x;
			Apple[i].flg = true;
		}
	}
}
// UI�`�揈��
void stage_ui_ctrl(void)
{
	int i;

	SetFontSize(25);
	DrawFormatString(520, 50, 0x00000000, "��������");
	SetFontSize(50);
	DrawFormatString(550, 100, 0x00000000, "%02d", (WorldTime / 100));
	for (i = 0; i < APPLE_AST; i++) {
		DrawRotaGraph((535 + (i * 40)), 230, 0.075, 0.0, GMainImg[i], TRUE);
	}
	SetFontSize(15);
	for (i = 0; i < APPLE_AST; i++) {
		DrawFormatString((530 + (i * 40)), 250, 0x00000000, "%02d", Score[i]);
	}
}
// �����蔻��`�F�b�N
int hitcheck(T_PLAYER *p, T_ENEMY *e)
{

	//x,y�͒��S���W�Ƃ���
	int sx1 = p->pos.x - (p->scale.x >> 1);
	int sx2 = sx1 + p->scale.x;
	int sy1 = p->pos.y - (p->scale.y >> 1);
	int sy2 = sy1 + p->scale.y;

	int dx1 = e->pos.x - (e->scale.x >> 1);
	int dx2 = dx1 + e->scale.x;
	int dy1 = e->pos.y - (e->scale.y >> 1);
	int dy2 = dy1 + e->scale.y;

	//��`���d�Ȃ��Ă���Γ�����
	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		return TRUE;
	}
	return FALSE;
}

#include <iostream>
#include <windows.h>
#include <list>
#include <stdio.h>

constexpr int s_iMaxHeight = 10;
constexpr int s_iMaxWidth = 15;

struct TEnemy {
	int m_ix;
	char m_cSprite;
	TEnemy(int _iX, char _cSprite);
	void Draw();
	void Move();
	void Die();
};
struct TPlayer{
	int m_ix;
	char m_cSprite;
	bool m_bAlive;
	TPlayer(int _iX, char _cSprite);
	void Draw();
	void ShootE();
	void ShootR();
	void Die();
};
struct TBullet {
	int m_ix;
	char m_cSprite; 
	TBullet(int _iX, char _cSprite);
	void Draw();
	void Move();
	void Die();
};

const int iMaxEnemies = 10;
const int iMaxBullets = 10;

const int iEnemyStartingPos = s_iMaxWidth;
const int iPlayerStartingPos = 0;
const int iBulletStartingPos = iPlayerStartingPos + 1;

const int iCharToUpper = 32;

TEnemy* tEnemies[s_iMaxWidth];
TEnemy* tEnemyPool[iMaxEnemies];
unsigned int uEnemyPoolSize = iMaxEnemies;
TBullet* tBullets[s_iMaxWidth];
TBullet* tBulletPoolE[iMaxBullets];
TBullet* tBulletPoolR[iMaxBullets];
unsigned int uBulletPoolSizeE = iMaxBullets;
unsigned int uBulletPoolSizeR = iMaxBullets;
TPlayer* pPlayer;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void hidecursor(void) {
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}

void clear()
{
	system("cls");
}






TPlayer::TPlayer(int _iX, char _cSprite)
	: m_ix(_iX)
	, m_cSprite(_cSprite)
	, m_bAlive(true)
{}

void TPlayer::Draw() {
	gotoxy(m_ix, 0);
	printf("%c", m_cSprite);
}
void TPlayer::ShootE() {
	if (uBulletPoolSizeE > 0) {
		tBullets[0] = tBulletPoolE[uBulletPoolSizeE - 1];
		tBulletPoolE[uBulletPoolSizeE - 1] = nullptr;
		uBulletPoolSizeE--;
	}
}
void TPlayer::ShootR() {
	if (uBulletPoolSizeR > 0) {
		tBullets[0] = tBulletPoolR[uBulletPoolSizeR - 1];
		tBulletPoolR[uBulletPoolSizeR - 1] = nullptr;
		uBulletPoolSizeR--;
	}
}
void TPlayer::Die() {
	m_bAlive = false;
}
TEnemy::TEnemy(int _iX, char _cSprite)
	: m_ix(_iX)
	, m_cSprite(_cSprite)
{}

void TEnemy::Draw() {
	gotoxy(m_ix, 0);
	printf("%c", m_cSprite);
}
void TEnemy::Move() {
	m_ix--;
	if (m_ix <= 0)
	{
		m_ix = 0;
		pPlayer->Die();
	}
	else {
		tEnemies[m_ix - 1] = this;
		tEnemies[m_ix] = nullptr;
		if (tBullets[m_ix - 1]) {
			int iAuxX = m_ix;
			if (tBullets[iAuxX - 1]->m_cSprite - iCharToUpper == m_cSprite) {
				Die();
			}
			// Si no se pone el aux se mata la que no toca porque al morirse se pone a si mismo m_iX al tope de la pantalla
			tBullets[iAuxX - 1]->Die();
		}
	}
}
void TEnemy::Die() {
	tEnemies[m_ix - 1] = nullptr;
	uEnemyPoolSize++;
	tEnemyPool[uEnemyPoolSize - 1] = this;
	m_ix = s_iMaxWidth;
}
TBullet::TBullet(int _iX, char _cSprite)
{
	m_ix = _iX;
	m_cSprite = _cSprite;
}

void TBullet::Draw() {
	gotoxy(m_ix, 0);
	printf("%c", m_cSprite);
}
void TBullet::Move() {
	m_ix++;
	if (m_ix > s_iMaxWidth) {
		m_ix = s_iMaxWidth;
		Die();
	}
	else {
		tBullets[m_ix - 1] = this;
		tBullets[m_ix - 2] = nullptr;
		if (tEnemies[m_ix - 1]) {
			int iAuxX = m_ix;
			if (tEnemies[iAuxX - 1]->m_cSprite == m_cSprite - iCharToUpper) {
				tEnemies[iAuxX - 1]->Die();
			}
			Die();
		}
	}
}
void TBullet::Die() {
	tBullets[m_ix - 1] = nullptr;
	if (m_cSprite == 'e') {
		uBulletPoolSizeE++;
		tBulletPoolE[uBulletPoolSizeE - 1] = this;
	}else if (m_cSprite == 'r') {
		uBulletPoolSizeR++;
		tBulletPoolR[uBulletPoolSizeR - 1] = this;
	}
	m_ix = 1;
}
void InitGameObjects() {
	for (unsigned int i = 0; i < iMaxEnemies; i++) {
		if (std::rand() % 2 == 0) {
			tEnemyPool[i] = new TEnemy(iEnemyStartingPos, 'E');
		}
		else {
			tEnemyPool[i] = new TEnemy(iEnemyStartingPos, 'R');
		}
	}
	for (unsigned int i = 0; i < iMaxBullets; i++) {
		tBulletPoolE[i] = new TBullet(iBulletStartingPos, 'e');
	}
	for (unsigned int i = 0; i < iMaxBullets; i++) {
		tBulletPoolR[i] = new TBullet(iBulletStartingPos, 'r');
	}
	pPlayer = new TPlayer(iPlayerStartingPos, 'A');
}

void Input(bool* _pEPressed, bool* _pRPressed) {
	*_pEPressed = GetKeyState('E') & 0x8000;
	*_pRPressed = GetKeyState('R') & 0x8000;
}
void Logic(bool _bEPressed, bool _bRPressed) {

	for (int i = s_iMaxWidth - 1; i >= 0; i--) {
		if (tBullets[i]) {
			tBullets[i]->Move();
		}
	}
	if (uEnemyPoolSize > 0 && std::rand() % 2 == 0) {
		tEnemies[s_iMaxWidth - 1] = tEnemyPool[uEnemyPoolSize - 1];
		tEnemyPool[uEnemyPoolSize - 1] = nullptr;
		uEnemyPoolSize--;
	}
	for (int i = 0 ; i < s_iMaxWidth; i++) {
		if (tEnemies[i]) {
			tEnemies[i]->Move();
		}
	}
	if (_bEPressed) {
		pPlayer->ShootE();
	}else if (_bRPressed) {
		pPlayer->ShootR();
	}
}
void Render() {
	pPlayer->Draw();
	for (int i = 0; i < s_iMaxWidth; i++) {
		if (tBullets[i]) {
			tBullets[i]->Draw();
		}
		if (tEnemies[i]) {
			tEnemies[i]->Draw();
		}
	}
}
int main(int argc, char* argv[])
{
	InitGameObjects();

	int i = 0;
	bool bEPressed = false;
	bool bRPressed = false;
	while (pPlayer->m_bAlive)
	{
		clear();
		Input(&bEPressed, &bRPressed);
		Logic(bEPressed, bRPressed);
		Render();

		Sleep(200);
	}
}

